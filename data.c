//============================================
// global variable
//============================================

/**
 * Bit variable
 */
//sleep
sbit B_Sleep;

//timer
sbit B_52ms;
sbit B_500ms;
sbit B_2s;
sbit B_10s;

//battery
sbit B_low_battery_shutdown;
sbit B_low_battery_warning;

//key
sbit B_key_pressed;
sbit B_key_waitfor_release;

//heating
sbit B_heat_level_low;
sbit B_heating;

/**
 * int variable
 */
//working mode
unsigned char work_mode;

//key status
unsigned char key_status;

//ADC
unsigned int AdData;                //ADC采样数据
unsigned int CurTabData;			//读表数据寄存器
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

//timer count
unsigned char t52ms_count;
unsigned char t500ms_count;
unsigned char t1s_count;
unsigned int t2s_count;
unsigned char t10s_count;

int test;
//const unsigned int a[2]={0x0c71,0x0e38}; //2.5V 2.9V ADC采样比较值,常量数组，数据存储在RAM里

//位定义初始化
void Bit_Initialization(void)
{	
	B_low_battery_shutdown = 0;
	B_low_battery_warning = 0;
	B_heat_level_low = 0;
	B_heating = 0;
}