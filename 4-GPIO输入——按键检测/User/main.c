#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

void Delay(__IO u32 nCount);

int main(void) {
	LED_GPIO_Config();
	KEY_GPIO_Config();
	while (1) {
		if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON) {
			LED_G_TOGGLE;
		}
	}

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
