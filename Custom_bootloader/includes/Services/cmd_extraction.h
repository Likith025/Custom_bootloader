/**
 * @file    cmd_extraction.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    02-Oct-2026
 */

#ifndef SERVICES_CMD_EXTRACTION_H_
#define SERVICES_CMD_EXTRACTION_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include "common_types.h"

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/
typedef enum extraction_states_tag
{
	SOF_ext=0,
	Cmd_ext,
	Len_ext,
	Payload_ext,
	Check_sum_ext,
	error,

}Ext_states_e;
/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void get_cmd_fields(void);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* SERVICES_CMD_EXTRACTION_H_ */
