/* 
 * File:   InitProcessor.h
 * Author: 11
 *
 * Created on 29 ������ 2022 �., 7:59
 */
typedef struct {
    unsigned char _1ms          :1;
    unsigned char _10ms         :1;
    unsigned char _100ms        :1;     
    unsigned char _1s           :1;
}interval_t;  //����� ���������� �������
extern unsigned char    Counter1ms;
extern unsigned char    Counter10ms;
extern unsigned char    Counter100ms;

extern interval_t       Interval;

void ProcessorInit(void);
