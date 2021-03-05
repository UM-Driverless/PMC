/*
 * File:   newmainXC16.c
 * Author: heqro
 *
 * Created on September 3, 2020, 6:35 PM
 */


#include "xc.h"
#include "CAN1Config.h"
#include "CAN2Config.h"
#include "CAN1Drv.h"
#include "CAN2Drv.h"

#include "UART1.h"
#include "UART2.h"
//#include "escrituraSD.h"

/* Definimos los buffers de mensajes de los módulos CAN */
uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));
// mensajes CAN a almacenar en RAM
//msgCAN rx_CAN1Mensaje;
//msgCAN rx_CAN2Mensaje;
// funciones de manipulación de mensajes CAN
void rx_CAN1(msgCAN* mensaje);
void rx_CAN2(msgCAN* mensaje);
void rx_ECAN1(mID* mensaje);
void rx_ECAN2(mID* mensaje);

// inicio copia pega
// CAN Messages in RAM
mID rx_CAN1Mensaje;
mID rx_CAN2Mensaje;

// Prototype Declaration
void oscConfig(void);
void clearIntrflags(void);
void ecan1WriteMessage(void);
void ecan2WriteMessage(void);
// fin copia pega

Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));
Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

int main(void) {
    /*
    CAN1ConfigInicializar();
    UART1init();
    CAN2ConfigInicializar();
    UART2init();
    while(1){
        Nop();
    } 
     */
    
    
    // inicio código copia pega
    
    /* Configure Oscillator Clock Source 	*/
	oscConfig();

/* Clear Interrupt Flags 				*/
	clearIntrflags();


/* ECAN1 Initialisation 		
   Configure DMA Channel 0 for ECAN1 Transmit
   Configure DMA Channel 2 for ECAN1 Receive */
	ecan1Init();
	dma0init();	
	dma2init();

/* Enable ECAN1 Interrupt */ 				
    	
	IEC2bits.C1IE = 1;
	C1INTEbits.TBIE = 1;	
	C1INTEbits.RBIE = 1;

/* ECAN2 Initialisation 		
   Configure DMA Channel 1 for ECAN2 Transmit
   Configure DMA Channel 3 for ECAN2 Receive */
	ecan2Init();
	dma1init();	
	dma3init();

/* Enable ECAN2 Interrupt */ 
	
	IEC3bits.C2IE = 1;
	C2INTEbits.TBIE = 1;	
	C2INTEbits.RBIE = 1;

 
/* Write a Message in ECAN1 Transmit Buffer	
   Request Message Transmission			*/
	ecan1WriteMessage();
	C1TR01CONbits.TXREQ0=1;	
	


/* Write a Message in ECAN2 Transmit Buffer
   Request Message Transmission			*/
	ecan2WriteMessage();
	C2TR01CONbits.TXREQ0=1;
	

/* Loop infinitely */

	while (1); 
    // fin código copia pega
    
    return 0;
}


/*
 Como sabemos qué clase de mensajes se envían, podemos ahorrarnos muchas
 * comprobaciones previas:
 * - Siempre estamos utilizando el formato de datos estándar
 * - RTR siempre estará a cero
 */
void rx_CAN1(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN1BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
}

void rx_CAN2(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN2BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
}


// inicio del copia y pega


/* ECAN1 buffer loaded with Identifiers and Data */
void ecan1WriteMessage(void){

/* Writing the message for Transmission
ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

buf -> Transmit Buffer number

txIdentifier -> SID<10:0> : EID<17:0>

ide = 0 -> Message will transmit standard identifier
ide = 1 -> Message will transmit extended identifier

remoteTransmit = 0 -> Normal message
remoteTransmit = 1 -> Message will request remote transmission

dataLength -> Data length can be from 0 to 8 bytes

data1, data2, data3, data4 -> Data words (2 bytes) each

*/

	ecan1WriteTxMsgBufId(0,0x1FFEFFFF,1,0);
	ecan1WriteTxMsgBufData(0,8,0x1111,0x2222,0x3333,0x4444);

}

/* ECAN2 buffer loaded with Identifiers and Data */

void ecan2WriteMessage(void){

/* Writing the message for Transmission

ecan2WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
ecan2WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

buf -> Transmit Buffer Number

txIdentifier -> SID<10:0> : EID<17:0>

ide = 0 -> Message will transmit standard identifier
ide = 1 -> Message will transmit extended identifier

remoteTransmit = 0 -> Normal message
remoteTransmit = 1 -> Message will request remote transmission


dataLength -> Data length can be from 0 to 8 bytes

data1, data2, data3, data4 -> Data words (2 bytes) each


*/

ecan2WriteTxMsgBufId(0,0x1FFEFFFF,1,0);
ecan2WriteTxMsgBufData(0,8,0xaaaa,0xbbbb,0xcccc,0xdddd);

}



/******************************************************************************
*                                                                             
*    Function:			rxECAN1
*    Description:       moves the message from the DMA memory to RAM
*                                                                             
*    Arguments:			*message: a pointer to the message structure in RAM 
*						that will store the message. 
*	 Author:            Jatinder Gharoo                                                      
*	                                                                 
*                                                                              
******************************************************************************/
void rxECAN1(mID* message)
{
	unsigned int ide=0;
	unsigned int srr=0;
	unsigned long id=0;
			
	/*
	Standard Message Format: 
	Word0 : 0bUUUx xxxx xxxx xxxx
			     |____________|||
 					SID10:0   SRR IDE(bit 0)     
	Word1 : 0bUUUU xxxx xxxx xxxx
			   	   |____________|
						EID17:6
	Word2 : 0bxxxx xxx0 UUU0 xxxx
			  |_____||	     |__|
			  EID5:0 RTR   	  DLC
	word3-word6: data bytes
	word7: filter hit code bits
	
	Substitute Remote Request Bit
	SRR->	"0"	 Normal Message 
			"1"  Message will request remote transmission
	
	Extended  Identifier Bit			
	IDE-> 	"0"  Message will transmit standard identifier
	   		"1"  Message will transmit extended identifier
	
	Remote Transmission Request Bit
	RTR-> 	"0"  Message transmitted is a normal message
			"1"  Message transmitted is a remote message
	*/
	/* read word 0 to see the message type */
	ide=uiaCAN1BufferMensajes[message->buffer][0] & 0x0001;	
	srr=uiaCAN1BufferMensajes[message->buffer][0] & 0x0002;	
	
	/* check to see what type of message it is */
	/* message is standard identifier */
	if(ide==0)
	{
		message->id=(uiaCAN1BufferMensajes[message->buffer][0] & 0x1FFC) >> 2;		
		message->frame_type=CAN_FRAME_STD;
	}
	/* mesage is extended identifier */
	else
	{
		id=uiaCAN1BufferMensajes[message->buffer][0] & 0x1FFC;		
		message->id=id << 16;
		id=uiaCAN1BufferMensajes[message->buffer][1] & 0x0FFF;
		message->id=message->id+(id << 6);
		id=(uiaCAN1BufferMensajes[message->buffer][2] & 0xFC00) >> 10;
		message->id=message->id+id;		
		message->frame_type=CAN_FRAME_EXT;
	}
	/* check to see what type of message it is */
	/* RTR message */
	if(srr==1)
	{
		message->message_type=CAN_MSG_RTR;	
	}
	/* normal message */
	else
	{
		message->message_type=CAN_MSG_DATA;
		message->data[0]=(unsigned char)uiaCAN1BufferMensajes[message->buffer][3];
		message->data[1]=(unsigned char)((uiaCAN1BufferMensajes[message->buffer][3] & 0xFF00) >> 8);
		message->data[2]=(unsigned char)uiaCAN1BufferMensajes[message->buffer][4];
		message->data[3]=(unsigned char)((uiaCAN1BufferMensajes[message->buffer][4] & 0xFF00) >> 8);
		message->data[4]=(unsigned char)uiaCAN1BufferMensajes[message->buffer][5];
		message->data[5]=(unsigned char)((uiaCAN1BufferMensajes[message->buffer][5] & 0xFF00) >> 8);
		message->data[6]=(unsigned char)uiaCAN1BufferMensajes[message->buffer][6];
		message->data[7]=(unsigned char)((uiaCAN1BufferMensajes[message->buffer][6] & 0xFF00) >> 8);
		message->data_length=(unsigned char)(uiaCAN1BufferMensajes[message->buffer][2] & 0x000F);
	}	
}


/******************************************************************************
*                                                                             
*    Function:			rxECAN2
*    Description:       moves the message from the DMA memory to RAM
*                                                                             
*    Arguments:			*message: a pointer to the message structure in RAM 
*						that will store the message. 
*	 Author:            Jatinder Gharoo                                                      
*	                                                                 
*                                                                              
******************************************************************************/
void rxECAN2(mID *message)
{
	unsigned int ide=0;
	unsigned int srr=0;
	unsigned long id=0;
			
	/*
	Standard Message Format: 
	Word0 : 0bUUUx xxxx xxxx xxxx
			     |____________|||
 					SID10:0   SRR IDE(bit 0)     
	Word1 : 0bUUUU xxxx xxxx xxxx
			   	   |____________|
						EID17:6
	Word2 : 0bxxxx xxx0 UUU0 xxxx
			  |_____||	     |__|
			  EID5:0 RTR   	  DLC
	word3-word6: data bytes
	word7: filter hit code bits
	
	Substitute Remote Request Bit
	SRR->	"0"	 Normal Message 
			"1"  Message will request remote transmission
	
	Extended  Identifier Bit			
	IDE-> 	"0"  Message will transmit standard identifier
	   		"1"  Message will transmit extended identifier
	
	Remote Transmission Request Bit
	RTR-> 	"0"  Message transmitted is a normal message
			"1"  Message transmitted is a remote message
	*/
	/* read word 0 to see the message type */
	ide=uiaCAN2BufferMensajes[message->buffer][0] & 0x0001;	
	srr=uiaCAN2BufferMensajes[message->buffer][0] & 0x0002;	
	
	/* check to see what type of message it is */
	/* message is standard identifier */
	if(ide==0)
	{
		message->id=(uiaCAN2BufferMensajes[message->buffer][0] & 0x1FFC) >> 2;		
		message->frame_type=CAN_FRAME_STD;
	}
	/* mesage is extended identifier */
	else
	{
		id=uiaCAN2BufferMensajes[message->buffer][0] & 0x1FFC;		
		message->id=id << 16;
		id=uiaCAN2BufferMensajes[message->buffer][1] & 0x0FFF;
		message->id=message->id+(id << 6);
		id=(uiaCAN2BufferMensajes[message->buffer][2] & 0xFC00) >> 10;
		message->id=message->id+id;		
		message->frame_type=CAN_FRAME_EXT;
	}
	/* check to see what type of message it is */
	/* RTR message */
	if(srr==1)
	{
		message->message_type=CAN_MSG_RTR;	
	}
	/* normal message */
	else
	{
		message->message_type=CAN_MSG_DATA;
		message->data[0]=(unsigned char)uiaCAN2BufferMensajes[message->buffer][3];
		message->data[1]=(unsigned char)((uiaCAN2BufferMensajes[message->buffer][3] & 0xFF00) >> 8);
		message->data[2]=(unsigned char)uiaCAN2BufferMensajes[message->buffer][4];
		message->data[3]=(unsigned char)((uiaCAN2BufferMensajes[message->buffer][4] & 0xFF00) >> 8);
		message->data[4]=(unsigned char)uiaCAN2BufferMensajes[message->buffer][5];
		message->data[5]=(unsigned char)((uiaCAN2BufferMensajes[message->buffer][5] & 0xFF00) >> 8);
		message->data[6]=(unsigned char)uiaCAN2BufferMensajes[message->buffer][6];
		message->data[7]=(unsigned char)((uiaCAN2BufferMensajes[message->buffer][6] & 0xFF00) >> 8);
		message->data_length=(unsigned char)(uiaCAN2BufferMensajes[message->buffer][2] & 0x000F);
	}	
}





void clearIntrflags(void){
/* Clear Interrupt Flags */

	IFS0=0;
	IFS1=0;
	IFS2=0;
	IFS3=0;
	IFS4=0;
}


void oscConfig(void){

/*  Configure Oscillator to operate the device at 40Mhz
 	Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
 	Fosc= 8M*40/(2*2)=80Mhz for 8M input clock */

	PLLFBD=38;					/* M=40 */
	CLKDIVbits.PLLPOST=0;		/* N1=2 */
	CLKDIVbits.PLLPRE=0;		/* N2=2 */
	OSCTUN=0;					/* Tune FRC oscillator, if FRC is used */

/* Disable Watch Dog Timer */

	RCONbits.SWDTEN=0;

/* Clock switch to incorporate PLL*/
	__builtin_write_OSCCONH(0x03);		// Initiate Clock Switch to Primary
													// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b011);	// Wait for Clock switch to occur	


/* Wait for PLL to lock */

	while(OSCCONbits.LOCK!=1) {};
}


void __attribute__((interrupt, no_auto_psv))_C1Interrupt(void)  
{    
	IFS2bits.C1IF = 0;        // clear interrupt flag
	if(C1INTFbits.TBIF)
    { 
    	C1INTFbits.TBIF = 0;
    } 
 
    if(C1INTFbits.RBIF)
    {      
		// read the message 
	    if(C1RXFUL1bits.RXFUL1==1)
	    {
	    	rx_CAN1Mensaje.buffer=1;
	    	C1RXFUL1bits.RXFUL1=0;
	    }	    
	    rxECAN1(&rx_CAN1Mensaje); 	    	    
		C1INTFbits.RBIF = 0;
	}
}


void __attribute__((interrupt, no_auto_psv))_C2Interrupt(void)  
{
	IFS3bits.C2IF = 0;        // clear interrupt flag
	if(C2INTFbits.TBIF)
    { 
		C2INTFbits.TBIF = 0;
    } 
    
    if(C2INTFbits.RBIF)
     {      
		// read the message 
	    if(C2RXFUL1bits.RXFUL1==1)
	    {
	    	rx_CAN2Mensaje.buffer=1;
	    	C2RXFUL1bits.RXFUL1=0;
	    }	    
	    rxECAN2(&rx_CAN2Mensaje); 	    	    
		C2INTFbits.RBIF = 0;
     }
}
 

//------------------------------------------------------------------------------
//    DMA interrupt handlers
//------------------------------------------------------------------------------

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void)
{
   IFS0bits.DMA0IF = 0;          // Clear the DMA0 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA1Interrupt(void)
{
   IFS0bits.DMA1IF = 0;          // Clear the DMA1 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA2Interrupt(void)
{
   IFS1bits.DMA2IF = 0;          // Clear the DMA2 Interrupt Flag;
}

void __attribute__((interrupt, no_auto_psv)) _DMA3Interrupt(void)
{
   IFS2bits.DMA3IF = 0;          // Clear the DMA3 Interrupt Flag;
}
