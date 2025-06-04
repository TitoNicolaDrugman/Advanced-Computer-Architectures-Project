import torch

def export_to_onnx(torch_model, dummy_input, output_path):
    torch.onnx.export(
        torch_model,                     # modello PyTorch
        dummy_input,               # input fittizio
        output_path,       # output file
        input_names=["input"],
        output_names=["output"],
        dynamic_axes={"input": {0: "batch_size"}, "output": {0: "batch_size"}},
        opset_version=13           # assicurati che sia compatibile col tuo target
    )