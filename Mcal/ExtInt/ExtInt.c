/*
 * ExtInt.c
 *
 *  Created on: Jun 14, 2022
 *      Author: mohm
 */

#include"ExtInt.h"


void (*ExtInt_CallBack)(void) = NULL;				//global pointer to function for ISR
void M_ExtInt_Void_ExtInt0Init()
{
#if SENSE_CONTROL == FALLING_EDGE
	//to select falling edge
	ClrBit(MCUCR_REG,0);
	SetBit(MCUCR_REG,1);
#elif SENSE_CONTROL == RISING_EDGE
	//to select rising edge
	SetBit(MCUCR_REG,0);
	SetBit(MCUCR_REG,1);
#elif SENSE_CONTROL == LOGICAL_CHANGE
	//to select logical change
	ClrBit(MCUCR_REG,1);
	SetBit(MCUCR_REG,0);
#elif SENSE_CONTROL == LOW_LEVEL
	//to select low level
	ClrBit(MCUCR_REG,0);
	ClrBit(MCUCR_REG,1);
#endif

	//to enable local interrupt for int0
	SetBit(GICR_REG,6);
	//to enable global interrupt
	SetBit(SREG_REG,7);
}

void M_ExtInt_Void_ExtInt0SetCallBack(void (*Local_ptr)(void))      //this is a callback function to avoid accessing the ISR by user
{
	ExtInt_CallBack = Local_ptr;
}

ISR(INT0_vect)
{
	ExtInt_CallBack();
}
