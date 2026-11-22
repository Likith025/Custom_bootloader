/**
 * @file    Mcal_timer.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    22-Nov-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "device_headers.h"
#include "Mcal_timer.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/
#define TIMER_TICK_PRESCALER   16000U        /* 16 MHz HSI / 16000 = 1 kHz */
#define TIMER_TICK_PERIOD      0xFFFFFFFFU
/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
static TIMER_handler_t tick_timer;
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void Mcal_Timer_Init(void)
{
	tick_timer.TimerConfig.PreScaler=TIMER_TICK_PRESCALER;
	tick_timer.TimerConfig.Period=TIMER_TICK_PERIOD;
	tick_timer.TimerConfig.direction=0U;
	TimerInit(&tick_timer);
}

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void Mcal_Timer_start(void)
{
	TimerControl(&tick_timer, 1U);
}

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

uint32_t Mcal_timer_get_count(void)
{
	return TimerGetCount(&tick_timer);
}


/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

