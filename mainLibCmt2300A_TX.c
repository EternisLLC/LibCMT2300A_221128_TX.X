/*
 * File:   mainLibCmt2300A.c
 * Author: 11
 *
 * Created on 28 ноября 2022 г., 11:58
 */
#include    <xc.h>
#include    "SetConfigBitsPic18f25k20.h"
#include    "ConfigPinsLibCmt2300A.h"
#include    "InitProcessor.h"
//#include    "CheckFunction.h"

#include    "LibCmt2300.h"

unsigned char   TempAddr = 0;
unsigned char   TempData = 0;

unsigned char   CounterMs = 0;

//unsigned char   ReadSettingCmt2300;

// прототипы обработчиков прерываний
void low_priority interrupt myLoIsr(void);
void high_priority interrupt myHiIsr(void);
void main(void) {
    ProcessorInit();
    
//// отладка тактирования работы с FIFO
//    while(1){
//        if(Interval._100ms){
//            TxFifo[0] ++;
//            TxFifo[1] --;
////            ReadFifoCmt2300(RxFifo,32);
////            WriteByteFifoCmt2300(TxFifo[0]);
//            WriteFifoCmt2300(TxFifo, 32);
//            Interval._100ms = 0;
//        }
//    }
////     
    while(!Interval._1s);
    Interval._1s = 0;
// программный сброс CMT2300
    SoftResetCmt2300();
    while(!Interval._1s);
    Interval._1s = 0;
    ModeCmt2300 = CheckModeCmt2300();
    while(!Interval._1s);
    Interval._1s = 0;
    if(ModeCmt2300 == 1){
        go_stby(); // переводим в STBY
    }
    while(!Interval._1s);
    Interval._1s = 0;
    ModeCmt2300 = CheckModeCmt2300();
    if(ModeCmt2300 == _STBY){
        // здесь конфигурируем CMT2300
        InitCmt2300();
        ModeCmt2300 = GotoNewModeCmt2300(_SLEEP);// сохраняем конфигурацию переводом в слип
        ModeCmt2300 = GotoNewModeCmt2300(_STBY);//выводим для работы в стендбай
    }
    
    Nop();
    ModeCmt2300 = GotoNewModeCmt2300(_TFS);//переходим в TFS
    Nop();
//    ModeCmt2300 = GotoNewModeCmt2300(_TX);//переходим в TX
    Nop();
//    ModeCmt2300 = GotoNewModeCmt2300(_STBY);//выводим для работы в стендбай
    Nop();
    // проверяем флаги заполнения tx_fifo
    TempData = ReadRegistrCmt2300(CUS_FIFO_FLAG);
    
    ClrTxFifoCmt2300(); // очищаем TX FIFO
    // загружаем tx_fifo 
    WriteRegistrCmt2300(CUS_FIFO_CTL,0x01);// включаем бит PI_FIFO_RD_WR_SEL
    WriteFifoCmt2300(TxFifoCmt2300, 9);           // записываем TX FIFO
    TempData = ReadRegistrCmt2300(CUS_FIFO_FLAG); // проверка заполнености tx_fifo
    Nop();
    WritePktLength(9);                              // записываем данные о длине пакета
    WriteNodeId(1);                                 // записываем NODE_ID
    // включаем передачу
    ModeCmt2300 = GotoNewModeCmt2300(_TX);//переходим в TX
    
//    TempData = ReadRegistrCmt2300(CUS_INT_CLR1);// проверяем окончание передачи
    Nop();
    WriteRegistrCmt2300(CUS_FIFO_CLR,0x03);// чистим tx_fifo
    while(1){
        if(Interval._1s){
            Interval._1s = 0;
            ModeCmt2300 = CheckModeCmt2300();
            if(ModeCmt2300 == _STBY){
// +++++++++++++++++++ прериодическая передача пакета   +++++++++             
                ClrTxFifoCmt2300(); // очищаем TX FIFO
                // загружаем tx_fifo 
                WriteRegistrCmt2300(CUS_FIFO_CTL,0x01);// включаем бит PI_FIFO_RD_WR_SEL
                WriteFifoCmt2300(TxFifoCmt2300, 9);           // записываем TX FIFO
                TempData = ReadRegistrCmt2300(CUS_FIFO_FLAG); // проверка заполнености tx_fifo
                Nop();
                WritePktLength(9);                              // записываем данные о длине пакета
                WriteNodeId(1);                                 // записываем NODE_ID
                // включаем передачу
                ModeCmt2300 = GotoNewModeCmt2300(_TX);//переходим в TX
// +++++++++++++++++++++++++++++++++                
//                ModeCmt2300 = GotoNewModeCmt2300(_RFS);//переходим в RFS
//                ModeCmt2300 = GotoNewModeCmt2300(_RX);//переходим в RX
                LED_A2 = !LED_A2;
            }
        }
//        if(Interval._100ms){
//            TempData = ReadRegistrCmt2300(CUS_FIFO_FLAG);
//            if(TempData){
//                Nop();
//            }
//            TempData = (TempData & 0x78);
//            if(TempData){
//                Nop();
//            }
//            Interval._100ms = 0;
//        }
    }
    return;
}
void high_priority interrupt myHiIsr(void) {
    //======
    
}

void low_priority interrupt myLoIsr(void) {
    if(PIE1bits.TMR2IE && PIR1bits.TMR2IF){
        PIR1bits.TMR2IF = 0;
        if(Counter1ms){
            Counter1ms --;
            if(!Counter1ms){
                Counter1ms = 10;
                Interval._10ms = 1;
                if(Counter10ms){
                    Counter10ms --;
                    if(!Counter10ms){
                        Counter10ms = 10;
                        Interval._100ms = 1;
                        if(Counter100ms){
                            Counter100ms --;
                            if(!Counter100ms){
                                Counter100ms = 10;
                                Interval._1s = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}