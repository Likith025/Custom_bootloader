/**
 * @file    Mcal_Usart.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "Mcal_Usart.h"

#include "device_headers.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/

USART_handler_t USART3_handler;

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void Mcal_usart_init(void)
{
	USART3_handler.pUSART=USART_3;
	USART3_handler.USART_config.USART_Mode=USART_MODE_TXRX;
	USART3_handler.USART_config.USART_WordLength=USART_WordLen_8bits;
	USART3_handler.USART_config.USART_OverSmapling=USART_OverSampling_8;
	USART3_handler.USART_config.USART_StopBits=USART_StopBits_1;
	USART3_handler.USART_config.USART_ParityControl=USART_Parity_None;
	USART3_handler.USART_config.USART_HWflowControl=USART_HW_FlowCtrl_None;
	USART3_handler.USART_config.USART_BaudRate=USART_BAUD_9600;
	USART3_handler.UASRT_Rxstate=USART_FREE;
	USART3_handler.UASRT_Txstate=USART_FREE;
	USART_init(&USART3_handler,ENABLE);
}


/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void Mcal_usart_send(uint8_t* pTxdata,uint32_t Length)
{
	USART_SendData_IT(&USART3_handler, pTxdata, Length);
}


/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void Mcal_usart_receive(uint8_t* pRxdata,uint32_t Length)
{
	USART_ReadData_IT(&USART3_handler, pRxdata, Length);
}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

