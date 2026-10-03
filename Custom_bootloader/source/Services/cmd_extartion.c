/**
 * @file    cmd_extartion.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    02-Oct-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "cmd_extraction.h"
#include "Buffer_handling.h"
#include "BootLoader.h"
#include "usart_tx_service.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
extern ring_buffer_t rx_buffer;

uint8_t CMD_data;
uint8_t LEN_data;
uint8_t Payload_data[MAX_PAYLOAD_LEN];
uint8_t CRC_data;

uint8_t CRC_cal=0;
Ext_states_e state=SOF_ext;

cmd_pack_t received_cmd;
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/
/**
	 * @brief  Brief description of the function.
	 *
	 * @param  parameter Description of parameter.
	 *
	 * @return Description of return value.
	 */
void get_cmd_fields()
{
	static uint8_t idx;
	uint8_t rx_byte;

	while(Buffer_pop(&rx_byte))
	{
		switch(state)
		{
		case SOF_ext:
		{
			if(rx_byte==SOF_data)
			{
				state=Cmd_ext;
				CRC_cal=0;
			}
			else{
				state=error;
			}
			break;
		}
		case Cmd_ext:
		{
			received_cmd.cmd=(Cmd_list_e)rx_byte;
			CRC_cal^=rx_byte;
			state=Len_ext;
			break;
		}
		case Len_ext:
		{
			received_cmd.len=rx_byte;
			CRC_cal^=rx_byte;
			if(received_cmd.len>MAX_PAYLOAD_LEN)
			{
				state=error;
				break;
			}
			idx=0;
			state=(received_cmd.len==0)?Check_sum_ext:Payload_ext;
			break;
		}
		case Payload_ext:{
			received_cmd.payload[idx++]=rx_byte;
			CRC_cal^=rx_byte;
			if(idx>=received_cmd.len)
			{
				idx=0;
				state=Check_sum_ext;
			}
			break;
		}
		case Check_sum_ext:
		{
			received_cmd.crc=rx_byte;

			if(received_cmd.crc==CRC_cal)
			{
				dispatch_cmd(&received_cmd);

			}
			else
			{

			}
			state=SOF_ext;
			break;
		}
		case error:
		{
			//sof error;
			idx=0;
			state=SOF_ext;
			break;
		}
		}

	}
}

/**
	 * @brief  Brief description of the function.
	 *
	 * @param  parameter Description of parameter.
	 *
	 * @return Description of return value.
	 */
void dispatch_cmd(cmd_pack_t *rx_cmd)
{

   switch(rx_cmd->cmd)
   {
   /*
    *  BL_GET_VER      = 0x30,
	  BL_GO_TO_ADDR   =  0x23,
	  BL_FLASH_ERASE  = 0x20 ,
	  BL_MEM_WRITE    = 0x21 ,
	  BL_GET_CRC     =  0x22,
    */
   case BL_GET_VER:
   {
	   get_boot_version(rx_cmd);
	   break;
   }

   case BL_GO_TO_ADDR:
   {

	   break;
   }
   case BL_FLASH_ERASE:
    {

 	   break;
    }
   case BL_MEM_WRITE:
    {

 	   break;
    }
   case BL_GET_CRC:
    {

 	   break;
    }
   default:
    {

 	   break;
    }

   }
}
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
/**
	 * @brief  Brief description of the function.
	 *
	 * @param  parameter Description of parameter.
	 *
	 * @return Description of return value.
	 */

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/
