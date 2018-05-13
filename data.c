//============================================
// global variable
//============================================

sbit if_key_press;
sbit if_usb_plug;
sbit if_adapter_plug;
sbit heating_low;
sbit B_low_battery_shutdown;
sbit B_low_battery_warning;

//working mode
unsigned char work_mode = WORK_MODE_SHUTDOWN;

//ADC
unsigned int AdData;                //ADC采样数据
unsigned int CurTabData;			//读表数据寄存器
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;



sbit B_200ms;
sbit B_urr;
sbit B_urt;
sbit B_send_ok;

sbit B_Time500ms;
sbit B_pwm2;
sbit B_pwm3;
sbit if_pwm;

sbit if_adc;

unsigned char R_flag;
unsigned char R_200ms_cnt;

unsigned char t200ms_count;
unsigned char t1s_count;
unsigned char t10s_count;

unsigned char R_LED_S;              //存储LED状态的变量
unsigned char E2_Addr;            //eeprom地址
unsigned char E2_Data;            //eeprom数据

unsigned int CurTabData;			//读表数据寄存器
unsigned int AdData;                //ADC采样数据
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

unsigned char R_key;        //按键操作标志
unsigned char R_Key_Value;  //存储键值的变量

sbit B_Sleep;

//const unsigned int a[2]={0x0c71,0x0e38}; //2.5V 2.9V ADC采样比较值,常量数组，数据存储在RAM里

//位定义初始化
void Bit_Initialization(void)
{
	if_key_press = 0;
	if_usb_plug = 0;
	if_adapter_plug = 0;
	
	heating_low = 0;  //default in low level
	B_low_battery_shutdown = 0;
	B_low_battery_warning = 0;
	
	B_pwm2 = 0;
}