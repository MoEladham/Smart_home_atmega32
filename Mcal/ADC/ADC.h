/*
 * ADC.h
 *
 *  Created on: Jun 15, 2022
 *      Author: mohm
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/********************************_INCLUDES_*****************************************************************/
#include<avr/interrupt.h>
#include"Dio.h"
#include"util/delay.h"
#include"ADCCfg.h"


/********************************_MACROS_*****************************************************************/
#define AVCC			1
#define AREF_PIN		2
#define _2V_PIN			3
#define ADC_POL			1
#define ADC_INT			2
/********************************_PROTOTYPES_***************************************************************/

void M_ADC_Void_ADCInit(void);
u16 M_ADC_U16_ADCRead(void);

#endif /* MCAL_ADC_ADC_H_ */
