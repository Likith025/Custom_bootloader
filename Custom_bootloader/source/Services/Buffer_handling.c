/**
 * @file    Buffer_handling.c
 * @brief   Brief description of the file.
 *
 * @details Detailed description of the file.
 *
 * @author  likith
 * @date    29-Sept-2026
 */


/* ------------------------------------------------------------------Includes ------------------------------------------------------------------*/
#include "Buffer_handling.h"
#include "Ecal_usart.h"

/*------------------------------------------------------------------ Macros ------------------------------------------------------------------*/
#define Buffer_SIZE		200U
/* ----------------------------------------------------------------- Global variables ------------------------------------------------------------------*/
ring_buffer_t rx_buffer;
uint8_t buffer[Buffer_SIZE];

uint8_t test_buffer[Buffer_SIZE];

uint8_t buffer_full_status=0;
uint8_t buffer_empty_status=0;

volatile uint8_t rx_overrun_count;

/*------------------------------------------------------------------ Local / static function prototypes ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
void init_buffer()
{
	rx_buffer.buffer=buffer;
	rx_buffer.head=0U;
	rx_buffer.tail=0U;
	rx_buffer.size=Buffer_SIZE;
}
/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */
uint8_t Buffer_push(uint8_t value)
{
    uint8_t reval = 0U;
    uint8_t next_head = (uint8_t)(rx_buffer.head + 1U);

    if (next_head >= rx_buffer.size)
    {
        next_head = 0U;
    }

    if (next_head != rx_buffer.tail)
    {
        rx_buffer.buffer[rx_buffer.head] = value;
        rx_buffer.head = next_head;
        reval = 1U;
    }
    else
    {
        rx_overrun_count++;   /* declare: volatile uint32_t */
    }
    return reval;
}

	/**
	 * @brief  Brief description of the function.
	 *
	 * @param  parameter Description of parameter.
	 *
	 * @return Description of return value.
	 */
uint8_t Buffer_pop(uint8_t* pop_val)
{
	uint8_t reval=1;
	buffer_empty_status=0;
	if((pop_val==NULL))
	{
		reval=0;
	}
	else
	{
		if(rx_buffer.head==rx_buffer.tail)
		{
			buffer_empty_status=1;
			reval=0;
		}
		else
		{
			*pop_val=rx_buffer.buffer[rx_buffer.tail];
			rx_buffer.tail++;
			if(rx_buffer.tail>=rx_buffer.size)
			{
				rx_buffer.tail=0;
			}
		}
	}
	return reval;

}



/*------------------------------------------------------------------ Local function  ------------------------------------------------------------------*/

/**
 * @brief  Brief description of the function.
 *
 * @param  parameter Description of parameter.
 *
 * @return Description of return value.
 */

