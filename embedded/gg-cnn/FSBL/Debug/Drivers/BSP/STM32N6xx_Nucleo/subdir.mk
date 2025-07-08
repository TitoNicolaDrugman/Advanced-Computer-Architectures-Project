################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.c 

OBJS += \
./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.o 

C_DEPS += \
./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.o: /Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.c Drivers/BSP/STM32N6xx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -DUSE_NUCLEO_64 -c -I../Core/Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/BSP/STM32N6xx_Nucleo -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32N6xx_Nucleo

clean-Drivers-2f-BSP-2f-STM32N6xx_Nucleo:
	-$(RM) ./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.cyclo ./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.d ./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.o ./Drivers/BSP/STM32N6xx_Nucleo/stm32n6xx_nucleo.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32N6xx_Nucleo

