/*
 * EEPROM.c
 *
 * Created: 9/16/2020 11:14:36 PM
 *  Author: Ibrahim
 */ 
#include "EEPROM.h"

void ROM_Write(uint8 Block_Address , uint8 Reg_Address , uint8 byte)
{
	I2C_StartCondition();
	
	I2C_Send_SlaveAddress_WriteOp(Block_Address);
	
	I2C_Write_Byte(Reg_Address);
	
	I2C_Write_Byte(byte);
	
	I2c_Stop_Cond();
	
}


uint8 ROM_Read(uint8 Block_Address , uint8 Reg_Address)
{
	uint8 data = 0;
	
	I2C_StartCondition();
	I2C_Send_SlaveAddress_WriteOp(Block_Address);
	
	I2C_Write_Byte(Reg_Address);
	
	I2C_RepeatedStart();
	
	I2C_Send_SlaveAddress_ReadOp(Block_Address);
	
	data = I2C_Read_Byte();
	
	I2c_Stop_Cond();
	
	return data;
}