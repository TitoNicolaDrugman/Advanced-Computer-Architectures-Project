import tensorflow as tf

# Carica il modello TFLite
interpreter = tf.lite.Interpreter(model_path="./pretrained_models/tiny_transformer.tflite")
interpreter.allocate_tensors()

# Estrai dettagli tensori e operatori
tensor_details = interpreter.get_tensor_details()
operator_details = interpreter._get_ops_details()

eltwise_ops = ["ADD", "MUL", "SUB", "DIV", "SQRT", "RSQRT", "NEG", "SQUARE"]

for i, op in enumerate(operator_details):
    op_type = op['op_name']
    if op_type in eltwise_ops:
        inputs = op['inputs']
        outputs = op['outputs']
        output_names = [tensor_details[o]['name'] for o in outputs]
        print(f"[{i}] Type: {op_type}, Output(s): {output_names}")