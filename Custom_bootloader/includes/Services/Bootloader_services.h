/**
 * @file    Bootloader_services.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    02-Oct-2026
 */

#ifndef SERVICES_BOOTLOADER_SERVICES_H_
#define SERVICES_BOOTLOADER_SERVICES_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include "common_types.h"
#include "cmd_extraction.h"

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void get_boot_version( cmd_pack_t* rx_cmd );
/* Function documentation can be generated using the Doxygen method template. */


#endif /* SERVICES_BOOTLOADER_SERVICES_H_ */
