#include "bsp_exti.h"

void EXTI_NVIC_Config(void);

void EXTI_Key_Config(void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	// 0. 配置中断优先级
	EXTI_NVIC_Config();
	
	// 1. 初始化 GPIO
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);

	// 2. 初始化 EXTI 用于产生中断、事件
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	// 3. 初始化 NVIC 用于处理中断
	
} 

static void EXTI_NVIC_Config(void) {
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}
