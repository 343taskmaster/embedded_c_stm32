/*Single Conversion Mode*/

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systic.h"


#define GPIOAEN 		(1U<<0)
#define PIN5			(1U<<5)
#define LED			PIN5



int main(void)
{
	/*1. Enable CLock access to GPIOA */
	RCC-> AHB1ENR |= GPIOAEN;

	/*2. Set PA5 as output pin */
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);


	uart2_tx_init();


	while(1)
	{

		printf("1 milli second passed !! \n\r");
		GPIOA->ODR ^=LED;
		systicDelayMs(5000);


		/*There is 1000 mili second in 1 second */
		/*There for 2000 mili second is 2 second */
		/*Please note that sysDelay() - only takes milli seconds, since we set the load 16,000 cycles */



	}

}





