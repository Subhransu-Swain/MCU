#include "stm32f4xx.h"
void delayMs(int n);
int main(void)
{
	// configure PA9 as output of TIM1 CH2
		RCC->AHB1ENR |= 1; 						/* enable GPIOA clock */
		GPIOA->MODER &=~(3<<18); 			/* clear pin mode */
		GPIOA->MODER |= (1<<19); 			/* set pin to alternate function */
		GPIOA->AFR[1] &= ~(0xF<<4); 			/* clear pin AF bits */
		GPIOA->AFR[1]|= 1<<4; 			/* set pin to AF1 for TIM1 CH2 */

	/* setup TIM9 */
	RCC->APB1ENR |= 1; 								/* enable TIM1 clock */
	TIM1->PSC = 10 - 1; 							/*divided by 10 */
	TIM1->ARR = 32000 - 1; 							/* divided by 26667 */
	TIM1->CNT = 0;
	TIM1->CCMR1 = 0xD<<11; 							/* PWM mode */
	TIM1->CCER = 1<<4; 								/* enable PWMCh2N */
	TIM1->CCR2 = 32; 								/* pulse width */
	TIM1->BDTR |= 0x8000; 							/*enable output */
	TIM1->CR1 = 1; 									/* enable timer */

	while(1)
	{
		TIM1->CCR2 = TIM1->CCR2 * 110 / 100;
			if (TIM1->CCR2 > 32000)
				TIM1->CCR2 = 32;
			delayMs(20);
	}
}
	/* 16 MHz SYSCLK */
void delayMs(int n)
{
	int i;
	for (; n > 0; n--)
		for (i = 0; i < 3195; i++) ;
}

