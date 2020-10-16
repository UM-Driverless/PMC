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

/* Configuraci�n de la longitud del buffer del CAN2 */
#define  CAN2_MSG_BUF_LENGTH 	4
typedef unsigned int uiaTablaMensajesCAN2 [CAN2_MSG_BUF_LENGTH][8];

/* S22-P18: inicializaci�n del buffer de DMA  */
extern uiaTablaMensajesCAN2  uiaCAN2BufferMensajes __attribute__((space(dma)));

/* Funciones de inicializaci�n del CAN2 */
extern void CAN2ConfigInicializacionCAN(void);
extern void CAN2ConfigInicializacionDMA1(void);
extern void CAN2ConfigInicializacionDMA3(void);

#endif	/* CAN2CONFIG_H */
