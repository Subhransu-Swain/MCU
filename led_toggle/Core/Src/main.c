#include "stm32f4xx.h"
void delay(int T){
	int i;
	while(T--){
	for(i=0;i<5000;i++);}
}
int main()
{

	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x400;
	while(1)
	{
		GPIOA->BSRR |=0x20;
		delay(500);
		GPIOA->BSRR |=0x200000;
		delay(500);

	}
}
