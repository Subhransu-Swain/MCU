/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f411x.h"

void delay(int T)
{
	while(T--){
	for(uint32_t i = 0; i < 500000; i ++); }
}
void led_init()
{
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400;
}
void sw_init()
{
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x0;
}
void operation()
{
	if(GPIOC->IDR & 0x2000)
	{
		GPIOA->BSRR |= 0x200000;
	}
	else
	{
		GPIOA->BSRR |= 0x20;
	}
}

int main(void)
{

//	GPIO_Handle_t GpioLed;
//
//	GpioLed.pGPIOx = GPIOA;
//	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
//	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
//	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_LOW;
//	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
//	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
//
//	Gpio_PerClkEnable(GPIOA , ENABLE);
//
//	Gpio_Init(&GpioLed);
	gpio_config();
	led_init();
	sw_init();


	while(1)
	{
//		Gpio_Toggle_pin(GPIOA, GPIO_PIN_NO_5);
//		delay(1000);
//		printf("LED ON\n");


		operation();
	}

}