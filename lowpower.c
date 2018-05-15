#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"

//sleep函数
void sleep()
{
	if (B_Sleep)					//判断Sleep标志                                             
	{                                                                                         
		B_Sleep=0;
		INTE = 0x00;				//先关掉总中断使能                                                           
//	;----------------------------------------
//	;ADC设置
  		SRADCON1 = 0x00;            //关ADC模块                                          
		SRADCON2 = 0x00;                                                 	                                                                           
//	;----------------------------------------
//	;定时器设置
		TM0CON = 0x00;					//关闭定时/计数器0 
		TM2CON = 0x00; 					//关闭定时/计数器2 
		TM3CON = 0x00;					//关闭定时/计数器3 
		TM4CON = 0x00;					//关闭定时/计数器4 
		/*注意：当在SLEEP前配置为PWM输出或者蜂鸣器输出，进入SLEEP前关闭定时器使能，
		PWM输出口仍然会输出固定电平，若SLEEP模式下IO电平要由PTx(x=1，2，3，5)寄存器决定，
		则必须将TMnCON（n=2、3、4）寄存器的低2位清零。*/
//	;----------------------------------------
//	;IO口设置(若IO口悬空，则要置为输出或者输入带上/下拉)
		PT1PU = 0x02;                   //I/O口上拉电阻设置                                                       
		PT1EN = 0xf7;					//pt1.3作输入口                                                          
		PT1CON = 0x08;					                                                          
		PT1 = 0x00;                                                        
		                                                                                     		                                                                                     
		PT3PU = 0x00;                                                       
		PT3EN = 0x00;                                                                        
		PT3CON = 0x00;                                               
		PT3 = 0x60;                                                                       

		PT5PU = 0x00;                                                       
		PT5EN = 0x00;                                                                        
		PT5CON = 0x00;                                               
		PT5 = 0x03; 
		SYSCFG1 = 0X00;					//关P3.4，3.6口的默认下拉
//	;----------------------------------------
//	;UART设置
		SCON2 = 0X00;
//	;----------------------------------------
//	;比较器/运放器设置
//	;----------------------------------------
//	;LCD设置
//	;----------------------------------------
//	;中断设置
		INTF = 0x00;                                                                              
		INTF2 = 0x00;               //关闭其他中断                                            
		INTE2 = 0x00;                                      
		INTE = 0x82;				//开启外部中断1、总中断使能 
		INTE2 = 0X00;
		INTE3 = 0X00;		
//	;----------------------------------------
//	;看门狗、时钟设置
		WDTCON = 0x00;              //关闭WDT                                                         
		asm("clrwdt");
		CST_WDT = 1;                //关闭内部WDT晶振
		asm("nop");
		asm("sleep");
		asm("nop");
		asm("nop");
		
		asm("clrwdt");
		delay();
		MCU_Initialization();		   	//调用初始化函数
		Bit_Initialization();
	}
}