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
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
extern GPIO_handler_t ErrorLed;
extern GPIO_handler_t StatusLed;
extern GPIO_handler_t UsartTX;
extern GPIO_handler_t UsartRX;
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
	Mcal_gpio_init();
	while(1)
	{
		Mcal_digital_write(&ErrorLed, enable);
		Mcal_digital_write(&StatusLed, enable);
		for(int i=0;i<1000000;i++);
		Mcal_digital_write(&ErrorLed, disable);
		Mcal_digital_write(&StatusLed, disable);
		for(int i=0;i<1000000;i++);

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

