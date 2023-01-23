/*
 * SSDCfg.h
 *
 *  Created on: Jun 9, 2022
 *      Author: mohm
 */

#ifndef HAL_SSD_SSDCFG_H_
#define HAL_SSD_SSDCFG_H_

/*********************************_SELECT_SSD_LED_PIN_***************************************/
#define SSD_LED_A				PA1_PIN
#define SSD_LED_B				PA2_PIN
#define SSD_LED_C				PA3_PIN
#define SSD_LED_D				PA4_PIN
#define SSD_LED_E				PA5_PIN
#define SSD_LED_F				PA6_PIN
#define SSD_LED_G				PA7_PIN
#define SSD_LED_DOT				PB0_PIN
#define SSD_EN_1				PC6_PIN
#define SSD_EN_2				PC7_PIN

/*********************************_SELECT_F_CPU_******************************************/
#define F_CPU					16000000UL
/*********************************_SELECT_LED_DELAY_TIME_********************************/
#define LED_DELAY_TIME			500

#endif /* HAL_SSD_SSDCFG_H_ */
