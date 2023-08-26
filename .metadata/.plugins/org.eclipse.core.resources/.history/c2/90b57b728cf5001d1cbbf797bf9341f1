//We will using bit set/reset
// SET means on
// reset means off

#include "stm32f4xx.h"

#define GPIOAEN 		(1U<<0)
#define GPIOCEN 		(1U<<2) // symbolic name for RCC_AHB1ENR for GPIOC, shift 1 on bit 2

#define PIN5 			(1U<<5)
#define PIN13 			(1U<<13) // symbolic name for PIN13

#define LED_PIN 		PIN5
#define BTN_PIN 		PIN13  // symbolic name for PIN13


int main(void)
{
	/*Enable Clock to GPIOA and GPIOC*/
	RCC-> AHB1ENR |= GPIOAEN;
	RCC-> AHB1ENR |= GPIOCEN;

	/*SET GPIOA or PORTA as OUTPUT */
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

	/*SET GPIOC PIN13 as INPUT */
	GPIOC->MODER  &=~(1U<<26);
	GPIOC->MODER  &=~(1U<<27);

	while(1)
	{

		/*Check if BTN_PIN is High */

		if(GPIOC->IDR & BTN_PIN){
			GPIOA->BSRR = LED_PIN; // BS5 SET REGISTER / ON TO 1
			for(int i=0; i<1000000; i++){}
		}else{
			GPIOA->BSRR = (1U<<21); //  BR5 SET REGISTER / OFF  TO 1
			for(int i=0; i<1000000; i++){}
		}

	}

}
