/*
 * EEPROM.h
 *
 * Created: 9/16/2020 11:14:57 PM
 *  Author: Ibrahim
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

#define Block0		0x50 //01010000
#define Block1		0x51 //01010001
#define Block2		0x52 //01010010
#define Block3		0x53 //01010011




void ROM_Write(uint8 Block_Address , uint8 Reg_Address , uint8 byte);


uint8 ROM_Read(uint8 Block_Address , uint8 Reg_Address);


#endif /* EEPROM_H_ */