/* 
 * File:   ConfigPinsLibCmt2300A.h
 * Author: 11
 *
 * Created on 28 ������ 2022 �., 12:31
 */

// ����� ���������� �� ������ CMT2300A
#define     in  1
#define     out 0

#define DIN_CMT2300          PORTCbits.RC5       // ���� ������ CMT2300A
#define DOUT_CMT2300          LATCbits.LATC5      // ����� ������ CMT2300QA
#define TRIS_DIO_CMT2300    TRISCbits.TRISC5    // ������������� ����������� ����� DIO_CMT2300A
#define TRIS_D_OUT_CMT2300()    TRISCbits.TRISC5 = out    // ������������� ����������� ����� DIO_CMT2300A
#define TRIS_D_IN_CMT2300()     TRISCbits.TRISC5 = in    // ������������� ����������� ����� DIO_CMT2300A

#define SCK_CMT2300         LATCbits.LATC3      // ����� ������������ ������ �� �����  DIO_CMT2300A
#define TRIS_SCK_CMT2300    TRISCbits.TRISC3    // ������������� ����������� ����� SCK_CMT2300A ��������������� �� �����

#define CSB_CMT2300         LATBbits.LATB1      /* ����� ���������� ������� � ��������� 
                                                    ������������ � ���������� CMT2300A �� ��������� 1*/
#define TRIS_CSB_CMT2300    TRISBbits.TRISB1    // ������������� ����������� ����� CSB_CMT2300A ��������������� �� �����

#define FCSB_CMT2300        LATBbits.LATB3      /* ����� ���������� ������� � ��������� FIFO CMT2300A �� ��������� 1*/
#define TRIS_FCSB_CMT2300   TRISBbits.TRISB3    // ������������� ����������� ����� FCSB_CMT2300A ��������������� �� �����
/*
 * ����� ����� CSB_CMT2300 � FCSB_CMT2300 �� ����� ������������ ��������� � ��������� "0"
 */
#define GPIN_1_CMT2300      PORTBbits.RB0       // ���� ��� ����� GPIO1 CMT2300A 
#define GPOUT_1_CMT2300     LATBbits.LATB0      // ����� ��� ����� GPIO1 CMT2300A
#define TRIS_GPIO1_CMT2300  TRISBbits.TRISB0    // ������������� ����������� ����� GPIO1 CMT2300A

/* ���� �� ������������
#define GPI_2_CMT2300       // ���� ��� ����� GPIO2 CMT2300A 
#define GPO_2_CMT2300       // ����� ��� ����� GPIO2 CMT2300A
#define TRIS_GPIO2_CMT2300  // ������������� ����������� ����� GPIO2 CMT2300A

#define GPI_3_CMT2300       // ���� ��� ����� GPIO3 CMT2300A 
#define GPO_3_CMT2300       // ����� ��� ����� GPIO3 CMT2300A
#define TRIS_GPIO3_CMT2300  // ������������� ����������� ����� GPIO3 CMT2300A
*/

// ����� �� ��������� � ������� CMT2300A
#define LED_A1      LATAbits.LATA1
#define TRIS_LED_A1 TRISAbits.TRISA1

#define LED_A2      LATAbits.LATA2
#define TRIS_LED_A2 TRISAbits.TRISA2

#define LED_B2      LATBbits.LATB2
#define TRIS_LED_B2 TRISBbits.TRISB2

#define LED_B4      LATBbits.LATB4
#define TRIS_LED_B4 TRISBbits.TRISB4

#define LED_B5      LATBbits.LATB5
#define TRIS_LED_B5 TRISBbits.TRISB5

#define KEY_1       PORTAbits.RA3 
#define TRIS_KEY_1  TRISAbits.TRISA3

#define KEY_2       PORTAbits.RA4 
#define TRIS_KEY_2  TRISAbits.TRISA5

#define KEY_3       PORTAbits.RA5 
#define TRIS_KEY_3  TRISAbits.TRISA5

#define RX_PIC      PORTCbits.RX
#define TRIS_RX_PIC TRISCbits.TRISC7

//#define TX_PIC      LATCbits.LATC6
#define TX_PIC       PORTCbits.TX
#define TRIS_TX_PIC TRISCbits.TRISC6

void InitPinsCMT2300(void);