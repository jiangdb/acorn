//============================================
// filename: initialization.c
// chip    : CSU8RP3216
// author  :
// date    : 2016-07-17
//============================================

//-------------------------------------------------
//Include Header
#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"

//����Ĵ���������ο�оƬ�û��ֲᣬ���û��ֲ�Ϊ׼
/*----------------------------------------------------------------------------
�������ƣ�F_Initial_MCU
������������ʼ��Mcu������
----------------------------------------------------------------------------*/
void MCU_Initialization(void)
{
	//-----------------------------------------------------------------	
	//��״̬�Ĵ���
	//-----------------------------------------------------------------
	
	////////////////��Ƕ�뵥��������ʾ����/////////////////////////////

	asm("clrf _STATUS");			//��״̬�Ĵ���
	//-----------------------------------------------------------------	
	//����MCK�Ĵ���
	//-----------------------------------------------------------------
	MCK 	= 0x80;					//MCK:(�ϵ�Ĭ��ֵΪ:1010uuu0)
									//Bit7   CST: �ⲿ������������
									//	1 = �ⲿ����ر�
									//	0 = �ⲿ�����
									
									//Bit6   CST_IN: �ڲ�������������
									//	1 = �ڲ�����ر�
									//	0 = �ڲ������
									 
									//Bit5   CST_WDT: �ڲ�WDT������������
									//	1 = �ڲ�WDT����ر�
									//	0 = �ڲ�WDT�����									
									 
									//Bit4   EO_SLP: �ⲿ���پ������λ
									//	1 = ���ѡ������ⲿ���پ���(32768Hz),��sleepģʽ�²��ر��ⲿ����
									//	0 = sleepģʽ�¹ر��ⲿ����
									
									//Bit0   CLKSEL: ʱ��Դѡ��λ
									//	0 = �ڲ�����ϵͳʱ��
									//	1 = �ⲿ����ϵͳʱ��

	//-----------------------------------------------------------------
	//����WDTCON�Ĵ���
	//˵�������Ҫ����WDT������Ҫ����WDT���񿪹�(CST_WDT)������RAM�Ƿ�Ҫ��0�������������	   
	//-----------------------------------------------------------------

									
	WDTCON	= 0x81;					//ʹ�ܿ��Ź���1.024s�����λ
									//WDTCON:(�ϵ�Ĭ��ֵΪ:0uuuu000)
									//Bit7   WDTEN: ���Ź�ʹ��λ
									//	 0 = WDT�ر�
									//   1 = WDT����
									
									//Bit4   WDT_DLY: ���Ź���λ��ʱʹ��λ
									//	 0 = WDT��λ����ʱ
									//   1 = WDT��λ����ʱ8ms
									
									//Bit[2-0]	wdts����wdtinΪ11111111bʱ 
									//			000   ���ʱ��Ϊ 2048ms    
									//			001   ���ʱ��Ϊ 1024ms    
									//			010   ���ʱ��Ϊ 512ms     
									//			011   ���ʱ��Ϊ 256ms     
									//			100   ���ʱ��Ϊ 128ms     
									//			101   ���ʱ��Ϊ 64ms      
									//			110   ���ʱ��Ϊ 32ms      
									//			111   ���ʱ��Ϊ 16ms  
	
	WDTIN 	= 0xff;					//WDTIN:(�ϵ�Ĭ��ֵΪ:11111111)
									//����WDT���ʱ��ֵ	
									//��WDTIN����FFHʱ������Ӧ�ı������л��������ʱ��ֵ
	//-----------------------------------------------------------------
	//���RAM(ע�⣺�°�C����������Ҫ�Լ���SRAM���������Ѿ����ˣ����Բ���ִ����һ��)	
	//-----------------------------------------------------------------	
			
	//-----------------------------------------------------------------
	//��ʼ��IO��
	//-----------------------------------------------------------------							
	//-------------------------------
	//PT1�˿�[7:1]
	//-------------------------------
	PT1CON = 0x01;					//PT1CON:(�ϵ�Ĭ��ֵ:00000000)
									//Bit7   PT11OD: PT1.1©����·ʹ��λ(�Ա���IO�������ͬ�ĵ�ѹֵ)
									//	0 = ��ֹPT1.1©����·
									//	1 = ʹ��PT1.1©����·
								
									//Bit6   PT1W[3]: PT1.5�ⲿ�ж�1ʹ��
									// 	0 = ��ֹPT1.5�ⲿ�ж�1 
									//	1 = ʹ��PT1.5�ⲿ�ж�1
								
									//Bit5   PT1W[2]: PT1.4�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.4�ⲿ�ж�1 
									//	1 = ʹ��PT1.4�ⲿ�ж�1
								
									//Bit4   PT1W[1]: PT1.3�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.3�ⲿ�ж�1 
									//	1 = ʹ��PT1.3�ⲿ�ж�1
								
									//Bit3   PT1W[0]: PT1.1�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.1�ⲿ�ж�1 
									//	1 = ʹ��PT1.1�ⲿ�ж�1
								
									//Bit2   E1M: �ⲿ�ж�1����ģʽ
									//	1 = �ⲿ�ж�1Ϊ�½��ش���
									//	0 = �ⲿ�ж�1��״̬�ı�ʱ����
								
									//Bit1-0 E0M[1:0]: �ⲿ�ж�0����ģʽ
									//	00 = �ⲿ�ж�0Ϊ�½��ش���
									//	01 = �ⲿ�ж�0Ϊ�����ش���
									//	10 = �ⲿ�ж�0��״̬�ı�ʱ����
									//	11 = �ⲿ�ж�0��״̬�ı�ʱ����	
	
	PT1CON1 = 0x00;					//PT1CON1(�ϵ�Ĭ��ֵ��uuuu0000)
	
									//Bit3   PT1W2[3]: PT3.1�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT3.1�ⲿ�ж�1 
									//	1 = ʹ��PT3.1�ⲿ�ж�1
									//Bit2   PT1W2[2]: PT1.7�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.7�ⲿ�ж�1 
									//	1 = ʹ��PT1.7�ⲿ�ж�1
									
									//Bit1   PT1W2[1]: PT1.6�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.6�ⲿ�ж�1 
									//	1 = ʹ��PT1.6�ⲿ�ж�1
									
									//Bit0   PT1W2[0]: PT1.2�ⲿ�ж�1ʹ��
									//	0 = ��ֹPT1.2�ⲿ�ж�1 
									//	1 = ʹ��PT1.2�ⲿ�ж�1
		
	PT1EN = 0x30;					//PT1EN:(�ϵ�Ĭ��ֵ:0000u00u)
					 				//	0 = ����Ϊ�����(PT1.3 only input)
									//	1 = ����Ϊ�����
	
	PT1PU = 0x00;					//PT1PU:(�ϵ�Ĭ��ֵ:0000000u)
									//	0 = �Ͽ���������
									//	1 = ʹ����������

	PT1 = 0x00;						//PT1:(�ϵ�Ĭ��ֵ:xxxxxxxu)	


	//-------------------------------
	//PT3�˿�[7:0]������PT3.4��ΪUART���Ϳڣ�����P3.0ΪADģ�������
	//-------------------------------
	PT3CON	= 0x01;					//PT3CON:(�ϵ�Ĭ��ֵ:00000000)
									//Bit7-0 PT3CON[7:0]: GPIO3ģ��/���ֶ˿�ʹ�ܱ�־
									//	0 = ����Ϊ���ֿ�
									//	1 = ����Ϊģ���
	
	PT3EN = 0x65;					//PT3EN:(�ϵ�Ĭ��ֵ:00000000)
									//	0 = ����Ϊ�����
									//	1 = ����Ϊ�����	
									
	PT3PU = 0x00;					//PT3PU:(�ϵ�Ĭ��ֵ:00000000)
									//	0 = �Ͽ���������
									//	1 = ʹ����������
									
	PT3	= 0x10;						//PT3:(�ϵ�Ĭ��ֵ:xxxxxxxx)

	//-------------------------------
	//PT5�˿�[2:0]
	//-------------------------------	
	PT5CON	=	0x00;				//PT5CON:(�ϵ�Ĭ��ֵ:00000000)
									//	[7:0]©����·ʹ��λ
									//	0 = ��ֹPT5.3©����·
									//	1 = ʹ��PT5.3©����·
									
										
	PT5EN = 0x01;					//PT5EN:(�ϵ�Ĭ��ֵ:00000000)
	
	PT5PU = 0x00;					//PT5PU:(�ϵ�Ĭ��ֵ:00000000)

	PT5 =	0x00;					//PT5:(�ϵ�Ĭ��ֵ:xxxxxxxx)

	//-----------------------------------------------------------------
	//AD��ʼ�����ο���ѹVDD��ͨ��1���������õ�AD
	//-----------------------------------------------------------------*/	
	SRADCON0 = 0x01;				//SRADCON0:(�ϵ�Ĭ��ֵΪ:uu00uu00)		
									//Bit5-4 SRADACKS[1:0]: 
									//	00 = 16��SAR_ADCʱ��(SAR_ADC�����źŻ�ȡʱ��/Ҫ>=4us)
									//	01 = 8��SAR_ADCʱ��
									//	10 = 4��SAR_ADCʱ��
									//	11 = 2��SAR_ADCʱ��
									
									//Bit1-0 SRADCKS[1:0]: SAR_ADCʱ��
									//	00 = cpuclk(SAR_ADC����ʱ��)
									//	01 = cpuclk/2
									//	10 = cpuclk/4
									//	11 = cpuclk/8

	
	SRADCON1 =	0x00;				//SRADCON1:(�ϵ�Ĭ��ֵΪ:00000000)	
									//Bit7   SRADEN: SAR_ADCʹ��λ
									//	1 = ʹ��
									//	0 = ��ֹ
									
									//Bit6   SRADS: SAR_ADC����λ/״̬����λ 
									//	1 = ��ʼ��ת��������
									//	0 = ֹͣ��ת������
									//	����λ������SAR_ADCת����ת����ɻ��Զ���0
									
									//Bit5   OFTEN: ת�����ѡ�����λ
									//	1 = ת���������SROFT�Ĵ�����
									//	0 = ת���������SRAD�Ĵ�����
									
									//Bit4   CALIF: У������λ(OFTENΪ0ʱ��Ч)
									//	1 = ʹ��У������SAR_ADCת���Ľ���Ǽ�ȥ��SROFTʧ����ѹֵ
									//	0 = ��ֹУ������SAR_ADCת�������û�м�ȥSROFTʧ����ѹֵ

									//Bit3   ENOV: ʹ�ܱȽ������ģʽ(CALIFΪ1ʱ��Ч)
									//	1 = ʹ�ܣ����������ֱ���Ǽ�ȥ��Ľ��
									//	0 = ��ֹ������Ϊ000h������Ϊfffh
									
									//Bit2   OFFEX: OFFSET����
									//	1 = �Ƚ��������źŽ���
									//	0 = �Ƚ��������źŲ�����(����Ϊ�źţ�����Ϊ�ο���ѹ)
									
									//Bit1-0 VREFS[1:0]: SAR_ADC�ο���Դѡ��
									//	00 = VDD
									//	01 = pt3.0�ⲿ�ο���Դ����
									//	10 = �ڲ��ο���ѹ
									//	11 = �ڲ��ο���ѹ��pt3.0����ӵ�����Ϊ���òο���ѹ�˲�ʹ�ã�����߾���    
		

	SRADCON2 = 0x10;				//SRADCON2:(�ϵ�Ĭ��ֵΪ:0000uuuu)		
									//Bit6-4 CHS[3:0]: SAR_ADC����ͨ��ѡ��λ 
									//		0000 = AIN0���� 
									//		0001 = AIN1����
									//		0010 = AIN2����
									//		0011 = AIN3����
									//		0100 = AIN4����
									//		0101 = AIN5����
									//		0110 = AIN6����
									//		0111 = AIN7����
									//  	1000 = AIN8����                
									//		1001 = AIN9���룬�ڲ�1/8VDD    
									//		1010 = AIN10���룬�ڲ��ο���ѹ 
									//		1011 = AIN11���룬�ڲ��ӵ�     															
									//  	 ���� = �ڶ� 
									
									//bit [1:0]	ref_sel[1:0]	
									//		vrefs[1:0] ADC�ο���ѹ����Ϊ2'b10��2'b11�����ͨ��REF_SEL [1:0]ѡ��ο����µ�ѹ��
									//							��vrefs[1:0]��������Ϊ2'b10��2'b11��������λ��Ч��
									//		ref_sel[1:0]	�ڲ��ο���ѹ
									//		00				1.4V
									//		01				2.0V
									//		10				3.0V
									//		11				4.0V
	SRADL=0;                          
	SRADH=0;							 
	//---------------------------------------------------------------
	//��ʱ��0��ʼ�����������õ���ʱ��0  
	//----------------------------------------------------------------*/
	TM0CON	= 0xF0;					//���ö�ʱ��0���˴�t0rate=cpu/128=4M/128=31.25K	����=32us
									//TM0CON:(�ϵ�Ĭ��ֵΪ:0000u100)	
									//Bit7   T0EN: ��ʱ0ʹ��λ
									//	1 = ʹ��TM0											
									//	0 = ��ֹTM0
									
									//Bit6-4 T0RATE[2:0]: ��ʱ0ʱ��ѡ��
									//	000 = CKT0
									//	001 = CKT0/2
									//	010 = CKT0/4
									//	011 = CKT0/8
									//	100 = CKT0/16
									//	101 = CKT0/32
									//	110 = CKT0/64
									//  111 = CKT0/128									
									
									//Bit2   T0RSTB: ��ʱ0��λ
									//	1 = ��ֹTM0��λ
									//	0 = ʹ��TM0��λ
									
									//Bit1-0  T0SEL[1:0]: ��ʱ��0ʱ��Դ
									//	00 = CPUCLK
									//	01 = MCK
									//	10 = �ⲿ32.768KHz����
									//	11 = �ڲ�32KHz WDTʱ��(����WDT�����ʱ��Ч)									
									
	TM0IN	=	124;				//tm0���ʱ��Ϊ 32us*(124+1)=4ms	     
	                                //��ʱ��0���ʱ����㷽����            
	                                //	��ʱ��0���ʱ��=(tm0in+1)/tm0clk 
	
	TM0CNT 	= 	0;				//�嶨ʱ��0�����Ĵ�����ֻ��

	//-----------------------------------------------------------------
	//��ʱ��2��ʼ�����������õ���ʱ��2�����ڴ��ڷ���
	//-----------------------------------------------------------------*/
  	TM2CON  = 0x00;		   			//TM2CON:(�ϵ�Ĭ��ֵΪ:00000100) 
									//Bit 7   T2EN: ��ʱ/������2ʹ��λ
									//	1 = ʹ��TM2										
									//	0 = ��ֹTM2
									
									//Bit[6-4] T2RATE[2:0]: ��ʱ/������2ʱ��ѡ��
									//	000 = CKT2
									//	001 = CKT2/2
									//	010 = CKT2/4
									//	011 = CKT2/8
									//	100 = CKT2/16
									//	101 = CKT2/32
									//	110 = CKT2/64
									//   111 = CKT2/128
									
									//Bit 3   T2CKS: ��ʱ/������2ʱ��Դѡ��λ
									//	1 = PT1.0��Ϊʱ��
									//	0 = cpuclk�ķ�Ƶʱ��
									
									//Bit 2   T2RSTB: ��ʱ/������2��λ
									//	1 = ��ֹTM2��λ
									//	0 = ʹ��TM2��λ
									
									//Bit[1-0]  T2OUT PWM2OUT: PT1.4�������(����PT1.4����Ϊ�����Ч)
									//				00 = IO���
									//				01 = PWM2���
									//				10 = ���������
									//				11 = PWM2���
	
	TM2IN =0x00;					//�嶨ʱ/������2���ֵ                                       	
	TM2INH=0x00;                    //��ʱ��2���ʱ����㷽����                                  
	                                //   	��ʱ��2���ʱ��=��tm2in[11:0]+1��/tm2clk ��tm2in��Ϊ0��
	TM2R   = 0;						//�嶨ʱ/������2��PWM�ߵ�ƽռ�ձȿ��ƼĴ��� 
	TM2RH  = 0;	
	        
	TM2CNT  = 0;					//�嶨ʱ/������2�����Ĵ���
	TM2CNTH	= 0;
	  	
//--------------------------------------------      
//��ʱ/������4��ʼ��                                
//--------------------------------------------
   
    TM4CON =0X80;	  			//���ö�ʱ��4                                                
                                //tm4con�����ϵ縴λֵΪ��00000100��                                                 
						        //Bit 7 		t4en 	��ʱ/������4ʹ��λ                                           
						        //       	1��ʹ�ܶ�ʱ��4                                                   
						        //       	0����ֹ��ʱ��4                                                  
						        //                                                                        
						        //Bit[6:4] 	t4rate[2:0] 	��ʱ/������4ʱ��ѡ��                                
						        //			t4rate [2:0]	tm4clk	(CKT4ʱ��Դѡ���TMCON2�Ĵ�����t4sel[1:0]λ)               
						        //			000				ckt4                                                
						        //			001				ckt4 /2                                             
						        //			010				ckt4 /4                                             
						        //			011				ckt4 /8                                             
						        //			100				ckt4 /16                                            
						        //			101				ckt4 /32                                            
						        //			110				ckt4 /64                                            
						        //			111				ckt4 /128                                                                       
						        //                                                                        
						        //Bit 3 		t4cks	��ʱ/������4ʱ��Դѡ��λ                                    
						        //			1��pt1.0��Ϊʱ��                                                        
						        //			0��cpuclk��mck�ķ�Ƶʱ��                                
						        //                                                                        
						        //Bit 2 		t4rstb 	��ʱ/������4��λ         
						        //			1����ֹ��ʱ/������4��λ                                                 
						        //			0��ʹ�ܶ�ʱ/������4��λ��������λΪ0ʱ����ʱ��4��λ��t4rstb���Զ���1  
						        //                                                                        
						        //Bit 1:0  	t4out pwm4out 	pt1.6��������ƣ�����pt1.6����Ϊ���ʱ��Ч                               
						        //			0	 	0	 	IO���                                        
						        //		 	0		1		PWM4���                                       
						        //			1		0		���������                                   
						        //			1		1		PWM4���                                      
							    
	TM4IN =25;				
    TM4INH =0;					//tm4�����Ϊ tm4clk/(tm4in[11:0]+1)= 4M/(25+1)= 153.8k
    							//��ʱ��4���ʱ����㷽����
                                // 	��ʱ��4���ʱ��=��tm4in[11:0]+1��/tm4clk ��tm4in��Ϊ0��
                                
    TM4R =0;					
    TM4RH =0;					//�嶨ʱ/������4��PWM�ߵ�ƽռ�ձȿ��ƼĴ���
                               
    TM4CNT =0;		            
    TM4CNTH	=0;					//�嶨ʱ/������4�����Ĵ���
	//-----------------------------------------------------------------
	//��ʱ��3��ʼ��
	//-----------------------------------------------------------------*/	              
	TM3CON = 0x00;  				//���ö�ʱ��3,����ΪIO���                                                                                                                 
	                            	//tm3con�����ϵ縴λֵΪ��00000100��                                                                           	                            
						        	//Bit 7 		t3en 	��ʱ/������3ʹ��λ                                                                                                    
						        	//       	1��ʹ�ܶ�ʱ��3                                                                                                                
						        	//       	0����ֹ��ʱ��3                                                                                                                    
						        	//                                                                                                             
						        	//Bit[6:4] 	t3rate[2:0] 	��ʱ/������2ʱ��ѡ��                                                              
						        	//			t3rate [3:0]	tm2clk	(t3rate[3]��metch�Ĵ�����)                                                
						        	//				000 = 		CKT2
									//				001 = 		CKT2/2
									//				010 = 		CKT2/4
									//				011 = 		CKT2/8
									//				100 = 		CKT2/16
									//				101 = 		CKT2/32
									//				110 = 		CKT2/64
									//  			 111 =		 CKT2/128                                                                  
                                                 
						        	//Bit 3 		t3cks	��ʱ/������3ʱ��Դѡ��λ                                                                  
						        	//			1��pt1.1��Ϊʱ��                                                                                  
						        	//			0��cpuclk��mck�ķ�Ƶʱ��                                                                          
						        	//                                                                                                             
						        	//Bit 2 		t3rstb 	��ʱ/������3��λ                                                                          
						        	//			1����ֹ��ʱ/������3��λ                                                                           
						        	//			0��ʹ�ܶ�ʱ/������3��λ��������λΪ0ʱ����ʱ��3��λ��t2rstb���Զ���1                            
						        	//                                                                                                             
						        	//Bit 1:0  	t3out pwm3out 	pt1.5��������ƣ�����pt1.5����Ϊ���ʱ��Ч                                        
						        	//			0	 	0	 	IO���                                                                            
						        	//		 	0		1		PWM3���                                                                          
						        	//			1		0		���������                                                                        
						        	//			1		1		PWM3���                                                                          
							    	                                                                                                             
	TM3IN  = 0;					                                                                                                             
	TM3INH = 0;						//�嶨ʱ/������3���ֵ                                                                                         
									//��ʱ��3���ʱ����㷽����                                                                                    
	                            	// 	��ʱ��3���ʱ��=��tm3in[11:0]+1��/tm3clk ��tm3in��Ϊ0��                                                   
	                            	                                                                                                             
	TM3R = 0;   					                                                                                                             
	TM3RH = 0;						//�嶨ʱ/������3��PWM�ߵ�ƽռ�ձȿ��ƼĴ���                                                                    
	                            	                                                                                                            
	TM3CNT = 0;              	                                                                                                          
	TM3CNTH	= 0;					//�嶨ʱ/������3�����Ĵ���                                                                                     
  		
	TM3CON2 = 0x00;   				//��������ʱ��                                                                                                 
									//tm3con2�����ϵ縴λֵΪ��00000000��                                                                          
									//Bit[7:6]	dt3ck[1:0]	��ʱ��3����ʱ��ʱ��ѡ��                                                               
									//			dt3ck[1:0]	dt3_clk                                                                               
									//			00       	mck                                                                                   
									//			01       	mck/2                                                                                 
									//			10       	mck/4                                                                                 
									//			11       	mck/8                                                                                 
									//                                                                                                             
									//Bit[5:3]	dt3cnt[2:0]	����ʱ��ѡ��                                                                          
									//                        ����ʱ��=dt3cnt[2:0]*dt3_clk                                                         
									//                                                                                                             
									//Bit 2		dt3_en		����������3ʹ��λ                                                                     
									//           0����ʹ������������3                                                                              
									//           1��ʹ������������3                                                                                
									//                                                                                                             
									//Bit 1 		p3h_oen		����PWM3H���ʹ��                                                                     
									//           0��PWM3H�����                                                                                    
									//           1��PWM3H��PT3.6���                                                                               
									//                                                                                                             
									//Bit 0		p3l_oen		����PWM3L���ʹ��                                                                     
									//           0��PWM3L�����                                                                                    
									//           1��PWM3L��PT3.5��� 
									
									
  	TMCON=0X01;					//���û���pwm3h��pwm3l,pwm��������� (�ϵ�Ĭ��ֵ��00uuu000)
								//bit 7		p3hinv	����PWM3Hȡ������λ 
								// 			0��PWM3H��ȡ��
								// 			1��PWM3Hȡ�����
								//
								//bit 6		p3linv	����PWM3Lȡ������λ
								//			0��PWM3L��ȡ��
								//			1��PWM3Lȡ�����
								//
								//bit 2		pwm4po	PWM4�����ѡ��
								//			0��PT1.6��ΪPWM4�����
								//			1��PT3.6��ΪPWM4�����
								//
								//bit 1		pwm3po	PWM3�����ѡ��
								//			0��PT1.5��ΪPWM3�����
								//			1��PT3.5��ΪPWM3�����
								//
								//bit 0		pwm2po	PWM2�����ѡ��
								//			0��PT1.4��ΪPWM2�����
								//			1��PT5.0��ΪPWM2�����
                              
								
	
	TMCON2=0X04;				//��ʱ����ʱ��ѡ��;(�ϵ�Ĭ��ֵ��uu000000)   
								//bit [5:4]	t4sel[1:0]	��ʱ��4ʱ��Դѡ��
								//			t4sel[1:0]	��ʱ��4ʱ��Դ
								//			00			CPUCLK
								//			01			MCK
								//			1x			�ⲿ����ʱ��ECK��(�����ⲿ���ⲿ�����Ҿ����ʱ��Ч)
                                //
								//bit [3:2]	t3sel[1:0]	��ʱ��3ʱ��Դѡ��
								//			t3sel[1:0]	��ʱ��3ʱ��Դ
								//			00			CPUCLK
								//			01			MCK
								//			1x			�ⲿ����ʱ��ECK��(�����ⲿ���ⲿ�����Ҿ����ʱ��Ч)
								//
								//bit [1:0]	t2sel[1:0]	��ʱ��2ʱ��Դѡ��
								//			t2sel[1:0]	��ʱ��2ʱ��Դ(CKT2)
								//			00			CPUCLK
								//			01			MCK
								//			1x			�ⲿ����ʱ��ECK��(�����ⲿ���ⲿ�����Ҿ����ʱ��Ч)
	//-----------------------------------------------------------------
	//����UART,�������õ�UART
	//-----------------------------------------------------------------
		
	SCON1 = 0x50;					//SCON1:(�ϵ�Ĭ��ֵλ:000000uu)
									//Bit7-6 SM0 SM1: ����ͨ�Ź�����ʽ
									//		 ��ʽ   ����   ������
									//		00 = 0      ͬ��   BaudRate = Fcpuclk/6
									//		01 = 1      �첽   
									//						   TM4�����/16(SMOD=1)
									//						   TM4�����/32(SMOD=0)
									//		10 = 2		�첽   Fcpuclk/16(SMOD=0)
									//						   Fcpuclk/32(SMOD=1)
									//		11 = 3		�첽  
									//					   		TM4�����/16(SMOD=1)
									//					   		TM4�����/32(SMOD=0)
									
									//Bit5   SM2: ����
									
									//Bit4   REN: ���տ���ѡ��
									//	1 = ��������
									//   0 = ��ֹ����
									
									//Bit3   TB8: �������ݵ�9λ
									
									//Bit2   RB8: �������ݵ�9λ
									
	
	SCON2 = 0xef;					//SCON2:(�ϵ�Ĭ��ֵ:000u0000)�����ò�����Ϊ9600
									//Bit 7   SMOD: ������ѡ��Ĵ���
									//		0����ʱ��0/2/3/4�������32
									//		1����ʱ��0/2/3/4�������16
									
									//bit[6:5]	URCLK[1:0]	UARTʱ��ѡ��λ              
									//			URCLK [1:0]		UARTʱ��                
									//          00   		ѡ��ʱ��0�����Ϊʱ�ӣ�   
									//                       SMOD=1��������Ϊ�����/16��
									//                       SMOD=0��������Ϊ�����/32  
									//          01          ѡ��ʱ��2�����Ϊʱ�ӣ�   
									//                       SMOD=1��������Ϊ�����/16��
									//                       SMOD=0��������Ϊ�����/32  
									//			10			ѡ��ʱ��3�����Ϊʱ�ӣ�   
									//                       SMOD=1��������Ϊ�����/16��
									//                       SMOD=0��������Ϊ�����/32  
									//			11			ѡ��ʱ��4�����Ϊʱ�ӣ�   
									//                       SMOD=1��������Ϊ�����/16��
									//                       SMOD=0��������Ϊ�����/32  									
																																																													   
									//bit 3		UARTEN		UARTģ��ʹ��                
									//         	0����ʹ��UARTģ��                           
									//          1��ʹ��UARTģ��                             
									//          ���ر�UARTģ��ʹ��λ���򲻻�����жϱ�־λ��
									
									//bit[2:0]  PINCTL[2:0] UARTͨ�ſ�ѡ��                                                                 
									//          3��b000      PT1.1��PT1.2����ͨIO�ڣ�PT3.3��PT3.4����ͨIO��                                                
									//          3��b001      PT1.1��UARTͨ�ſڣ�������PT1EN[1]������PT1.2����ͨIO�ڣ�PT3.3��PT3.4����ͨIO��                                                                                                                            
									//          3��b010      PT1.2��UARTͨ�ſڣ�������PT1EN[2]������PT1.1����ͨIO�ڣ�PT3.3��PT3.4����ͨIO��                                              
									//          3��b011      PT1.1��PT1.2�ֱ���UARTͨ�ſ�RI��TI�� PT3.3��PT3.4����ͨIO��                       
									//          3��b100      PT1.1��PT1.2����ͨIO�ڣ�PT3.3��PT3.4����ͨIO��                                    
									//          3��b101      PT3.3��UARTͨ�ſڣ�������PT3EN[3]������PT3.4����ͨIO�ڣ�PT1.1��PT1.2����ͨIO��    
									//          3��b110      PT3.4��UARTͨ�ſڣ�������PT3EN[4]������PT3.3����ͨIO�ڣ�PT1.1��PT1.2����ͨIO��    
									//          3��b111      PT3.3��PT3.4�ֱ���UARTͨ�ſ�RI��TI�� PT1.1��PT1.2����ͨIO��                       
									//          	��ѡ��ͬ��ͨ�Ż���ͬʱ��Ҫ���з��ͺͽ���ʱ������������������Ϊͨ�ſڣ�                   
									//          	��PINCTL[2:0]��������Ϊ3��bx11����PINCTL[2:0]����Ϊ3��bx01��3��bx10ʱ��                  
									//          	��ʱֻ��һ��ͨ�ſ���ʹ�ã���ʱ���ͨ�ſڿ��Է�ʱ����ΪRI��TI��                           
									//          	������IO�ڵķ���λ���ƣ����磺����PINCTL[2:0]����Ϊ3��b001ʱ��                           
									//          	��ʱֻ��PT1.1��UARTͨ�ſڣ���PT1EN[1]Ϊ0ʱ��PT1��ΪRI�ڣ���PT1EN[1]Ϊ1ʱ��PT1��ΪTI�ڡ�										
	
	SBUF = 0;						//�崮�����ݼĴ���	
	//-----------------------------------------------------------------
	//�жϳ�ʼ��
	//-----------------------------------------------------------------
	INTF =0X00;      	 		//�������жϱ�־
								//intf�����ϵ縴λֵΪ��u0u00u00��
								//Bit 6 		tm2if		12-Bit��ʱ/������2�жϱ�־���������㣬Ӳ���ø�
								//			1 = ������ʱ�жϣ�����������0                               
								//			0 = û������ʱ�ж�  
								//                                      
								//Bit 4 		tm0if		8-Bit��ʱ��0�жϱ�־���������㣬Ӳ���ø�      
								//			1 = ������ʱ�жϣ�����������0                              
								//			0 = û������ʱ�ж�       
								//                                  
								//Bit 3 		sradif		AD�ж��жϱ�־���������㣬Ӳ���ø�            
								//			1 = ����AD�жϣ�����������0                                
								//			0 = û����AD�ж�   
								//                                       
								//Bit 1 		e1if		�ⲿ�ж�1�жϱ�־���������㣬Ӳ���ø�           
								//			1 =�ⲿ�ж�1�����жϣ�����������0                           
								//			0 =�ⲿ�ж�1û�����ж�                                     
								//
								//Bit 0 		e0if		�ⲿ�ж�0�жϱ�־���������㣬Ӳ���ø�          
								//			1 = �ⲿ�ж�0�����жϣ�����������0                          
								//			0 =�ⲿ�ж�0û�����ж�                                     
								//		    
	INTF2 =0X00;				//���жϱ�־
								//intf2�����ϵ縴λֵΪ��uuu0uuuu��
								//Bit 5 		tm4if		12-Bit��ʱ/������4�жϱ�־���������㣬Ӳ���ø�
                                //			1 = ������ʱ�жϣ�����������0                              
	      	                    //			0 = û������ʱ�ж�    
	                            //
								//Bit 4 		tm3if		12-Bit��ʱ/������3�жϱ�־���������㣬Ӳ���ø�
                                //			1 = ������ʱ�жϣ�����������0                              
	      	                    //			0 = û������ʱ�ж�                                         
                                //
	INTF3 =0X00; 	    		//���жϱ�־
								//inte3�����ϵ縴λֵΪ��0uuuuu00��
								//Bit 7 		cmpif	�Ƚ����жϱ�־	
								//Bit 1 		urtif	UART����ͨ�ŷ����жϱ�־
								//Bit 0 		urrif	UART����ͨ�Ž����жϱ�־       	          
	      	                    
	      	                    
	INTE =0X90;  				//�������ж�ʹ�ܡ�TM0�ж�ʹ�ܡ��ⲿ�ж�0ʹ��
								//inte�����ϵ縴λֵΪ��00u00u00�� 
								//Bit 7 		gie			ȫ���ж�ʹ�ܱ�־                
			         	     	//			1 = ʹ�����з������ж�                     
			         	     	//			0 = ��ʹ�������ж� 
			         	     	//                       
			         	     	//Bit 6 		tm2ie		12-Bit��ʱ/������2�ж�ʹ�ܱ�־
			         	     	//			1 = ʹ�ܶ�ʱ/������2�ж�                   
			         	     	//			0 = ��ʹ�ܶ�ʱ/������2�ж�  
			         	     	//              
			         	     	//Bit 4 		tm0ie		8-Bit��ʱ��0�ж�ʹ�ܱ�־      
			         	     	//			1 = ʹ�ܶ�ʱ��0�ж�                        
			         	     	//			0 = ��ʹ�ܶ�ʱ��0�ж�                      
			         	     	//
			         	     	//Bit 3 		sradie		AD�ж�ʹ�ܱ�־               
			         	     	//			1 = ʹ��AD�ж�                             
			         	     	//			0 = ��ʹ��AD�ж�                           
			         	     	//
			         	     	//Bit 1 		e1ie		�ⲿ�ж�1ʹ�ܱ�־              
			         	     	//			1 =ʹ���ⲿ�ж�1                           
			         	     	//			0 = ��ʹ���ⲿ�ж�1                        
			         	     	//
			         	     	//Bit 0 		e0ie		�ⲿ�ж�0ʹ�ܱ�־              
			         	     	//			1 = ʹ���ⲿ�ж�0                          
			         	     	//			0 = ��ʹ���ⲿ�ж�0                        
			         	     	//		         	     	
	INTE2 =0X00; 	    		//�رն�ʱ��3,4�ж�ʹ��
								//inte2�����ϵ縴λֵΪ��uu00uuuu��
								//Bit 5 		tm4ie		12-Bit��ʱ/������4�ж�ʹ�ܱ�־
								//			1 = ʹ�ܶ�ʱ/������4�ж�
								//			0 = ��ʹ�ܶ�ʱ/������4�ж�
	                            //
								//Bit 4 		tm3ie		12-Bit��ʱ/������3�ж�ʹ�ܱ�־
								//			1 = ʹ�ܶ�ʱ/������3�ж�
								//			0 = ��ʹ�ܶ�ʱ/������3�ж�
	                            
	INTE3 =0X00; 	    		//�رն�ʱ��3�ж�ʹ��
								//inte3�����ϵ縴λֵΪ��0uuuuu00��
								//Bit 7 		cmpie	�Ƚ����ж�ʹ��
								//			1 = ʹ�ܱȽ����ж�
								//			0 = ��ֹ�Ƚ����ж�
	                            //
								//Bit 1 		urtie	UART�ķ����ж�ʹ��
								//			1 = ʹ��UART�ķ����ж�    
								//			0 = ��ֹUART�ķ����ж�   
								//
								//Bit 0 		urrie	UART�Ľ����ж�ʹ�� 
								//			1 = ʹ��UART�Ľ����ж�      
		       	                //			0 = ��ֹUART�Ľ����ж�     


}




