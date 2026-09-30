/**
 * @file    Buffer_handling.h
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    29-Sept-2026
 */

#ifndef SERVICES_BUFFER_HANDLING_H_
#define SERVICES_BUFFER_HANDLING_H_

/*------------------------------------------------------------------ Includes ------------------------------------------------------------------*/
#include "device_headers.h"

/*------------------------------------------------------------------ Exported macros ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported types ------------------------------------------------------------------*/

typedef struct ring_buffer_tag
{
	uint8_t* buffer;
	uint8_t head;
	uint8_t tail;
	uint8_t size;
}ring_buffer_t;

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void init_buffer(void);
uint8_t Buffer_push(uint8_t value);
uint8_t Buffer_pop(uint8_t* pop_val);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* SERVICES_BUFFER_HANDLING_H_ */
