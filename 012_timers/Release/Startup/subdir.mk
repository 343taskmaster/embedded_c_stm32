################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f411retx.s 

OBJS += \
./Startup/startup_stm32f411retx.o 

S_DEPS += \
./Startup/startup_stm32f411retx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 '-DD:/STM32 workspace/chip_header/CMSIS/Device/ST/STM32F4xx/Include' '-DD:/STM32 workspace/chip_header/CMSIS/Include' -c -I../STM32 -I../STM32F4 -I../STM32F411RETx -I../STM32F411xE -I../DEBUG -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f411retx.d ./Startup/startup_stm32f411retx.o

.PHONY: clean-Startup
