/*
 * I2C.h
 *
 * Created: 9/12/2020 6:33:39 PM
 *  Author: Ibrahim
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "ATmega_Registers.h"
#include "BIT_MATH.h"

#define START_AKN				0x08 //A START condition has been transmitted
#define REP_START_AKN			0x10 //A repeated START condition has been transmitted
#define SLAVE_Addr_WR			0x18 //SLave Address +Write op has been transmitted With ACK
#define SLAVE_Addr_RD			0X40 //SLave Address +read op has been transmitted with ACK
#define WR_BYTE_AKN				0x28 //Data byte has been transmitted & ACK has been received
#define RD_BYTE_NACK			0x58 //Data byte has been received with no ACK 
#define RD_BYTE_AKN				0x50 //Data byte has been received with ACK
#define SLAVE_ADR_RCVD_RD_REQ	0xA8 //Slave Address is received with read request
#define SLAVE_ADR_RCVD_WR_REQ	0x60 //Slave Address is received with write request
#define SlAVE_DATA_RECEIVED		0x80 //Read byte request is received
#define SLAVE_BYTE_TRANSMITTED	0xc0 //Write byte request is received




void I2C_InitMaster(void);

void I2C_InitSlave(void);

void I2C_StartCondition(void);

void I2C_RepeatedStart(void);

void I2C_Send_SlaveAddress_WriteOp(uint8 addr);

void I2C_Send_SlaveAddress_ReadOp(uint8 addr);

void I2C_Write_Byte(uint8 byte);

uint8 I2C_Read_Byte(void);

void I2c_Stop_Cond(void);


#endif /* I2C_H_ */