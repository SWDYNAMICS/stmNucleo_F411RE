################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/cube_F411CE/USB_DEVICE/App/usb_device.c \
../src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.c \
../src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.c 

OBJS += \
./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.o \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.o \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.o 

C_DEPS += \
./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.d \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.d \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/cube_F411CE/USB_DEVICE/App/%.o src/lib/cube_F411CE/USB_DEVICE/App/%.su: ../src/lib/cube_F411CE/USB_DEVICE/App/%.c src/lib/cube_F411CE/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -c -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/FreeRTOS/Source/CMSIS_RTOS" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/FreeRTOS/Source/include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/ap" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/bsp" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/common" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/common/hw/include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/common/core" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/hw" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/CMSIS/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/USB_DEVICE/App" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/USB_DEVICE/Target" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_fw/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App

clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App:
	-$(RM) ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.d ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.o ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.su ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.d ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.o ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_cdc_if.su ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.d ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.o ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.su

.PHONY: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App

