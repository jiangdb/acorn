//============================================
// global variable
//============================================
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
	if_adc=1;						//if_adc为1时，采集的是pt3.1口的电压值；if_adc为0时，采集的是芯片内部参考电压的AD值 
	if_pwm=0;                       //if_pwm为1时，输出pwm2作蜂鸣器输出；if_pwm为0时，输出互补pwm3                      		
}
