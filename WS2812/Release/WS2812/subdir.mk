################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WS2812/ws2812.c \
../WS2812/ws281x.c 

OBJS += \
./WS2812/ws2812.o \
./WS2812/ws281x.o 

C_DEPS += \
./WS2812/ws2812.d \
./WS2812/ws281x.d 


# Each subdirectory must supply rules for building sources it contributes
WS2812/%.o: ../WS2812/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


