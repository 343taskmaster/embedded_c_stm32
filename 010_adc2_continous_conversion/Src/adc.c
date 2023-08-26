/*
 * adc.c
 *
 *  Created on: Jul 22, 2023
 *      Author: agana
 */
#include "stm32f4xx.h"
#include <stdint.h>

#define GPIOAEN 	    (1U<<0)
#define ADC1EN  	    (1U<<8)
#define ADC_CH1  		(1U<<0) // Set bit 0 to 1 on SQR1 Register
#define ADC_SEQ_LEN_1    0x00 	//means 0x0000 0000 or 0

#define CR2_ADON		(1U<<0)
#define CR2_SWSTART     (1U<<30)
#define SR_EOC			(1U<<1)
#define CR2_CONT		(1U<<1)

void pa1_adc_init(void){

	/***Configure the ADC GPIO Pin ***/

	/*Enable Clock Access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;


	/*Set the mode of PA1 to analog*/

	GPIOA->MODER |=(1U<<2); // set bit 2 to 1 for GPIOA->MODER1
	GPIOA->MODER |=(1U<<3); // set bit 3 to 1  for GPIOA->MODER1

	/***Configure the ADC module ***/

	/*Enable clock access to ADC*/
	RCC->APB2ENR |= ADC1EN;

	/*Conversion sequence star, SQ1 */
	ADC1->SQR3 =  ADC_CH1;

	/*Conversion sequence lenght, How many channels are we sampling  */
	ADC1->SQR1 = ADC_SEQ_LEN_1;

	/*Enable the ADC Module*/
	ADC1->CR2 = CR2_ADON;
}

void start_conversion(void)
{
    /* Enable Continous Conversion */
	ADC1->CR2 |= CR2_CONT;

	/*Start ADC conversion*/
	ADC1->CR2 |= CR2_SWSTART;

}

uint32_t adc_read(void){
	/*wait for the converstion to be complete*/
	while (!(ADC1->SR & SR_EOC)) {}
	/*Read Converted result*/
	return (ADC1->DR);

}
