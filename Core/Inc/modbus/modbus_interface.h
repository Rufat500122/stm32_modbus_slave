#ifndef __MODBUS_INTARFACE_H__
#define __MODBUS_INTARFACE_H__
//TODO: добавить в IDLE callback
void modbus_rtu_process_incoming_data(uint8_t* data, uint8_t len);
#endif
