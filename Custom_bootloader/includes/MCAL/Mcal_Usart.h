/**
 * @file    Mcal_Usart.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */

#ifndef MCAL_MCAL_USART_H_
#define MCAL_MCAL_USART_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/

#include "device_headers.h"
/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/

/* Function documentation can be generated using the Doxygen method template. */
void Mcal_usart_init(void);
void Mcal_usart_send(uint8_t* pTxdata,uint32_t Length);
void Mcal_usart_receive(uint8_t* pRxdata,uint32_t Length);
#endif /* MCAL_MCAL_USART_H_ */
