/*
 * Led.h
 *
 *  Created on: Jun 8, 2022
 *      Author: mohm
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"LedCfg.h"

/********************************_MACROS_*****************************************************************/
#define	BLU_LED			1
#define	GRN_LED			2
#define	RED_LED			3
/********************************_PROTOTYPES_***************************************************************/

void H_Led_Void_LedInit(u8);
void H_Led_Void_LedOn(u8);
void H_Led_Void_LedOff(u8);
void H_Led_Void_LedTog(u8);
void H_Led_Void_LedBlink(u8);

#endif /* HAL_LED_LED_H_ */
