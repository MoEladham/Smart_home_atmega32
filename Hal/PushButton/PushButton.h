/*
 * PushButton.h
 *
 *  Created on: Jun 12, 2022
 *      Author: mohm
 */


#ifndef HAL_PUSHBUTTON_PUSHBUTTON_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_H_

/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"PushButtonCfg.h"

/********************************_MACROS_*****************************************************************/
#define PUSHBUTTON1				1
#define PUSHBUTTON2				2
#define PUSHBUTTON3				3
#define PUSHBUTTON4				4


#if PUSHBUTTON_MODE == ACTIVE_LOW
#define PRESSED 				0
#define RELEASED				1
#elif PUSHBUTTON_MODE == ACTIVE_HIGH
#define PRESSED 				1
#define RELEASED				0
#endif


/********************************_PROTOTYPES_***************************************************************/

void H_PushButton_Void_PushButtonInit(u8);
u8 H_PushButton_Void_PushButtonRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_H_ */
