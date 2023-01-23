/*
 * Led.c
 *
 *  Created on: Jun 8, 2022
 *      Author: mohm
 */

#include"Led.h"



void H_Led_Void_LedInit(u8 Local_Led_Pin)
{
	switch(Local_Led_Pin)
	{
	case BLU_LED:M_Dio_Void_PinMode(Blu_Led_Pin,OUTPUT);	break;
	case GRN_LED:M_Dio_Void_PinMode(Grn_Led_Pin,OUTPUT); 	break;
	case RED_LED:M_Dio_Void_PinMode(Red_Led_Pin,OUTPUT);	break;
	default:												break;
	}
}

void H_Led_Void_LedOn(u8 Local_Led_Pin)
{
	switch(Local_Led_Pin)
	{
	case BLU_LED:M_Dio_Void_PinWrite(Blu_Led_Pin,HIGH);	break;
	case GRN_LED:M_Dio_Void_PinWrite(Grn_Led_Pin,HIGH);	break;
	case RED_LED:M_Dio_Void_PinWrite(Red_Led_Pin,HIGH);	break;
	default:											break;
	}
}
void H_Led_Void_LedOff(u8 Local_Led_Pin)
{
	switch(Local_Led_Pin)
	{
	case BLU_LED:M_Dio_Void_PinWrite(Blu_Led_Pin,LOW);	break;
	case GRN_LED:M_Dio_Void_PinWrite(Grn_Led_Pin,LOW); 	break;
	case RED_LED:M_Dio_Void_PinWrite(Red_Led_Pin,LOW);	break;
	default:											break;
	}
}

void H_Led_Void_LedBlink(u8 Local_Led_Pin)
{
		 _delay_ms(LED_DELAY_TIME);
		H_Led_Void_LedOn(Local_Led_Pin);
		 _delay_ms(LED_DELAY_TIME);
		H_Led_Void_LedOff(Local_Led_Pin);
}


void H_Led_Void_LedTog(u8 Local_Led_Pin)
{
	switch(Local_Led_Pin)
	{
	case BLU_LED:M_Dio_Void_PinTog(Blu_Led_Pin);	break;
	case RED_LED:M_Dio_Void_PinTog(Red_Led_Pin);	break;
	case GRN_LED:M_Dio_Void_PinTog(Grn_Led_Pin);	break;
	default:										break;
	}
}
