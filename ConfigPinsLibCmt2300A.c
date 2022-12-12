#include    <xc.h>
#include    "ConfigPinsLibCmt2300A.h"


void InitPinsCMT2300(void){
// ������������ ����� ��� ������ ��� PIC18...    
    ANSEL = 0;          // �������� ������/������
    ANSELH = 0;         // �������� ������/������
    
// ������������ ����� ��������� � CMT2300A    
    CSB_CMT2300 = 1;            // ������ ��������� ���������� � ������������ ��������
    TRIS_CSB_CMT2300 = out;
    FCSB_CMT2300 = 1;           // ������ ��������� FIFO ��������
    TRIS_FCSB_CMT2300 = out;
    SCK_CMT2300 = 0;
    TRIS_SCK_CMT2300 = out;
    DOUT_CMT2300 = 0;
    TRIS_D_OUT_CMT2300();
    TRIS_GPIO1_CMT2300 = in;
// ����� ������������ ����� ��������� � CMT2300A

// ������������ ����� ��� ����� ���������� ����� �� ��������� � ������� CMT2300A
    LED_A1 = 0;
    TRIS_LED_A1 = out;
    LED_A2 = 0;
    TRIS_LED_A2 = out;
    LED_B2 = 0;
    TRIS_LED_B2 = out;
    LED_B4 = 0;
    TRIS_LED_B4 = out;
    LED_B5 = 0;
    TRIS_LED_B5 = out;
    TRIS_KEY_1 = in;
    TRIS_KEY_2 = in;
    TRIS_KEY_3 = in;
    
    TRIS_RX_PIC = in;
    TX_PIC = 1;
    TRIS_TX_PIC = out;
}