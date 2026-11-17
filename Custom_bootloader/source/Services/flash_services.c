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

void erase_flash(void)
{
	Flash_Unlock();
	for(int i=2;i<=7;i++)
	{
		Flash_EraseSector(i);
		printmsg("erased sector %d\n\r",i);
	}

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
