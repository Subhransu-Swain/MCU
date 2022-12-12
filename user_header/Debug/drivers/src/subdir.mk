################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32f411x_driver_gpio.c \
../drivers/src/stm32f411x_gpio_config.c 

OBJS += \
./drivers/src/stm32f411x_driver_gpio.o \
./drivers/src/stm32f411x_gpio_config.o 

C_DEPS += \
./drivers/src/stm32f411x_driver_gpio.d \
./drivers/src/stm32f411x_gpio_config.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/Users/PHY202209EF10/STM32CubeIDE/workspace_1.10.1/user_header/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32f411x_driver_gpio.d ./drivers/src/stm32f411x_driver_gpio.o ./drivers/src/stm32f411x_driver_gpio.su ./drivers/src/stm32f411x_gpio_config.d ./drivers/src/stm32f411x_gpio_config.o ./drivers/src/stm32f411x_gpio_config.su

.PHONY: clean-drivers-2f-src

