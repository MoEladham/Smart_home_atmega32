/*
 * Led_Control.c
 *
 *  Created on: Jun 28, 2022
 *      Author: mohm
 */

#include "Led_Control.h"

void led_control (void)
{
	H_Led_Void_LedInit(BLU_LED);
	H_Led_Void_LedInit(RED_LED);
	H_Led_Void_LedInit(GRN_LED);

	u8 push_button=0,press_flag=0,x=1;

	while(1 //x )
	{

		push_button = H_KeyPad_U8_KeyPadRead();

		switch (push_button)
			{
			case '1':H_Led_Void_LedTog(BLU_LED);
					 H_LCD_Void_LCDClr();
					 if(M_Dio_U8_PinRead(Blu_Led_Pin)==1)
					 {
						 H_LCD_Void_LCDWriteString("Blue LED ON");
					 }
					 else
					 {
						 H_LCD_Void_LCDWriteString("Blue LED OFF");
					 }

					 _delay_ms(1000);
					 H_LCD_Void_LCDClr();
			break;
			case '2':H_Led_Void_LedTog(GRN_LED);
					 H_LCD_Void_LCDClr();
					 if(M_Dio_U8_PinRead(Grn_Led_Pin)==1)
					 {
						 H_LCD_Void_LCDWriteString("GRN LED ON");
					 }
					 else
					 {
						 H_LCD_Void_LCDWriteString("GRN LED OFF");
					 }
					 _delay_ms(1000);
					 H_LCD_Void_LCDClr();
					 break;
			case '3':H_Led_Void_LedTog(RED_LED);
					 H_LCD_Void_LCDClr();
					 if(M_Dio_U8_PinRead(Red_Led_Pin)==1)
					 {
						 H_LCD_Void_LCDWriteString("RED LED ON");
					 }
					 else
					 {
						 H_LCD_Void_LCDWriteString("RED LED OFF");
					 }
					 _delay_ms(1000);
					 H_LCD_Void_LCDClr();
			break;
			default:							break;
			}
			push_button=0;
			break;
			//x=0;

	}
}
//}

