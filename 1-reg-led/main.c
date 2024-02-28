# if 0

#include <REG52.H>

sbit LED = P0^0

void main(void) {

	P0 = 0xFE;	// register operation
	
	LED = 0;		// bit operation
	
}

#endif

#include "stm32f10x.h"

int main(void) {
#if 0 
	// 开启 GPIOB 的时钟
	*(unsigned int *)0x40021018 |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	*(unsigned int *)0x40010C00 &= ~( (1) << (4 * 0) );
	*(unsigned int *)0x40010C00 |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	*(unsigned int *)0x40010C0C &= ~(1<<0);
#else
	// 开启 GPIOB 的时钟
	RCC_APB2ENR |= ( (1) << 3);
	// 配置 IO 口为输出模式，同时设置多个位前需要提前清零，防止原始数据干扰
	*(unsigned int *)0x40010C00 &= ~( (1) << (4 * 0) );
	GPIOB_CRL |= ( (1) << (4 * 0) );
	// 控制 ODR 寄存器
	GPIOB_ODR &= ~(1<<0);
	// GPIOB_ODR |= (1<<0);
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
