#include "CSU8RP3216.h"

#ifndef  	_define_data_h
#define 	_define_data_h 1

#define WORK_MODE_SHUTDOWN		0	
#define WORK_MODE_HEATING		1	
#define WORK_MODE_CHARGING		2	
#define WORK_MODE_DISCHARGING	3	

extern unsigned char work_mode;

extern sbit if_key_press;
extern sbit if_usb_plug;
extern sbit if_adapter_plug;
extern sbit heating_low;
extern sbit B_low_battery_shutdown;
extern sbit B_low_battery_warning;






#define led3	 PT3_0
#define led      PT1_4
#define led1     PT1_5
#define led2     PT3_2

//extern const unsigned int a[];

extern unsigned int CurTabData;			
extern unsigned int AdData;
extern unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

extern volatile sbit led;
extern volatile sbit led1;
extern volatile sbit led2;
extern sbit if_adc;
extern sbit B_Sleep;
extern sbit B_Time500ms;
extern sbit B_200ms;
extern sbit B_urr;
extern sbit B_urt;
extern sbit B_send_ok;

extern sbit B_pwm2;
extern sbit B_pwm3;
extern sbit if_pwm;

extern unsigned char t10s_count;
extern unsigned char t200ms_count;
extern unsigned char t1s_count;

extern unsigned char R_flag;
extern unsigned char R_200ms_cnt;

#define CONST_PWM2_TMR 125	
#define CONST_PWM2_TMIN 249
#define CONST_PWM3_TMR 20
#define CONST_PWM3_TMIN 79
#define CONST_UART_SEND1 0X48
#define CONST_UART_SEND2 0X69
#define CONST_UART_RE 0X0D

#endif 
