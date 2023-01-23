

#include"Buzzer.h"

 void H_Buzzer_Void_BuzzerInit(void)
 {
	 M_Dio_Void_PinMode(Buzzer_Pin,OUTPUT);
 }


 void H_Buzzer_Void_BuzzerOn(void)
 {
	M_Dio_Void_PinWrite(Buzzer_Pin,HIGH);
 }

 void H_Buzzer_Void_BuzzerOff(void)
 {
	M_Dio_Void_PinWrite(Buzzer_Pin,LOW);
 }
 void H_Buzzer_Void_BuzzerOnce(void)
 {
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
 }
 void H_Buzzer_Void_BuzzerTwice(void)
 {
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
	 _delay_ms(BUZZER_OFFDELAY_TIME);
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
 }
 void H_Buzzer_Void_BuzzerTriple(void)
 {
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
	 _delay_ms(BUZZER_OFFDELAY_TIME);
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
	 _delay_ms(BUZZER_OFFDELAY_TIME);
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
 }
 void H_Buzzer_Void_BuzzerLong(void)
 {
	 H_Buzzer_Void_BuzzerOn();
	 _delay_ms(10*BUZZER_ONDELAY_TIME);
	 H_Buzzer_Void_BuzzerOff();
 }
