/*
 * I2C.c
 *
 * Created: 9/12/2020 6:33:25 PM
 *  Author: Ibrahim
 */ 

#include "I2C.h"


void I2C_InitMaster(void)
{
	// intit clock with freq 400khz  ((16m/400k)-16)/2  with TWPS bits (0,0)
	TWBR = 0x0c;
	
	//TWPS bits in reg TWSR
	CLR_BIT(TWSR , 0);
	CLR_BIT(TWSR , 1);
	
	//enable I2C peripheral in tW control register
	
	SET_BIT(TWCR , 2);
	 
}

void I2C_InitSlave(void)
{	
	//assigning slave address 0000001 to the TW (slave)Adress register
	
	TWAR = ( 0x01 << 1);
	
	//enable broadcast bit in TWAR
	SET_BIT(TWAR , 0);
	
	//enable I2C peripheral in tW control register
	
	SET_BIT(TWCR , 2);
}

void I2C_StartCondition(void)
{
	//enable start condition 
	SET_BIT(TWCR , 5);
	
	//to make sure I2c is enabled whenever the function is called
	//SET_BIT(TWCR , 2);
	
	//clearing flag by setting interrupt flag bit 
	SET_BIT(TWCR , 7);
	
	//pooling till the flag is set 
	while (GET_BIT(TWCR , 7) == 0);
	
	//monitoring the status bits
	while( (TWSR & 0xF8) == START_AKN );
	
}

void I2C_RepeatedStart(void)
{
	//enable Repeated start
	SET_BIT(TWCR , 5);
	
	//SET_BIT(TWCR , 2);
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);
	
	while( (TWSR & 0xF8) == REP_START_AKN );
}

void I2C_Send_SlaveAddress_WriteOp(uint8 addr)
{
	TWDR = (addr<<1);
	
	//SET_BIT(TWCR , 2);
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);
	
	while( (TWSR & 0xF8) == SLAVE_Addr_WR );
}

void I2C_Send_SlaveAddress_ReadOp(uint8 addr)
{
	TWDR = (addr<<1)|0x01;
	
	//SET_BIT(TWCR , 2);
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);
	
	while( (TWSR & 0xF8) == SLAVE_Addr_RD );
}


void I2C_Write_Byte(uint8 byte)
{
	//assigning the (byte to be written)  to the data register
	TWDR = byte;
	
	//SET_BIT(TWCR , 2);
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);
	
	while( (TWSR & 0xF8) == WR_BYTE_AKN );
}

uint8 I2C_Read_Byte(void)
{
	//SET_BIT(TWCR , 2);
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);
	
	while( (TWSR & 0xF8) == RD_BYTE_AKN );
	
	//returning the value of the data register
	return TWDR;
}

void I2c_Stop_Cond(void)
{
	//setting the stop condition bit
	SET_BIT(TWCR , 4);
	
	SET_BIT(TWCR , 7);
	
	while (GET_BIT(TWCR , 7) == 0);

}

