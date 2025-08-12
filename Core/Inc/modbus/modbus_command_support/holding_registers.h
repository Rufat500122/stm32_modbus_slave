/*
 * holdering_registers.h
 *
 *  Created on: Aug 11, 2025
 *      Author: SUser
 */

#ifndef __HOLDING_REGISTERS_H__
#define __HOLDING_REGISTERS_H__

#include "database/holding_register_list.h"
#include "modbus/modbus_common_content.h"

modbus_request_status_code_t read_holding_register_handler(uint8_t *data, uint8_t len);

#endif /* __HOLDING_REGISTERS_H__ */
