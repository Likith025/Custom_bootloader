/**
 * @file    Mcal_gpio.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    24-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "Mcal_gpio.h"

#include "device_headers.h"
#include "common_types.h"
/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/

/* ------------------------------------------------------------------ Global variables ------------------------------------------------------------------*/
GPIO_handler_t ErrorLed;
GPIO_handler_t StatusLed;
GPIO_handler_t UsartTX;
GPIO_handler_t UsartRX;

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

void ErrorLed_init(void);
void StatusLed_init(void);
void UsartTX_init(void);
void UsartRX_init(void);

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Initalizing pins for status led's and usart
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

void Mcal_gpio_init(void)
{
	ErrorLed_init();
	StatusLed_init();
	UsartTX_init();
	UsartRX_init();
}


/**
 * @brief  Initalizing pins for status led's and usart
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void Mcal_digital_write(GPIO_handler_t* gpio_handler,enable_e value)
{
	(void)GPIO_WritePin(gpio_handler->pGPIOx,gpio_handler->GPIO_pin_config.GPIO_PinNumber,(uint8_t)value);
}

/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void ErrorLed_init()
{
	//PB14 as output
	int8_t reval=0;
	ErrorLed.pGPIOx=GPIO_B;
	ErrorLed.GPIO_pin_config.GPIO_PinMode=GPIO_MODE_OUTPUT;
	ErrorLed.GPIO_pin_config.GPIO_PinNumber=14U;
	ErrorLed.GPIO_pin_config.GPIO_PinOutSpeed=GPIO_OPSPEED_LOW;
	ErrorLed.GPIO_pin_config.GPIO_PinOutType=GPIO_OPTYPE_PUSH_PULL;
	reval=GPIO_init(&ErrorLed);
}


/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void StatusLed_init()
{
	//PB7 as output

	StatusLed.pGPIOx=GPIO_B;
	StatusLed.GPIO_pin_config.GPIO_PinMode=GPIO_MODE_OUTPUT;
	StatusLed.GPIO_pin_config.GPIO_PinNumber=7U;
	StatusLed.GPIO_pin_config.GPIO_PinOutSpeed=GPIO_OPSPEED_LOW;
	StatusLed.GPIO_pin_config.GPIO_PinOutType=GPIO_OPTYPE_PUSH_PULL;
	(void)GPIO_init(&StatusLed);
}



/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void UsartTX_init()
{
	//PD8 as USART3 TX
	 UsartTX.pGPIOx = GPIO_D;
	 UsartTX.GPIO_pin_config.GPIO_PinMode = GPIO_MODE_ALTERNATE_FUN;
	 UsartTX.GPIO_pin_config.GPIO_PinNumber = 8;
	 UsartTX.GPIO_pin_config.GPIO_PinOutType = GPIO_OPTYPE_PUSH_PULL;
	 UsartTX.GPIO_pin_config.GPIO_PinOutSpeed = GPIO_OPSPEED_LOW;
	 UsartTX.GPIO_pin_config.GPIO_PinPushPullResistor = GPIO_PUPD_NO;
	 UsartTX.GPIO_pin_config.GPIO_PinAltFun = 7;
	 (void)GPIO_init(&UsartTX);
}


/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void UsartRX_init()
{
	//PD9 as USART3 TX
	 UsartRX.pGPIOx = GPIO_D;
	 UsartRX.GPIO_pin_config.GPIO_PinMode = GPIO_MODE_ALTERNATE_FUN;
	 UsartRX.GPIO_pin_config.GPIO_PinNumber = 9;
	 UsartRX.GPIO_pin_config.GPIO_PinOutType = GPIO_OPTYPE_PUSH_PULL;
	 UsartRX.GPIO_pin_config.GPIO_PinOutSpeed = GPIO_OPSPEED_LOW;
	 UsartRX.GPIO_pin_config.GPIO_PinPushPullResistor = GPIO_PUPD_NO;
	 UsartRX.GPIO_pin_config.GPIO_PinAltFun = 7;
	 (void)GPIO_init(&UsartRX);
}
