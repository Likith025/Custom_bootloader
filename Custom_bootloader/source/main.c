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
#include "digital_signal_services.h"
#include "print_handler.h"
#include "Jump_app.h"
#include "BootLoader.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
uint8_t txdata[]="liki\n\r";
uint8_t rxdata[4]={};
uint8_t msg_count=0;

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
	Get_boot_mode();

	printmsg("entered Bootloader\n\r");
	if(Boot_mode==Application_mode)
	{
		//in application mode
		jump_to_application();
	}
	else
	{
		bootloader_run();

	}
	while(1)
	{

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

