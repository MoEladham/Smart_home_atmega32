/*
 * main.c
 *
 *  Created on: 07/06/2022
 *      Author: mohm
 */

#include"Std.h"
#include"GIE_Interface.h"
#include"Led.h"
#include"Timer_Interface.h"
#include"LCD.h"
#include "KeyPad.h"
#include "PassWord.h"
#include "Led_Control.h"
#include "Fan_control.h"

/*************************************************TIMER0_PROJECT******************************************************************************/


int main()
{
	H_LCD_Void_LCDInit();


	H_KeyPad_Void_KeyPadInit();


	PassWord();
	M_Timer0_Void_Init();
	M_Dio_Void_PinMode(PB3_PIN,OUTPUT);
	M_Timer0_Void_StartTimer();
	H_SSD_Void_SSDInit();
	M_ADC_Void_ADCInit();

	while(1)
		{
		led_control();
		Fan_Control();
		}
}

