/*
 * systic.c
 *
 *  Created on: Aug 5, 2023
 *      Author: agana
 */

#include "stm32f4xx.h"
/*1milli seconds is equals 16000 cycles for more info see Unit Conversion on note */
#define SYSTIC_LOAD_VAL 				16000
#define CTRL_ENABLE 					(1U<<0)
#define CTRL_CLKSRC 					(1U<<2)
#define CTRL_COUNTFLAG					(1U<<16)

/*What is the countflag register */

//This function will take the number of seconds you want to delay
void systicDelayMs(int delay)
{

	/*Reload/refresh with number of clocks per millisecond */
	SysTick->LOAD = SYSTIC_LOAD_VAL;

	/*Clear systic current value register */
	SysTick->VAL = 0;

	/*Enable systic and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC ;

	for(int i=0; i<delay ; i++){
		/*wait until the counter flag is set  */
		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0 ){}
			/*if
			 * SysTick->CTRL & CTRL_COUNTFLAG are both 0 then do nothing
			 * if (SysTick->CTRL & CTRL_COUNTFLAG are both 1 then proceed to the outside of the loop
			 *
			 * */

	}



	SysTick->CTRL = 0; /*This will turn off the following bits */

	/*
	 * 	• Bit 0 (ENABLE): This bit enables or disables the SysTick timer. When set to 1, the timer is enabled, and when set to 0 (as in SysTick->CTRL = 0), the timer is disabled.

	• Bit 1 (TICKINT): This bit enables or disables the SysTick interrupt. When set to 1, the SysTick interrupt is enabled, and when set to 0, the interrupt is disabled.

	• Bit 2 (CLKSOURCE): This bit selects the clock source for the SysTick timer. When set to 1, the processor clock is used as the SysTick clock source. When set to 0, an external clock source is used (not available on all STM32 devices).

	• Bit 16 (COUNTFLAG): This read-only bit is set to 1 when the SysTick timer reaches zero. It is cleared to 0 when the SysTick value is reloaded. You can use this bit to check if the timer has reached zero.
	 * */

}
