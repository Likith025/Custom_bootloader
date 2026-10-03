/**
 * @file    print_handler.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    27-Sept-2026
 */

#ifndef SERVICES_USART_TX_SERVICE_H_
#define SERVICES_USART_TX_SERVICE_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "cmd_extraction.h"

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void printmsg(char *format,...);
void send_response(response_pack_t* resp);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* SERVICES_USART_TX_SERVICE_H_ */
