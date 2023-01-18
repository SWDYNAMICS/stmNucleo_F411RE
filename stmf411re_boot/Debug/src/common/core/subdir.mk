################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common/core/qbuffer.c 

OBJS += \
./src/common/core/qbuffer.o 

C_DEPS += \
./src/common/core/qbuffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/core/%.o src/common/core/%.su: ../src/common/core/%.c src/common/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -DUSER_VECT_TAB_ADDRESS -c -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/ap" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/bsp" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common/hw/include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common/core" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/hw" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/CMSIS/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/USB_DEVICE/App" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/USB_DEVICE/Target" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-common-2f-core

clean-src-2f-common-2f-core:
	-$(RM) ./src/common/core/qbuffer.d ./src/common/core/qbuffer.o ./src/common/core/qbuffer.su

.PHONY: clean-src-2f-common-2f-core

