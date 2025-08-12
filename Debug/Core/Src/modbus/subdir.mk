################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modbus/modbus_common.c \
../Core/Src/modbus/modbus_interface.c 

OBJS += \
./Core/Src/modbus/modbus_common.o \
./Core/Src/modbus/modbus_interface.o 

C_DEPS += \
./Core/Src/modbus/modbus_common.d \
./Core/Src/modbus/modbus_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modbus/%.o Core/Src/modbus/%.su Core/Src/modbus/%.cyclo: ../Core/Src/modbus/%.c Core/Src/modbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modbus

clean-Core-2f-Src-2f-modbus:
	-$(RM) ./Core/Src/modbus/modbus_common.cyclo ./Core/Src/modbus/modbus_common.d ./Core/Src/modbus/modbus_common.o ./Core/Src/modbus/modbus_common.su ./Core/Src/modbus/modbus_interface.cyclo ./Core/Src/modbus/modbus_interface.d ./Core/Src/modbus/modbus_interface.o ./Core/Src/modbus/modbus_interface.su

.PHONY: clean-Core-2f-Src-2f-modbus

