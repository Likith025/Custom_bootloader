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
#include <usart_tx_service.h>
#include "Jump_app.h"
#include "common_types.h"
#include "device_headers.h"


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
//	void jump_to_application(void)
//	{
//		 printmsg("started jump tp application process\r\n");
//		 void (*app_reset_handler)(void);
//		 uint32_t app_msp_value;
//		 uint32_t app_reset_handler_addr;
//		 app_msp_value=*(volatile uint32_t*)SECTOR_2_ADDR;
//		 printmsg("msp of app is at %x\r\n",SECTOR_2_ADDR);
//
//		 app_reset_handler_addr=*(volatile uint32_t*)(SECTOR_2_ADDR+0x4);
//		 printmsg("reset handler of app is at %x\r\n",(SECTOR_2_ADDR+0x4));
//		 app_reset_handler=(void*)app_reset_handler_addr;
//		 SCB->VTOR=SECTOR_2_ADDR;
//		// __set_MSP(app_msp_value);
//		 __asm volatile ("MSR msp, %0" : : "r" (app_msp_value) : );
//		 app_reset_handler();
//	}

void jump_to_application(void)
{
    uint32_t app_msp_value;
    uint32_t app_reset_handler_addr;
    void (*app_reset_handler)(void);

    app_msp_value = *(volatile uint32_t *)0x08010000;
    app_reset_handler_addr = *(volatile uint32_t *)0x08010004;

    /* Stop bootloader interrupts */
    __asm volatile ("cpsid i");
//
//    /* Disable USART3 interrupts */
//    USART3_handler.pUSART->USART_CR1 &= ~(USART_CR1_TXEIE |
//                                          USART_CR1_TCIE  |
//                                          USART_CR1_RXNEIE);

    /* Disable USART3 NVIC interrupt */
    IRQ_IntrruptConfig(IRQ_NO_USART3, DISABLE);

    /* Switch to application vector table */
    SCB->VTOR = 0x08010000;

    /* Switch to application stack */
    __asm volatile ("MSR msp, %0"
                    :
                    : "r" (app_msp_value)
                    : );

    /* Jump to application Reset_Handler */
    app_reset_handler = (void (*)(void))app_reset_handler_addr;
    app_reset_handler();

   while (1);

}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

