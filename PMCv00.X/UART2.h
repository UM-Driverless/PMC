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


/* Buffers para transferencia por DMA */
typedef unsigned int Buffer_A_UART2[8];
typedef unsigned int Buffer_B_UART2[8];

extern Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
extern Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

extern void UART2inicializacion();
extern void UART2DMA7init(); //RX
extern void UART2DMA1init(); //TX
extern void UART2init();
#endif	/* UART2_H */

