/* 
 * File:   SPI.h
 * Author: heqro
 *
 * Created on October 17, 2020, 5:06 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

//Definir puertos físicos SPI2
#define TRIS_SCK2 _TRISG6 
#define TRIS_SDI2 _TRISG7 
#define TRIS_SDO2 _TRISG8 

//Definir control del RS232
#define TRIS_SS2    _TRISG9    //Selector de esclavo para RTC
#define TRIS_SS1    _TRISB2    //Selector de esclavo para SD
#define CTR_SS2_SD  _LATG9 //control del puerto fisico SS2 RTC
#define CTR_SS1_RTC _LATB2 //control del puerto fisico SS1 SD


#define NUM_TRANSFERENCIAS   16

extern unsigned int uiaTxBufferSPIA[NUM_TRANSFERENCIAS] __attribute__((space(dma)));
extern unsigned int uiaTxBufferSPIB[NUM_TRANSFERENCIAS] __attribute__((space(dma)));

/* Funcion para configurar el canal de SPI2 */
extern void InicializacionSPI2(void);
/* Funcion para inicializar el canal de DMA4 para transmitir datos */
extern void InicializacionDMA4(void);
extern unsigned char WriteSPI2(unsigned char command, unsigned char slave);
extern unsigned char ReadSPI2(unsigned char slave);

#endif	/* SPI_H */

/*
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
MACROS
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
*/   
#define SPI1Get() SPI1BUF   
#define SPI2Get() SPI2BUF

