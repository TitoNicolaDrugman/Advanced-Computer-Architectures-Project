/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __ICCARM__ )
#  define CMSE_NS_CALL  __cmse_nonsecure_call
#  define CMSE_NS_ENTRY __cmse_nonsecure_entry
#else
#  define CMSE_NS_CALL  __attribute((cmse_nonsecure_call))
#  define CMSE_NS_ENTRY __attribute((cmse_nonsecure_entry))
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32n6xx_hal.h"

#include "stm32n6xx_nucleo.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* Function pointer declaration in non-secure*/
#if defined ( __ICCARM__ )
typedef void (CMSE_NS_CALL *funcptr)(void);
#else
typedef void CMSE_NS_CALL (*funcptr)(void);
#endif

/* typedef for non-secure callback functions */
typedef funcptr funcptr_NS;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define I2C1_SDA_Pin GPIO_PIN_1
#define I2C1_SDA_GPIO_Port GPIOC
#define I2CA_SCL_Pin GPIO_PIN_9
#define I2CA_SCL_GPIO_Port GPIOH
#define VCP_RX_Pin GPIO_PIN_6
#define VCP_RX_GPIO_Port GPIOE
#define TRACED1_Pin GPIO_PIN_0
#define TRACED1_GPIO_Port GPIOB
#define TRACED3_Pin GPIO_PIN_7
#define TRACED3_GPIO_Port GPIOB
#define TRACED2_Pin GPIO_PIN_6
#define TRACED2_GPIO_Port GPIOB
#define TRACECLK_Pin GPIO_PIN_3
#define TRACECLK_GPIO_Port GPIOB
#define TRACED0_Pin GPIO_PIN_3
#define TRACED0_GPIO_Port GPIOE
#define OCTOSPI_IO2_Pin GPIO_PIN_4
#define OCTOSPI_IO2_GPIO_Port GPION
#define I2C2_SDA_Pin GPIO_PIN_11
#define I2C2_SDA_GPIO_Port GPIOB
#define JTDI_Pin GPIO_PIN_15
#define JTDI_GPIO_Port GPIOA
#define OCTOSPI_CLK_Pin GPIO_PIN_6
#define OCTOSPI_CLK_GPIO_Port GPION
#define OCTOSPI_IO4_Pin GPIO_PIN_8
#define OCTOSPI_IO4_GPIO_Port GPION
#define OCTOSPI_DQS_Pin GPIO_PIN_0
#define OCTOSPI_DQS_GPIO_Port GPION
#define OCTOSPI_IO1_Pin GPIO_PIN_3
#define OCTOSPI_IO1_GPIO_Port GPION
#define OCTOSPI_IO3_Pin GPIO_PIN_5
#define OCTOSPI_IO3_GPIO_Port GPION
#define OCTOSPI_NCS_Pin GPIO_PIN_1
#define OCTOSPI_NCS_GPIO_Port GPION
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define UCPD1_VSENSE_Pin GPIO_PIN_11
#define UCPD1_VSENSE_GPIO_Port GPIOA
#define OCTOSPI_IO5_Pin GPIO_PIN_9
#define OCTOSPI_IO5_GPIO_Port GPION
#define OCTOSPI_IO0_Pin GPIO_PIN_2
#define OCTOSPI_IO0_GPIO_Port GPION
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define I2C2_SCL_Pin GPIO_PIN_10
#define I2C2_SCL_GPIO_Port GPIOB
#define SWO_Pin GPIO_PIN_5
#define SWO_GPIO_Port GPIOB
#define OCTOSPI_IO6_Pin GPIO_PIN_10
#define OCTOSPI_IO6_GPIO_Port GPION
#define OCTOSPI_IO7_Pin GPIO_PIN_11
#define OCTOSPI_IO7_GPIO_Port GPION

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
