/**
 * @file    Ecal_timer.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    22-Nov-2026
 */

#ifndef ECAL_ECAL_TIMER_H_
#define ECAL_ECAL_TIMER_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/


/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void Ecal_timer_init(void);
uint32_t Ecal_get_tick_ms(void);
uint8_t Ecal_tick_elapsed(uint32_t since_ms,uint32_t timeout);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* ECAL_ECAL_TIMER_H_ */
