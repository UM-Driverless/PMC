/* 
 * File:   CAN2Config.h
 * Author: heqro
 *
 * Created on September 15, 2020, 6:27 PM
 */

#ifndef CAN2CONFIG_H
#define	CAN2CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

/* CAN Baud Rate Configuration 		*/
/*#define FCAN  	40000000 
#define BITRATE 1000000  
#define NTQ 	20		// 20 Time Quanta in a Bit Time
#define BRP_VAL		((FCAN/(2*NTQ*BITRATE))-1)*/

/* Configuración de la longitud del buffer del CAN2 */
#define  CAN2_MSG_BUF_LENGTH 	4
typedef unsigned int uiaTablaMensajesCAN2 [CAN2_MSG_BUF_LENGTH][8];

/* S22-P18: inicialización del buffer de DMA  */
extern uiaTablaMensajesCAN2  uiaCAN2BufferMensajes __attribute__((space(dma)));

/* Funciones de inicialización del CAN2 */
extern void CAN2ConfigInicializacionCAN(void);
extern void CAN2ConfigInicializacionDMA1(void);
extern void CAN2ConfigInicializacionDMA3(void);
extern void CAN2ConfigInicializar(void);
#endif	/* CAN2CONFIG_H */

