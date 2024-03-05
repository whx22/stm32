#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define LED_G_GPIO_PIN   GPIO_Pin_0
#define LED_G_GPIO_PORT  GPIOB
#define LED_G_GPIO_CLK   RCC_APB2Periph_GPIOB

#define OFF 0
#define ON  1

#define LED_G(a) 	if (a) \
						GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\
					else \
						GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\

void LED_GPIO_Config(void);

#endif // __BSP_LED_H__
