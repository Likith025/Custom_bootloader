/**
 * @file    common_types.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    26-Sept-2026
 */

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include <stdint.h>

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/
typedef enum enable_tag
	{
		disable=0,
		enable
	}enable_e;

typedef enum digital_outputs_tag
	{
		Error_led=0,
		Status_Led,
		Mode_Switch,
	}digital_signals_e;

typedef enum boot_mode_tag
{
	Application_mode=0,
	Bootloader_mode,
}Boot_mode_e;

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/

/* Function documentation can be generated using the Doxygen method template. */


#endif /* COMMON_TYPES_H_ */
