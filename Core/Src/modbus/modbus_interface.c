/*
 * modbus_interface.c
 *
 *  Created on: Aug 11, 2025
 *      Author: SUser
 */
#include "modbus/modbus_common_content.h"
#include "modbus/modbus_interface.h"
#include "modbus/modbus_command_support/holding_registers.h"
#include "modbus/modbus_command_support/input_registers.h"



typedef modbus_request_status_code_t (*request_handler)(uint8_t* data, uint8_t len);

typedef struct {
	modbus_function_code_t code;
	request_handler handler;
} modbus_table_t;


const modbus_table_t modbus_hadler_table[] = {
#ifdef SUPPORT_MODBUS_CODE_READ_COILS
		{READ_COILS, 				read_coils_handelr					},
#endif
#ifdef SUPPORT_MODBUS_CODE_READ_DISCRETE_INPUTS
		{READ_DISCRETE_INPUTS, 		read_discrete_inputs_handler		},
#endif
#ifdef SUPPORT_MODBUS_CODE_READ_HOLDING_REGISTERS
		{READ_HOLDING_REGISTERS, 	read_holding_register_handler		},
#endif
#ifdef SUPPORT_MODBUS_CODE_READ_INPUT_REGISTERS
		{READ_INPUT_REGISTERS, 		read_input_register_handler			},
#endif
#ifdef SUPPORT_MODBUS_CODE_WRITE_SINGLE_COIL
		{WRITE_SINGLE_COIL, 		write_single_coil_handler			},
#endif
#ifdef SUPPORT_MODBUS_CODE_WRITE_SINGLE_REGISTER
		{WRITE_SINGLE_REGISTER, 	write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_DIAGNOSTICS
		{DIAGNOSTICS, 				diagnostic_handler					},
#endif
#ifdef SUPPORT_MODBUS_CODE_GET_COMM_EVENT_COUNTER
		{GET_COMM_EVENT_COUNTER, 	write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_WRITE_MULTIPLE_COILS
		{WRITE_MULTIPLE_COILS, 		write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_WRITE_MULTIPLE_REGISTER
		{WRITE_MULTIPLE_REGISTER, 	write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_REPORT_SERVER_ID
		{REPORT_SERVER_ID, 			write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_MASK_WRITE_REGISTER
		{MASK_WRITE_REGISTER, 		write_register_handler				},
#endif
#ifdef SUPPORT_MODBUS_CODE_READ_WRIET_MULTIPLE_REGISTERS
		{READ_WRIET_MULTIPLE_REGISTERS, 	write_register_handler		},
#endif
#ifdef SUPPORT_MODBUS_CODE_READ_DEVICE_INDIFICATION
		{READ_DEVICE_INDIFICATION, 	write_register_handler				},
#endif
};

HAL_StatusTypeDef modbus_response_error_handle(uint8_t dest_address, modbus_function_code_t code, modbus_request_status_code_t status);

//TODO: поместить в IDLE callback
void modbus_rtu_process_incoming_data(uint8_t* data, uint8_t len) {
	modbus_request_status_code_t status = UNKNOWN_FUNCTIONAL_CODE;
	if (len < MODBUS_RTU_MIN_PACKEG_SIZE){
		return;
	}
    uint8_t dest_address = data[0];
    modbus_function_code_t code = (modbus_function_code_t)data[1];

    if(dest_address != modbus_get_device_addres()){
    	return;
    }
    //TODO: проверить полином crc, правильный должен выдать 0, иначе поменять проверку
    if(modbus_calculate_crc16(data, len) != 0){
    	//TODO: разобраться есть ли ошибка crc в модбас или просто игнорировать такие пакеты
    	return;
    }
	for (int i = 0; i < sizeof(modbus_hadler_table)/sizeof(modbus_table_t); i++) {
		if (modbus_hadler_table[i].code == code) {
			status = modbus_hadler_table[i].handler(data + 2, len);
			break;
		}
	}
	if(status != REQUEST_PROCESSED_SUCCESS){
		modbus_response_error_handle(dest_address, code, status);
	}
	return;
}


HAL_StatusTypeDef modbus_response_error_handle(uint8_t dest_address, modbus_function_code_t code, modbus_request_status_code_t status){
	uint8_t tx_buffer[5] = {0};
	uint8_t tx_len = 0;

	tx_buffer[tx_len++] = dest_address;
	tx_buffer[tx_len++] = (uint8_t)code | 0x80;
	tx_buffer[tx_len] = (uint8_t)status;

	uint16_t crc = modbus_calculate_crc16(tx_buffer, tx_len++);
	tx_buffer[tx_len++] = (uint8_t)(crc & 0xFF);
	tx_buffer[tx_len++] = (uint8_t)(crc >> 8) & 0xFF;

	return modbus_uart_transmit_IT(tx_buffer, tx_len);
}
