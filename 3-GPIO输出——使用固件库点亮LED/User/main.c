#include "stm32f10x.h"
#include "bsp_led.h"

void Delay(__IO u32 nCount);

int main(void) {
	LED_GPIO_Config();
	while (1) {
		LED_G(OFF);
		Delay(0xFFFFF);
		LED_G(ON);
		Delay(0xFFFFF);
	}

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
