/**
  ******************************************************************************
  * @file    app_config.h
  * @author  GPM/AIS Application Team
  * @brief   APP configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#ifndef NUCLEO_N6_CONFIG
#define NUCLEO_N6_CONFIG                0
#endif

#ifndef USE_RELOC_MODE
#define USE_RELOC_MODE                  0
#endif

#define USE_MCU_DCACHE                  1
#define USE_MCU_ICACHE                  1
#define USE_EXTERNAL_MEMORY_DEVICES     1
#define USE_OVERDRIVE                   1       /* Using overdrive, clocks:CPU@800/NPU@1GHz, no overdrive: clocks:CPU@600/NPU@800 */
#define NO_OVD_CLK400                           // When no overdrive: use clocks all @ 400MHz (CPU/NIC/NOC/NPU)

/* UART usage/configuration */
#define USE_UART_BAUDRATE               921600 // 5529600 // 3686400  // 921600          /* 921600 115200 */

#endif /* __APP_CONFIG_H__ */