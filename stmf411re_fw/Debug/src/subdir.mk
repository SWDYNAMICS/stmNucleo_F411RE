################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -c -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/ap" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/bsp" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/common" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/hw" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_f411/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_f411/Drivers/CMSIS/Include" -I"C:/GithubTemp/stm32F411RE/stmf411re_fw/src/lib/cube_f411/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.d ./src/main.o

.PHONY: clean-src

