# if 0

#include <REG52.H>

sbit LED = P0^0

void main(void) {

	P0 = 0xFE;	// register operation
	
	LED = 0;		// bit operation
	
}

#endif

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

//#define   LED_G_GPIO_PORT                   GPIOB
//#define   LED_G_GPIO_CLK_ENABLE            (RCC->APB2ENR  |=  ( (1) << 3 ))
//#define   LED_G_GPIO_PIN                    GPIO_Pin_0

#define   LED_G_GPIO_PORT                   GPIOB
#define   LED_G_GPIO_CLK_ENABLE            (RCC->APB2ENR  |=  ( (1) << 3 ))
#define   LED_G_GPIO_PIN                    GPIO_Pin_0

#define LED_G_GPIO_PORT       GPIOB
#define LED_G_GPIO_CLK_ENABLE (RCC->APB2ENR |= ((1) << 3))
#define LED_B_GPIO_PIN        GPIO_Pin_1

#define LED_G_GPIO_PORT       GPIOB
#define LED_G_GPIO_CLK_ENABLE (RCC->APB2ENR |= ((1) << 3))
#define LED_R_GPIO_PIN        GPIO_Pin_5

// 软件延时
void Delay(uint32_t count)
{
	for( ; count !=0; count-- );
}

int main(void) {
#if 0 
	// 开启 GPIOB 的时钟
	*(unsigned int *)0x40021018 |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	*(unsigned int *)0x40010C00 &= ~( (1) << (4 * 0) );
	*(unsigned int *)0x40010C00 |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	*(unsigned int *)0x40010C0C &= ~(1<<0);
#elif 0
	// 开启 GPIOB 的时钟
	RCC_APB2ENR |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	GPIOB_CRL &= ~( (1) << (4 * 0) );
	GPIOB_CRL |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	GPIOB_ODR &= ~(1<<0);
	// GPIOB_ODR |= (1<<0);
#elif 0
	// 开启 GPIOB 的时钟
	RCC_APB2ENR |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	GPIOB->CRL &= ~( (1) << (4 * 0) );
	GPIOB->CRL |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	GPIOB->ODR &= ~(1<<0);
	// GPIOB_ODR |= (1<<0);
#elif 0
	// 开启 GPIOB 的时钟
	RCC_APB2ENR |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	GPIOB->CRL &= ~( (1) << (4 * 0) );
	GPIOB->CRL |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
	GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	// GPIOB_ODR |= (1<<0);
#elif 1
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// 打开 GPIOB 端口的时钟
	LED_G_GPIO_CLK_ENABLE;
	
	GPIO_InitStructure.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);	

  while(1)
  {
		GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
		Delay(0xFFFF);
		GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
		Delay(0xFFFF);
	}

#endif
}

/** 
 * 置1：|= 
 * 置0：&= ~
 */


// SystemInit 函数配置系统时钟为72MHz
// SystemInit 函数空实现，使用内部晶振HSI（8MHz）驱动外设工作
void SystemInit(void) {
	// defined symbol SystemInit, avoid compiler errors
}
