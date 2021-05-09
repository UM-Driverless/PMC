/* 
 * File:   UART2.h
 * Author: heqro
 *
 * Created on December 19, 2020, 2:12 PM
 */

#ifndef UART2_H
#define	UART2_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
#include "PARAMETERS.h"

//Definir puertos fisicos UART2
#define TRIS_UART2_RX _TRISF4 
#define TRIS_UART2_TX _TRISF5 

//Definir control del RS232
#define TRIS_CTR232 _TRISB14 
#define CTR232      _LATB14 //control del puerto fisico

/* Buffers para transferencia por DMA */
typedef unsigned int Buffer_A_UART2[8];
typedef unsigned int Buffer_B_UART2[8];

extern Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
extern Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

extern volatile unsigned char ucUART2_RX_DATA;
extern volatile unsigned char ucUART2_TX_DATA;

extern void UART2inicializacion();
extern void UART2DMA7init(); //RX
extern void UART2DMA1init(); //TX
extern void UART2init();
extern void UART2WriteCharacter(unsigned char c);
extern void UART2ReceiveCharacter(unsigned char c);

#endif	/* UART2_H */

