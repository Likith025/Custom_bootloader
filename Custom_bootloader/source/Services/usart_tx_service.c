/**
 * @file    usart_tx_service.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    27-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "usart_tx_service.h"
#include "Ecal_usart.h"
#include "cmd_extraction.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
 char str[80];
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/
 uint8_t cal_crc(response_pack_t* response);
/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void printmsg(char *format,...)
{


  /*Extract the the argument list using VA apis */
  va_list args;
  va_start(args, format);
  vsprintf(str, format,args);
  Ecal_usart_send((uint8_t*)str, strlen(str));
  va_end(args);

}

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void send_response(response_pack_t* resp)
{
    uint8_t tx_buf[1 + 1 + 1 + 1 + MAX_PAYLOAD_LEN + 1];  // SOF+CMD+STATUS+LEN+PAYLOAD+CRC
    uint8_t idx = 0;

    resp->response_crc = cal_crc(resp);   // computed here, not by the caller

    tx_buf[idx++] = RESP_SOF_data;         // 0xC3
    tx_buf[idx++] = resp->response_cmd;
    tx_buf[idx++] = resp->response_status;
    tx_buf[idx++] = resp->response_len;

    for (uint8_t i = 0; i < resp->response_len; i++)
    {
        tx_buf[idx++] = resp->response_payload[i];
    }

    tx_buf[idx++] = resp->response_crc;

    Ecal_usart_send(tx_buf, idx);
}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

uint8_t cal_crc(response_pack_t* response)
{
	uint8_t crc_val=0;
	crc_val=response->response_cmd^response->response_len^response->response_status;
	for(int i=0;i<response->response_len;i++)
	{
		crc_val=crc_val^response->response_payload[i];
	}
	return crc_val;
}
