import torch
from models.ggcnn2 import GGCNN2

model = GGCNN2()
model.load_state_dict(torch.load('../../pretrained_models/gg-cnn_statedict.pt', weights_only=False, map_location=torch.device("mps")))


dummy_input = torch.randn(1, 1, 300, 300)

def export_to_onnx(torch_model, output_path):
    torch.onnx.export(
        model,                     # modello PyTorch
        dummy_input,               # input fittizio
        output_path,       # output file
        input_names=["input"],
        output_names=["output"],
        dynamic_axes={"input": {0: "batch_size"}, "output": {0: "batch_size"}},
        opset_version=13           # assicurati che sia compatibile col tuo target
    )