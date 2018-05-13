#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"

void adc_battery()
{
	SRADCON1=0X80;			//使能AD转换，VDD作参考电压
	SRADCON2=0X10;			//设置pt3.1口为输入通道
	ad_voltage_collect();
	battery_deal();
}

void adc_temp1()
{
	SRADCON1=0X80;			//使能AD转换，VDD作参考电压
	SRADCON2=0X30;			//设置pt3.3口为输入通道
	ad_voltage_collect();
	temp_deal()
}

void adc_temp2()
{
	SRADCON1=0X80;			//使能AD转换，VDD作参考电压
	SRADCON2=0X40;			//设置pt3.4口为输入通道
	ad_voltage_collect();
	temp_deal()
}

//ADC采集函数
void ad_voltage_collect()
{
	int temp;							//AD值临时寄存器                        
	int i;                              //计数寄存器                            
	OFFEX = 0;	                        //offset交换置零					    
	AdData = 0;                         //清ADC采样数据的高低位寄存器           
	delay_10us();						//AD转换前延时10us
	for(i=1;i<=8;i++)                   //循环采八次AD值                        
	{		                                                                    
		SRADS=1;                        //开始AD 转换                           
		asm("nop");	                                                            
		while(SRADS);                   //等待AD 转换                           
		OFFEX = !OFFEX;                 //offset 交换                           
		temp=SRADH;                     //取AD值的高位                          
		AdData=(temp<<8)+SRADL+AdData;  //累加八次AD值到AdData寄存器            
	}                                                                           
	C=0;								//bcf	status,c                        
	AdData>>=3;					        //求八次平均，最终结果存在AdData寄存器	
}
//ADC处理函数
void battery_deal()
{	
	asm("movlw	TabStartAddr");
	asm("movwf	_EADRL");
	asm("movlw	.high(TabStartAddr)");	//取表地址高位
	asm("movwf	_EADRH");				//赋读表地址	
	asm("movp");						//读表
	asm("nop");
	asm("movwf	_CurTabData");
	asm("movfw	_EDATH");
	asm("movwf	_CurTabData+1");		//表值
	
	if(AdData<CurTabData)				//比较表值和采集到的AD值
	{									//若AD值小则关led1,led2指示灯                 
		R_AdcStation2_Cnt=0;                                                          
		R_AdcStation3_Cnt=0;                                                          
		R_AdcStation1_Cnt++;                                                          
		if(R_AdcStation1_Cnt>=20)       //滤波计数                                    
		{                               //连续20次AD值比第一个表值小则shutdown  
			R_AdcStation1_Cnt=0;
			low_battery_shutdown = 1;
		}                                                                             
	}                                                                                 
	else 			
	{                                   //若AD值小则亮led1                            
		asm("movlw	1");
		asm("addwf	_EADRL,1");
		asm("clrf	_WORK");
		asm("addwfc _EADRH,1");			//赋读表地址
		asm("movp");					//读表
		asm("nop");
		asm("movwf	_CurTabData");
		asm("movfw	_EDATH");
		asm("movwf	_CurTabData+1");	//表值

		if(AdData<CurTabData)           //比较表值和采集到的AD值                    
		{                         		
			R_AdcStation1_Cnt=0;
			R_AdcStation3_Cnt=0;
			R_AdcStation2_Cnt++;
			if(R_AdcStation2_Cnt>=10)	//滤波计数                                       
			{                           //连续10次AD值比第二个表值小则warning     
				R_AdcStation2_Cnt=0;
				low_battery_warning = 1;
			}                                                                            
		}                                                                                
	}
}

void temp_deal()
{
	asm("movlw	TabStartAddr");
	asm("movwf	_EADRL");
	asm("movlw	.high(TabStartAddr)");	//取表地址高位
	asm("movwf	_EADRH");				//赋读表地址	
	asm("movp");						//读表
	asm("nop");
	asm("movwf	_CurTabData");
	asm("movfw	_EDATH");
	asm("movwf	_CurTabData+1");		//表值
	
	if(AdData<CurTabData)				//比较表值和采集到的AD值
	{									//若AD值小则关led1,led2指示灯                 
		R_AdcStation2_Cnt=0;                                                          
		R_AdcStation3_Cnt=0;                                                          
		R_AdcStation1_Cnt++;                                                          
		if(R_AdcStation1_Cnt>=20)       //滤波计数                                    
		{                               //连续20次AD值比第一个表值小则shutdown  
			R_AdcStation1_Cnt=0;
			low_battery_shutdown = 1;
		}                                                                             
	}                                                                                 
	else 			
	{                                   //若AD值小则亮led1                            
		asm("movlw	1");
		asm("addwf	_EADRL,1");
		asm("clrf	_WORK");
		asm("addwfc _EADRH,1");			//赋读表地址
		asm("movp");					//读表
		asm("nop");
		asm("movwf	_CurTabData");
		asm("movfw	_EDATH");
		asm("movwf	_CurTabData+1");	//表值

		if(AdData<CurTabData)           //比较表值和采集到的AD值                    
		{                         		
			R_AdcStation1_Cnt=0;
			R_AdcStation3_Cnt=0;
			R_AdcStation2_Cnt++;
			if(R_AdcStation2_Cnt>=10)	//滤波计数                                       
			{                           //连续10次AD值比第二个表值小则warning     
				R_AdcStation2_Cnt=0;
				low_battery_warning = 1;
			}                                                                            
		}                                                                                
	}

}
