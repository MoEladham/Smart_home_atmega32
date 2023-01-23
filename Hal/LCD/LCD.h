/*
 * LCD.h
 *
 *  Created on: Jun 13, 2022
 *      Author: mohm
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"LCDCfg.h"
#include"util/delay.h"

/********************************_MACROS_*****************************************************************/

#define _8_BIT_MODE_COMMAND			0x38
#define _4_BIT_MODE_COMMAND_1		0x33
#define _4_BIT_MODE_COMMAND_2		0x32
#define _4_BIT_MODE_COMMAND_3		0x28
#define DISPLAY_ON_CURSOR_OFF		0x0C
#define DISPLAY_ON_CURSOR_ON		0x0E
#define LCD_RETURN_HOME				0x02
#define LCD_CLEAR_SCREEN			0x01
#define _4_BIT_MODE					4
#define	_8_BIT_MODE					8
#define LCD_1st_Row_command			0x80
#define LCD_2nd_Row_command			0xC0

/********************************_PROTOTYPES_***************************************************************/

void H_LCD_Void_LCDInit(void);
void H_LCD_Void_LCDWriteCharacter(u8);
void H_LCD_Void_LCDWriteCommand(u8);
void H_LCD_Void_LCDWriteString(u8*);
void H_LCD_Void_LCDWriteNumber(f64);
void H_LCD_Void_LCDGoto(u8,u8);
void H_LCD_Void_LCDClr(void);
void H_Lcd_Void_WriteDecimal(f32);


#endif /* HAL_LCD_LCD_H_ */
