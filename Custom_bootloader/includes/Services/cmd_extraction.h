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
#define MAX_PAYLOAD_LEN	128
#define  SOF_data	0xA5
#define  RESP_SOF_data        0xC3
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


typedef enum cmds_tag
{
	  BL_GET_VER      = 0x30,
	  BL_GO_TO_ADDR   =  0x23,
	  BL_FLASH_ERASE  = 0x20 ,
	  BL_MEM_WRITE    = 0x21 ,
	  BL_GET_CRC     =  0x22,
}Cmd_list_e;


typedef enum fault_sts_tag
{
	 BL_ACK     =	0x00,
	 BL_NACK_INVALID_CMD =  0x01,
	 BL_NACK_CHECKSUM =   0x02,
	 BL_NACK_INVALID_ADDR =  0x03,
	 BL_NACK_INVALID_LEN =  0x04 ,
	 BL_NACK_ERASE_FAIL = 0x05 ,
	BL_NACK_WRITE_FAIL=  0x06,
	 BL_NACK_TIMEOUT= 0x07     ,
}falut_status_e;

typedef struct response_tag
{
	Cmd_list_e response_cmd;
	falut_status_e response_status;
	uint8_t response_len;
	uint8_t response_payload[128];
	uint8_t response_crc;
}response_pack_t;

typedef struct cmd_tag
{
	Cmd_list_e  cmd;
    uint8_t  len;
    uint8_t  payload[MAX_PAYLOAD_LEN];
    uint8_t  crc;
} cmd_pack_t;

/*------------------------------------------------------------------ Exported constants ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported variables ------------------------------------------------------------------*/

/*------------------------------------------------------------------ Exported function prototypes ------------------------------------------------------------------*/
void get_cmd_fields(void);
void dispatch_cmd(cmd_pack_t* rx_cmd);
void get_boot_version( cmd_pack_t* rx_cmd );
uint8_t cal_crc(response_pack_t* response);
/* Function documentation can be generated using the Doxygen method template. */


#endif /* SERVICES_CMD_EXTRACTION_H_ */
