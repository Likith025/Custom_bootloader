/**
 * @file    flash_services.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    15-Oct-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/

#include "device_headers.h"
#include "usart_tx_service.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void erase_flash(void)
{
	Flash_Unlock();
	for(int i=2;i<=7;i++)
	{
		Flash_EraseSector(i);
		printmsg("erased sector %d\n\r",i);
	}

	Flash_EraseSector(2);
}


/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

