import os
import torch

from custom_models.ggcnn.models.ggcnn2 import GGCNN2
from tools.torch_to_onnx import export_to_onnx

script_dir = os.path.dirname(os.path.abspath(__file__))
weights_path = os.path.abspath(os.path.join(script_dir, "../pretrained_models/gg-cnn/gg-cnn_statedict.pt"))
output_path = os.path.abspath(os.path.join(script_dir, "../pretrained_models/gg-cnn/gg-cnn.onnx"))

model = GGCNN2()
model.load_state_dict(torch.load(weights_path, weights_only=False, map_location=torch.device("mps")))


dummy_input = torch.randn(1, 1, 300, 300)
export_to_onnx(torch_model=model, dummy_input=dummy_input, output_path=output_path)

