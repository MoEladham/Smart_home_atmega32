/*
 * KeyPad.h
 *
 *  Created on: Jun 14, 2022
 *      Author: mohm
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_


/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"KeyPadCfg.h"

/********************************_MACROS_*****************************************************************/

#define PRESSED 				0
#define RELEASED				1

/********************************_PROTOTYPES_***************************************************************/

void H_KeyPad_Void_KeyPadInit(void);
u8 H_KeyPad_U8_KeyPadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
