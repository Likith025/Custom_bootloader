/**
 * @file    BootLoader.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    26-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include <usart_tx_service.h>
#include "BootLoader.h"
#include "Buffer_handling.h"
#include "common_types.h"
#include "cmd_extraction.h"
#include "Ecal_gpio.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/

	  uint8_t poped_val;
	  uint8_t pop_ctrl=0;

	  extern ring_buffer_t rx_buffer;
	  extern uint8_t buffer_empty_status;
	/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

	/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

	/**
	 * @brief  Brief description of the function.
	 *
	 * @param  parameter Description of parameter.
	 *
	 * @return Description of return value.
	 */
	void bootloader_run(void)
	{
		enable_e val=enable;
		while(1)
		{

			get_cmd_fields();
			Ecal_digital_write(Error_led, val);
			val=~val;
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

