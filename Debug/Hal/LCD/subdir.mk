################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/LCD/LCD.c 

OBJS += \
./Hal/LCD/LCD.o 

C_DEPS += \
./Hal/LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/LCD/%.o: ../Hal/LCD/%.c Hal/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\App" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Tasks" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal\GIE" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal\Timer" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal\ADC" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal\ExtInt" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\KeyPad" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\LCD" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\PushButton" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\App\Library" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\Buzzer" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\Led" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\Relay" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Hal\SSD" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal" -I"C:\Users\20101\Desktop\Study\embedded\AVR material\NTIavr\Mcal\Dio" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


