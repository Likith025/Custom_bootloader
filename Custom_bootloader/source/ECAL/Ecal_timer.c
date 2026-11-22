/**
 * @file    Ecal_timer.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    22-Nov-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "common_types.h"
#include "Ecal_timer.h"
#include "Mcal_timer.h"

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

void Ecal_timer_init(void)
{
	Mcal_Timer_Init();
	Mcal_Timer_start();
}


/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

uint32_t Ecal_get_tick_ms(void)
{
	return Mcal_timer_get_count();
}

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

uint8_t Ecal_tick_elapsed(uint32_t since_ms,uint32_t timeout_ms)
{
	 return ((Ecal_get_tick_ms() - since_ms) >= timeout_ms) ? 1U : 0U;
}
/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

