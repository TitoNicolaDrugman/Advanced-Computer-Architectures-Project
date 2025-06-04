import tensorflow as tf

model_path = "./pretrained_models/mobile_bert.tflite"

interpreter = tf.lite.Interpreter(model_path=model_path)
print(interpreter.allocate_tensors())

for detail in interpreter.get_tensor_details():
    print(detail["name"])