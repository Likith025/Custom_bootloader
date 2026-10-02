/**
 * @file    main.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/

#include "common_types.h"
#include "Ecal_gpio.h"
#include "Ecal_Usart.h"
#include "Mcal_Intrrupt.h"
#include "digital_signal_services.h"
#include "print_handler.h"
#include "Jump_app.h"
#include "BootLoader.h"
#include "Buffer_handling.h"

#include "Mcal_Usart.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
volatile uint8_t tx_complete=0;
uint8_t rx_byte=0;

extern USART_handler_t USART3_handler;
extern uint8_t buffer_full_status;

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

int main()
{
	Ecal_gpio_init();
	Ecal_usart_init();
	mcal_intrrupt_config();
	Get_boot_mode();
	Mcal_usart_receive(&rx_byte, 1);

	printmsg("entered Bootloader\n\r");
	 init_buffer();
	while(!tx_complete); // ensure tx is completed so that irq's can be disabled in jump to application mode
	if(Boot_mode==Application_mode)
	{
		//in application mode
		jump_to_application();
	}
	else
	{
		bootloader_run();

	}
	while(1)
	{

	//	USART_SendData_IT(&USART3_handler, txdata, 6);
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
void USART_ApplicationEventCallback(USART_handler_t *pUSARTHandle,USART_CallBack_t event)
{
if (event==USART_EVENT_RX_CMPL)
{
	Mcal_usart_receive(&rx_byte, 1);
	if(buffer_full_status!=1)
	{
	Buffer_push(rx_byte);
	}

}
if(event==USART_EVENT_TX_CMPL){
	pUSARTHandle->UASRT_Txstate=USART_FREE;
	tx_complete=1;
}
}

