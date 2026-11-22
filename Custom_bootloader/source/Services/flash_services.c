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
#include "flash_services.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
uint32_t address_test=0;
uint8_t payload_test[128]={0};
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void erase_flash(cmd_pack_t *rx_cmd)
{
	response_pack_t erase_res;
	Flash_StatusType_e status;
	erase_res.response_cmd=rx_cmd->cmd;
	erase_res.response_len=0;
	status=Flash_Unlock();
	if( status==Status_OK)
	{
		for(int i=2;i<=7;i++)
		{
			status=Flash_EraseSector(i);
			erase_res.response_status=BL_ACK;
			printmsg("erased sector %d\n\r",i);
			if(status!=Status_OK)
			{
				erase_res.response_status=BL_NACK_ERASE_FAIL;
				break;
			}
		}
	}
	else
	{
		erase_res.response_status=BL_NACK_TIMEOUT;
	}

	Flash_Lock();
//for(volatile int i=0;i<10000000;i++);
	send_response(&erase_res);

//	Flash_EraseSector(2);
}


/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void write_flash(cmd_pack_t *rx_cmd)
{
	uint32_t temp_address=0;
	temp_address=((rx_cmd->payload[3]<<24)|(rx_cmd->payload[2]<<16)|(rx_cmd->payload[1]<<8)|(rx_cmd->payload[0]));
	address_test=temp_address;
	Flash_StatusType_e status;

	status = Flash_Unlock();

	if (status != Status_OK)
	{
	    return;
	}

	for (uint16_t i = 0; i < 128; i++)
	{
	    status = Flash_Write(FLASH_TYPEPROGRAM_BYTE,
	                         address_test + i,
	                         rx_cmd->payload[4 + i]);

	    if (status != Status_OK)
	    {
	        printmsg("Flash write failed at offset: %d\r\n", i);
	        break;
	    }
	}

	Flash_Lock();

}

//void write_flash(cmd_pack_t *rx_cmd)
//{
//	response_pack_t flash_write_res;
//	uint32_t temp_address=0;
//	Flash_StatusType_e status;
//
//	flash_write_res.response_cmd=rx_cmd->cmd;
//	temp_address=((rx_cmd->payload[3]<<24)|(rx_cmd->payload[2]<<16)|(rx_cmd->payload[1]<<8)|(rx_cmd->payload[0]));
//	address_test=temp_address;
//
//	if(rx_cmd->len==0)
//	{
//		flash_write_res.response_status=BL_NACK_INVALID_LEN;
//	}
//	else
//	{
//		status = Flash_Unlock();
//		if (status != Status_OK)
//		{
//				flash_write_res.response_status=BL_NACK_WRITE_FAIL;
//
//		}
//		else
//		{
//			for (uint16_t i = 0; i < 128; i++)
//				{
//				    status = Flash_Write(FLASH_TYPEPROGRAM_BYTE,
//				                         address_test + i,
//				                         rx_cmd->payload[4 + i]);
//
//				    if (status != Status_OK)
//				    {
//				    	flash_write_res.response_status=BL_NACK_WRITE_FAIL;
//				        break;
//				    }
//
//				}
//			if(status==Status_OK)
//			{
//				flash_write_res.response_status=BL_ACK;
//			}
//		}
//	}
//
//	Flash_Lock();
//	send_response(&flash_write_res);
//	return ;
//
//}
//
