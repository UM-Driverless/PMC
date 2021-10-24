    /* 
 * File:   MESSAGES.h
 * Author: 93Urbano
 *
 * Created on 19 de agosto de 2021, 22:37
 */

#ifndef MESSAGES_H
#define	MESSAGES_H

#define DRIVING_DYNAMICS_1 0x500
#define DRIVING_DYNAMICS_2 0x501
#define SYSTEM_STATUS 0x502
//Autonomous system msgs
#define AS1 0x511
#define AS2 0x512
#define AS3 0x513
#define AS4 0x514
#define AS5 0x515
//Res msgs
#define NMT_NODE_CONTROL 0x000
#define SYNC 0x080
#define TIME_STAMP 0x100
#define LSS_T 0x7E4
#define LSS_R 0x7E5
//ID Message
#define ID1 0x360
#define RATE1HZ 50
//ID Message
#define ID2 0x361
#define RATE2HZ 50
//ID Message
#define ID3 0x362
#define RATE3HZ 50
//ID Message
#define ID4 0x363
#define RATE4HZ 20
//ID Message
#define ID5 0x368
#define RATE5HZ 20
//ID Message
#define ID6 0x369
#define RATE6HZ 20
//ID Message
#define ID7 0x36A
#define RATE7HZ 20
//ID Message
#define ID8 0x36B
#define RATE8HZ 20
//ID Message
#define ID9 0x36C
#define RATE9HZ 20
//ID Message
#define ID10 0x36D
#define RATE10HZ 20
//ID Message
#define ID11 0x36E
#define RATE11HZ 20
//ID Message
#define ID12 0x36F
#define RATE12HZ 20
//ID Message
#define ID13 0x370
#define RATE13HZ 20
//ID Message
#define ID14 0x371
#define RATE14HZ 10
//ID Message
#define ID15 0x372
#define RATE15HZ 10
//ID Message
#define ID16 0x373
#define RATE16HZ 10
//ID Message
#define ID17 0x374
#define RATE17HZ 10
//ID Message
#define ID18 0x375
#define RATE18HZ 10
//ID Message
#define ID19 0x3E0
#define RATE19HZ 5
//ID Message
#define ID20 0x3E1
#define RATE20HZ 5
//ID Message
#define ID21 0x3E2
#define RATE21HZ 5
//ID Message
#define ID22 0x3E3
#define RATE22HZ 5
//ID Message
#define ID23 0x3E4
#define RATE23HZ 5

#ifdef	__cplusplus
extern "C" {
#endif

// INICIALIZACION DE VARIABLES //
extern volatile unsigned long ulCAN1RXID;
extern volatile unsigned char ucCAN1RXDataLenght;
extern volatile unsigned char ucCAN1RXData0;
extern volatile unsigned char ucCAN1RXData1;
extern volatile unsigned char ucCAN1RXData2;
extern volatile unsigned char ucCAN1RXData3;
extern volatile unsigned char ucCAN1RXData4;
extern volatile unsigned char ucCAN1RXData5;
extern volatile unsigned char ucCAN1RXData6;
extern volatile unsigned char ucCAN1RXData7;

extern volatile unsigned long ulCAN2RXID;
extern volatile unsigned char ucCAN2RXDataLenght;
extern volatile unsigned char ucCAN2RXData0;
extern volatile unsigned char ucCAN2RXData1;
extern volatile unsigned char ucCAN2RXData2;
extern volatile unsigned char ucCAN2RXData3;
extern volatile unsigned char ucCAN2RXData4;
extern volatile unsigned char ucCAN2RXData5;
extern volatile unsigned char ucCAN2RXData6;
extern volatile unsigned char ucCAN2RXData7;


// INICIALIZACION DE FUNCIONES //
extern void MESSAGES_CAN1_Rx(void);
extern void MESSAGES_CAN2_Rx(void);


// DECLARACION DE CONSTANTES DE ID //
#define ID1 0x0FFF


#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGES_H */

