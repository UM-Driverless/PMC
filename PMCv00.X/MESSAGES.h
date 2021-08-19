/* 
 * File:   MESSAGES.h
 * Author: 93Urbano
 *
 * Created on 19 de agosto de 2021, 22:37
 */

#ifndef MESSAGES_H
#define	MESSAGES_H

#ifdef	__cplusplus
extern "C" {
#endif

// INICIALIZACION DE VARIABLES //
extern volatile unsigned int uiCAN1RXID;
extern volatile unsigned char ucCAN1RXDataLenght;
extern volatile unsigned char ucCAN1RXData0;
extern volatile unsigned char ucCAN1RXData1;
extern volatile unsigned char ucCAN1RXData2;
extern volatile unsigned char ucCAN1RXData3;
extern volatile unsigned char ucCAN1RXData4;
extern volatile unsigned char ucCAN1RXData5;
extern volatile unsigned char ucCAN1RXData6;
extern volatile unsigned char ucCAN1RXData7;

extern volatile unsigned int uiCAN2RXID;
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

