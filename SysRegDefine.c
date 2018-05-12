//==============================================
// Date:2017-04-27
// Version: V1.0.0 
//==============================================

//Data Memory Organization 00h-08h
volatile unsigned char IND0             @ 0x00;     //{ IND0[7:0] }
volatile unsigned char FSR0             @ 0x02;     //{ FSR0[7:0] }
volatile unsigned char STATUS           @ 0x04;     //{ LVD36, LVD24, 0, PD, TO, DC, C, Z }
volatile unsigned char WORK             @ 0x05;     //{ WORK[7:0] }
volatile unsigned char INTF             @ 0x06;     //{ 0, TM2IF, 0, TM0IF, SRADIF, 0, E1IF, E0IF }
volatile unsigned char INTE             @ 0x07;     //{ GIE, TM2IE, 0, TM0IE, SRADIE, 0, E1IE, E0IE }

//Peripheral special registers 0Ah-7Ch
volatile unsigned char EADRH            @ 0x0A;     //{ 0, 0, 0, 0, PAR[10:8] }
volatile unsigned char EADRL            @ 0x0B;     //{ PAR[7:0] }
volatile unsigned char EDATH            @ 0x0C;     //{ EDATH[7:0] }
volatile unsigned char WDTCON           @ 0x0D;     //{ WDTEN, 0, 0, 0, 0, WTS[2:0] }
volatile unsigned char WDTIN            @ 0x0E;     //{ WDTIN[7:0] }
volatile unsigned char TM0CON           @ 0x0F;     //{ T0EN, T0RATE[2:0], 0, T0RSTB, T0SEL[1:0] }
volatile unsigned char TM0IN            @ 0x10;     //{ TM0IN[7:0] }
volatile unsigned char TM0CNT           @ 0x11;     //{ TM0CNT[7:0] }
volatile unsigned char MCK              @ 0x16;     //{ CST, CST_IN, CST_WDT, EO_SLP, 0, 0, 0, CLKSEL }
volatile unsigned char TM2CON           @ 0x17;     //{ T2EN, T2RATE[2:0], T2CKS, T2RSTB, T2OUT, PWM2OUT }
volatile unsigned char TM2IN            @ 0x18;     //{ TM2IN[7:0] }
volatile unsigned char TM2CNT           @ 0x19;     //{ TM2CNT[7:0] }
volatile unsigned char TM2R             @ 0x1A;     //{ TM2R[7:0] }
volatile unsigned char TM3CON           @ 0x1B;     //{ T3EN, T3RATE[2:0], T3CKS, T3RSTB, T3OUT, PWM3OUT }
volatile unsigned char TM3IN            @ 0x1C;     //{ TM3IN[7:0] }
volatile unsigned char TM3CNT           @ 0x1D;     //{ TM3CNT[7:0] }
volatile unsigned char TM3R             @ 0x1E;     //{ TM3R[7:0] }
volatile unsigned char PT1              @ 0x20;     //{ PT1[7:1], 0 }
volatile unsigned char PT1EN            @ 0x21;     //{ PT1EN[7:1], 0 }
volatile unsigned char PT1PU            @ 0x22;     //{ PT1PU[7:1], 0 }
volatile unsigned char PT1CON           @ 0x23;     //{ PT11OD, PT1W[3:0], E1M, E0M[1:0] }
volatile unsigned char PT3              @ 0x28;     //{ PT3[7:0] }
volatile unsigned char PT3EN            @ 0x29;     //{ PT3EN[7:0] }
volatile unsigned char PT3PU            @ 0x2A;     //{ PT3PU[7:0] }
volatile unsigned char PT3CON           @ 0x2B;     //{ PT3CON[7:0] }
volatile unsigned char PT3OD            @ 0x2C;     //{ 0, PT36OD, PT35OD, 0, 0, 0, 0, 0 }
volatile unsigned char TM3CON2          @ 0x2D;     //{ DT3CK[1:0], DT3CNT[2:0], DT3_EN, P3H_OEN, P3L_OEN }
volatile unsigned char TMCON            @ 0x2E;     //{ P3HINV, P3LINV, 0, 0, 0, PWM4PO, PWM3PO, PWM2PO }
volatile unsigned char TMCON2           @ 0x2F;     //{ 0, 0, T4SEL[1:0], T3SEL[1:0], T2SEL[1:0] }
volatile unsigned char PT5              @ 0x30;     //{ 0, 0, 0, 0, 0, PT5[2:0] }
volatile unsigned char PT5EN            @ 0x31;     //{ 0, 0, 0, 0, 0, PT5EN[2:0] }
volatile unsigned char PT5PU            @ 0x32;     //{ 0, 0, 0, 0, 0, PT5PU[2:0] }
volatile unsigned char PT5CON           @ 0x33;     //{ 0, 0, 0, 0, 0, PT51OD, PT50OD, PT5CON0 }
volatile unsigned char PT1CON1          @ 0x38;     //{ 0, 0, 0, 0, PT1W2[3:0] }
volatile unsigned char EX0CFG           @ 0x39;     //{ PWMRL[1:0], POLSEL, 0, 0, 0, EX0FILT[1:0] }
volatile unsigned char INTF2            @ 0x3C;     //{ 0, 0, TM4IF, TM3IF, 0, 0, 0, 0 }
volatile unsigned char INTE2            @ 0x3D;     //{ 0, 0, TM4IE, TM3IE, 0, 0, 0, 0 }
volatile unsigned char INTF3            @ 0x3E;     //{ CMPIF, 0, 0, 0, 0, 0, URTIF, URRIF }
volatile unsigned char INTE3            @ 0x3F;     //{ CMPIE, 0, 0, 0, 0, 0, URTIE, URRIE }
volatile unsigned char TM4CON           @ 0x40;     //{ T4EN, T4RATE[2:0], T4CKS, T4RSTB, T4OUT, PWM4OUT }
volatile unsigned char TM4IN            @ 0x41;     //{ TM4IN[7:0] }
volatile unsigned char TM4CNT           @ 0x42;     //{ TM4CNT[7:0] }
volatile unsigned char TM4R             @ 0x43;     //{ TM4R[7:0] }
volatile unsigned char TM2INH           @ 0x44;     //{ 0, 0, 0, 0, TM2IN[11:8] }
volatile unsigned char TM2CNTH          @ 0x45;     //{ 0, 0, 0, 0, TM2CNT[11:8] }
volatile unsigned char TM2RH            @ 0x46;     //{ 0, 0, 0, 0, TM2R[11:8] }
volatile unsigned char TM3INH           @ 0x47;     //{ 0, 0, 0, 0, TM3IN[11:8] }
volatile unsigned char TM3CNTH          @ 0x48;     //{ 0, 0, 0, 0, TM3CNT[11:8] }
volatile unsigned char TM3RH            @ 0x49;     //{ 0, 0, 0, 0, TM3R[11:8] }
volatile unsigned char TM4INH           @ 0x4A;     //{ 0, 0, 0, 0, TM4IN[11:8] }
volatile unsigned char TM4CNTH          @ 0x4B;     //{ 0, 0, 0, 0, TM4CNT[11:8] }
volatile unsigned char TM4RH            @ 0x4C;     //{ 0, 0, 0, 0, TM4R[11:8] }
volatile unsigned char SRADCON0         @ 0x50;     //{ QDIF, 0, SRADACKS[1:0], 0, 0, SRADCKS[1:0] }
volatile unsigned char SRADCON1         @ 0x51;     //{ SRADEN, SRADS, OFTEN, CALIF, ENOV, OFFEX, VREFS[1:0] }
volatile unsigned char SRADCON2         @ 0x52;     //{ CHS[3:0], 0, 0, REF_SEL[1:0] }
volatile unsigned char SRADL            @ 0x54;     //{ SRAD[7:0] }
volatile unsigned char SRADH            @ 0x55;     //{ 0, 0, 0, 0, SRAD[11:8] }
volatile unsigned char SROFTL           @ 0x56;     //{ SROFT[7:0] }
volatile unsigned char SROFTH           @ 0x57;     //{ 0, 0, 0, 0, SROFT[11:8] }
volatile unsigned char TRIM_EX          @ 0x59;     //{ TRIM_EX[7:0] }
volatile unsigned char TRIM_REF         @ 0x5A;     //{ TRIM_REF[7:0] }
volatile unsigned char LCDCOM           @ 0x5B;     //{ VLCD_SEL, 0, 0, 0, COM[3:0] }
volatile unsigned char LCDSEG           @ 0x5C;     //{ 0, 0, 0, SEG[4:0] }
volatile unsigned char LVDCON           @ 0x5E;     //{ LVD36, 0, 0, 0, LVD_TRIM[3:0] }
volatile unsigned char METCH            @ 0x5F;     //{ METCH[7:0] }
volatile unsigned char CMPCON           @ 0x6A;     //{ CMPEN, 0, 0, 0, 0, 0, CMP_OEN, CMPOUT }
volatile unsigned char SCON1            @ 0x77;     //{ SM0, SM1, SM2, REN, TB8, RB8, 0, 0 }
volatile unsigned char SCON2            @ 0x78;     //{ SMOD, URCLK[1:0], 0, UARTEN, PINCTL[2:0] }
volatile unsigned char SBUF             @ 0x79;     //{ SBUF[7:0] }
volatile unsigned char CURCON           @ 0x7A;     //{ P36CUR, P35CUR, P14CUR[1:0], 0, CURP17[1:0], 0 }
volatile unsigned char SYSCFG0          @ 0x7B;     //{ VTHSEL, RST20_SEL, VTHP30[1:0], P30REFEN, LFILT_EN, LFILT_S[1:0] }
volatile unsigned char SYSCFG1          @ 0x7C;     //{ PDP13, PDP31, PDP34, PDP36, CURP16[1:0], CURP15[1:0] }

//-------------------------------------------------------
//  STATUS register bit map
//-------------------------------------------------------
volatile sbit Z                         @ 0x04*8+0;
volatile sbit C                         @ 0x04*8+1;
volatile sbit DC                        @ 0x04*8+2;
volatile sbit TO                        @ 0x04*8+3;
volatile sbit PD                        @ 0x04*8+4;
volatile sbit LVD24                     @ 0x04*8+6;
volatile sbit LVD36                     @ 0x04*8+7;

//-------------------------------------------------------
//  INTF register bit map
//-------------------------------------------------------
volatile sbit E0IF                      @ 0x06*8+0;
volatile sbit E1IF                      @ 0x06*8+1;
volatile sbit SRADIF                    @ 0x06*8+3;
volatile sbit TM0IF                     @ 0x06*8+4;
volatile sbit TM2IF                     @ 0x06*8+6;

//-------------------------------------------------------
//  INTE register bit map
//-------------------------------------------------------
volatile sbit E0IE                      @ 0x07*8+0;
volatile sbit E1IE                      @ 0x07*8+1;
volatile sbit SRADIE                    @ 0x07*8+3;
volatile sbit TM0IE                     @ 0x07*8+4;
volatile sbit TM2IE                     @ 0x07*8+6;
volatile sbit GIE                       @ 0x07*8+7;

//-------------------------------------------------------
//  EADRH register bit map
//-------------------------------------------------------
volatile sbit PAR_8                     @ 0x0A*8+0;
volatile sbit PAR_9                     @ 0x0A*8+1;
volatile sbit PAR_10                    @ 0x0A*8+2;
volatile sbit PAR_11                    @ 0x0A*8+3;

//-------------------------------------------------------
//  WDTCON register bit map
//-------------------------------------------------------
volatile sbit WTS_0                     @ 0x0D*8+0;
volatile sbit WTS_1                     @ 0x0D*8+1;
volatile sbit WTS_2                     @ 0x0D*8+2;
volatile sbit WDTEN                     @ 0x0D*8+7;

//-------------------------------------------------------
//  TM0CON register bit map
//-------------------------------------------------------
volatile sbit T0SEL_0                   @ 0x0F*8+0;
volatile sbit T0SEL_1                   @ 0x0F*8+1;
volatile sbit T0RSTB                    @ 0x0F*8+2;
volatile sbit T0RATE_0                  @ 0x0F*8+4;
volatile sbit T0RATE_1                  @ 0x0F*8+5;
volatile sbit T0RATE_2                  @ 0x0F*8+6;
volatile sbit T0EN                      @ 0x0F*8+7;

//-------------------------------------------------------
//  MCK register bit map
//-------------------------------------------------------
volatile sbit CLKSEL                    @ 0x16*8+0;
volatile sbit EO_SLP                    @ 0x16*8+4;
volatile sbit CST_WDT                   @ 0x16*8+5;
volatile sbit CST_IN                    @ 0x16*8+6;
volatile sbit CST                       @ 0x16*8+7;

//-------------------------------------------------------
//  TM2CON register bit map
//-------------------------------------------------------
volatile sbit PWM2OUT                   @ 0x17*8+0;
volatile sbit T2OUT                     @ 0x17*8+1;
volatile sbit T2RSTB                    @ 0x17*8+2;
volatile sbit T2CKS                     @ 0x17*8+3;
volatile sbit T2RATE_0                  @ 0x17*8+4;
volatile sbit T2RATE_1                  @ 0x17*8+5;
volatile sbit T2RATE_2                  @ 0x17*8+6;
volatile sbit T2EN                      @ 0x17*8+7;

//-------------------------------------------------------
//  TM3CON register bit map
//-------------------------------------------------------
volatile sbit PWM3OUT                   @ 0x1B*8+0;
volatile sbit T3OUT                     @ 0x1B*8+1;
volatile sbit T3RSTB                    @ 0x1B*8+2;
volatile sbit T3CKS                     @ 0x1B*8+3;
volatile sbit T3RATE_0                  @ 0x1B*8+4;
volatile sbit T3RATE_1                  @ 0x1B*8+5;
volatile sbit T3RATE_2                  @ 0x1B*8+6;
volatile sbit T3EN                      @ 0x1B*8+7;

//-------------------------------------------------------
//  PT1 register bit map
//-------------------------------------------------------
volatile sbit PT1_1                     @ 0x20*8+1;
volatile sbit PT1_2                     @ 0x20*8+2;
volatile sbit PT1_3                     @ 0x20*8+3;
volatile sbit PT1_4                     @ 0x20*8+4;
volatile sbit PT1_5                     @ 0x20*8+5;
volatile sbit PT1_6                     @ 0x20*8+6;
volatile sbit PT1_7                     @ 0x20*8+7;

//-------------------------------------------------------
//  PT1EN register bit map
//-------------------------------------------------------
volatile sbit PT1EN_1                   @ 0x21*8+1;
volatile sbit PT1EN_2                   @ 0x21*8+2;
volatile sbit PT1EN_3                   @ 0x21*8+3;
volatile sbit PT1EN_4                   @ 0x21*8+4;
volatile sbit PT1EN_5                   @ 0x21*8+5;
volatile sbit PT1EN_6                   @ 0x21*8+6;
volatile sbit PT1EN_7                   @ 0x21*8+7;

//-------------------------------------------------------
//  PT1PU register bit map
//-------------------------------------------------------
volatile sbit PT1PU_1                   @ 0x22*8+1;
volatile sbit PT1PU_2                   @ 0x22*8+2;
volatile sbit PT1PU_3                   @ 0x22*8+3;
volatile sbit PT1PU_4                   @ 0x22*8+4;
volatile sbit PT1PU_5                   @ 0x22*8+5;
volatile sbit PT1PU_6                   @ 0x22*8+6;
volatile sbit PT1PU_7                   @ 0x22*8+7;

//-------------------------------------------------------
//  PT1CON register bit map
//-------------------------------------------------------
volatile sbit E0M_0                     @ 0x23*8+0;
volatile sbit E0M_1                     @ 0x23*8+1;
volatile sbit E1M                       @ 0x23*8+2;
volatile sbit PT1W_0                    @ 0x23*8+3;
volatile sbit PT1W_1                    @ 0x23*8+4;
volatile sbit PT1W_2                    @ 0x23*8+5;
volatile sbit PT1W_3                    @ 0x23*8+6;
volatile sbit PT11OD                    @ 0x23*8+7;

//-------------------------------------------------------
//  PT3 register bit map
//-------------------------------------------------------
volatile sbit PT3_0                     @ 0x28*8+0;
volatile sbit PT3_1                     @ 0x28*8+1;
volatile sbit PT3_2                     @ 0x28*8+2;
volatile sbit PT3_3                     @ 0x28*8+3;
volatile sbit PT3_4                     @ 0x28*8+4;
volatile sbit PT3_5                     @ 0x28*8+5;
volatile sbit PT3_6                     @ 0x28*8+6;
volatile sbit PT3_7                     @ 0x28*8+7;

//-------------------------------------------------------
//  PT3EN register bit map
//-------------------------------------------------------
volatile sbit PT3EN_0                   @ 0x29*8+0;
volatile sbit PT3EN_1                   @ 0x29*8+1;
volatile sbit PT3EN_2                   @ 0x29*8+2;
volatile sbit PT3EN_3                   @ 0x29*8+3;
volatile sbit PT3EN_4                   @ 0x29*8+4;
volatile sbit PT3EN_5                   @ 0x29*8+5;
volatile sbit PT3EN_6                   @ 0x29*8+6;
volatile sbit PT3EN_7                   @ 0x29*8+7;

//-------------------------------------------------------
//  PT3PU register bit map
//-------------------------------------------------------
volatile sbit PT3PU_0                   @ 0x2a*8+0;
volatile sbit PT3PU_1                   @ 0x2a*8+1;
volatile sbit PT3PU_2                   @ 0x2a*8+2;
volatile sbit PT3PU_3                   @ 0x2a*8+3;
volatile sbit PT3PU_4                   @ 0x2a*8+4;
volatile sbit PT3PU_5                   @ 0x2a*8+5;
volatile sbit PT3PU_6                   @ 0x2a*8+6;
volatile sbit PT3PU_7                   @ 0x2a*8+7;

//-------------------------------------------------------
//  PT3CON register bit map
//-------------------------------------------------------
volatile sbit PT3CON_0                  @ 0x2b*8+0;
volatile sbit PT3CON_1                  @ 0x2b*8+1;
volatile sbit PT3CON_2                  @ 0x2b*8+2;
volatile sbit PT3CON_3                  @ 0x2b*8+3;
volatile sbit PT3CON_4                  @ 0x2b*8+4;
volatile sbit PT3CON_5                  @ 0x2b*8+5;
volatile sbit PT3CON_6                  @ 0x2b*8+6;
volatile sbit PT3CON_7                  @ 0x2b*8+7;

//-------------------------------------------------------
//  PT3OD register bit map
//-------------------------------------------------------
volatile sbit PT35OD                    @ 0x2C*8+5;
volatile sbit PT36OD                    @ 0x2C*8+6;

//-------------------------------------------------------
//  PT3OD register bit map
//-------------------------------------------------------
volatile sbit PT35OD                    @ 0x2C*8+5;
volatile sbit PT36OD                    @ 0x2C*8+6;

//-------------------------------------------------------
//  TM3CON2 register bit map
//-------------------------------------------------------
volatile sbit P3L_OEN                   @ 0x2D*8+0;
volatile sbit P3H_OEN                   @ 0x2D*8+1;
volatile sbit DT3_EN                    @ 0x2D*8+2;
volatile sbit DT3CNT_0                  @ 0x2D*8+3;
volatile sbit DT3CNT_1                  @ 0x2D*8+4;
volatile sbit DT3CNT_2                  @ 0x2D*8+5;
volatile sbit DT3CK_0                   @ 0x2D*8+6;
volatile sbit DT3CK_1                   @ 0x2D*8+7;

//-------------------------------------------------------
//  TMCON register bit map
//-------------------------------------------------------
volatile sbit PWM2PO                    @ 0x2E*8+0;
volatile sbit PWM3PO                    @ 0x2E*8+1;
volatile sbit PWM4PO                    @ 0x2E*8+2;
volatile sbit P3LINV                    @ 0x2E*8+6;
volatile sbit P3HINV                    @ 0x2E*8+7;

//-------------------------------------------------------
//  TMCON2 register bit map
//-------------------------------------------------------
volatile sbit T2SEL_0                   @ 0x2F*8+0;
volatile sbit T2SEL_1                   @ 0x2F*8+1;
volatile sbit T3SEL_0                   @ 0x2F*8+2;
volatile sbit T3SEL_1                   @ 0x2F*8+3;
volatile sbit T4SEL_0                   @ 0x2F*8+4;
volatile sbit T4SEL_1                   @ 0x2F*8+5;

//-------------------------------------------------------
//  PT5 register bit map
//-------------------------------------------------------
volatile sbit PT5_0                     @ 0x30*8+0;
volatile sbit PT5_1                     @ 0x30*8+1;
volatile sbit PT5_2                     @ 0x30*8+2;

//-------------------------------------------------------
//  PT5EN register bit map
//-------------------------------------------------------
volatile sbit PT5EN_0                   @ 0x31*8+0;
volatile sbit PT5EN_1                   @ 0x31*8+1;
volatile sbit PT5EN_2                   @ 0x31*8+2;

//-------------------------------------------------------
//  PT5PU register bit map
//-------------------------------------------------------
volatile sbit PT5PU_0                   @ 0x32*8+0;
volatile sbit PT5PU_1                   @ 0x32*8+1;
volatile sbit PT5PU_2                   @ 0x32*8+2;

//-------------------------------------------------------
//  PT5CON register bit map
//-------------------------------------------------------
volatile sbit PT5CON0                   @ 0x33*8+0;
volatile sbit PT50OD                    @ 0x33*8+1;
volatile sbit PT51OD                    @ 0x33*8+2;

//-------------------------------------------------------
//  PT1CON1 register bit map
//-------------------------------------------------------
volatile sbit PT1W2_0                   @ 0x38*8+0;
volatile sbit PT1W2_1                   @ 0x38*8+1;
volatile sbit PT1W2_2                   @ 0x38*8+2;
volatile sbit PT1W2_3                   @ 0x38*8+3;

//-------------------------------------------------------
//  EX0CFG register bit map
//-------------------------------------------------------
volatile sbit EX0FILT_0                 @ 0x39*8+0;
volatile sbit EX0FILT_1                 @ 0x39*8+1;
volatile sbit POLSEL                    @ 0x39*8+5;
volatile sbit PWMRL_0                   @ 0x39*8+6;
volatile sbit PWMRL_1                   @ 0x39*8+7;

//-------------------------------------------------------
//  INTF2 register bit map
//-------------------------------------------------------
volatile sbit TM3IF                     @ 0x3C*8+4;
volatile sbit TM4IF                     @ 0x3C*8+5;

//-------------------------------------------------------
//  INTE2 register bit map
//-------------------------------------------------------
volatile sbit TM3IE                     @ 0x3D*8+4;
volatile sbit TM4IE                     @ 0x3D*8+5;

//-------------------------------------------------------
//  INTF3 register bit map
//-------------------------------------------------------
volatile sbit URRIF                     @ 0x3E*8+0;
volatile sbit URTIF                     @ 0x3E*8+1;
volatile sbit CMPIF                     @ 0x3E*8+7;

//-------------------------------------------------------
//  INTE3 register bit map
//-------------------------------------------------------
volatile sbit URRIE                     @ 0x3F*8+0;
volatile sbit URTIE                     @ 0x3F*8+1;
volatile sbit CMPIE                     @ 0x3F*8+7;

//-------------------------------------------------------
//  TM4CON register bit map
//-------------------------------------------------------
volatile sbit PWM4OUT                   @ 0x40*8+0;
volatile sbit T4OUT                     @ 0x40*8+1;
volatile sbit T4RSTB                    @ 0x40*8+2;
volatile sbit T4CKS                     @ 0x40*8+3;
volatile sbit T4RATE_0                  @ 0x40*8+4;
volatile sbit T4RATE_1                  @ 0x40*8+5;
volatile sbit T4RATE_2                  @ 0x40*8+6;
volatile sbit T4EN                      @ 0x40*8+7;

//-------------------------------------------------------
//  TM2INH register bit map
//-------------------------------------------------------
volatile sbit TM2IN_8                   @ 0x44*8+0;
volatile sbit TM2IN_9                   @ 0x44*8+1;
volatile sbit TM2IN_10                  @ 0x44*8+2;
volatile sbit TM2IN_11                  @ 0x44*8+3;

//-------------------------------------------------------
//  TM2CNTH register bit map
//-------------------------------------------------------
volatile sbit TM2CNT_8                  @ 0x45*8+0;
volatile sbit TM2CNT_9                  @ 0x45*8+1;
volatile sbit TM2CNT_10                 @ 0x45*8+2;
volatile sbit TM2CNT_11                 @ 0x45*8+3;

//-------------------------------------------------------
//  TM2RH register bit map
//-------------------------------------------------------
volatile sbit TM2R_8                    @ 0x46*8+0;
volatile sbit TM2R_9                    @ 0x46*8+1;
volatile sbit TM2R_10                   @ 0x46*8+2;
volatile sbit TM2R_11                   @ 0x46*8+3;

//-------------------------------------------------------
//  TM3INH register bit map
//-------------------------------------------------------
volatile sbit TM3IN_8                   @ 0x47*8+0;
volatile sbit TM3IN_9                   @ 0x47*8+1;
volatile sbit TM3IN_10                  @ 0x47*8+2;
volatile sbit TM3IN_11                  @ 0x47*8+3;

//-------------------------------------------------------
//  TM3CNTH register bit map
//-------------------------------------------------------
volatile sbit TM3CNT_8                  @ 0x48*8+0;
volatile sbit TM3CNT_9                  @ 0x48*8+1;
volatile sbit TM3CNT_10                 @ 0x48*8+2;
volatile sbit TM3CNT_11                 @ 0x48*8+3;

//-------------------------------------------------------
//  TM3RH register bit map
//-------------------------------------------------------
volatile sbit TM3R_8                    @ 0x49*8+0;
volatile sbit TM3R_9                    @ 0x49*8+1;
volatile sbit TM3R_10                   @ 0x49*8+2;
volatile sbit TM3R_11                   @ 0x49*8+3;

//-------------------------------------------------------
//  TM4INH register bit map
//-------------------------------------------------------
volatile sbit TM4IN_8                   @ 0x4A*8+0;
volatile sbit TM4IN_9                   @ 0x4A*8+1;
volatile sbit TM4IN_10                  @ 0x4A*8+2;
volatile sbit TM4IN_11                  @ 0x4A*8+3;

//-------------------------------------------------------
//  TM4CNTH register bit map
//-------------------------------------------------------
volatile sbit TM4CNT_8                  @ 0x4B*8+0;
volatile sbit TM4CNT_9                  @ 0x4B*8+1;
volatile sbit TM4CNT_10                 @ 0x4B*8+2;
volatile sbit TM4CNT_11                 @ 0x4B*8+3;

//-------------------------------------------------------
//  TM4RH register bit map
//-------------------------------------------------------
volatile sbit TM4R_8                    @ 0x4C*8+0;
volatile sbit TM4R_9                    @ 0x4C*8+1;
volatile sbit TM4R_10                   @ 0x4C*8+2;
volatile sbit TM4R_11                   @ 0x4C*8+3;

//-------------------------------------------------------
//  SRADCON0 register bit map
//-------------------------------------------------------
volatile sbit SRADCKS_0                 @ 0x50*8+0;
volatile sbit SRADCKS_1                 @ 0x50*8+1;
volatile sbit SRADACKS_0                @ 0x50*8+4;
volatile sbit SRADACKS_1                @ 0x50*8+5;

//-------------------------------------------------------
//  SRADCON1 register bit map
//-------------------------------------------------------
volatile sbit VREFS_0                   @ 0x51*8+0;
volatile sbit VREFS_1                   @ 0x51*8+1;
volatile sbit OFFEX                     @ 0x51*8+2;
volatile sbit ENOV                      @ 0x51*8+3;
volatile sbit CALIF                     @ 0x51*8+4;
volatile sbit OFTEN                     @ 0x51*8+5;
volatile sbit SRADS                     @ 0x51*8+6;
volatile sbit SRADEN                    @ 0x51*8+7;

//-------------------------------------------------------
//  SRADCON2 register bit map
//-------------------------------------------------------
volatile sbit REF_SEL_0                 @ 0x52*8+0;
volatile sbit REF_SEL_1                 @ 0x52*8+1;
volatile sbit CHS_0                     @ 0x52*8+4;
volatile sbit CHS_1                     @ 0x52*8+5;
volatile sbit CHS_2                     @ 0x52*8+6;
volatile sbit CHS_3                     @ 0x52*8+7;

//-------------------------------------------------------
//  SRADH register bit map
//-------------------------------------------------------
volatile sbit SRAD_8                    @ 0x55*8+0;
volatile sbit SRAD_9                    @ 0x55*8+1;
volatile sbit SRAD_10                   @ 0x55*8+2;
volatile sbit SRAD_11                   @ 0x55*8+3;

//-------------------------------------------------------
//  SROFTH register bit map
//-------------------------------------------------------
volatile sbit SROFT_8                   @ 0x57*8+0;
volatile sbit SROFT_9                   @ 0x57*8+1;
volatile sbit SROFT_10                  @ 0x57*8+2;
volatile sbit SROFT_11                  @ 0x57*8+3;

//-------------------------------------------------------
//  LCDCOM register bit map
//-------------------------------------------------------
volatile sbit COM_0                     @ 0x5B*8+0;
volatile sbit COM_1                     @ 0x5B*8+1;
volatile sbit COM_2                     @ 0x5B*8+2;
volatile sbit COM_3                     @ 0x5B*8+3;
volatile sbit VLCD_SEL                  @ 0x5B*8+7;

//-------------------------------------------------------
//  LCDSEG register bit map
//-------------------------------------------------------
volatile sbit SEG_0                     @ 0x5C*8+0;
volatile sbit SEG_1                     @ 0x5C*8+1;
volatile sbit SEG_2                     @ 0x5C*8+2;
volatile sbit SEG_3                     @ 0x5C*8+3;
volatile sbit SEG_4                     @ 0x5C*8+4;

//-------------------------------------------------------
//  LVDCON register bit map
//-------------------------------------------------------
volatile sbit LVD_TRIM_0                @ 0x5E*8+0;
volatile sbit LVD_TRIM_1                @ 0x5E*8+1;
volatile sbit LVD_TRIM_2                @ 0x5E*8+2;
volatile sbit LVD_TRIM_3                @ 0x5E*8+3;

//-------------------------------------------------------
//  CMPCON register bit map
//-------------------------------------------------------
volatile sbit CMPOUT                    @ 0x6A*8+0;
volatile sbit CMP_OEN                   @ 0x6A*8+1;
volatile sbit CMPEN                     @ 0x6A*8+7;

//-------------------------------------------------------
//  SCON1 register bit map
//-------------------------------------------------------
volatile sbit RB8                       @ 0x77*8+2;
volatile sbit TB8                       @ 0x77*8+3;
volatile sbit REN                       @ 0x77*8+4;
volatile sbit SM2                       @ 0x77*8+5;
volatile sbit SM1                       @ 0x77*8+6;
volatile sbit SM0                       @ 0x77*8+7;

//-------------------------------------------------------
//  SCON2 register bit map
//-------------------------------------------------------
volatile sbit PINCTL_0                  @ 0x78*8+0;
volatile sbit PINCTL_1                  @ 0x78*8+1;
volatile sbit PINCTL_2                  @ 0x78*8+2;
volatile sbit UARTEN                    @ 0x78*8+3;
volatile sbit URCLK_0                   @ 0x78*8+5;
volatile sbit URCLK_1                   @ 0x78*8+6;
volatile sbit SMOD                      @ 0x78*8+7;

//-------------------------------------------------------
//  CURCON register bit map
//-------------------------------------------------------
volatile sbit CURP17_0                  @ 0x7A*8+1;
volatile sbit CURP17_1                  @ 0x7A*8+2;
volatile sbit P14CUR_0                  @ 0x7A*8+4;
volatile sbit P14CUR_1                  @ 0x7A*8+5;
volatile sbit P35CUR                    @ 0x7A*8+6;
volatile sbit P36CUR                    @ 0x7A*8+7;

//-------------------------------------------------------
//  SYSCFG0 register bit map
//-------------------------------------------------------
volatile sbit LFILT_S_0                 @ 0x7B*8+0;
volatile sbit LFILT_S_1                 @ 0x7B*8+1;
volatile sbit LFILT_EN                  @ 0x7B*8+2;
volatile sbit P30REFEN                  @ 0x7B*8+3;
volatile sbit VTHP30_0                  @ 0x7B*8+4;
volatile sbit VTHP30_1                  @ 0x7B*8+5;
volatile sbit RST20_SEL                 @ 0x7B*8+6;
volatile sbit VTHSEL                    @ 0x7B*8+7;

//-------------------------------------------------------
//  SYSCFG1 register bit map
//-------------------------------------------------------
volatile sbit CURP15_0                  @ 0x7C*8+0;
volatile sbit CURP15_1                  @ 0x7C*8+1;
volatile sbit CURP16_0                  @ 0x7C*8+2;
volatile sbit CURP16_1                  @ 0x7C*8+3;
volatile sbit PDP36                     @ 0x7C*8+4;
volatile sbit PDP34                     @ 0x7C*8+5;
volatile sbit PDP31                     @ 0x7C*8+6;
volatile sbit PDP13                     @ 0x7C*8+7;

