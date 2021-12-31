/* 
 * File:   CAN1Config.h
 * Author: heqro
 *
 * Created on September 15, 2020, 12:30 PM
 * 
 * 
 */

#ifndef CAN1CONFIG_H
#define	CAN1CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

// FUNCIONES COPIADAS Y PEGADAS
extern void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel);
extern void ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide,unsigned int exide);
extern void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
extern void ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);
extern void ecan1DisableRXFilter(int n);

/* CAN Baud Rate Configuration 		*/
/*
#define FCAN  	40000000 
#define BITRATE 1000000  
#define NTQ 	20		// 20 Time Quanta in a Bit Time
#define BRP_VAL		((FCAN/(2*NTQ*BITRATE))-1)
*/

/* Configuración de la longitud del buffer del CAN1 */
#define  CAN1_MSG_BUF_LENGTH 	4
typedef unsigned int uiaTablaMensajesCAN1 [CAN1_MSG_BUF_LENGTH][8];

//27.03.2021 Definir puertos físicos del CAN1 (EN URM PRUEBAS)
#define RXCAN1          _LATF0
#define TRISRXCAN1      _TRISF0
#define TXCAN1          _LATF1
#define TRISTXCAN1      _TRISF1

/* S22-P18: inicialización del buffer de DMA  */
extern uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma)));

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
}mIDCAN1;

// CAN Messages in RAM
extern mIDCAN1 rx_CAN1Mensaje;


//Funciones de inicialización del CAN1 
/*
extern void CAN1ConfigInicializacionCAN(void);
extern void CAN1ConfigInicializacionDMA0(void);
extern void CAN1ConfigInicializacionDMA2(void);
extern void CAN1ConfigInicializar(void);
*/
// funciones copiadas y pegadas
extern void dma0init(void);
extern void dma2init(void);
extern void ecan1Init(void);
extern void ecan1ClkInit(void);
extern void ecan1WriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
extern void rxECAN1(mIDCAN1 *message);

//CAN2Buffers 
extern volatile unsigned char ucCAN1BUSTXList[16][13];  //15 TX buffers of 12 data bytes
extern volatile unsigned char ucCAN1BUSTXRead;
extern volatile unsigned char ucCAN1BUSTXWrite;
extern volatile unsigned char ucCAN1BUSTXOverFlow;
extern volatile unsigned char ucCAN1BUSTXCounter;

extern volatile unsigned char ucCAN1BUSRXList[16][13];  //15 RX buffers of 12 data bytes
extern volatile unsigned char ucCAN1BUSRXRead;
extern volatile unsigned char ucCAN1BUSRXWrite;
extern volatile unsigned char ucCAN1BUSRXOverFlow;
extern volatile unsigned char ucCAN1BUSRXCounter;
extern volatile unsigned char ucCAN1BUSValidMessage;


// extern void CAN1ConfigEnvioMsg()

#endif	/* CAN1CONFIG_H */

