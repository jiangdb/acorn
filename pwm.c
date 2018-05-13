#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"

//开启pwm函数
void open_pwm()
{
	if(if_pwm)							//当if_pwm为1时，执行else前的语句；否则执行else后的语句
	{
		if (B_Time500ms)				//当B_Time500ms标志为1时打开蜂鸣器                          
		{                                                                                           
			if (!B_pwm2)	            //打开pwm2时只能开启一次，以保证pwm波形的稳定，用B_pwm2控制 
			{                           //  		若为1则说明已经开启pwm，则不操作直接退出        
				B_pwm2=1;
				TM2CON=0x00;
				TM2RH=0;
				TM2INH=0;
				TM2R= CONST_PWM2_TMR;	//100,占空比	
				TM2IN=CONST_PWM2_TMIN;	//249,频率4kHz
				TM2CON=0xa1;			//开启pwm2，作蜂鸣器输出
			}
		}
		else
		{
			TM2CON=0x00;      			//当B_Time500ms标志为0时关pwm2	
			TM2R=0;           
			TM2IN=0;          
			B_pwm2=0;         			
		}
	}
	else
	{
		if(!B_pwm3)       				//打开互补pwm3时只能开启一次，以保证pwm波形的稳定，用B_pwm3控制
		{                               //		若为1则说明已经开启pwm，则不操作直接退出               
			B_pwm3=1;     
			TM3CON=0x00;  
			TM3RH=0;       
			TM3INH=0;     
			TM3R=CONST_PWM3_TMR;		//20,占空比  
			TM3IN=CONST_PWM3_TMIN;		//79,频率200kHz
			TM3CON2=0X27; 				//设置死区时间                                  
			TM3CON=0X80;				//开pwm3                                        
			t10s_count=0;				//清30s计时计数器，开始30s计时，30s后关闭pwm    
		}		
	}   
		
}

//white led
void open_pwm2()
{
	if (!B_pwm2)	            //打开pwm2时只能开启一次，以保证pwm波形的稳定，用B_pwm2控制 
	{                           //  		若为1则说明已经开启pwm，则不操作直接退出        
		B_pwm2=1;
		TM2CON=0x00;
		TM2RH=0;
		TM2INH=0;
		TM2R= CONST_PWM2_TMR;	//100,占空比	
		TM2IN=CONST_PWM2_TMIN;	//249,频率4kHz
		TM2CON=0xa1;			//开启pwm2，作蜂鸣器输出
	}
}	
			
        
        
        
        
        