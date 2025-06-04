import tensorflow as tf
from tensorflow.keras import layers, models

def create_tiny_transformer(seq_len=16, vocab_size=100, d_model=32):
    inputs = tf.keras.Input(shape=(seq_len,), batch_size=1, dtype='int32')

    x = layers.Embedding(input_dim=vocab_size, output_dim=d_model)(inputs)

    positions = tf.range(start=0, limit=seq_len, delta=1)
    pos_embed = layers.Embedding(input_dim=seq_len, output_dim=d_model)(positions)
    x = x + pos_embed

    attention_output = layers.MultiHeadAttention(num_heads=1, key_dim=d_model)(x, x)
    x = layers.Add()([x, attention_output])
    x = layers.LayerNormalization()(x)

    ff = layers.Dense(64, activation='relu')(x)
    ff = layers.Dense(d_model)(ff)
    x = layers.Add()([x, ff])
    x = layers.LayerNormalization()(x)

    x = layers.GlobalAveragePooling1D()(x)
    outputs = layers.Dense(2, activation='softmax')(x)

    model = tf.keras.Model(inputs=inputs, outputs=outputs)
    return model