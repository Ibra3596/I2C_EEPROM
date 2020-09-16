/*
 * I2C EEPROM.c
 *
 * Created: 9/16/2020 11:07:41 PM
 * Author : Ibrahim
 */ 

#include "LCD.h"

#include "EEPROM.h"



int main(void)
{
	I2C_InitMaster();
	LCD_Init();
	
	uint8 data = 0;
	
	ROM_Write(Block0 , 0x01 , 'A');
	
	data = ROM_Read(Block0 , 0x01);
	
	LCD_GoTo(0,0);
	LCD_WriteData(data);
	
	    while (1) 
    {
    }
}

