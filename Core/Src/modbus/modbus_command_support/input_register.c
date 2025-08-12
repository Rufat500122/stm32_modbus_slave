/*
 * input_register.c
 *
 *  Created on: Aug 12, 2025
 *      Author: SUser
 */
#include "modbus/modbus_command_support/input_registers.h"
#define get_input_register_value(register)				0xAAAA

typedef struct __attribute__((__packed__)){
	uint16_t register_number;
	uint16_t register_counter;
} command_format_t;

modbus_request_status_code_t read_input_register_handler(uint8_t *data, uint8_t len){
	uint8_t tx_buffer[MODBUS_RTU_MAX_PACKEG_SIZE] = {0};
	uint16_t tx_len = 0;
	command_format_t *cmd = (command_format_t*)data;

	if(cmd->register_number >= 	INPUT_REGISTER_COUNTER){
		return INVALID_DATA_ADDRESS;
	}
	if (cmd->register_counter > (INPUT_REGISTER_COUNTER - cmd->register_number)) {
		return INVALID_DATA_REQUEST;
	}
	if ((cmd->register_counter * 2) > MODBUS_RTU_MAX_PAYLOAD) {
		return INVALID_DATA_REQUEST;
	}

	tx_buffer[tx_len++] = modbus_get_device_addres();
	tx_buffer[tx_len++] = (uint8_t)READ_INPUT_REGISTERS;
	tx_buffer[tx_len++] = cmd->register_counter * 2;

	for(uint16_t i = 0; i < cmd->register_counter; i++){
		union{
			uint8_t u8[2];
			uint16_t u16;
		} value;
		value.u16 = get_input_register_value(cmd->register_number + i);
		memcpy(tx_buffer + tx_len, value.u8, sizeof(value));
		tx_len += sizeof(value);
	}

	uint16_t crc = modbus_calculate_crc16(tx_buffer, tx_len);
	//TODO: проверить порядок байт crc в модбас LSB или MSB
	tx_buffer[tx_len++] = (uint8_t)(crc & 0xFF);
	tx_buffer[tx_len++] = (uint8_t)(crc >> 8) & 0xFF;

	modbus_uart_transmit_IT(tx_buffer, (uint8_t)tx_len);
	return REQUEST_PROCESSED_SUCCESS;
}
