/*
 * KEyPad.c
 *
 *  Created on: Jun 14, 2022
 *      Author: mohm
 */

#include"KeyPad.h"

void H_KeyPad_Void_KeyPadInit(void)
{
	M_Dio_Void_PinMode(KEYPAD_R0_PIN,OUTPUT);
	M_Dio_Void_PinMode(KEYPAD_R1_PIN,OUTPUT);
	M_Dio_Void_PinMode(KEYPAD_R2_PIN,OUTPUT);
	M_Dio_Void_PinMode(KEYPAD_R3_PIN,OUTPUT);

	M_Dio_Void_PinMode(KEYPAD_C0_PIN,INPUT);
	M_Dio_Void_PinMode(KEYPAD_C1_PIN,INPUT);
	M_Dio_Void_PinMode(KEYPAD_C2_PIN,INPUT);
	M_Dio_Void_PinMode(KEYPAD_C3_PIN,INPUT);

	M_Dio_Void_PinWrite(KEYPAD_R0_PIN,HIGH);
	M_Dio_Void_PinWrite(KEYPAD_R1_PIN,HIGH);
	M_Dio_Void_PinWrite(KEYPAD_R2_PIN,HIGH);
	M_Dio_Void_PinWrite(KEYPAD_R3_PIN,HIGH);
}
u8 H_KeyPad_U8_KeyPadRead(void)
{
#if KEY_PAD_MODE == CALCULATOR
	u8 Local_u8_Arr [4][4] = {{'1','2','3','+'},
							  {'4','5','6','-'},
	 	 	 	 	 	 	  {'7','8','9','*'},
	 	 	 	 	 	 	  {'.','0','=','/'}};
#elif KEY_PAD_MODE == KEYBOARD
	u8 Local_u8_Arr [4][4] = {{'1','2','3','A'},
							  {'4','5','6','B'},
	 	 	 	 	 	 	  {'7','8','9','C'},
	 	 	 	 	 	 	  {'*','0','#','D'}};
#endif
	u8 Local_u8_ColCounter = 0;
	u8 Local_u8_RowCounter = 0;
	u8 Local_u8_Reading = 0;
	for(Local_u8_RowCounter = KEYPAD_R0_PIN ; Local_u8_RowCounter <= KEYPAD_R3_PIN ; Local_u8_RowCounter++)
	{
		M_Dio_Void_PinWrite(Local_u8_RowCounter,LOW);
		for(Local_u8_ColCounter = KEYPAD_C0_PIN ; Local_u8_ColCounter <= KEYPAD_C3_PIN ; Local_u8_ColCounter++ )
		{
			if(M_Dio_U8_PinRead(Local_u8_ColCounter) == PRESSED)
			{
				_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
				if(M_Dio_U8_PinRead(Local_u8_ColCounter) == PRESSED)
				{
					while(M_Dio_U8_PinRead(Local_u8_ColCounter) == PRESSED);
					Local_u8_Reading = Local_u8_Arr[Local_u8_RowCounter - KEYPAD_R0_PIN][Local_u8_ColCounter -KEYPAD_C0_PIN ];
				}
			}
		}
		M_Dio_Void_PinWrite(Local_u8_RowCounter,HIGH);
	}
	return Local_u8_Reading;
}
