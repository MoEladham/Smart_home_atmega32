/*
 * SSD.h
 *
 *  Created on: Jun 9, 2022
 *      Author: mohm
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_


/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"SSDCfg.h"
#include"util/delay.h"

/********************************_MACROS_*****************************************************************/


/********************************_PROTOTYPES_***************************************************************/

void H_SSD_Void_SSDInit(void);
void H_SSD_Void_SSDDisplay(u8);
void H_SSD_Void_SSDCountUp(u8);
void H_SSD_Void_SSDCountDown(u8);

#endif /* HAL_SSD_SSD_H_ */
