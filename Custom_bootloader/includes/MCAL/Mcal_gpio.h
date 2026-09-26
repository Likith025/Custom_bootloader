/**
 * @file    Mcal_gpio.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */

#ifndef MCAL_MCAL_GPIO_H_
#define MCAL_MCAL_GPIO_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include "device_headers.h"
#include "common_types.h"
/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/


/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/


/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/

void Mcal_gpio_init(void);

void Mcal_digital_write(digital_outputs_e output_signal,enable_e value);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* MCAL_MCAL_GPIO_H_ */
