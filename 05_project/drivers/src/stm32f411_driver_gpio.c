/*
 * stm32f411x_driver_gpio.c
 *
 *  Created on: Nov 15, 2022
 *      Author: PHY202209EF13
 */
#include "stm32f411x_driver_gpio.h"

//GPIO_Peripheral Clock Control()/

void Gpio_PerClkEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PLCK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PLCK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PLCK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PLCK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PLCK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PLCK_EN();
		}
	}
	else
	{
		//TODO
	}
}

//GPIO_Init(){}/

void Gpio_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp =0;  //temp. register

	//enable the peripheral clock

	Gpio_PerClkEnable(pGPIOHandle->pGPIOx, ENABLE);

	//1. CONFIGURE THE MODE OF GPIO PIN

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//THE NON INTERRUPT MODE
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		//pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //Clearing a pin bits
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		//LATER WILL IMPLEMENT THE IQR PART/
	}

	temp =0;

	//2.Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //Clearing a pin bits
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;  //Pin Mode Setting

	temp =0;
	//3.Configure the PUPD Setting
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //Clearing a pin bits
	pGPIOHandle->pGPIOx->PUPDR |= temp;  //Pin Mode Setting

	//4.Configure the otype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //Clearing a pin bits
	pGPIOHandle->pGPIOx->OTYPER |= temp;  //Pin Mode Setting


}

//GPIO_DeInit(){}/

void Gpio_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}


//GPIO_ReadFrm_inputpin(){}/

uint8_t GPIO_Rd_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001 );
	return value;
}

//GPIO_ReadFrm_inputport(){}/

uint16_t Gpio_Rd_port(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

//GPIO_WriteFrm_outputpin(){}/

void Gpio_Wr_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//Write 1 to output data register a the bit field corresponding to the Pin Number
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		//write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}

}

//GPIO_WriteFrm_outputport(){}/

void Gpio_Wr_port(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}


//Gpio_Toggle_output_pin(){}/

void Gpio_Toggle_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

