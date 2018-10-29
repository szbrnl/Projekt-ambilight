################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include WS2812/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
002_WS2812_TEST.lss \

FLASH_IMAGE += \
002_WS2812_TEST.hex \

EEPROM_IMAGE += \
002_WS2812_TEST.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 002_WS2812_TEST.elf secondary-outputs

# Tool invocations
002_WS2812_TEST.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,002_WS2812_TEST.map -mmcu=atmega328p -o "002_WS2812_TEST.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

002_WS2812_TEST.lss: 002_WS2812_TEST.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 002_WS2812_TEST.elf  >"002_WS2812_TEST.lss"
	@echo 'Finished building: $@'
	@echo ' '

002_WS2812_TEST.hex: 002_WS2812_TEST.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 002_WS2812_TEST.elf  "002_WS2812_TEST.hex"
	@echo 'Finished building: $@'
	@echo ' '

002_WS2812_TEST.eep: 002_WS2812_TEST.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 002_WS2812_TEST.elf  "002_WS2812_TEST.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 002_WS2812_TEST.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p 002_WS2812_TEST.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 002_WS2812_TEST.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
