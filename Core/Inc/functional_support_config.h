/*
 * board_config.h
 *
 *  Created on: Aug 11, 2025
 *      Author: SUser
 */

#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__
#include "stdint.h"

#define SUPPORT_MODBUS_CODE_READ_HOLDING_REGISTERS
#define SUPPORT_MODBUS_CODE_READ_INPUT_REGISTERS

#define SENSOR_HUMIDITY_COUNTER 	1
#define SENSOR_NTC_COUNTER 			0
#define SENSOR_4_20_COUNTER 		0

#if (SENSOR_HUMIDITY_COUNTER + SENSOR_NTC_COUNTER + SENSOR_4_20_COUNTER) == 0
	#error Configuration board ERROR. There must be at least 1 sensor
#endif
#endif /* INC_BOARD_CONFIG_H_ */
