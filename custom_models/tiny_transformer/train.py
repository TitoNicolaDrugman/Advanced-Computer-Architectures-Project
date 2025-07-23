import numpy as np
import tensorflow as tf
from tiny_transformer import create_tiny_transformer

model = create_tiny_transformer()
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Dummy training data
X = np.random.randint(0, 100, size=(100, 16))
y = np.random.randint(0, 2, size=(100,))
model.fit(X, y, epochs=1)

np.savetxt("example_input.txt", X[:1], fmt="%d")

# Export to TFLite format
converter = tf.lite.TFLiteConverter.from_keras_model(model)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
tflite_model = converter.convert()

with open("tiny_transformer.tflite", "wb") as f:
    f.write(tflite_model)

print("Model exported as tiny_transformer.tflite")