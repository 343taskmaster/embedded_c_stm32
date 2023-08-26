/*
 * uart.h
 *
 *  Created on: May 20, 2023
 *      Author: agana
 */

#ifndef UART_H_
#define UART_H_
#include <stdio.h>

#include "stm32f4xx.h"


void uart2_tx_init(void);	//transtmit function
char uart2_read(void);
void uart2_rxtx_init(void); //Receive and trasnsmit function



#endif /* UART_H_ */
