/*
 * modbus_common_defines.h
 *
 *  Created on: Aug 12, 2025
 *      Author: SUser
 */

#ifndef __MODBUS_MODBUS_COMMON_DEFINES_H__
#define __MODBUS_MODBUS_COMMON_DEFINES_H__
#include "stm32g0xx_hal.h"
#include "stdint.h"
#include "string.h"



#define MODBUS_RTU_MIN_PACKEG_SIZE	7
#define MODBUS_RTU_MAX_PAYLOAD		251
#define MODBUS_RTU_MAX_PACKEG_SIZE	256

typedef enum {
	READ_COILS 				= 0x01,
	READ_DISCRETE_INPUTS 	= 0x02,
	READ_HOLDING_REGISTERS 	= 0x03,
	READ_INPUT_REGISTERS 	= 0x04,
	WRITE_SINGLE_COIL 		= 0x05,
	WRITE_SINGLE_REGISTER 	= 0x06,
	DIAGNOSTICS 			= 0x08,	//Serial Line only
	GET_COMM_EVENT_COUNTER	= 0x0B,	//Serial Line only
	WRITE_MULTIPLE_COILS	= 0x0F,
	WRITE_MULTIPLE_REGISTER = 0x10,
	REPORT_SERVER_ID		= 0x11,	//Serial Line only
	MASK_WRITE_REGISTER		= 0x16,
	READ_WRIET_MULTIPLE_REGISTERS = 0x17,
	READ_DEVICE_INDIFICATION	=0x2B,
} modbus_function_code_t;

//TODO: не очень поняты реальные триггеры ошибок
typedef enum {
	REQUEST_PROCESSED_SUCCESS = 0,
	UNKNOWN_FUNCTIONAL_CODE = 1,
	INVALID_DATA_ADDRESS 	= 2,
	INVALID_DATA_REQUEST 	= 3,
	UNKNOWN_ERROR			= 4,
	NEED_TIMEOUT_UPDATE 	= 5,
	DEVICE_BUSY 			= 6,
	FUNCTIONAL_NOT_SUPPORTED= 7,
	PARITY_ERROR			= 8,
	GATEWAY_OVERLOADED		= 10,
	SLAVE_UNAVAILABLE		= 11,
} modbus_request_status_code_t;

//TODO: добавить реализацию команд
#define modbus_uart_transmit_IT(data, data_len)		HAL_OK
#define modbus_get_device_addres()  				0x70

uint16_t modbus_calculate_crc16(uint8_t *data, uint8_t len);

#endif /* INC_MODBUS_MODBUS_COMMON_DEFINES_H_ */
