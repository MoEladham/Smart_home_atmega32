/*
 * Timer_Private.h
 *
 *  Created on: Jun 19, 2022
 *      Author: mohm
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

//************************PRESCALER_MODES**********************************/
#define TIMER0_PRESCALER_TIMER_STOP							0
#define TIMER0_PRESCALER_NO_PRESCALER						1
#define TIMER0_PRESCALER_8									2
#define TIMER0_PRESCALER_64									3
#define TIMER0_PRESCALER_256								4
#define TIMER0_PRESCALER_1024								5
#define TIMER0_PRESCALER_EXT_CLK_FALLING_EDGE				6
#define TIMER0_PRESCALER_EXT_CLK_RISING_EDGE				7

#define TIMER0_PRESCALER_MASK								0b11111000

//************************TIMER_MODES**********************************/

#define TIMER0_NORMAL_MODE									0
#define TIMER0_CTC_MODE										1
#define TIMER0_FAST_PWM_MODE								2
#define TIMER0_PHASE_CORRECT_PWM_MODE						3

//************************OC0_PIN_MODES**********************************/

#define TIMER0_OC0_MODE_DISCONNECTED						0
#define TIMER0_OC0_MODE_TOGGLE								1
#define TIMER0_OC0_MODE_CLER								2
#define TIMER0_OC0_MODE_SET									3

#define TIMER0_OC0_MODE_PWM_NON_INVERTING				0b00100000
#define TIMER0_OC0_MODE_PWM_INVERTING					0b00110000



#define TIMER0_OC0_MODE_MASK								0b11001111

#define MTCCR0_REG	*(volatile TCCRO_REG_t*)0x53

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
