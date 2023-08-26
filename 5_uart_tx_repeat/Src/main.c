//We will using bit set/reset
// SET means on
// reset means off

#include "stm32f4xx.h"

#define GPIOAEN 		(1U<<0)
#define GPIOCEN 		(1U<<2) // symbolic name for RCC_AHB1ENR for GPIOC, shift 1 on bit 2
#define UART2EN 		(1U<<17)


int main(void)
{
	RCC->AHB1ENR |= USART2EN;



}
