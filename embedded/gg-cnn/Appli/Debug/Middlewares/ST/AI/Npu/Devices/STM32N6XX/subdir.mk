################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.c \
/Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.c 

OBJS += \
./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.o \
./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.o 

C_DEPS += \
./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.d \
./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.o: /Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.c Middlewares/ST/AI/Npu/Devices/STM32N6XX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -DLL_ATON_DUMP_DEBUG_API -DLL_ATON_PLATFORM=LL_ATON_PLAT_STM32N6 -DLL_ATON_OSAL=LL_ATON_OSAL_BARE_METAL -DLL_ATON_RT_MODE=LL_ATON_RT_ASYNC -DLL_ATON_SW_FALLBACK -DLL_ATON_EB_DBG_INFO -DLL_ATON_DBG_BUFFER_INFO_EXCLUDED=1 -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../../Middlewares/ST/AI/Npu/Devices/STM32N6XX -I../../Middlewares/ST/AI/Inc -I../../Middlewares/ST/AI/Npu/ll_aton -I../../Appli/X-CUBE-AI/App -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.o: /Users/lucabrini/Documents/PoliMI/Courses/ACA/aca-stm32n6/embedded/gg-cnn/Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.c Middlewares/ST/AI/Npu/Devices/STM32N6XX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -DLL_ATON_DUMP_DEBUG_API -DLL_ATON_PLATFORM=LL_ATON_PLAT_STM32N6 -DLL_ATON_OSAL=LL_ATON_OSAL_BARE_METAL -DLL_ATON_RT_MODE=LL_ATON_RT_ASYNC -DLL_ATON_SW_FALLBACK -DLL_ATON_EB_DBG_INFO -DLL_ATON_DBG_BUFFER_INFO_EXCLUDED=1 -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../../Middlewares/ST/AI/Npu/Devices/STM32N6XX -I../../Middlewares/ST/AI/Inc -I../../Middlewares/ST/AI/Npu/ll_aton -I../../Appli/X-CUBE-AI/App -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-AI-2f-Npu-2f-Devices-2f-STM32N6XX

clean-Middlewares-2f-ST-2f-AI-2f-Npu-2f-Devices-2f-STM32N6XX:
	-$(RM) ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.cyclo ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.d ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.o ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/mcu_cache.su ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.cyclo ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.d ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.o ./Middlewares/ST/AI/Npu/Devices/STM32N6XX/npu_cache.su

.PHONY: clean-Middlewares-2f-ST-2f-AI-2f-Npu-2f-Devices-2f-STM32N6XX

