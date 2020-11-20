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


#define FCY      40000000
#define BAUDRATE 9600                
#define BRGVAL   ((FCY/BAUDRATE)/16)-1 

/* Buffers para transferencia por DMA */
unsigned int BufferA[8] __attribute__((space(dma)));
unsigned int BufferB[8] __attribute__((space(dma)));

extern void UART1inicializacion();
extern void UART1DMA5init(); //RX
extern void UART1DMA6init(); //TX
extern void UART1init();

#endif	/* UART_H */

