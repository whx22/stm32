// 用来存放stm32寄存器映射的代码

// 外设 perirhral

#define PERIPH_BASE     ((unsigned int)0x40000000)
#define APB1PERIPH_BASE (PERIPH_BASE)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHPPERIPH_BASE  (PERIPH_BASE + 0x20000)

#define RCC_BASE        (AHPPERIPH_BASE + 0x1000)
#define GPIOB_BASE      (APB2PERIPH_BASE + 0x0C00)

#define RCC_APB2ENR     *(unsigned int *)(RCC_BASE + 0x18)

#define GPIOB_CRL       *(unsigned int *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH       *(unsigned int *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR       *(unsigned int *)(GPIOB_BASE + 0x0C)
