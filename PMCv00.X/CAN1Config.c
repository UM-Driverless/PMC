#include "xc.h"
#include "CAN1Config.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "GPIO.h"


/*
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
VARIABLES GLOBALES
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
*/
//Multidimensional array (indexing with INT, not CHAR)
volatile unsigned char ucCAN1BUSTXList[16][13];    //15 TX buffers of 12 data bytes
volatile unsigned char ucCAN1BUSTXRead;                                        //an array index is INT
volatile unsigned char ucCAN1BUSTXWrite;                                       //an array index is INT
volatile unsigned char ucCAN1BUSTXOverFlow;
volatile unsigned char ucCAN1BUSTXCounter;

//Multidimensional array (indexing with INT, not CHAR)
volatile unsigned char ucCAN1BUSRXList[16][13];    //15 RX buffers of 12 data bytes
volatile unsigned char ucCAN1BUSRXRead;                                        //an array index is INT
volatile unsigned char ucCAN1BUSRXWrite;                                       //an array index is INT
volatile unsigned char ucCAN1BUSRXOverFlow;
volatile unsigned char ucCAN1BUSRXCounter;
volatile unsigned char ucCAN1BUSValidMessage;



// funciones de manipulación de mensajes CAN
void rx_CAN1(msgCAN* mensaje);
void rx_ECAN1(mIDCAN1* mensaje);

// CAN Messages in RAM
mIDCAN1 rx_CAN1Mensaje;
//msgCAN rx_CAN1Mensaje;

/* Definimos los buffers de mensajes de los módulos CAN */
uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));

/* 
This function configures Acceptance Filter "n" 

Inputs:
n-> Filter number [0-15]
identifier-> Bit ordering is given below
Filter Identifier (29-bits) : 0b000f ffff ffff ffff ffff ffff ffff ffff
								   |____________|_____________________|
									  SID10:0           EID17:0


Filter Identifier (11-bits) : 0b0000 0000 0000 0000 0000 0fff ffff ffff
														  |___________|
															  SID10:0
exide -> "0" for standard identifier 
		 "1" for Extended identifier

bufPnt -> Message buffer to store filtered message [0-15]
maskSel -> Optinal Masking of identifier bits [0-3]
						
*/

void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide, unsigned int bufPnt,unsigned int maskSel) {

unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
unsigned int *sidRegAddr,*bufPntRegAddr,*maskSelRegAddr, *fltEnRegAddr;


	C1CTRL1bits.WIN=1;

	// Obtain the Address of CiRXFnSID, CiBUFPNTn, CiFMSKSELn and CiFEN register for a given filter number "n"
	sidRegAddr = (unsigned int *)(&C1RXF0SID + (n << 1));
	bufPntRegAddr = (unsigned int *)(&C1BUFPNT1 + (n >> 2));
	maskSelRegAddr = (unsigned int *)(&C1FMSKSEL1 + (n >> 3));
	fltEnRegAddr = (unsigned int *)(&C1FEN1);


	// Bit-filed manupulation to write to Filter identifier register
	if(exide==1) { 	// Filter Extended Identifier
		eid15_0 = (identifier & 0xFFFF);
		eid17_16= (identifier>>16) & 0x3;
		sid10_0 = (identifier>>18) & 0x7FF;

		*sidRegAddr=(((sid10_0)<<5) + 0x8) + eid17_16;	// Write to CiRXFnSID Register
	    *(sidRegAddr+1)= eid15_0;					// Write to CiRXFnEID Register

	}else{			// Filter Standard Identifier
		sid10_0 = (identifier & 0x7FF);			
		*sidRegAddr=(sid10_0)<<5;					// Write to CiRXFnSID Register
		*(sidRegAddr+1)=0;							// Write to CiRXFnEID Register
	}


   *bufPntRegAddr = (*bufPntRegAddr) & (0xFFFF - (0xF << (4 *(n & 3)))); // clear nibble
   *bufPntRegAddr = ((bufPnt << (4 *(n & 3))) | (*bufPntRegAddr));       // Write to C1BUFPNTn Register

   *maskSelRegAddr = (*maskSelRegAddr) & (0xFFFF - (0x3 << ((n & 7) * 2))); // clear 2 bits
   *maskSelRegAddr = ((maskSel << (2 * (n & 7))) | (*maskSelRegAddr));      // Write to C1FMSKSELn Register

   *fltEnRegAddr = ((0x1 << n) | (*fltEnRegAddr)); // Write to C1FEN1 Register

   C1CTRL1bits.WIN=0;


}


/* 
This function configures Acceptance Filter Mask "m" 

Inputs:
m-> Mask number [0-2]
identifier-> Bit ordering is given below
Filter Mask Identifier (29-bits) : 0b000f ffff ffff ffff ffff ffff ffff ffff
								        |____________|_____________________|
									        SID10:0           EID17:0


Filter Mask Identifier (11-bits) : 0b0000 0000 0000 0000 0000 0fff ffff ffff
														       |___________|
															      SID10:0

mide ->  "0"  Match either standard or extended address message if filters match 
         "1"  Match only message types that correpond to 'exide' bit in filter
					
*/

void ecan1WriteRxAcptMask(int m, long identifier, unsigned int mide, unsigned int exide){

unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
unsigned int *maskRegAddr;


	C1CTRL1bits.WIN=1;

	// Obtain the Address of CiRXMmSID register for given Mask number "m"
	maskRegAddr = (unsigned int *)(&C1RXM0SID + (m << 1));

	// Bit-filed manupulation to write to Filter Mask register
	if(exide==1) 
	{ 	// Filter Extended Identifier
		eid15_0 = (identifier & 0xFFFF);
		eid17_16= (identifier>>16) & 0x3;
		sid10_0 = (identifier>>18) & 0x7FF;

		if(mide==1)
			*maskRegAddr=((sid10_0)<<5) + 0x0008 + eid17_16;	// Write to CiRXMnSID Register
		else
			*maskRegAddr=((sid10_0)<<5) + eid17_16;	// Write to CiRXMnSID Register
	    *(maskRegAddr+1)= eid15_0;					// Write to CiRXMnEID Register

	}
	else
	{			// Filter Standard Identifier
		sid10_0 = (identifier & 0x7FF);			
		if(mide==1)
			*maskRegAddr=((sid10_0)<<5) + 0x0008;					// Write to CiRXMnSID Register
		else
			*maskRegAddr=(sid10_0)<<5;					// Write to CiRXMnSID Register	
		
		*(maskRegAddr+1)=0;							// Write to CiRXMnEID Register
	}


	C1CTRL1bits.WIN=0;	

}


/* ECAN Transmit Message Buffer Configuration

Inputs:
buf	-> Transmit Buffer Number

txIdentifier ->	

Extended Identifier (29-bits) : 0b000f ffff ffff ffff ffff ffff ffff ffff
								     |____________|_____________________|
									        SID10:0           EID17:0



Standard Identifier (11-bits) : 0b0000 0000 0000 0000 0000 0fff ffff ffff
														    |___________|
															      SID10:0

Standard Message Format: 
											Word0 : 0b000f ffff ffff ffff
													     |____________|||___
 									        				SID10:0   SRR   IDE     

											Word1 : 0b0000 0000 0000 0000
														   |____________|
															  EID17:6

											Word2 : 0b0000 00f0 0000 ffff
													  |_____||	  	 |__|
													  EID5:0 RTR   	  DLC
										
																  
																	
Extended Message Format: 
											Word0 : 0b000f ffff ffff ffff
													     |____________|||___
 									        				SID10:0   SRR   IDE     

											Word1 : 0b0000 ffff ffff ffff
														   |____________|
															  EID17:6

											Word2 : 0bffff fff0 0000 ffff
													  |_____||	  	 |__|
													  EID5:0 RTR   	  DLC

ide -> "0"  Message will transmit standard identifier
	   "1"  Message will transmit extended identifier



remoteTransmit -> "0" Message transmitted is a normal message
				  "1" Message transmitted is a remote message

				Standard Message Format: 
											Word0 : 0b000f ffff ffff ff1f
													     |____________|||___
 									        				SID10:0   SRR   IDE     

											Word1 : 0b0000 0000 0000 0000
														   |____________|
															  EID17:6

											Word2 : 0b0000 0010 0000 ffff
													  |_____||	  	 |__|
													  EID5:0 RTR   	  DLC
										
																  
																	
				Extended Message Format: 
											Word0 : 0b000f ffff ffff ff1f
													     |____________|||___
 									        				SID10:0   SRR   IDE     

											Word1 : 0b0000 ffff ffff ffff
														   |____________|
															  EID17:6

											Word2 : 0bffff ff10 0000 ffff
													  |_____||	  	 |__|
													  EID5:0 RTR   	  DLC

*/

void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit){

    unsigned long word0=0, word1=0, word2=0;
    unsigned long sid10_0=0, eid5_0=0, eid17_6=0;


    if(ide)
    {
        eid5_0  = (txIdentifier & 0x3F);
        eid17_6 = (txIdentifier>>6) & 0xFFF;
        sid10_0 = (txIdentifier>>18) & 0x7FF;
        word1 = eid17_6;
    }
    else
    {
        sid10_0 = (txIdentifier & 0x7FF);
    }


    if(remoteTransmit==1) { 	// Transmit Remote Frame

        word0 = ((sid10_0 << 2) | ide | 0x2);
        word2 = ((eid5_0 << 10)| 0x0200);
    }
    else {
        word0 = ((sid10_0 << 2) | ide);
        word2 = (eid5_0 << 10);
    }

    // Obtain the Address of Transmit Buffer in DMA RAM for a given Transmit Buffer number

    if(ide)
    {
        uiaCAN1BufferMensajes[buf][0] = (word0 | 0x0002);
    }
    else
    {
        uiaCAN1BufferMensajes[buf][0] = word0;

        uiaCAN1BufferMensajes[buf][1] = word1;
        uiaCAN1BufferMensajes[buf][2] = word2;
    }
}


/* ECAN Transmit Data

Inputs :
buf -> Transmit Buffer Number

dataLength -> Length of Data in Bytes to be transmitted

data1/data2/data3/data4 ->  Transmit Data Bytes 

*/

void ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4)
{

	uiaCAN1BufferMensajes[buf][2] = ((uiaCAN1BufferMensajes[buf][2] & 0xFFF0) + dataLength) ;
	
	uiaCAN1BufferMensajes[buf][3] = data1;
	uiaCAN1BufferMensajes[buf][4] = data2;
	uiaCAN1BufferMensajes[buf][5] = data3;
	uiaCAN1BufferMensajes[buf][6] = data4;

}

/*------------------------------------------------------------------------------
 Disable RX Acceptance Filter
 void ecan1DisableRXFilter(int n)
------------------------------------------------------------------------------

n -> Filter number [0-15]
*/

void ecan1DisableRXFilter(int n)
{
    unsigned int *fltEnRegAddr;
    C1CTRL1bits.WIN=1;
    fltEnRegAddr = (unsigned int *)(&C1FEN1);
    *fltEnRegAddr = (*fltEnRegAddr) & (0xFFFF - (0x1 << n));
    C1CTRL1bits.WIN=0;

}



void CAN1ConfigInicializacionDMA0(void){
    /* Este controlador de DMA0 lo vamos a utilizar para transmitir datos */
    
    /* Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup */
    DMA0REQ = 0x0046; /* S22-P6: Indicamos al controlador de DMA0 del CAN1
                       * que su tarea es transmitir datos. */
    DMA0PAD = 0x0442; /* S22-P15: nos indica el valor del registro para escribir
                       * sobre un periférico */
    /* Paso 2 (S22-P16): Peripheral Configuration Setup */
    
    
    /* Paso 3 (S22-P17): Memory Address Initialization */
    DMA0STA = __builtin_dmaoffset(uiaCAN1BufferMensajes);
    
    /* Paso 4 (S22-P19): DMA Transfer Count Set Up*/
    DMA0CNT = 0x0007; /* S22-P3: estamos indicando el número de transferencias
                       * por DMA que se deben realizar para considerar completa
                       * la transferencia de un bloque de datos.
                       * Este número es DMA0CNT + 1. */
    /* Paso 5 (S22-P19): Operating Mode Set Up */
    DMA0CON = 0xA020; /* S22-P5: 
                       * - Habilitamos el canal de DMA0
                       * - Leeremos palabras por el canal de DMA0
                       * - Leemos de DPSRAM y escribimos en dirección periférica
                       * - Iniciamos interrupción cuando se haya leído la palabra
                       * completa.
                       * - AMODE: 10
                       * - MODE: 00 */
    DMACS0 = 0; /* S22-P9: hacemos un Clear en el registro de estado del 
                 * controlador */   
}

void CAN1ConfigInicializacionDMA2(void){
    /* El controlador de DMA2 Lo vamos a utilizar para leer datos */
    /* Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup */
    DMA2REQ = 0x0022; /* S22-P6: indicamos al controlador que su tarea es leer
                       * datos. */
    DMA2PAD = 0x0440; /* S22-P15: nos indica el valor que tenemos que poner en
                       el registro para poder leer de un periférico. */
    /* Paso 2 (S22-P16): Peripheral Configuration Setup */
    
    
    /* Paso 3 (S22-P17): Memory Address Initialization */
    DMA2STA = __builtin_dmaoffset(uiaCAN1BufferMensajes);
    /* Paso 4 (S22-P19): DMA Transfer Count Set Up*/
    DMA2CNT = 0x0007; /* S22-P3 */
    /* Paso 5 (S22-P19): Operating Mode Set Up */
    DMA2CON = 0x8020; /* S22-P5: 
                       * - Habilitamos el canal de DMA2
                       * - Leeremos palabras por el canal de DMA2
                       * - Leemos de dirección periférica y escribimos en 
                       * dirección de DPSRAM
                       * - Iniciamos interrupción cuando se haya leído la palabra
                       * completa.
                       * - AMODE: 10
                       * - MODE: 00 */
    DMACS0 = 0; /* S22-P9 */
}

void CAN1ConfigInicializacionCAN(void){
    /* entramos en el modo de configuración */
    C1CTRL1bits.REQOP = 4;
    while(C1CTRL1bits.OPMODE != 4); /* Esperar hasta entrar en el modo 
                                     * de configuración */
    
    /* S21-P21: Definir buffers de mensajes en la RAM del DMA */
    C1FCTRLbits.DMABS = 4; /* valores válidos: 4, 6, 8, 12, 16, 24, 32 */
	
    /* entramos en el modo Normal Operation */
    C1CTRL1bits.REQOP = 0;
	while(C1CTRL1bits.OPMODE != 0); /* Esperar hasta entrar en el modo 
                                     * de operación normal */
    
    
    C1TR01CONbits.TXEN0=1;			/* S21-P28, Buffer 0 del CAN1 para transmisión */
	C1TR01CONbits.TXEN1=0;			/* S21-P28, Buffer 1 del CAN1 para recepción */
    C1TR01CONbits.TX0PRI=0b11; 		/* S21-P28, prioridad máxima al buffer 0 */
	C1TR01CONbits.TX1PRI=0b11; 		/* S21-P28, prioridad máxima al buffer 1 */
    
    C1CFG1bits.BRP = 0;
}

void CAN1ConfigInicializar(void){
    // CAN1ConfigInicializacionCAN(); /* Inicializar CAN1 */
    CAN1ConfigInicializacionDMA0(); /* Configurar DMA0 para transmitir por CAN1 */
    CAN1ConfigInicializacionDMA2(); /* Configurar DMA2 para recibir por CAN1 */
}

// funciones copiadas y pegadas
/* Dma Initialization for ECAN1 Transmission */
void dma0init(void){

	 DMACS0=0; /* .. -> p142 librochip (DMA Controller Status Register 0) */
     DMA0CON=0x2020; /*.. -> p56 (DMA Register Map; no aparece más referenciado) */
	 DMA0PAD=0x0442;	/* ECAN 1 (C1TXD) .. -> p58 librochip (transmit data word) */
 	 DMA0CNT=0x0007;  /* ..-> p56 librochip (DMA Register Map; no aparece más referenciado) */
	 DMA0REQ=0x0046;	/* ECAN 1 Transmit .. -> p135 librochip */
	 DMA0STA=  __builtin_dmaoffset(uiaCAN1BufferMensajes);	/*..-> p56 librochip*/
	 DMA0CONbits.CHEN=1; /* ..-> Habilitamos el canal enchufándole un 1. */
}


/* Dma Initialization for ECAN1 Reception */
     
void dma2init(void){

	 DMACS0=0;
     DMA2CON=0x0020;
	 DMA2PAD=0x0440;	/* ECAN 1 (C1RXD) .. -> p58 librochip (received data word) */
 	 DMA2CNT=0x0007;
	 DMA2REQ=0x0022;	/* ECAN 1 Receive .. ->  p135 librochip */
	 DMA2STA= __builtin_dmaoffset(uiaCAN1BufferMensajes);	
	 DMA2CONbits.CHEN=1;

}


void ecan1ClkInit(void){

/* FCAN is selected to be FCY ..-> clock source from the CPU
 FCAN = FCY = 40MHz */
	C1CTRL1bits.CANCKS = 0x1;

/*
Bit Time = (Sync Segment + Propagation Delay + Phase Segment 1 + Phase Segment 2)=20*TQ
Phase Segment 1 = 8TQ
Phase Segment 2 = 6Tq
Propagation Delay = 5Tq
Sync Segment = 1TQ
CiCFG1<BRP> =(FCAN /(2 ×N×FBAUD))– 1
*/

	/* Synchronization Jump Width set to 4 TQ */
	C1CFG1bits.SJW = 0x3;
	/* Baud Rate Prescaler */
	C1CFG1bits.BRP = BRP_VAL;
	

	/* Phase Segment 1 time is 8 TQ */
	C1CFG2bits.SEG1PH=0x7;
	/* Phase Segment 2 time is set to be programmable */
	C1CFG2bits.SEG2PHTS = 0x1;
	/* Phase Segment 2 time is 6 TQ */
	C1CFG2bits.SEG2PH = 0x5;
	/* Propagation Segment time is 5 TQ */
	C1CFG2bits.PRSEG = 0x4;
	/* Bus line is sampled three times at the sample point */
	C1CFG2bits.SAM = 0x1;
}

void ecan1Init(void){
    
    //27.03.2021 Definir puertos físicos del CAN1 (EN URM PRUEBAS)
    TRISRXCAN1 = 1;     //Define as "RX CAN" as input   : RPI96/RF0 RX CANBUS.
    TRISTXCAN1 = 0;     //Define as "TX CAN" as output  : RP97/RF1  TX CANBUS.

    CANSTB1_SetDigitalOutput();
    CANSTB1_SetHigh();
    
    
/* Request Configuration Mode */
	C1CTRL1bits.REQOP=4;
	while(C1CTRL1bits.OPMODE!=4);

	ecan1ClkInit();	

	C1FCTRLbits.DMABS=0b000;		/* 4 CAN Message Buffers in DMA RAM */
	
/*	Filter Configuration

	ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel)

	n = 0 to 15 -> Filter number

	identifier -> SID <10:0> : EID <17:0> 

	exide = 0 -> Match messages with standard identifier addresses 
	exide = 1 -> Match messages with extended identifier addresses 

	bufPnt = 0 to 14  -> RX Buffer 0 to 14
	bufPnt = 15 -> RX FIFO Buffer

	maskSel = 0	->	Acceptance Mask 0 register contains mask
	maskSel = 1	->	Acceptance Mask 1 register contains mask
	maskSel = 2	->	Acceptance Mask 2 register contains mask
	maskSel = 3	->	No Mask Selection
	
*/

	ecan1WriteRxAcptFilter(1,0x1FFEFFFF,ucTipoMensajeCAN1,1,0);


/*	Mask Configuration

	ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)

	m = 0 to 2 -> Mask Number

	identifier -> SID <10:0> : EID <17:0> 

	mide = 0 -> Match either standard or extended address message if filters match 
	mide = 1 -> Match only message types that correpond to 'exide' bit in filter

	exide = 0 -> Match messages with standard identifier addresses 
	exide = 1 -> Match messages with extended identifier addresses
	
*/

	ecan1WriteRxAcptMask(1,0x1FFFFFFF,ucTipoMensajeCAN1,1);
	

/* Enter Normal Mode */
	C1CTRL1bits.REQOP=0;
	while(C1CTRL1bits.OPMODE!=0);
	
/* ECAN transmit/receive message control */

	C1RXFUL1=C1RXFUL2=C1RXOVF1=C1RXOVF2=0x0000;
	C1TR01CONbits.TXEN0=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR01CONbits.TXEN1=0;			/* ECAN1, Buffer 1 is a Receive Buffer */
	C1TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 1 Priority Level */
    
    
    /* Enable ECAN1 Interrupt */ 				
    	
	IEC2bits.C1IE = 1;
	C1INTEbits.TBIE = 1;	
	C1INTEbits.RBIE = 1;
		
}

/*
 Como sabemos qué clase de mensajes se envían, podemos ahorrarnos muchas
 * comprobaciones previas:
 * - Siempre estamos utilizando el formato de datos estándar
 * - RTR siempre estará a cero
 */
/*void rx_CAN1(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN1BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
    Nop();
    Nop();
    
    
}*/




// inicio del copia y pega


/* ECAN1 buffer loaded with Identifiers and Data */
extern void ecan1WriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{
    unsigned int uiData1;
    unsigned int uiData2;
    unsigned int uiData3;
    unsigned int uiData4;

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
    
    uiData1 = ( data1 << 0x08 ) & 0xFF00;
    uiData1 |= data2;
    uiData2 = ( data3 << 0x08 ) & 0xFF00;
    uiData2 |= data4;
    uiData3 = ( data5 << 0x08 ) & 0xFF00;
    uiData3 |= data6;
    uiData4 = ( data7 << 0x08 ) & 0xFF00;
    uiData4 |= data8;

    ecan1WriteTxMsgBufId(0,id,ucTipoMensajeCAN1,0);
    ecan1WriteTxMsgBufData(0,dataLength,uiData1,uiData2,uiData3,uiData4);
    
    //EJECUTAR BUFFER
    C1TR01CONbits.TXREQ0=1;	

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
void rxECAN1(mIDCAN1* message)
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
        
        
        
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][0] = (rx_CAN1Mensaje.id & 0x00000FF); 
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][1] = ((rx_CAN1Mensaje.id>>8) & 0x00000FF);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][2] = ((rx_CAN1Mensaje.id>>16) & 0x00000FF);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][3] = (unsigned char)(uiaCAN1BufferMensajes[message->buffer][2] & 0x000F);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][4] = (unsigned char)(uiaCAN1BufferMensajes[message->buffer][3] & 0x00FF);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][5] = (unsigned char)((uiaCAN1BufferMensajes[message->buffer][3] & 0xFF00) >> 8);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][6] = (unsigned char)uiaCAN1BufferMensajes[message->buffer][4];
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][7] = (unsigned char)((uiaCAN1BufferMensajes[message->buffer][4] & 0xFF00) >> 8);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][8] = (unsigned char)uiaCAN1BufferMensajes[message->buffer][5];
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][9] = (unsigned char)((uiaCAN1BufferMensajes[message->buffer][5] & 0xFF00) >> 8);
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][10] = (unsigned char)uiaCAN1BufferMensajes[message->buffer][6];
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][11] = (unsigned char)((uiaCAN1BufferMensajes[message->buffer][6] & 0xFF00) >> 8);               
        ucCAN1BUSRXList[ucCAN1BUSRXWrite][12] = 0x01; 
        
        //DJU Añadir procesamiento de mensajes CAN a mayor nivel
        MESSAGES_CAN1_Rx();
	}	
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