
#include"Relay.h"

void H_Relay_Void_RelayInit(u8 Local_u8_RelayNum)
{
	switch(Local_u8_RelayNum)
	{
		case RELAY1:
			M_Dio_Void_PinMode(Relay1_Pin,OUTPUT);		break;
		case RELAY2:
			M_Dio_Void_PinMode(Relay2_Pin,OUTPUT);		break;
		default:									break;
	}
}
void H_Relay_Void_RelayOn(u8 Local_u8_RelayNum)
{
	switch(Local_u8_RelayNum)
	{
		case RELAY1:
			M_Dio_Void_PinWrite(Relay1_Pin,HIGH);		break;
		case RELAY2:
			M_Dio_Void_PinWrite(Relay2_Pin,HIGH);		break;
		default:									break;
	}
}
void H_Relay_Void_RelayOff(u8 Local_u8_RelayNum)
{
	switch(Local_u8_RelayNum)
	{
		case RELAY1:
			M_Dio_Void_PinWrite(Relay1_Pin,LOW);		break;
		case RELAY2:
			M_Dio_Void_PinWrite(Relay2_Pin,LOW);		break;
		default:									break;
	}
}
void H_Relay_Void_RelayTog(u8 Local_u8_RelayNum)
{
	switch(Local_u8_RelayNum)
	{
		case RELAY1:
			M_Dio_Void_PinTog(Relay1_Pin);		break;
		case RELAY2:
			M_Dio_Void_PinTog(Relay2_Pin );		break;
		default:							break;
	}
}
