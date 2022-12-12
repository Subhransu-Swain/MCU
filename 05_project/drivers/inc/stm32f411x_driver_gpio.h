/*
 * stm32f411x_driver_gpio.h
 *
 *  Created on: Nov 16, 2022
 *      Author: PHY202209EF10
 */


#ifndef INC_STM32F411X_DRIVER_GPIO_H_
#define INC_STM32F411X_DRIVER_GPIO_H_

#include "stm32f411x.h"

//This is a Configuration structure for a GPIO PIN/



typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO Pin
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;




//List of GPIO Pin numbers/

#define GPIO_PIN_NO_0           0
#define GPIO_PIN_NO_1           1
#define GPIO_PIN_NO_2           2
#define GPIO_PIN_NO_3           3
#define GPIO_PIN_NO_4           4
#define GPIO_PIN_NO_5           5
#define GPIO_PIN_NO_6           6
#define GPIO_PIN_NO_7           7
#define GPIO_PIN_NO_8           8
#define GPIO_PIN_NO_9           9
#define GPIO_PIN_NO_10          10
#define GPIO_PIN_NO_11          11
#define GPIO_PIN_NO_12          12
#define GPIO_PIN_NO_13          13
#define GPIO_PIN_NO_14          14
#define GPIO_PIN_NO_15          15


/*
 * List of GPIO pin modes
 * @GPIO_PIN_MODE
 * GPIO pin possible modes
 */

#define GPIO_MODE_IN       0
#define GPIO_MODE_OUT      1
#define GPIO_MODE_ALTFN    2
#define GPIO_MODE_ANALOG   3

/*
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP     0
#define GPIO_OP_TYPE_OD     1


/*
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW       0
#define GPIO_SPEED_MEDIUM    1
#define GPIO_SPEED_FAST      2
#define GPIO_SPEED_HIGH      3

/*
 * GPIO pin pull-up and pull-down configuration macros
 */
#define GPIO_NO_PUPD     0
#define GPIO_PIN_PU      1
#define GPIO_PIN_PD      2

//GPIO pin Alternative function configuration macros/

//GPIO pin BitRS configuration macros/

/*List of GPIO API's:
 	 	 	 	 *Gpio_PerClkEnable();
 	 	 	 	 *Gpio_Init();
 	 	 	 	 *Gpio_DeInit();
 	 	 	 	 *Gpio_ReadFrm_inputpin();
 	 	 	 	 *Gpio_ReadFrm_inputport();
 	 	 	 	 *Gpio_WriteFrm_outputpin();
 	 	 	 	 *Gpio_WriteFrm_outputport();
 	 	 	 	 *Gpio_Toggle_output_pin();
*/

/*
 * Peripheral Clock Setup
 */
void Gpio_PerClkEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */

void Gpio_Init(GPIO_Handle_t *pGPIOHandle);
void Gpio_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write
 */

uint8_t Gpio_Rd_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t Gpio_Rd_port(GPIO_RegDef_t *pGPIOx);
void Gpio_Wr_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void Gpio_Wr_port(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void Gpio_Toggle_pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* INC_STM32F411X_DRIVER_GPIO_H_ */
