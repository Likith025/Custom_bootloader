/**
 * @file    Ecal_usart.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    26-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/

#include "Ecal_usart.h"
#include "Mcal_Usart.h"
#include "common_types.h"


/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
	void Ecal_usart_send(uint8_t* pTxdata,uint32_t len)
	{
		Mcal_usart_send(pTxdata, len);
	}

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void Ecal_usart_init(void)
{
	Mcal_usart_init();
}
/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

