<h1>Demonstration of a Simple Transformer Running on the NPU of an STM32N6</h1>

<h2>Table of contents</h2>

- [Overview](#overview)
- [Outcomes](#outcomes)
- [Outline](#outline)
- [Useful Links](#useful-links)
  - [STM32N6 Resources](#stm32n6-resources)
  - [STM32AI Model Zoo](#stm32ai-model-zoo)
  - [Transformers](#transformers)

---

## Overview

This project aims at realizing a functioning demonstration of a simple Transformer neural network running on the Neural Processing Unit (NPU) of the latest STMicroelectronics STM32N6 MCU. The achievement of such goal could be the starting point for further analysis and profiling of Transformers on edge devices.

The specific board you will work with is the **STM32N6570-DK**. Instead, the target Transformer model will need to be decided during the project’s development, but quantized variants of **BERT** and **GPT-2** are strong candidates.

---

## Outcomes

Deploying AI models on edge is challenging due to the limited resources and the highly specialized nature of the available hardware. Many tools and techniques come into play to enable AI on the edge, such as:

- Model distillation and quantization  
- Approximation of activation functions  
- Deep learning hardware accelerators  
- Custom solutions to interface with accelerators  

During this project, students will need to steel themselves and dive into the challenges of running modern AI models on the edge. They will touch first-hand the full stack, from preparing such models to piecing together the firmware that will run them.

---

## Outline

1. **Tools Setup**  
   Students will read the documentation and install the tools from section [Useful Links](#useful-links).

2. **Transformers vs Convolutional Neural Networks (CNNs)**  
   Students will need to learn the basic differences between the architectures (from a computational perspective) of a classic CNN and a Transformer.

3. **Start with an Example**  
   Students will demonstrate one of the CNNs from the official STM32AI Model Zoo running on the provided board.

4. **Toolchain Development for Transformers**  
   Students will jointly modify a Transformer model, quantizing it with STM’s tools, and adapt the code in the Model Zoo to handle text input and output for the model.

5. **Project Report, Presentation, and Demonstration**  
   Students will write a brief report describing their final toolchain and hold a presentation focused on a demonstration of their project.

---

## Useful Links

### STM32N6 Resources

- STM32N6:  
  https://www.st.com/en/microcontrollers-microprocessors/stm32n6-series.html

- STM32N6570-DK:  
  https://www.st.com/en/evaluation-tools/stm32n6570-dk.html#overview

- STM32N6 AI Software Ecosystem:  
  https://www.st.com/en/development-tools/stm32n6-ai.html

- STM32Cube.AI:  
  https://wiki.st.com/stm32mcu/wiki/Category:STM32Cube.AI

---

### STM32AI Model Zoo

- **Models Repository**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo

- **Tools Repository**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo-services

- **A Good Starting Point**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo-services/tree/main/pose_estimation/deployment

---

### Transformers

- **Architectural Insights**:  
  https://arxiv.org/abs/2302.14017

- **BERT (reference only)**:  
  https://arxiv.org/abs/1810.04805

- **MobileBERT (reference only)**:  
  https://arxiv.org/abs/2004.02984

- **BERT-tiny**:  
  https://huggingface.co/prajjwal1/bert-tiny
