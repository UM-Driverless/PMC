/* 
 * File:   CAN1Config.h
 * Author: heqro
 *
 * Created on September 15, 2020, 12:30 PM
 */

#ifndef CAN1CONFIG_H
#define	CAN1CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

/* CAN Baud Rate Configuration 		*/
#define FCAN  	40000000 
#define BITRATE 1000000  
#define NTQ 	20		// 20 Time Quanta in a Bit Time
#define BRP_VAL		((FCAN/(2*NTQ*BITRATE))-1)


/* Configuración de la longitud del buffer del CAN1 */
#define  CAN1_MSG_BUF_LENGTH 	4
typedef unsigned int uiaTablaMensajesCAN1 [CAN1_MSG_BUF_LENGTH][8];

/* S22-P18: inicialización del buffer de DMA  */
extern uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma)));

/* Funciones de inicialización del CAN1 */
extern void CAN1ConfigInicializacionCAN(void);
extern void CAN1ConfigInicializacionDMA0(void);
extern void CAN1ConfigInicializacionDMA2(void);
// extern void CAN1ConfigEnvioMsg()




#endif	/* CAN1CONFIG_H */

