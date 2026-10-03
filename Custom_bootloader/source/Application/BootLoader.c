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
		while(1)
		{
		//printmsg("running in boot mode\n\r");
	//	for(volatile int i=0;i<2000000;i++);
			get_cmd_fields();
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

