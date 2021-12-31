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

// FUNCIONES COPIADAS Y PEGADAS
extern void ecan2WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel);
extern void ecan2WriteRxAcptMask(int m, long identifierMask, unsigned int mide,unsigned int exide);
extern void ecan2WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
extern void ecan2WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);
extern void ecan2DisableRXFilter(int n);

/* CAN Baud Rate Configuration 		*/
/*#define FCAN  	40000000 
#define BITRATE 1000000  
#define NTQ 	20		// 20 Time Quanta in a Bit Time
#define BRP_VAL		((FCAN/(2*NTQ*BITRATE))-1)*/


/* Configuración de la longitud del buffer del CAN2 */
#define  CAN2_MSG_BUF_LENGTH 	4
typedef unsigned int uiaTablaMensajesCAN2 [CAN2_MSG_BUF_LENGTH][8];

//27.03.2021 Definir puertos físicos del CAN2 (EN URM PRUEBAS)
#define RXCAN2          _LATG0
#define TRISRXCAN2      _TRISG0
#define TXCAN2          _LATG1
#define TRISTXCAN2      _TRISG1

/* S22-P18: inicialización del buffer de DMA  */
extern uiaTablaMensajesCAN2  uiaCAN2BufferMensajes __attribute__((space(dma)));

/* message structure in RAM */
typedef struct{
	/* keep track of the buffer status */
	unsigned char buffer_status;
	/* RTR message or data message */
	unsigned char message_type;
	/* frame type extended or standard */
	unsigned char frame_type;
	/* buffer being used to reference the message */
	unsigned char buffer;
	/* 29 bit id max of 0x1FFF FFFF 
	*  11 bit id max of 0x7FF */
	unsigned long id; 
	/* message data */
	unsigned char data[8];	
	/* received message data length */
	unsigned char data_length;
}mIDCAN2;

// CAN Messages in RAM
extern mIDCAN2 rx_CAN2Mensaje;

// Funciones de inicialización del CAN2
/*
extern void CAN2ConfigInicializacionCAN(void);
extern void CAN2ConfigInicializacionDMA1(void);
extern void CAN2ConfigInicializacionDMA3(void);
extern void CAN2ConfigInicializar(void);
 */

// funciones copiadas y pegadas
extern void dma1init(void);
extern void dma3init(void);
extern void ecan2Init(void);
extern void ecan2ClkInit(void);
extern void ecan2WriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
extern void rxECAN2(mIDCAN2 *message);

//CAN2Buffers 
extern volatile unsigned char ucCAN2BUSTXList[16][13];  //15 TX buffers of 12 data bytes
extern volatile unsigned char ucCAN2BUSTXRead;
extern volatile unsigned char ucCAN2BUSTXWrite;
extern volatile unsigned char ucCAN2BUSTXOverFlow;
extern volatile unsigned char ucCAN2BUSTXCounter;

extern volatile unsigned char ucCAN2BUSRXList[16][13];  //15 RX buffers of 12 data bytes
extern volatile unsigned char ucCAN2BUSRXRead;
extern volatile unsigned char ucCAN2BUSRXWrite;
extern volatile unsigned char ucCAN2BUSRXOverFlow;
extern volatile unsigned char ucCAN2BUSRXCounter;
extern volatile unsigned char ucCAN2BUSValidMessage;

#endif	/* CAN2CONFIG_H */

