/**
 * @file    main.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include "common_types.h"
#include "Mcal_gpio.h"
#include "Ecal_gpio.h"
#include "Mcal_Usart.h"
#include "Mcal_Intrrupt.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
uint8_t txdata[]="liki\n\r";
uint8_t rxdata[4]={};
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

int main()
{
	Ecal_gpio_init();
	Mcal_usart_init();
	mcal_intrrupt_config();
	while(1)
	{
		Ecal_digital_write(Error_led, enable);
		Ecal_digital_write(Status_Led, disable);
		for(int i=0;i<1000000;i++);
		Mcal_usart_send(txdata, sizeof(txdata));
		Ecal_digital_write(Error_led, disable);
		Ecal_digital_write(Status_Led, enable);
		for(int i=0;i<1000000;i++);

		Mcal_usart_receive(rxdata, sizeof(rxdata));

	}
}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

