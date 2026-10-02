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
#include "BootLoader.h"
#include "print_handler.h"
#include "Buffer_handling.h"
#include "common_types.h"
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
			Buffer_pop(&poped_val);
		if(buffer_empty_status!=1)
		{

			switch(rx_buffer.buffer[1])
			{
				case 0x20:
				{
					printmsg("cmd: earse\n\r");
					break ;
				}

				case 0x21:
				{
					printmsg("cmd: write\n\r");
					break ;
				}

				case 0x23:
				{
					printmsg("cmd: go to address\n\r");
					break ;
				}

				case 0x22:
				{
					printmsg("cmd: get CRC \n\r");
					break ;
				}

				case 0x30:
				{
					printmsg("cmd: get bootloader version\n\r");
					break ;
				}
				default:
				{
					printmsg("invalid cmd\n\r");
					break;
				}

			}
		}
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

