#ifndef __STM32F10X_GPIO_H__
#define __STM32F10X_GPIO_H__

#include "stm32f10x.h"

#define GPIO_Pin_0 ((uint16_t)0x0001) 	/*选择Pin0 (0000 0000 0000 0001)*/
#define GPIO_Pin_1 ((uint16_t)0x0002) 	/*选择Pin1 (0000 0000 0000 0010)*/
#define GPIO_Pin_2 ((uint16_t)0x0004) 	/*选择Pin2 (0000 0000 0000 0100)*/
#define GPIO_Pin_3 ((uint16_t)0x0008) 	/*选择Pin3 (0000 0000 0000 1000)*/
#define GPIO_Pin_4 ((uint16_t)0x0010) 	/*选择Pin4 (0000 0000 0001 0000)*/
#define GPIO_Pin_5 ((uint16_t)0x0020) 	/*选择Pin5 (0000 0000 0010 0000)*/
#define GPIO_Pin_6 ((uint16_t)0x0040) 	/*选择Pin6 (0000 0000 0100 0000)*/
#define GPIO_Pin_7 ((uint16_t)0x0080) 	/*选择Pin7 (0000 0000 1000 0000)*/
#define GPIO_Pin_8 ((uint16_t)0x0100) 	/*选择Pin8 (0000 0001 0000 0000)*/
#define GPIO_Pin_9 ((uint16_t)0x0200) 	/*选择Pin9 (0000 0010 0000 0000)*/
#define GPIO_Pin_10 ((uint16_t)0x0400) 	/*选择Pin10 (0000 0100 0000 0000)*/
#define GPIO_Pin_11 ((uint16_t)0x0800) 	/*选择Pin11 (0000 1000 0000 0000)*/
#define GPIO_Pin_12 ((uint16_t)0x1000) 	/*选择Pin12 (0001 0000 0000 0000)*/
#define GPIO_Pin_13 ((uint16_t)0x2000) 	/*选择Pin13 (0010 0000 0000 0000)*/
#define GPIO_Pin_14 ((uint16_t)0x4000) 	/*选择Pin14 (0100 0000 0000 0000)*/
#define GPIO_Pin_15 ((uint16_t)0x8000) 	/*选择Pin15 (1000 0000 0000 0000)*/
#define GPIO_Pin_ALL ((uint16_t)0xFFFF) /*选择全部引脚 (1111 1111 1111 1111)*/

typedef enum { 
  GPIO_Speed_10MHz = 1,         // 10MHZ        (01)b
  GPIO_Speed_2MHz,              // 2MHZ         (10)b
  GPIO_Speed_50MHz              // 50MHZ        (11)b
}GPIOSpeed_TypeDef;

typedef enum { 
	GPIO_Mode_AIN = 0x0,           // 模拟输入     (0000 0000)b
  GPIO_Mode_IN_FLOATING = 0x04,  // 浮空输入     (0000 0100)b
  GPIO_Mode_IPD = 0x28,          // 下拉输入     (0010 1000)b
  GPIO_Mode_IPU = 0x48,          // 上拉输入     (0100 1000)b
  
  GPIO_Mode_Out_OD = 0x14,       // 开漏输出     (0001 0100)b
  GPIO_Mode_Out_PP = 0x10,       // 推挽输出     (0001 0000)b
  GPIO_Mode_AF_OD = 0x1C,        // 复用开漏输出 (0001 1100)b
  GPIO_Mode_AF_PP = 0x18         // 复用推挽输出 (0001 1000)b
}GPIOMode_TypeDef;

typedef struct {
	uint16_t GPIO_Pin;
	uint16_t GPIO_Speed;
	uint16_t GPIO_Mode;
}GPIO_InitTypeDef;

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif // __STM32F10X_GPIO_H__
