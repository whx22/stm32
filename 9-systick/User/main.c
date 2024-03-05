#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_systick.h"

void Delay(__IO u32 nCount);

int main(void) {
	LED_GPIO_Config();
	while (1) {
		LED_G(OFF);
		// Delay(0xFFFFF);
		SysTick_Delay_ms(500);
		LED_G(ON);
		// Delay(0xFFFFF);
		SysTick_Delay_ms(500);
	}

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
