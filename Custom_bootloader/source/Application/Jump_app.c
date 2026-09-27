/**
 * @file    Jump_app.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    27-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "Jump_app.h"
#include "common_types.h"
#include "device_headers.h"
#include "print_handler.h"


/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/
#define SECTOR_2_ADDR		(0x08010000)
/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
//uint32_t sector_2_addr= 0x08010000;
/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
	void jump_to_application(void)
	{
		 printmsg("started jump tp application process\r\n");
		 void (*app_reset_handler)(void);
		 uint32_t app_msp_value;
		 uint32_t app_reset_handler_addr;
		 app_msp_value=*(volatile uint32_t*)SECTOR_2_ADDR;
		 printmsg("msp of app is at %x\r\n",SECTOR_2_ADDR);

		 app_reset_handler_addr=*(volatile uint32_t*)(SECTOR_2_ADDR+0x4);
		 printmsg("reset handler of app is at %x\r\n",(SECTOR_2_ADDR+0x4));
		 app_reset_handler=(void*)app_reset_handler_addr;
		 SCB->VTOR=SECTOR_2_ADDR;
		// __set_MSP(app_msp_value);
		 __asm volatile ("MSR msp, %0" : : "r" (app_msp_value) : );
		 app_reset_handler();
	}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

