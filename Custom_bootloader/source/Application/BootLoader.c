/**
 * @file    BootLoader.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    26-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "BootLoader.h"
#include "print_handler.h"
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
void bootloader_run(void)
{
	while(1)
	{
	printmsg("running in boot mode\n\r");
	for(volatile int i=0;i<1000000;i++);
	}
}


/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

