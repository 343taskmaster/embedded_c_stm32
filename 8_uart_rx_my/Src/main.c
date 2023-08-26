/*By Arnold*/
/*PA2 is used to Transmit/TX*/
/*PA3 is used to Received/RX*/

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

uint32_t sensor_value;

int main(void)
{




	uart2_tx_init();
	pa1_adc_init();
	start_conversion();

	while(1)
	{
		sensor_value =adc_read();
		printf("Sensor Value : %d \n\r", (int)sensor_value);
		//locate PA1 on usermanual connect it 3.3 volt using a jumper wire
	}

}





