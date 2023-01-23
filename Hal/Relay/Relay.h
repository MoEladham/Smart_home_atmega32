

#ifndef HAL_RELAY_RELAY_H_
#define HAL_RELAY_RELAY_H_


/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"RelayCfg.h"

/********************************_MACROS_*****************************************************************/
#define	RELAY1			1
#define	RELAY2			2

/********************************_PROTOTYPES_***************************************************************/

void H_Relay_Void_RelayOn(u8);
void H_Relay_Void_RelayOff(u8);
void H_Relay_Void_RelayInit(u8);
void H_Relay_Void_RelayTog(u8);


#endif /* HAL_RELAY_RELAY_H_ */
