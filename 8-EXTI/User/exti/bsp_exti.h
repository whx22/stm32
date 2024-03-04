#ifndef __BSP_EXTI_H__
#define __BSP_EXTI_H__

#include "stm32f10x.h"
#include "misc.h"

#define KEY1_INT_GPIO_PIN   GPIO_Pin_0
#define KEY1_INT_GPIO_PORT  GPIOA
#define KEY1_INT_GPIO_CLK   RCC_APB2Periph_GPIOA

void EXTI_Key_Config(void);

#endif // __BSP_EXTI_H__
