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

/* Buffers para transferencia por DMA */
typedef unsigned int Buffer_A_UART1[8];
typedef unsigned int Buffer_B_UART1[8];
//extern Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
//extern Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));

extern void UART1inicializacion();
extern void UART1DMA5init(); //RX
extern void UART1DMA6init(); //TX
extern void UART1init();

#endif	/* UART_H */

