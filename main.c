//============================================
// filename: main.c
// chip    : CSU8RP3216
// author  :
// date    : 2018-05-12
// clk=4 Mhz
// v1.0

//IO口配置:
//pt1.4：LED0闪灯				pt5.0：pwm2蜂鸣器输出
//pt1.5：电压等级显示LED1		pt3.5：pwm3互补pwm3L输出                  
//pt3.1：分压电压检测口			pt3.6：pwm3互补pwm3H输出
//pt3.2：电压等级显示LED2		pt3.0：UART发送指示灯LED3 
//pt3.3: UART数据接收口			pt3.4：UART数据发送口

//功能说明：
//1、定时器0：4ms的定时中断；
//2、pt1.4的LED0每秒钟闪烁一次;
//3、pt3.1的分压电压AD检测范围	2.2V(2/3VDD)~3.3V(VDD)，比较表值和电压AD值的大小，
//	电压分为三级：	2.2V~2.5V LED1不亮,LED2不亮;
//					2.5V~2.9V LED1亮,LED2不亮;
//					2.9V~3.3V LED1不亮,LED2亮;
//4、pt5.0作pwm2蜂鸣器输出时，频率为4kHz,并且每秒钟响一次蜂鸣器，响30s后停止
//	 	pt3.5、pt3.6作互补pwm3L输出时，频率为200kHz，输出30s后停止输出pwm波形;                      
//5、pt3.3&pt3.4作UART数据发送口和接收口。接收来自电脑的发过来的一帧数据，
// 		当这帧数据为0DH时，则MCU切换到发送状态，给电脑发送两帧数据，
// 		 内容是"Hi" （ASCⅡ码分别为48H、69H），且LED3亮200ms又熄灭
//============================================
#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"
//============================================
// program start
//============================================
int main()
{
	asm("clrwdt");					//清看门狗 
	delay();						//上电延时
	MCU_Initialization();			//芯片初始化	
	Bit_Initialization();           //位定义初始化（新版C不需要做全局变量初始化，直接在定义时初始化即可,但BIT位定义不能在定义时初始化）	
	while(1)
	{
		asm("clrwdt");				//清看门狗        
		open_pwm();                 //调用开启pwm函数 
		adc();						//调用采AD函数   
		uart();						//调用UART发送和接受函数
		sleep();	
	}

    return 0;
}
//============================================
// interrupt function
//============================================
void INT_FUNCTION(void) interrupt
{
	if(E0IF)						//判断是否为外部中断0
	{
		E0IF=0;		
	}

	else if(E1IF)					//判断是否为外部中断1        
	{                                                            
		E1IF=0;                                                  
	}                                                            
	else if(TM0IF)                  //判断是否为定时器0溢出中断  
	{                                                            
		TM0IF=0;                    //是则清定时器0中断标志      
		t200ms_count++;             //计时200ms       	
		if(t200ms_count>=50)		               
		{                                          
			B_200ms=1;              //置计时200ms标志
		}
		t1s_count++;                                             
		if(t1s_count>=125)			//计时500ms                  
		{
			t1s_count=0;
			led=!led;				//每500ms闪烁一次led灯			
			if(t10s_count>=60)		//计时30s	          
			{                                             
				TM3CON=0X00;        //30s后关闭互补pwm3   
				TM3CON2=0X00;                             
				B_Time500ms=0;      //30s后关闭蜂鸣器
				B_Sleep=1;			//30s后进入休眠模式
			}
			else
			{
				t10s_count++;
				B_Time500ms=!B_Time500ms;//每500ms翻转一次B_Time500ms标志位   
			}
		}
	}
	
	else if(TM2IF)					//判断是否为定时器2溢出中断
	{
		TM2IF=0;			
	}
	
	else if(TM3IF)					//判断是否为定时器3溢出中断
	{
		TM3IF=0;			
	}
	
	else if(URRIF)					//判断是否为UART接收中断
	{
		URRIF=0;
		B_urr=1;					//UART数据接收标志位置1		
	}

	else if(URTIF)					//判断是否为UART发送中断
	{
		URTIF=0;
		B_urt=1;					//UART数据发送标志位置1		
	}

}
