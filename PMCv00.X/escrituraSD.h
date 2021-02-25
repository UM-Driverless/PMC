/* 
 * File:   escrituraSD.h
 * Author: heqro
 *
 * Created on October 17, 2020, 5:06 PM
 */

#ifndef ESCRITURASD_H
#define	ESCRITURASD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#define NUM_TRANSFERENCIAS   16
unsigned int uiaTxBufferSPIA[NUM_TRANSFERENCIAS] __attribute__((space(dma)));
unsigned int uiaTxBufferSPIB[NUM_TRANSFERENCIAS] __attribute__((space(dma)));

/* Funcion para configurar el canal de SPI1 */
extern void escrituraSDInicializacionSPI1(void);
/* Funcion para inicializar el canal de DMA4 para transmitir datos */
extern void escrituraSDInicializacionDMA4(void);
/* Función para inicializar todo */
extern void escrituraSDinit();
#endif	/* ESCRITURASD_H */

