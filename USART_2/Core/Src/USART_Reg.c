/*
 * USART_Reg.c
 * 1.Protocol Selected:USART2
 * 2.Enable APB1 clock with RCC
 * 3.Enable AHB1 clock with RCC
 * 4.Alternative function of PA2 as USART2_Tx
 * 5.Alternative Function of PA3 as USART2_Rx
 *
 *
 *  Created on: Nov 23, 2022
 *      Author: anujm
 */

#include"main.h"
void Sconfig_Init()
{
	RCC->APB1ENR |=0X20000;
	RCC->AHB1ENR |=0X1;
	GPIOA->MODER |=0X20;
	GPIOA->AFR[0] |=0X700;
	USART2->BRR |=0X683;   //9600 baudrate
	USART2->CR1 |=0X8;
	USART2->CR1 |=0X2000;

}
void USART2_Tx(unsigned char data)
{
	while(!(USART2->SR & 0x80)){}
	USART2-> DR |=(data & 0xff);
}

void USART2_send(unsigned char *str)
{
	while(*str)
	{
	USART2_Tx(*str);
	str++;
	}
}

void delay(int T)
{
	while(T--)
	{
		for(int i=0;i<100000;i++);

	}
}

int main()
{
	Sconfig_Init();
	while(1)
	{
		USART2_send("Hello\t");
//		USART2_send
//		USART2_Tx("hello");
	delay(10);
	}
}
