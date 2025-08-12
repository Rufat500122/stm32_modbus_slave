/*
 * input_registers.h
 *
 *  Created on: Aug 12, 2025
 *      Author: SUser
 */

#ifndef __INPUT_REGISTERS_H__
#define __INPUT_REGISTERS_H__

#include "database/input_register_list.h"
#include "modbus/modbus_common_content.h"

modbus_request_status_code_t read_input_register_handler(uint8_t *data, uint8_t len);


#endif /* __INPUT_REGISTERS_H__ */
