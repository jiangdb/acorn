//============================================
/** filename: main.c
 * chip    : CSU8RP3216
 * author  :
 * date    : 2018-05-12
 * v1.0
 */

/** CODE OPTION
 * MCK = 16 Mhz
 * FCPU = 4 Mhz
 */

/** IO口配置:
 * pt1.1(GPIO-O): Charger Enable		pt1.2(GPIO-I)：Charger Status
 * pt1.6(GPIO-O): Charger Switch		pt1.7(GPIO-I): USB OTG detect
 * pt3.0(GPIO-I): Key Input				pt3.1(ADC): Battery Level Detect
 * pt3.2: N/A							pt3.3(ADC): Temperature Detect
 * pt3.4(ADC): Temperature Detect		pt3.5(PWM3): Heating Blue Led
 * PT3.6(PWM4): Heating Red Led			pt3.7: N/A
 * pt5.0(PWM2): Charging LED			pt5.1(GPIO-O): Charger Switch
 * pt5.2(GPIO-O): Heating enable 
 */

/** Battery policy
 * pt3.1的分压电压AD检测范围	2.2V(2/3VDD)~3.3V(VDD)，比较表值和电压AD值的大小，
 * 电压分为三级：	2.2V~2.5V 5%, shutdown;
 *					2.5V~2.9V 10%, warning;
 *					2.9V~3.3V no action;
 */

/** 功能说明：
 * 1. pt1.2 low to high: charge mode, high to low: charge done or adapter unplug
 * 2. pt1.7 high to low: discharge mode, low to high: USB OTG unplug
 * 3. pt3.0 high to low: key pressed
 */

//============================================
#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"
//============================================
// program start
//============================================


void shutdown_handler() {
	//reset timer count
	t500ms_count = 0;
	t2s_count = 0;
	B_500ms = 0;
	B_2s = 0;
	while(1)
	{
		//check if adapter plug in
		if ( PT1_2 ) {
			work_mode = WORK_MODE_CHARGING;
			break;
		}
		//check if USB OTG plug in
		if ( !PT1_7 ) {
			work_mode = WORK_MODE_DISCHARGING;
			break;
		}
		//check if key pressed for 2s
		if ( !PT3_0 && B_2s) {
			work_mode = WORK_MODE_HEATING;
			break;
		}
	}
}

void heating_handler() {
	B_key_waitfor_release = 0;
	B_heat_level_low = 1;
	B_heating = 0;
	while(1)
	{
		//check if adapter plug in
		if ( PT1_2 ) {
			work_mode = WORK_MODE_CHARGING;
			break;
		}
		//check if USB OTG plug in
		if ( !PT1_7 ) {
			work_mode = WORK_MODE_DISCHARGING;
			break;
		}
		//check battery level
		adc_battery();
		if (B_low_battery_shutdown) {
			work_mode = WORK_MODE_SHUTDOWN;
			B_Sleep = 1;
			break;
		}
		//check if key pressed short
		if (B_key_pressed) {
			if ( !B_key_waitfor_release ) {
				B_key_waitfor_release = 1;
				t500ms_count = 0;
				t2s_count = 0;
				B_500ms = 0;
				B_2s = 0;
			}

			//2s shutdown
			if ( B_2s ) {
				work_mode = WORK_MODE_SHUTDOWN;
				B_Sleep = 1;
				break;
			}
		} else {
			B_key_waitfor_release = 0;
			// swith heat level
		}

		//get temperature
		adc_temp1();
		//if heating
		//	if temp large than level, stop heating
		//else
		//	if temp lower than level - 10 degree, start heating
	}
}

void charging_handler() {
	while(1)
	{
		//check if adapter unplugged
		if ( PT1_2 ) {
			// count 500ms first
			t200ms_count = 0;
			t800ms_count = 0;
			B_200ms = 0;
			B_800ms = 0;
		} else {
			if ( B_800ms) {
				//adapter unplugged
				work_mode = WORK_MODE_SHUTDOWN;
				B_Sleep = 1;
				break;
			}
		}
	}
}

void discharging_handler() {
	//turn on white led
	PT5_0 = 1;
	PT1_6 = 1;
	PT5_1 = 0;
	//enter work loop
	while(1)
	{
		asm("clrwdt");				//清看门狗
		//check if USB OTG unpluged
		if (PT1_7) {
			//unplugged, should shutdown
			work_mode = WORK_MODE_SHUTDOWN;
			B_Sleep = 1;
			break;
		}

		//check battery level
		adc_battery();
		if ( B_low_battery_shutdown ) {
			//should shutdown
			work_mode = WORK_MODE_SHUTDOWN;
			B_Sleep = 1;
			break;
		}
	}
}

int main()
{
	asm("clrwdt");					//清看门狗 
	delay();						//上电延时
	MCU_Initialization();			//芯片初始化	
	Bit_Initialization();           //位定义初始化（新版C不需要做全局变量初始化，直接在定义时初始化即可,但BIT位定义不能在定义时初始化）	
	work_mode = WORK_MODE_SHUTDOWN;
	while(1)
	{
		asm("clrwdt");				//清看门狗    
		//switch mode
		switch(work_mode) {
			case WORK_MODE_SHUTDOWN:
				shutdown_handler();
				break;
			case WORK_MODE_HEATING:
				heating_handler();
				break;
			case WORK_MODE_CHARGING:
				charging_handler();
				break;
			case WORK_MODE_DISCHARGING:
				discharging_handler();
				break;
			default:
				break;
		}
		//sleep
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
		if ( PT3_0 ) {
			B_key_pressed = 0;
		} else {
			B_key_pressed = 1;
		}
	}

	else if(E1IF)					//判断是否为外部中断1        
	{                                                            
		E1IF=0;
	}                                                            
	else if(TM0IF)                  //判断是否为定时器0溢出中断  
	{                                                            
		TM0IF=0;                    //是则清定时器0中断标志     

		//计时200ms 
		t200ms_count++;						      	
		if(t200ms_count>=50)				//4ms * 50 = 200ms
		{   
			t200ms_count = 0;
			B_200ms = 1;						//置计时200ms标志
			t800ms_count++;
			if (t800ms_count >=4 ) {
				t800ms_count = 0;
				B_800ms=1;						//置计时800ms标志
			}
		}
		
		//计时500ms 
		t500ms_count++;                                             
		if(t500ms_count>=125)				//4ms * 125 = 500ms         
		{
			t500ms_count=0;
			B_500ms = 1;					//置计时500ms标志
			if (B_low_battery_warning) {
				red_led=!red_led;			//每500ms闪烁一次RED灯			
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
	}

	else if(URTIF)					//判断是否为UART发送中断
	{
		URTIF=0;
	}

}
