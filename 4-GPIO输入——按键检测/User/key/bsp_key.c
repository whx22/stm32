#include "bsp_key.h"

void KEY_GPIO_Config(void) {
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
		// 松手检测
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin));
		return KEY_ON;
	} else {
		return KEY_OFF;
	}
}
