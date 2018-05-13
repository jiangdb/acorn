#ifndef  	_define_function_h
#define 	_define_function_h 1 

/*-------------------------------------------------
Code Name: None
Include  : None
Ouput    : None
function : 函数声明
---------------------------------------------------*/
/*-------------------------------------------------
delay.c
-------------------------------------------------*/
extern void delay();                              //软件延时
extern void delay_10us();                         //延时10us
/*-------------------------------------------------
initialization.c
-------------------------------------------------*/
extern void MCU_Initialization(void);             //芯片初始化
void Bit_Initialization(void);					  //位初始化
/*-------------------------------------------------
adc.c
-------------------------------------------------*/
//ADC模式选择
extern void adc_battery();
extern void adc_temp1();
extern void adc_temp2();
//ADC采集函数
extern void ad_voltage_collect();
//ADC处理函数
extern void battery_deal();
extern void temp1_deal();
extern void temp2_deal();
/*-------------------------------------------------
lowpower.c
-------------------------------------------------*/
extern void sleep(void);
/*-------------------------------------------------
pwm.c
-------------------------------------------------*/
extern void open_pwm(void);

#endif 








