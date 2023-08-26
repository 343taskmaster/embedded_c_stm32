//Locating the PA5
// PA5 is located on GPIOA (GPIOx = A,B,C,D)
// Boundry Address or Base Address or starting address of a peripheral (GPIO_BASE / RCC_BASE )
// OFFSET address of the peripherals without the base address
// GPIOA => AHB1BUS > RCC
// 0x4002 0000U This a hexadecimal number = 01000000000000100000000000000000
#include <stdint.h>
//=====================================================================================================================

//AHB1 BASE ADDRESS
#define PERIPH_BASE 	   (0x40000000UL) // BASE Address of AHB1 Bus
#define AHB1_PERIPH_OFFSET (0x00020000UL) //Access AHB

#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1_PERIPH_OFFSET)  //GPIOA Starting address 0x4002 0000UL
#define GPIOA_OFFSET 	   (0x0000UL)

//GPIOA BASE ADDRESS
#define GPIOA_BASE 		   (AHB1PERIPH_BASE + GPIOA_OFFSET ) //GPIOA Starting address 0x4002 0000UL same us above

// RCC BASE Address
#define RCC_OFFSET			(0x3800UL) // RCC 0x0000 3800
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET) //  0x4002 0000 + 0x0000 3800 =  0x4002 3800 RCC BASE Address

//=====================================================================================================================
// Enable Clock access to AHB1 and RCC
//6.3.9 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) = Enabled



// Enable Clock Access of AHB1 TO RCC
#define AHB1EN_R_OFFSET		(0x30UL) //OFFSET ADDRESS OF AHB1 ENABLE Registry , REFERENCE MANUAL IS 117 0x0000 0030
#define RCC_AHB1EN_R 	    (*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))   // 0x4002 3800 +   0x4002 3800 = 0x4002 3830


// GPIOA - set GPIOA - set 1 on position 0
#define  GPIOAEN    		(1U<<0) // Shift 1 at position Zero  0000 0000 0000 0000 0000 0000 0001 this is a 32bit register


//=====================================================================================================================
//Direction  Register
// 8.4.1 GPIO port mode register (GPIOx_MODER) (x = A..E and H) (INPUT OR OUTPUT)
//Set peripheral GPIOA =OUTPUT

#define MODE_R_OFFSET  (0x00UL)
#define GPIOA_MODE_R   (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

//=====================================================================================================================
//Data Direction Register (Set Pin as High or Low)
//8.4.6 GPIO port output data register (GPIOx_ODR) (x = A..E and H)
//Set Peripheral GPIOA as Write
#define OD_R_OFFSET (0X14UL) // 0x1400 0000
#define GPIOA_OD_R  (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))  // 0x4002 0000 + 0x0000 0014 = 0x4002 0014

#define PIN5 	    (1U<<5)
#define LED_PIN 	PIN5

#define __IO volatile

//=====================================================================================================================
typedef struct {
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;  /*!< RCC AHB1 peripheral clock register */

}RCC_TypeDef;

//=====================================================================================================================

typedef struct
{
 volatile uint32_t MODER; 	   /*!< GPIO Port mode register, 		 	              Address offset: 0x00      */
 volatile uint32_t DUMMY[4];
 volatile uint32_t ODR;          /*!< GPIO Port input data register, 	              Address offset: 0x14      */

}GPIO_TypeDef;

#define RCC 	((RCC_TypeDef*) RCC_BASE)
#define GPIOA 	((GPIO_TypeDef*) GPIOA_BASE)

int main(void){


	/*1. Enable Clock Access to GPIOA */
	// RCC_AHB1EN_R |=  GPIOAEN;    // 0000 0000 0000 0000 0000 0000 0000 0001 + 0x4002 3830

								//or

								// 0100 0000 0000 0010 0000 0000 0000 0000 +  0000 0000 0000 0000 0000 0000 0000 0001
	RCC-> AHB1ENR |= GPIOAEN;

	/*2. Set PA5 as OUTPUT Pin*/
	//GPIOA_MODE_R |= (1U<<10);
	//GPIOA_MODE_R &=~(1U<<11);

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~  (1U<<11);


	while(1){

	/*3.Set PA5 as HIGH */
		GPIOA_OD_R ^= LED_PIN;
		for(int i=0; i<1000000; i++){

		}
	}

}
