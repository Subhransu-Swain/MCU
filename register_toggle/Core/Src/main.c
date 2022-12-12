#include"stm32f4xx.h"
void delay(int T)
{
	int i;
	while(T--)
	{
		for(i=0;i<5000;i++);
	}
}
void LED_init()
{
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400;
}
void button()
{
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x0;
}
void toggle_pin()
{
	GPIOA->ODR^= 0x20;
	delay(100);
}
int main()
{
	LED_init();
	button();
	while(1)
	{
		toggle_pin();
	}
}
