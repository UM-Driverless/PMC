/* 
 * File:   UART.h
 * Author: heqro
 *
 * Created on November 20, 2020, 11:06 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif


#include "PARAMETERS.h"

//Definir puertos fisicos UART1
#define TRIS_UART1_RX _TRISF2 
#define TRIS_UART1_TX _TRISF3 

//Definir control del RS485
#define TRIS_CTR485 _TRISB15 
#define CTR485      _LATB15 //control del puerto fisico

/* Buffers para transferencia por DMA */
typedef unsigned int Buffer_A_UART1[8];
typedef unsigned int Buffer_B_UART1[8];

extern Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
extern Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));

extern volatile unsigned char ucUART1_RX_DATA;
extern volatile unsigned char ucUART1_TX_DATA;

extern void UART1inicializacion();
extern void UART1DMA5init(); //RX
extern void UART1DMA6init(); //TX
extern void UART1init();
extern void UART1WriteCharacter(unsigned char c);
extern void UART1WriteString(char s[]);
extern void UART1ReceiveCharacter(unsigned char c);

#endif	/* UART_H */

