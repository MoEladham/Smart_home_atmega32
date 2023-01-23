/*
 * GIE_Prog.c
 *
 *  Created on: Jun 20, 2022
 *      Author: mohm
 */

#ifndef MCAL_GIE_GIE_PROG_C_
#define MCAL_GIE_GIE_PROG_C_

#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "GIE_Private.h"
#include "GIE_Config.h"
#include "GIE_Interface.h"

void M_GIE_Void_Enable(void)
{
	//SetBit(SREG_REG,7);
	asm("SEI");		//accessing registers not on the address bus by assembly
}
void M_GIE_Void_Disable(void)
{
	//ClrBit(SREG_REG,7);
	asm("CLI");		//accessing registers not on the address bus by assembly
}
#endif /* MCAL_GIE_GIE_PROG_C_ */
