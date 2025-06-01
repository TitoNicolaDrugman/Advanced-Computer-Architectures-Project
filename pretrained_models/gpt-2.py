import torch
from transformers import pipeline

pipeline = pipeline(task="text-generation", model="openai-community/gpt2", torch_dtype=torch.float16, device=0)
print(pipeline("Hello, I'm a language model"))