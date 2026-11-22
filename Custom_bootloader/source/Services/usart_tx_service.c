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
 void printmsg(const char *format, ...)
 {
     uint8_t buf[2 + 128];
     va_list args;
     va_start(args, format);
     int n = vsnprintf((char*)&buf[2], 128, format, args);
     va_end(args);
     if (n < 0) return;
     if (n > 127) n = 127;          /* vsnprintf returns would-be length */
     buf[0] = 0x5A;                 /* SOF_DBG */
     buf[1] = (uint8_t)n;
     Ecal_usart_send(buf, 2 + n);
 }

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

 void send_response(response_pack_t *resp)
 {
     uint8_t tx_buf[1U + 1U + 1U + 1U + MAX_PAYLOAD_LEN + 1U];
     uint8_t idx = 0U;

     if (resp == NULL)
     {
         return;
     }

 
     if (resp->response_len > MAX_PAYLOAD_LEN)
     {
         resp->response_len = 0U;
         resp->response_status = BL_NACK_INVALID_LEN; 
     }

     resp->response_crc = cal_crc(resp);   

     tx_buf[idx++] = RESP_SOF_data;
     tx_buf[idx++] = (uint8_t)resp->response_cmd;
     tx_buf[idx++] = (uint8_t)resp->response_status;
     tx_buf[idx++] = resp->response_len;

     for (uint8_t i = 0U; i < resp->response_len; i++)
     {
         tx_buf[idx++] = resp->response_payload[i];
     }

     tx_buf[idx++] = resp->response_crc;

     (void)Ecal_usart_send(tx_buf, idx);
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
