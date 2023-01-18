################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/cube_F411CE/USB_DEVICE/Target/subdir.mk
-include src/lib/cube_F411CE/USB_DEVICE/App/subdir.mk
-include src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include src/lib/cube_F411CE/Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/subdir.mk
-include src/lib/cube_F411CE/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/USB_DEVICE/Target/subdir.mk
-include src/lib/cube_F411CE/Debug/USB_DEVICE/App/subdir.mk
-include src/lib/cube_F411CE/Debug/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/Core/Startup/subdir.mk
-include src/lib/cube_F411CE/Debug/Core/Src/subdir.mk
-include src/lib/cube_F411CE/Debug/subdir.mk
-include src/hw/driver/subdir.mk
-include src/hw/subdir.mk
-include src/common/core/subdir.mk
-include src/bsp/startup/subdir.mk
-include src/bsp/subdir.mk
-include src/ap/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := stmf411re_boot
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stmf411re_boot.elf \

MAP_FILES += \
stmf411re_boot.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stmf411re_boot.list \


# All Target
all: main-build

# Main-build Target
main-build: stmf411re_boot.elf secondary-outputs

# Tool invocations
stmf411re_boot.elf stmf411re_boot.map: $(OBJS) $(USER_OBJS) C:\gitHubTemp\stmNucleo_F411RE\stmf411re_boot\src\bsp\ldscript\STM32F411CEUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "stmf411re_boot.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\gitHubTemp\stmNucleo_F411RE\stmf411re_boot\src\bsp\ldscript\STM32F411CEUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stmf411re_boot.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stmf411re_boot.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stmf411re_boot.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout stmf411re_boot.elf stmf411re_boot.list stmf411re_boot.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
