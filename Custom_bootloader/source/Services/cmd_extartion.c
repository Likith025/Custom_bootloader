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

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/
#define SOF_idx		0
#define CMD_idx		1
#define LEN_idx		2
#define MAX_PAYLOAD_LEN	128
/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
extern ring_buffer_t rx_buffer;
uint8_t SOF_data=0xA5;
uint8_t CMD_data;
uint8_t LEN_data;
uint8_t Payload_data[MAX_PAYLOAD_LEN];
uint8_t CRC_data;

 uint8_t CRC_cal=0;
 Ext_states_e state=SOF_ext;
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
		case SOF_ext:{
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
		case Cmd_ext:{
			CMD_data=rx_byte;
			CRC_cal^=rx_byte;
			state=Len_ext;
			break;
		}
		case Len_ext:
		{
			LEN_data=rx_byte;
			CRC_cal^=rx_byte;
			if(LEN_data>MAX_PAYLOAD_LEN)
			{
				// BL_NACK_INVALID_LEN case, bail before writing any payload
				state=error;
				break;
			}

			idx=0;
			state=(LEN_data==0)?Check_sum_ext:Payload_ext;
			break;
		}
		case Payload_ext:{
			Payload_data[idx++]=rx_byte;
			CRC_cal^=rx_byte;
			if(idx>=LEN_data)
			{
				idx=0;
				state=Check_sum_ext;
			}
			break;
		}
		case Check_sum_ext:{
			CRC_data=rx_byte;
			if(CRC_data==CRC_cal)
			{

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
/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
