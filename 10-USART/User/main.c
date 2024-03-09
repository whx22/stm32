#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

int main(void) {
	USART_Config();
	Usart_SendByte(DEBUG_USARTx, 'A');
	while (1) {
	
	
	}
}
