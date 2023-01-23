/*
 * LCD.c
 *
 *  Created on: Jun 13, 2022
 *      Author: mohm
 */

#include"LCD.h"


void H_LCD_Void_LCDInit(void)
{
#if LCD_MODE == _8_BIT_MODE

	M_Dio_Void_PinMode(LCD_DATA0_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA1_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA2_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA3_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA7_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_RS_PIN,OUTPUT);
	_delay_ms(1000);
	H_LCD_Void_LCDWriteCommand(_8_BIT_MODE_COMMAND);

#elif LCD_MODE == _4_BIT_MODE

	M_Dio_Void_PinMode(LCD_DATA4_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA5_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA6_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_DATA7_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_RS_PIN,OUTPUT);
	_delay_ms(1000);
	H_LCD_Void_LCDWriteCommand(_4_BIT_MODE_COMMAND_1);
	H_LCD_Void_LCDWriteCommand(_4_BIT_MODE_COMMAND_2);
	H_LCD_Void_LCDWriteCommand(_4_BIT_MODE_COMMAND_3);
#endif
	H_LCD_Void_LCDWriteCommand(DISPLAY_ON_CURSOR_OFF);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_SCREEN);
	_delay_ms(5);
}
void H_LCD_Void_LCDWriteCharacter(u8 Local_u8_Character)
{
#if LCD_MODE == _8_BIT_MODE

	M_Dio_Void_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = Local_u8_Character;
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);

#elif LCD_MODE == _4_BIT_MODE

	M_Dio_Void_PinWrite(LCD_RS_PIN,HIGH);
	LCD_DATA_PORT = ((Local_u8_Character >> 1) & 0b01111000 ) | (LCD_DATA_PORT & 0b10000111);
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(1);
	LCD_DATA_PORT = ((Local_u8_Character << 3) & 0b01111000 ) | (LCD_DATA_PORT & 0b10000111);
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);

#endif
	_delay_ms(5);
}
void H_LCD_Void_LCDWriteCommand(u8 Local_u8_Command)
{
#if LCD_MODE == _8_BIT_MODE

	M_Dio_Void_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = Local_u8_Command;
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);

#elif LCD_MODE == _4_BIT_MODE

	M_Dio_Void_PinWrite(LCD_RS_PIN,LOW);
	LCD_DATA_PORT = ((Local_u8_Command >> 1) & 0b01111000 ) | (LCD_DATA_PORT & 0b10000111);
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(1);
	LCD_DATA_PORT = ((Local_u8_Command << 3) & 0b01111000 ) | (LCD_DATA_PORT & 0b10000111);
	M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);

#endif
	_delay_ms(5);
}


void H_LCD_Void_LCDWriteString(u8* Local_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8_Ptr[Local_u8_Counter] != '\0')
	{
	H_LCD_Void_LCDWriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
	Local_u8_Counter++;
	}
	_delay_ms(5);
}
void H_LCD_Void_LCDWriteNumber(f64 Local_f64_Number)
{
	u8 Local_u8_IntArr[10] = {0};
	u8 Local_u8_FloatArr[5] = {0};
	s8 Local_s8_Counter1 = 0;
	s8 Local_s8_Counter2 = 0;
	f64 Local_f64_FloatSector = 0;
	s32 Local_s32_IntSector = 0;
	if(Local_f64_Number == 0)H_LCD_Void_LCDWriteCharacter(48);
	if(Local_f64_Number < 0)
	{
		H_LCD_Void_LCDWriteCharacter('-');
		Local_f64_Number = Local_f64_Number * (-1);
	}
	Local_s32_IntSector = Local_f64_Number;
	Local_f64_FloatSector = Local_f64_Number - Local_s32_IntSector;

	/*************************************EXTRACTING_INTEGER_SECTION************************************/
	while(Local_s32_IntSector)
	{
	Local_u8_IntArr[Local_s8_Counter1] = Local_s32_IntSector % 10;
	Local_s32_IntSector = Local_s32_IntSector / 10;
	Local_s8_Counter1++;
	}
	Local_s8_Counter1--;
	/*************************************EXTRACTING_FLOAT_SECTION************************************/
	while(Local_s8_Counter2 < 5)
	{

	Local_f64_FloatSector = Local_f64_FloatSector * 10;
	Local_u8_FloatArr[Local_s8_Counter2] = Local_f64_FloatSector;
	Local_s8_Counter2++;
	Local_f64_FloatSector = (Local_f64_FloatSector - (u8)Local_f64_FloatSector);
	}
	Local_s8_Counter2--;

	/*************************************WRITING_INTEGER_SECTION************************************/
	while(Local_s8_Counter1 >= 0 )
	{
	H_LCD_Void_LCDWriteCharacter(Local_u8_IntArr[Local_s8_Counter1] + 48);
	Local_s8_Counter1--;
	}
	/*************************************WRITING_FLOAT_SECTION************************************/
	H_LCD_Void_LCDWriteCharacter('.');
	Local_s8_Counter2 = 0;
	while(Local_s8_Counter2 < 4 )
	{
	H_LCD_Void_LCDWriteCharacter(Local_u8_FloatArr[Local_s8_Counter2] + 48);
	Local_s8_Counter2++;
	}
}


void H_LCD_Void_LCDGoto(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_Arr[2] = {LCD_1st_Row_command , LCD_2nd_Row_command};
	H_LCD_Void_LCDWriteCommand(Local_u8_Arr[Local_u8_Row] + Local_u8_Col);
}


void H_LCD_Void_LCDClr(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_SCREEN);
	_delay_ms(5);
}
void H_Lcd_Void_WriteDecimal(f32 Local_f32_float)
{
	u8 Local_u8_arr[4] = {0};
	u8 Local_u8_arrf[4]={0};
	u16 local_u16_integer= (u16)Local_f32_float;
	u16 Local_u16_fraction= (Local_f32_float-local_u16_integer)*10000;
	s8 Local_s8_Counter = 0;
	s8 Local_s8_Counterf = 0;
	if(Local_f32_float<0)
	{
		H_LCD_Void_LCDWriteCharacter('-');
		Local_f32_float=Local_f32_float*(-1);
	}
	if (Local_u16_fraction==0)
	{
		while(local_u16_integer!= 0)
			{

				Local_u8_arr[Local_s8_Counter] = local_u16_integer%10;
				local_u16_integer = local_u16_integer/10;
				Local_s8_Counter++;
			}
				Local_s8_Counter--;
			do
			{
				H_LCD_Void_LCDWriteCharacter(Local_u8_arr[Local_s8_Counter]+48);
				Local_s8_Counter--;

			}while(Local_s8_Counter>=0);
	}
	else
	{
	while(local_u16_integer != 0)
	{

		Local_u8_arr[Local_s8_Counter] = local_u16_integer % 10;
		//Local_f32_arr[Local_s8_Counter]= Local_u16_fraction % 10;
		local_u16_integer = local_u16_integer/10;
		Local_s8_Counter++;
	}
	//Local_s8_Counter=0;
	while(Local_u16_fraction != 0)
	{

		//Local_u8_arr[Local_s8_Counter] = local_u8_integer % 10;
		Local_u8_arrf[Local_s8_Counterf]= Local_u16_fraction % 10;
		Local_u16_fraction = Local_u16_fraction/10;
		Local_s8_Counterf++;
	}
	Local_s8_Counter--;
	do
	{
		H_LCD_Void_LCDWriteCharacter(Local_u8_arr[Local_s8_Counter]+48);
		Local_s8_Counter--;

	}while(Local_s8_Counter>=0);
	H_LCD_Void_LCDWriteCharacter('.');
	Local_s8_Counterf--;
	do
		{
			H_LCD_Void_LCDWriteCharacter(Local_u8_arrf[Local_s8_Counterf]+48);
			Local_s8_Counterf--;

		}while(Local_s8_Counterf>=0);
}

}
