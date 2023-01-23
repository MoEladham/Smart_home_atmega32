/*
 * ExtInt.h
 *
 *  Created on: Jun 14, 2022
 *      Author: mohm
 */

#ifndef MCAL_EXTINT_EXTINT_H_
#define MCAL_EXTINT_EXTINT_H_

/********************************_INCLUDES_*****************************************************************/
#include<avr/interrupt.h>
#include"util/delay.h"
#include"Dio.h"
#include"ExtIntCfg.h"


/********************************_MACROS_*****************************************************************/
#define FALLING_EDGE			1
#define RISING_EDGE				2
#define LOGICAL_CHANGE			3
#define LOW_LEVEL				4
/********************************_PROTOTYPES_***************************************************************/

void M_ExtInt_Void_ExtInt0Init();
void M_ExtInt_Void_ExtInt0SetCallBack(void (*)(void));

#endif /* MCAL_EXTINT_EXTINT_H_ */
