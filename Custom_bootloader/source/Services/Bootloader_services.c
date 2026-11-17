/**
 * @file    Bootloader_services.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    02-Oct-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "Bootloader_services.h"
#include "cmd_extraction.h"
#include "usart_tx_service.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/
#define Bootloader_version 		0x1
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
void get_boot_version( cmd_pack_t* rx_cmd )
{
	response_pack_t boot_version;
	boot_version.response_cmd=rx_cmd->cmd;

	if(rx_cmd->len!=0)
	{
		boot_version.response_status=BL_NACK_INVALID_LEN;
		boot_version.response_len=0x00;
	}
	else
	{
		boot_version.response_status=BL_ACK;
		boot_version.response_len=0x01;
		boot_version.response_payload[0]=Bootloader_version;
	}

	send_response(& boot_version);


}
/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

