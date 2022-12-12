#include    <xc.h>
#include    "ConfigPinsLibCmt2300A.h"
#include    "InitProcessor.h"
interval_t       Interval;
unsigned char    Counter1ms = 10;
unsigned char    Counter10ms = 10;
unsigned char    Counter100ms = 10;

//void InitTmr0(void){
//	T0CONbits.T0PS = 1;
////    T0PS2 = 0;T0PS1 = 0;T0PS0 = 0;
///*  
//    111 = 1:256 prescale value 8192
//    110 = 1:128 prescale value 4096
//    101 = 1:64 prescale value 2048
//    100 = 1:32 prescale value 1024
//    011 = 1:16 prescale value �� 32�?� 512���
//    010 = 1:8 prescale value 256
//    001 = 1:4 prescale value 128
//    000 = 1:2 prescale value 64
// */
//	PSA = 0;
//	T08BIT = 1;
//	T0CS = 0;
//    T0CONbits.TMR0ON = 0; // ���. 14
//    TMR0IP = 0; // ������������� ������ ��������� �� ���������� �� TMR0
//    TMR0IE = 0;
//    TMR0IF = 0;
//    
//}
//void InitTmr1(void){
//    T1CONbits.RD16 = 0; // ������ �������� � 16 ������ ������
//    T1CONbits.T1CKPS = 2;//2; //������������� �������������� ������� =4
//    T1CONbits.T1OSCEN = 1; // �������� ��������� ������� 1
//    T1CONbits.nT1SYNC = 1; // ������������� ������ � ����� ������������ ��������
//    T1CONbits.TMR1CS = 1; // ������ ���������� ������� ��������
//    T1CONbits.TMR1ON = 0; // ��������� ������� 1
//    TMR1IP = 0;             // ������ ��������� ���������� �� ������� 1
//    TMR1IE = 0;
//    TMR1IF = 0;
//}
void InitTmr2(void){
	//����������� ������� 2 ������� T2CON
    T2CONbits.T2OUTPS = 0x0F;
	//T2OUTPS3 = 1;T2OUTPS2 = 1;T2OUTPS1 = 1;T2OUTPS0 = 1;	//����������� �����������
	//TOUTPS3:TOUTPS0: ���� ������ ������������ �����������
	//0000 = 1:1 ������������
	//0001 = 1:2 ������������
	//�
	//�
	//�
	//1111 = 1:16 ������������*/
	T2CONbits.T2CKPS = 1;
//    T2CONbits.T2CKPS1 = 0; T2CONbits.T2CKPS0 = 0;						//
	//����������� �����������
	//00 = ������������ 1
	//01 = ������������ 4
	//1X = ������������ 16
	PR2 = 124; //
    T2CONbits.TMR2ON = 0; //��������� ������� 2
    IPR1bits.TMR2IP = 0; // ������������� ������ ��������� �� ���������� �� TMR2
	PIE1bits.TMR2IE = 0;									//��������� �� ������� 2
    PIR1bits.TMR2IF = 0;
									
	//Tint_t2=((4*N_pre*(PR2+1))/Fosc)*N_post
	//��� Tint_t2 - ������ ��������� ���������� �� TMR2
	//N_pre 		- �������� �����������
	//N_post 		- �������� �����������
	//PR2			- �������� �������� PR2
	//Fosc		- �������� ������� ���������� � �?�
	//=>PR2= ((Tint_t2*Fosc)/(4*N_pre*N_post))-1
	}
//void InitTmr3(void){
//    T3CONbits.T3RD16 = 0; // ������ �������� � 16 ������ ������
//    T3CONbits.T3CKPS = 1;//2; //������������� �������������� �������
//    T3CONbits.nT3SYNC = 1; // ������������� ������ � ����� ������������ ��������
//    T3CONbits.TMR3CS = 0; // ������ ���������� ���������� ��������
//    T3CONbits.TMR3ON = 0; // ��������� ������� 3
//    TMR3IP = 0;             // ������ ��������� ���������� �� ������� 3
//    TMR3IE = 0;
//    TMR3IF = 0;
//}
//void OpenTmr0(void){
//	TMR0H = 0x00;
//	TMR0L = 0x00;
//	TMR0IF = 0;
//	TMR0IE = 1;
//	T0CONbits.TMR0ON = 1;
//}
//void CloseTmr0(void){
//	TMR0IF = 0;
//	TMR0IE = 0;
//	T0CONbits.TMR0ON = 0;
//}
//void OpenTmr1(void){
//	TMR1IF = 0;
//	TMR1IE = 1;
//	TMR1ON = 1;
//}
//void CloseTmr1(void){
//	TMR1ON = 0;
//	TMR1IE = 0;
//	TMR1IF = 0;
//}
void OpenTmr2(void){
	TMR2 = 0;
	TMR2IF = 0;
	TMR2IE = 1;
	TMR2ON = 1;
}
//void CloseTmr2(void){
//	TMR2ON = 0;
//	TMR2IE = 0;
//	TMR2IF = 0;
//}
//void OpenTmr3(void){
//	TMR3 = 3036;
//	TMR3IF = 0;
//	TMR3IE = 1;
//	TMR3ON = 1;
//}
void InitInterrupt(void){
    RCONbits.IPEN = 1;   // ���������� �������������� ����������
    INTCONbits.GIEH = 1;   // ���������� ������������������ ���������� 
    INTCONbits.GIEL = 1;   // ���������� ����������������� ����������
    INTCONbits.INT0IF = 0; // ���������� ���� ��������� INT0
    INTCONbits.INT0IE = 1; // �������� ���������� �� ������ ������
}
void ProcessorInit(void){
    InitPinsCMT2300();
    InitTmr2();
    OpenTmr2();
    InitInterrupt();
    
}