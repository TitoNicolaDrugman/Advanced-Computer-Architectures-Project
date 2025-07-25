import math, time, torch, torch.nn as nn, torch.optim as optim
import torchvision, torchvision.transforms as T
import onnx
from sklearn.metrics import accuracy_score, average_precision_score
import numpy as np
from onnxruntime.quantization import quantize_static, CalibrationDataReader, QuantType

# ─── Transformer Block ────────────────────────────────────────────────
class Block(nn.Module):
    def __init__(self, E, mlp_mul):
        super().__init__()
        self.ln1 = nn.LayerNorm(E)
        self.qkv = nn.Linear(E, 3 * E)
        self.proj = nn.Linear(E, E)
        self.ln2 = nn.LayerNorm(E)
        self.ff1 = nn.Linear(E, E * mlp_mul)
        self.act = nn.GELU()
        self.ff2 = nn.Linear(E * mlp_mul, E)

    def forward(self, x):
        r = x
        x = self.ln1(x)
        q, k, v = self.qkv(x).chunk(3, dim=-1)
        att = (q @ k.transpose(-2, -1)) / math.sqrt(x.size(-1))
        x = self.proj(att.softmax(-1) @ v) + r

        r = x
        x = self.ln2(x)
        x = self.ff2(self.act(self.ff1(x))) + r
        return x

# ─── Vision Transformer ───────────────────────────────────────────────
class VisionTransformer(nn.Module):
    def __init__(self, img=32, patch=4, E=192, mlp_mul=2, depth=6, n_cls=10):
        super().__init__()
        n_p = (img // patch) ** 2
        self.patch = nn.Conv2d(3, E, patch, patch)
        self.bn = nn.BatchNorm2d(E)
        self.pos = nn.Parameter(torch.zeros(1, n_p, E))
        self.blocks = nn.ModuleList([Block(E, mlp_mul) for _ in range(depth)])
        self.head = nn.Linear(E, n_cls)

    def forward(self, x):
        x = self.patch(x)
        x = self.bn(x)
        x = x.flatten(2).transpose(1, 2)
        x = x + self.pos
        for blk in self.blocks:
            x = blk(x)
        return self.head(x.mean(1))

# ─── Calibration Reader ───────────────────────────────────────────────
class CalibDataReader(CalibrationDataReader):
    def __init__(self, data_loader, max_samples=50):
        self.inputs = []
        for i, (x, _) in enumerate(data_loader):
            if i >= max_samples: break
            self.inputs.append({"input": x[0:1].numpy().astype(np.float32)})
        self.idx = 0

    def get_next(self):
        if self.idx >= len(self.inputs): return None
        sample = self.inputs[self.idx]
        self.idx += 1
        return sample

    def rewind(self): self.idx = 0

# ─── Main ─────────────────────────────────────────────────────────────
def main():
    BATCH, EPOCHS = 64, 20
    TARGET_PARAMS = 2_000_000

    # Data
    tf = T.Compose([T.RandomCrop(32, padding=4), T.RandomHorizontalFlip(),
                    T.ToTensor(), T.Normalize((0.4914,0.4822,0.4465),
                                              (0.2471,0.2435,0.2616))])
    train_ds = torchvision.datasets.CIFAR10("data", train=True, download=True, transform=tf)
    test_ds = torchvision.datasets.CIFAR10("data", train=False, download=True, transform=tf)

    # Reduce steps per epoch
    train_ds = torch.utils.data.Subset(train_ds, range(2000))
    test_ds = torch.utils.data.Subset(test_ds, range(1000))

    train_ld = torch.utils.data.DataLoader(train_ds, batch_size=BATCH, shuffle=True)
    test_ld = torch.utils.data.DataLoader(test_ds, batch_size=BATCH)

    # Model
    device = "cuda" if torch.cuda.is_available() else "cpu"
    model = VisionTransformer(E=192, depth=6, mlp_mul=2).to(device)
    n_params = sum(p.numel() for p in model.parameters())
    print(f"Parameter count: {n_params:,} (Target: {TARGET_PARAMS:,})")

    opt = optim.AdamW(model.parameters(), lr=3e-4)
    criterion = nn.CrossEntropyLoss()

    # Training
    for ep in range(EPOCHS):
        model.train()
        for x, y in train_ld:
            x, y = x.to(device), y.to(device)
            opt.zero_grad()
            loss = criterion(model(x), y)
            loss.backward()
            opt.step()

        # Eval with Accuracy & AP
        model.eval()
        y_true, y_pred, y_prob = [], [], []
        with torch.no_grad():
            for x, y in test_ld:
                x = x.to(device)
                out = model(x)
                probs = nn.Softmax(dim=1)(out).cpu().numpy()
                preds = probs.argmax(1)
                y_true += y.numpy().tolist()
                y_pred += preds.tolist()
                y_prob.append(probs)
        y_prob = np.vstack(y_prob)
        acc = accuracy_score(y_true, y_pred)
        ap = average_precision_score(np.eye(10)[y_true], y_prob, average='macro')
        print(f"Epoch {ep+1:2d}: Accuracy={acc*100:.2f}%, AP={ap:.4f}")

    # Export FP32
    dummy = torch.randn(1, 3, 32, 32).to(device)
    onnx_fp32 = "vit2M_20ep_fp32.onnx"
    torch.onnx.export(model, dummy, onnx_fp32, opset_version=13,
                      input_names=["input"], output_names=["output"])
    onnx.checker.check_model(onnx_fp32)
    print("✔ Exported FP32 ONNX:", onnx_fp32)

    # Quantize INT8
    reader = CalibDataReader(test_ld)
    onnx_int8 = "vit2M_20ep_int8.onnx"
    quantize_static(
        model_input=onnx_fp32,
        model_output=onnx_int8,
        calibration_data_reader=reader,
        activation_type=QuantType.QInt8,
        weight_type=QuantType.QInt8,
        quant_format="QOperator"
    )
    print("✔ Exported INT8 ONNX:", onnx_int8)

if __name__ == "__main__":
    import multiprocessing as mp
    mp.freeze_support()
    torch.multiprocessing.set_start_method("spawn", force=True)
    main()
