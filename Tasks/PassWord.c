/*
 * PassWord.c
 *
 *  Created on: Jun 28, 2022
 *      Author: mohm
 */

#include "PassWord.h"
void PassWord (void)
{
	u8 pass[4]="3377", pass_check[4]={0},pass_flag=0,pass_temp=0,x=1;
	H_LCD_Void_LCDWriteString("Enter Password");

	while (1)
		{


			if ((pass[0]==pass_check[0])&&(pass[1]==pass_check[1])&&(pass[2]==pass_check[2])&&(pass[3]==pass_check[3]) &&  pass_flag==4 )
			
			{
				H_Led_Void_LedInit(BLU_LED);
				H_Led_Void_LedInit(GRN_LED);
				H_Led_Void_LedInit(RED_LED);
				H_LCD_Void_LCDClr();
				H_LCD_Void_LCDWriteString("Welcome Sir");
				_delay_ms(1000);
				H_LCD_Void_LCDClr();
				H_LCD_Void_LCDWriteString("LEDS ON");
				H_Led_Void_LedOn(BLU_LED);
				H_Led_Void_LedOn(GRN_LED);
				H_Led_Void_LedOn(RED_LED);
				_delay_ms(1000);
				H_LCD_Void_LCDClr();
				H_LCD_Void_LCDWriteString("LEDS OFF");
				H_Led_Void_LedOff(BLU_LED);
				H_Led_Void_LedOff(GRN_LED);
				H_Led_Void_LedOff(RED_LED);
				_delay_ms(1000);




				break;
			}
			else if (((pass[0]!=pass_check[0])||(pass[1]!=pass_check[1])||(pass[2]!=pass_check[2])||(pass[3]!=pass_check[3])) && pass_flag==4)
			{

				static u8 pass_attempt=0;
				H_LCD_Void_LCDClr();
				H_LCD_Void_LCDWriteString("Wrong Password");
				H_LCD_Void_LCDGoto(1,0);
				H_LCD_Void_LCDWriteString("Try again");
				pass_flag=0;
				for(int j=0;j<4;j++)
				{
					pass_check[j]=0;
				}
				_delay_ms(1000);

				pass_attempt++;
				while (pass_attempt==3)
				{
					H_LCD_Void_LCDClr();
					H_LCD_Void_LCDWriteString("w8 1 min");
					_delay_ms(1000);
					for (int x =0;x<60;x++)
					{
						H_LCD_Void_LCDClr();
						H_Lcd_Void_WriteDecimal(x);
						_delay_ms(1000);
					}
					pass_attempt=0;
					H_LCD_Void_LCDClr();
					H_LCD_Void_LCDWriteString("Enter Password");
					break;
				}
				
				H_LCD_Void_LCDClr();
				H_LCD_Void_LCDWriteString("Enter Password");
			}

			for(int i = 0; i < 4; i++)
					{
					

						while(1)
						{

							pass_check[i] = H_KeyPad_U8_KeyPadRead();

							if(pass_check[i] !=0)
							{
								H_LCD_Void_LCDClr();
								H_LCD_Void_LCDWriteString(pass_check);
								pass_flag++;
								break;
								
							}

						}
					}

}
}
