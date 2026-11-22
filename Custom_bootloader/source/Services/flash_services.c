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
#define WRITE_ADDR_LEN       4U
#define MAX_WRITE_DATA_LEN   128U

#define APP_FLASH_START      0x08008000UL   /* confirm against your app's linker script */
#define APP_FLASH_END        0x080FFFFFUL   /* last byte of the app region */
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
    response_pack_t erase_res = {0};
    Flash_StatusType_e status;

    erase_res.response_cmd    = rx_cmd->cmd;
    erase_res.response_status = BL_ACK;

    if (rx_cmd->len != 0U)
    {
        erase_res.response_status = BL_NACK_INVALID_LEN;
    }
    else if (Flash_Unlock() != Status_OK)
    {
        erase_res.response_status = BL_NACK_TIMEOUT;
    }
    else
    {
        for (int i = 2; i <= 7; i++)
        {
            status = Flash_EraseSector(i);
            printmsg("erased sector %d\n\r", i);
            if (status != Status_OK)
            {
                erase_res.response_status = BL_NACK_ERASE_FAIL;
                break;
            }
        }
        Flash_Lock();
    }

    send_response(&erase_res);
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
    response_pack_t res = {0};
    res.response_cmd    = rx_cmd->cmd;
    res.response_status = BL_ACK;

    if ((rx_cmd->len <= WRITE_ADDR_LEN) ||
        ((rx_cmd->len - WRITE_ADDR_LEN) > MAX_WRITE_DATA_LEN))
    {
        res.response_status = BL_NACK_INVALID_LEN;
    }
    else
    {
        uint32_t data_len = (uint32_t)rx_cmd->len - WRITE_ADDR_LEN;
        uint32_t addr = ((uint32_t)rx_cmd->payload[3] << 24) |
                        ((uint32_t)rx_cmd->payload[2] << 16) |
                        ((uint32_t)rx_cmd->payload[1] << 8)  |
                         (uint32_t)rx_cmd->payload[0];

        if ((addr < APP_FLASH_START) ||
            (addr > (APP_FLASH_END + 1UL - data_len)))
        {
            res.response_status = BL_NACK_INVALID_ADDR;   /* add to your enum if missing */
        }
        else if (Flash_Unlock() != Status_OK)
        {
            res.response_status = BL_NACK_WRITE_FAIL;     /* not unlocked: do not lock */
        }
        else
        {
            for (uint32_t i = 0U; i < data_len; i++)
            {
                if (Flash_Write(FLASH_TYPEPROGRAM_BYTE, addr + i,
                                rx_cmd->payload[WRITE_ADDR_LEN + i]) != Status_OK)
                {
                    res.response_status = BL_NACK_WRITE_FAIL;
                    break;
                }
            }
            Flash_Lock();
        }
    }

    send_response(&res);
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
