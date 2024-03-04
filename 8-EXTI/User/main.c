#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_exti.h"

void Delay(__IO u32 nCount);

int main(void) {
	LED_GPIO_Config();
	EXTI_Key_Config(); 
	while (1) {
		
	}

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
