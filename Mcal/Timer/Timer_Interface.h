/*
 * Timer_Interface.h
 *
 *  Created on: Jun 19, 2022
 *      Author: mohm
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#define Timer0_OVF_INT_ID			0
#define Timer0_CMPMATCH_INT_ID		1

#define Timer1_RISING_EDGE_TRIGGER	0
#define Timer1_FALLING_EDGE_TRIGGER	1

void M_Timer0_Void_Init(void);
void M_Timer0_Void_StartTimer(void);
void M_Timer0_Void_StopTimer(void);
void M_Timer0_Void_InterruptEnable(u8 IntID);
void M_Timer0_Void_InterruptDisable(u8 IntID);
void M_Timer0_Void_SetPreload(u8 Copy_U8_Preload);
void M_Timer0_Void_SetCmpMatch(u8 Copy_U8_CmpMatch);
void M_Timer0_Void_SetCallBackFun(void (*PtrFun)(void) ,u8 IntID);
void M_Timer0_Void_SetFastPWM(u8 Copy_U8_DutyCycle);
void M_Timer0_Void_SetPhaseCorrectPWM(u8 Copy_U8_DutyCycle);

/************************************INPUT_CAPTURE_UNIT_(ICU)_IN_TIMER_1*************************************************************************************/

void M_Timer1_Void_Init(void);
void M_Timer1_Void_ICUInit(void);
void M_Timer1_Void_Settrigger(u8 Copy_U8_Trigger);
void M_Timer1_Void_InterruptEnable(void);
void M_Timer1_Void_InterruptDisable(void);
void M_Timer1_Void_SetCallBackFun(void (*PtrFun)(void));
u16 M_Timer1_Void_InputCapture(void);


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
