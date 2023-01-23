/*
 * Timer_Prog.c
 *
 *  Created on: Jun 19, 2022
 *      Author: mohm
 */

#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "Timer_Private.h"
#include "Timer_Config.h"
#include "Timer_Interface.h"
#include "avr/interrupt.h"
#include "stdlib.h"

//Syntax of global ptr to fn

static void (*PV_CallBack[2]) (void) = {NULL}; // array of two pointers to function(Over Flow function & Compare Match function)
static void (*PV_ICU_CallBack)(void) = NULL;



void M_Timer0_Void_Init(void)
{
	//step1 : choose mode

#if(TIMER0_MODE == TIMER0_NORMAL_MODE )
	ClrBit(TCCR0_REG,6);
	ClrBit(TCCR0_REG,3);

	//step2 : choose OC0 mode
#if(TIMER0_OC0_PIN_MODE >=0 &&  TIMER0_OC0_PIN_MODE <= 3)

	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	TCCR0_REG |= TIMER0_OC0_PIN_MODE << 4 ;
#else
	#error("Wrong OC0 Mode")
#endif



#elif(TIMER0_MODE == TIMER0_CTC_MODE )
	SetBit(TCCR0_REG,3);
	ClrBit(TCCR0_REG,6);

	//step2 : choose OC0 mode
#if(TIMER0_OC0_PIN_MODE >=0 &&  TIMER0_OC0_PIN_MODE <= 3)

	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE << 4 ;

#else
	#error("Wrong OC0 Mode")
#endif

	//step1 : choose mode
#elif(TIMER0_MODE == TIMER0_FAST_PWM_MODE )
	SetBit(TCCR0_REG,6);
	SetBit(TCCR0_REG,3);

	//step2 : choose OC0 mode
#if(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING || TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_INVERTING)

	TCCR0_REG = (TCCR0_REG & TIMER0_OC0_MODE_MASK) | TIMER0_OC0_PIN_MODE ;
#else
	#error("Wrong OC0 Mode")
#endif

#elif(TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE )
	ClrBit(TCCR0_REG,3);
	SetBit(TCCR0_REG,6);
	//step2 : choose OC0 mode
#if(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING || TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_INVERTING)
	TCCR0_REG = (TCCR0_REG & TIMER0_OC0_MODE_MASK) | TIMER0_OC0_PIN_MODE ;

#else
	#error("Wrong Timer Mode")
#endif

#endif


}
void M_Timer0_Void_StartTimer(void)
{
	//step3 : choose prescaler   //timer starts once the prescaler is defined
#if(TIMER0_PRESCALER >= 0 && TIMER0_PRESCALER <= 7)
	TCCR0_REG = (TCCR0_REG & TIMER0_PRESCALER_MASK) | TIMER0_PRESCALER;
#else
	#error("Wrong prescaler")
#endif
}
void M_Timer0_Void_StopTimer(void)
{
	TCCR0_REG = (TCCR0_REG & TIMER0_PRESCALER_MASK); //Stop counter by clearing prescaler mode pins
}
void M_Timer0_Void_InterruptEnable(u8 IntID)
{
	switch(IntID)
	{
	case Timer0_OVF_INT_ID :
		SetBit(TIMSK_REG,0);
		break;
	case Timer0_CMPMATCH_INT_ID :
		SetBit(TIMSK_REG,1);
		break;
	default:
		break ;
	}

}
void M_Timer0_Void_InterruptDisable(u8 IntID)
{
	switch(IntID)
	{
	case Timer0_OVF_INT_ID :
		ClrBit(TIMSK_REG,0);
		break;
	case Timer0_CMPMATCH_INT_ID :
		ClrBit(TIMSK_REG,1);
		break;
	default:
		break ;
	}
}
void M_Timer0_Void_SetPreload(u8 Copy_U8_Preload)
{
	TCNT0_REG = Copy_U8_Preload;
}
void M_Timer0_Void_SetCmpMatch(u8 Copy_U8_CmpMatch)
{
	OCR0_REG = Copy_U8_CmpMatch;
}
void M_Timer0_Void_SetCallBackFun(void (*PtrFun)(void) ,u8 IntID)
{
	switch(IntID)
	{
	case Timer0_OVF_INT_ID :
		PV_CallBack[Timer0_OVF_INT_ID] = PtrFun;
		break;
	case Timer0_CMPMATCH_INT_ID :
		PV_CallBack[Timer0_CMPMATCH_INT_ID] = PtrFun;
		break;
	default:
		break ;
	}
}

ISR(TIMER0_OVF_vect)
{
	if(PV_CallBack[Timer0_OVF_INT_ID] != NULL)
		PV_CallBack[Timer0_OVF_INT_ID]();
}

ISR(TIMER0_COMP_vect)
{
	if(PV_CallBack[Timer0_CMPMATCH_INT_ID] != NULL )
		PV_CallBack[Timer0_CMPMATCH_INT_ID]();
}


void M_Timer0_Void_SetFastPWM(u8 Copy_U8_DutyCycle)
{
#if (TIMER0_MODE == TIMER0_FAST_PWM_MODE )
	if(Copy_U8_DutyCycle > 100)
		return;
#if(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING)
	OCR0_REG = abs(((Copy_U8_DutyCycle * 256) / 100) - 1);
#elif(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_INVERTING)
	OCR0_REG = abs(255 - ((Copy_U8_DutyCycle * 256) / 100));
#else
	#error("Wrong OC0 Mode")
#endif

#endif
}


void M_Timer0_Void_SetPhaseCorrectPWM(u8 Copy_U8_DutyCycle)
{
#if(TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE)
	if(Copy_U8_DutyCycle > 100)
		return;
#if(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_NON_INVERTING)
	OCR0_REG = (Copy_U8_DutyCycle * 255) / 100;
#elif(TIMER0_OC0_PIN_MODE == TIMER0_OC0_MODE_PWM_INVERTING)
	OCR0_REG = 255 - ((Copy_U8_DutyCycle * 255) / 100);
#else
	#error("Wrong OC0 Mode")
#endif

#endif
}


/************************************INPUT_CAPTURE_UNIT_(ICU)_IN_TIMER_1*************************************************************************************/

void M_Timer1_Void_Init(void)
{
	//set timer1 mode  (normal mode)
	ClrBit(TCCR1A_REG,0);
	ClrBit(TCCR1A_REG,1);
	ClrBit(TCCR1B_REG,3);
	ClrBit(TCCR1B_REG,4);
	//set prescaler
	ClrBit(TCCR1B_REG,0);
	SetBit(TCCR1B_REG,1);
	ClrBit(TCCR1B_REG,2);
}
void M_Timer1_Void_ICUInit(void)
{
	//set ICU trigger on rising edge
	SetBit(TCCR1B_REG,6);
}
void M_Timer1_Void_Settrigger(u8 Copy_U8_Trigger)
{
	switch(Copy_U8_Trigger)
	{
	case Timer1_RISING_EDGE_TRIGGER :
		SetBit(TCCR1B_REG,6);
		break;
	case Timer1_FALLING_EDGE_TRIGGER :
		ClrBit(TCCR1B_REG,6);
		break;
	default:
		break;
	}
}
void M_Timer1_Void_InterruptEnable(void)
{
	SetBit(TIMSK_REG,5);
}
void M_Timer1_Void_InterruptDisable(void)
{
	ClrBit(TIMSK_REG,5);
}
void M_Timer1_Void_SetCallBackFun(void (*PtrFun)(void))
{
	PV_ICU_CallBack = PtrFun;
}
u16 M_Timer1_Void_InputCapture(void)
{
	return ICR_REG ;
}

ISR(TIMER1_CAPT_vect)
{
	if(PV_ICU_CallBack != NULL )
		PV_ICU_CallBack();
}
