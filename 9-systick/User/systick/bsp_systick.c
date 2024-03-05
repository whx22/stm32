#include "bsp_systick.h"

#if 0
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	// 判断 ticks(0 ~ 2^24-1) 值合法性
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
  
	// 初始化reload寄存器的值
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
  
  // 默认配置中断优先级为15（最低）
	NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  
	// 初始化counter寄存器的值为0
	SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  
	// 配置 systick 时钟为 AHB 时钟（72MHz）
	// 使能中断
	// 使能systick
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
#endif


void SysTick_Delay_us(uint32_t us) {
	uint32_t i = 0;
	SysTick_Config(72);
	
	for (i = 0; i < us; ++i) {
		// 延时一次定时器计数
		while (!((SysTick->CTRL) & (1 << 16)));
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Delay_ms(uint32_t ms) {
	uint32_t i = 0;
	SysTick_Config(72000);
	
	for (i = 0; i < ms; ++i) {
		// 延时一次定时器计数
		while (!((SysTick->CTRL) & (1 << 16)));
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
