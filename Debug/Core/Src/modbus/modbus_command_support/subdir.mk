################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modbus/modbus_command_support/holding_registers.c \
../Core/Src/modbus/modbus_command_support/input_register.c 

OBJS += \
./Core/Src/modbus/modbus_command_support/holding_registers.o \
./Core/Src/modbus/modbus_command_support/input_register.o 

C_DEPS += \
./Core/Src/modbus/modbus_command_support/holding_registers.d \
./Core/Src/modbus/modbus_command_support/input_register.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modbus/modbus_command_support/%.o Core/Src/modbus/modbus_command_support/%.su Core/Src/modbus/modbus_command_support/%.cyclo: ../Core/Src/modbus/modbus_command_support/%.c Core/Src/modbus/modbus_command_support/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modbus-2f-modbus_command_support

clean-Core-2f-Src-2f-modbus-2f-modbus_command_support:
	-$(RM) ./Core/Src/modbus/modbus_command_support/holding_registers.cyclo ./Core/Src/modbus/modbus_command_support/holding_registers.d ./Core/Src/modbus/modbus_command_support/holding_registers.o ./Core/Src/modbus/modbus_command_support/holding_registers.su ./Core/Src/modbus/modbus_command_support/input_register.cyclo ./Core/Src/modbus/modbus_command_support/input_register.d ./Core/Src/modbus/modbus_command_support/input_register.o ./Core/Src/modbus/modbus_command_support/input_register.su

.PHONY: clean-Core-2f-Src-2f-modbus-2f-modbus_command_support

