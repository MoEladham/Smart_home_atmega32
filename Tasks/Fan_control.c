/*
 * Fan_control.c
 *
 *  Created on: Jun 28, 2022
 *      Author: mohm
 */

#include "Fan_control.h"
/* Fan Control fnc */
void Fan_Control (void)
{
	// 
	static u16 x=0;
	u16 temp=0;
	static u32 z=0;
	z++;

	if(z==2000)
	{
	temp=H_KeyPad_U8_KeyPadRead();
	x=M_ADC_U16_ADCRead();
	H_LCD_Void_LCDClr();
	H_LCD_Void_LCDWriteString("ADC=");
	H_Lcd_Void_WriteDecimal(x);
	temp=0;
	z=0;
	}
	if(x>=0 && x<200)
	{
		M_Timer0_Void_SetFastPWM(0);
	}
	else if(x>=200 && x<250)
	{
		M_Timer0_Void_SetFastPWM(25);
	}
	else if (x>=250 && x<1023)
	{
		M_Timer0_Void_SetFastPWM(80);
	}

}
