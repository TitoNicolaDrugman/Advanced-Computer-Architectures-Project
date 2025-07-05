# Demonstration of a Simple Transformer Running on the NPU of an STM32N6

## Table of contents

- [Demonstration of a Simple Transformer Running on the NPU of an STM32N6](#demonstration-of-a-simple-transformer-running-on-the-npu-of-an-stm32n6)
  - [Table of contents](#table-of-contents)
  - [Overview](#overview)
  - [Outcomes](#outcomes)
  - [Outline](#outline)
  - [Useful Links](#useful-links)
    - [STM32N6 Resources](#stm32n6-resources)
    - [STM32AI Model Zoo](#stm32ai-model-zoo)
    - [Transformers](#transformers)
  - [Really Useful Links](#really-useful-links)
  - [Project Structure](#project-structure)
  - [Get started](#get-started)
    - [Raw Notes](#raw-notes)
    - [Model Limits](#model-limits)
  - [Performance](#performance)
  - [Quantizzazione evaluation](#quantizzazione-evaluation)

## Overview

This project aims at realizing a functioning demonstration of a simple Transformer neural network running on the Neural Processing Unit (NPU) of the latest STMicroelectronics STM32N6 MCU. The achievement of such goal could be the starting point for further analysis and profiling of Transformers on edge devices.

The specific board you will work with is the **STM32N6570-DK**. Instead, the target Transformer model will need to be decided during the project’s development, but quantized variants of **BERT** and **GPT-2** are strong candidates.

## Outcomes

Deploying AI models on edge is challenging due to the limited resources and the highly specialized nature of the available hardware. Many tools and techniques come into play to enable AI on the edge, such as:

- Model distillation and quantization
- Approximation of activation functions
- Deep learning hardware accelerators
- Custom solutions to interface with accelerators

During this project, students will need to steel themselves and dive into the challenges of running modern AI models on the edge. They will touch first-hand the full stack, from preparing such models to piecing together the firmware that will run them.

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

### STM32AI Model Zoo

- **Models Repository**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo

- **Tools Repository**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo-services

- **A Good Starting Point**:  
  https://github.com/STMicroelectronics/stm32ai-modelzoo-services/tree/main/pose_estimation/deployment

### Transformers

- **Architectural Insights**:  
  https://arxiv.org/abs/2302.14017

- **BERT (reference only)**:  
  https://arxiv.org/abs/1810.04805

- **MobileBERT (reference only)**:  
  https://arxiv.org/abs/2004.02984

- **BERT-tiny**:  
  https://huggingface.co/prajjwal1/bert-tiny

## Really Useful Links

- https://stedgeai-dc-qa.st.com/assets/embedded-docs/index.html
- https://stedgeai-dc-qa.st.com/assets/embedded-docs/stneuralart_programming_model.html
- https://stedgeai-dc-qa.st.com/assets/embedded-docs/stneuralart_operator_support.html
- https://stedgeai-dc-qa.st.com/assets/embedded-docs/stneuralart_stm32n6_projects.html
- https://stedgeai-dc-qa.st.com/assets/embedded-docs/command_line_interface.html
- Most important one: https://community.st.com/t5/edge-ai/bd-p/edge-ai

---

- [Build (and train) your own transformer-based TensorFlow model](https://www.tensorflow.org/text/tutorials/transformer)

## Project Structure

- **custom_models:** custom models definition and training scripts. This folder is the place to store custom models that are not part of the STM32AI Model Zoo.
- **pretrained_models:** pretrained models used in the project. This folder is the place to store weights and configurations of third-party, trained models or converted models
- **tools:** tools and scripts to help with the project, such as model conversion and quantization.
  - `torch_to_onnx`: scripts to convert PyTorch models to ONNX format.
- **embedded:** STM32CubeIDE project for the STM32N6 board. This folder contains the necessary files to run the model on the STM32N6 board, including the main application and configuration files.`
- **st_ai_output** and **st_ai_ws:** output folders for the `stedgeai` CLI tool

## Get started

- Download STM32CubeIde and relative softwares.
- Open STM32CubeIDE, click File -> Open Projects from File System -> Directory -> choose this project `embedded` folder. Deploy it to your board.

### Raw Notes

STEdgeAI CLI tool generates the necessary files to run a given model on the STM32N6 based boards. For other boards it creates an STM32CubeIDE project or a .ioc configuration file.

For the STM32N6, the CLI tool generates only the files related to the network, the user must create the main application and the necessary files to run it on the board.

---

MobileBERT is not supported out of the box by stedgeai CLI tool due to the use of a dynamic batch/tensor sizes. It brokes at 12%.

### Model Limits

- Input and output tensors must be static
- Variable-length batch dimension (i.e. (None,)) is considered as equal to 1
- Operator with un-connected output is not supported
- Mixed data operations (i.e hybrid operator) are not supported, activations and weights should be quantized
- Data type for the weights/activations tensors must be:
- int8 (scale/offset format) ss/sa scheme (see Quantized models – per-channel)
- if float32 operation is requested, it will be mapped on a SW operation

## Performance

- Performance counter hw:
  - Cicli di clock e quanto succede durante l'esecuzione del modello
  - Trasferimenti di memoria
  - Cache miss, cache hit
  - TOPS
  -

## Quantizzazione evaluation

- quantizzato su cpu
- quantizzato su npu
- non quantizzato su cpu
  plot di confronto
