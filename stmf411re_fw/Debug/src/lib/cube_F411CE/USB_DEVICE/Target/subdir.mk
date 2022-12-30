################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/cube_F411CE/USB_DEVICE/Target/usbd_conf.c 

OBJS += \
./src/lib/cube_F411CE/USB_DEVICE/Target/usbd_conf.o 

C_DEPS += \
./src/lib/cube_F411CE/USB_DEVICE/Target/usbd_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/cube_F411CE/USB_DEVICE/Target/%.o: ../src/lib/cube_F411CE/USB_DEVICE/Target/%.c src/lib/cube_F411CE/USB_DEVICE/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -c -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/ap" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/bsp" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/common" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/common/hw/include" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/common/core" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/hw" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/CMSIS/Include" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/USB_DEVICE/App" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/USB_DEVICE/Target" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-Target

clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-Target:
	-$(RM) ./src/lib/cube_F411CE/USB_DEVICE/Target/usbd_conf.d ./src/lib/cube_F411CE/USB_DEVICE/Target/usbd_conf.o

.PHONY: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-Target

