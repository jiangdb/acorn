#include "CSU8RP3216.h"

#ifndef  	_define_data_h
#define 	_define_data_h 1

/**
 * defines
 */
//heating
#define HEAT_ENABLE				(PT5_2 = 1)
#define HEAT_DISABLE			(PT5_2 = 0)

//led
#define blue_led				PT3_5
#define red_led					PT3_6
#define white_led				PT5_0

//work mode
#define WORK_MODE_SHUTDOWN		0	
#define WORK_MODE_HEATING		1	
#define WORK_MODE_CHARGING		2	
#define WORK_MODE_DISCHARGING	3

//key event
#define KEY_RELEASED			0
#define KEY_PRESSED				1	
#define KEY_HOLD				2

/**
 * Bit variable
 */
//sleep
extern sbit B_Sleep;

//timer
extern sbit B_52ms;
extern sbit B_500ms;
extern sbit B_2s;
extern sbit B_10s;

//battery
extern sbit B_low_battery_shutdown;
extern sbit B_low_battery_warning;

//key
extern sbit B_key_pressed;
extern sbit B_key_waitfor_release;

//heating
extern sbit B_heat_level_low;
extern sbit B_heating;
	
/**
 * int variable
 */
 //work mode
extern unsigned char work_mode;

//adc
extern unsigned int CurTabData;			
extern unsigned int AdData;
extern unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

//timer count
extern unsigned char t52ms_count;
extern unsigned char t500ms_count;
extern unsigned char t1s_count;
extern unsigned int t2s_count;
extern unsigned char t10s_count;

extern int test;

#endif 
