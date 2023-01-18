################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/cube_F411CE/USB_DEVICE/App/usb_device.c \
../src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.c \
../src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.c 

OBJS += \
./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.o \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.o \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.o 

C_DEPS += \
./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.d \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.d \
./src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/cube_F411CE/USB_DEVICE/App/%.o src/lib/cube_F411CE/USB_DEVICE/App/%.su: ../src/lib/cube_F411CE/USB_DEVICE/App/%.c src/lib/cube_F411CE/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -DUSER_VECT_TAB_ADDRESS -c -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/ap" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/bsp" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common/hw/include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/common/core" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/hw" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/CMSIS/Include" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/USB_DEVICE/App" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/USB_DEVICE/Target" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/gitHubTemp/stmNucleo_F411RE/stmf411re_boot/src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App

clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App:
	-$(RM) ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.d ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.o ./src/lib/cube_F411CE/USB_DEVICE/App/usb_device.su ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.d ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.o ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_desc.su ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.d ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.o ./src/lib/cube_F411CE/USB_DEVICE/App/usbd_dfu_if.su

.PHONY: clean-src-2f-lib-2f-cube_F411CE-2f-USB_DEVICE-2f-App

