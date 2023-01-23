/*
 * PushButton.c

 *
 *  Created on: Jun 12, 2022
 *      Author: mohm
 */

#include"PushButton.h"
#include"util/delay.h"

void H_PushButton_Void_PushButtonInit(u8 Local_u8_PushButton)
{
	switch(Local_u8_PushButton)
	{
	case PUSHBUTTON1: M_Dio_Void_PinMode(PUSHBUTTON1_PIN,INPUT);	break;
	case PUSHBUTTON2: M_Dio_Void_PinMode(PUSHBUTTON2_PIN,INPUT);	break;
	case PUSHBUTTON3: M_Dio_Void_PinMode(PUSHBUTTON3_PIN,INPUT);	break;
	case PUSHBUTTON4: M_Dio_Void_PinMode(PUSHBUTTON4_PIN,INPUT);	break;
	default:														break;
	}
}
u8 H_PushButton_Void_PushButtonRead(u8 Local_u8_PushButton)
{
	u8 Local_u8_Reading = RELEASED;
	switch(Local_u8_PushButton)
	{
	case PUSHBUTTON1:
		Local_u8_Reading = M_Dio_U8_PinRead(PUSHBUTTON1_PIN) ;
		if(Local_u8_Reading == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_U8_PinRead(PUSHBUTTON1_PIN) == PRESSED)
			{
				while(M_Dio_U8_PinRead(PUSHBUTTON1_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}
		break;
	case PUSHBUTTON2:
		Local_u8_Reading = M_Dio_U8_PinRead(PUSHBUTTON2_PIN) ;
		if(Local_u8_Reading == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_U8_PinRead(PUSHBUTTON2_PIN) == PRESSED)
			{
				while(M_Dio_U8_PinRead(PUSHBUTTON2_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}
		break;
	case PUSHBUTTON3:
		Local_u8_Reading = M_Dio_U8_PinRead(PUSHBUTTON3_PIN) ;
		if(Local_u8_Reading == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_U8_PinRead(PUSHBUTTON3_PIN) == PRESSED)
			{
				while(M_Dio_U8_PinRead(PUSHBUTTON3_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}
		break;
	case PUSHBUTTON4:
		Local_u8_Reading = M_Dio_U8_PinRead(PUSHBUTTON4_PIN) ;
		if(Local_u8_Reading == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_U8_PinRead(PUSHBUTTON4_PIN) == PRESSED)
			{
				while(M_Dio_U8_PinRead(PUSHBUTTON4_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}
		break;
	default:												break;
	}
	return Local_u8_Reading;
}
