/**
 * @file    Ecal_gpio.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    26-Sept-2026
 */

#ifndef ECAL_ECAL_GPIO_H_
#define ECAL_ECAL_GPIO_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include "common_types.h"

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void Ecal_gpio_init(void);

void Ecal_digital_write(digital_outputs_e output_signal,enable_e value);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* ECAL_ECAL_GPIO_H_ */
