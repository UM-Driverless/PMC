#include "xc.h"
#include "CAN2Config.h"
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
volatile unsigned char ucCAN2BUSTXList[16][13];    //15 TX buffers of 12 data bytes
volatile unsigned char ucCAN2BUSTXRead;                                        //an array index is INT
volatile unsigned char ucCAN2BUSTXWrite;                                       //an array index is INT
volatile unsigned char ucCAN2BUSTXOverFlow;
volatile unsigned char ucCAN2BUSTXCounter;

//Multidimensional array (indexing with INT, not CHAR)
volatile unsigned char ucCAN2BUSRXList[16][13];    //15 RX buffers of 12 data bytes
volatile unsigned char ucCAN2BUSRXRead;                                        //an array index is INT
volatile unsigned char ucCAN2BUSRXWrite;                                       //an array index is INT
volatile unsigned char ucCAN2BUSRXOverFlow;
volatile unsigned char ucCAN2BUSRXCounter;
volatile unsigned char ucCAN2BUSValidMessage;



// funciones de manipulación de mensajes CAN
void rx_CAN2(msgCAN* mensaje);
void rx_ECAN2(mIDCAN2* mensaje);

// CAN Messages in RAM
mIDCAN2 rx_CAN2Mensaje;
//msgCAN rx_CAN2Mensaje;

/* Definimos los buffers de mensajes de los módulos CAN */
uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));

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

void ecan2WriteRxAcptFilter(int n, long identifier, unsigned int exide, unsigned int bufPnt,unsigned int maskSel) {

unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
unsigned int *sidRegAddr,*bufPntRegAddr,*maskSelRegAddr, *fltEnRegAddr;

    
	C2CTRL1bits.WIN=1;

	// Obtain the Address of CiRXFnSID, CiBUFPNTn, CiFMSKSELn and CiFEN register for a given filter number "n"
	sidRegAddr = (unsigned int *)(&C2RXF0SID + (n << 1));
	bufPntRegAddr = (unsigned int *)(&C2BUFPNT1 + (n >> 2));
	maskSelRegAddr = (unsigned int *)(&C2FMSKSEL1 + (n >> 3));
	fltEnRegAddr = (unsigned int *)(&C2FEN1);


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

	C2CTRL1bits.WIN=0;

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

void ecan2WriteRxAcptMask(int m, long identifier, unsigned int mide,unsigned int exide){

unsigned long sid10_0=0, eid15_0=0, eid17_16=0;
unsigned int *maskRegAddr;


	C2CTRL1bits.WIN=1;

	// Obtain the Address of CiRXMmSID register for given Mask number "m"
	maskRegAddr = (unsigned int *)(&C2RXM0SID + (m << 1));

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


	C2CTRL1bits.WIN=0;	

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

void ecan2WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit){

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
        uiaCAN2BufferMensajes[buf][0] = (word0 | 0x0002);
    }
    else
    {
        uiaCAN2BufferMensajes[buf][0] = word0;

        uiaCAN2BufferMensajes[buf][1] = word1;
        uiaCAN2BufferMensajes[buf][2] = word2;
    }
}


/* ECAN Transmit Data

Inputs :
buf -> Transmit Buffer Number

dataLength -> Length of Data in Bytes to be transmitted

data1/data2/data3/data4 ->  Transmit Data Bytes 

*/

void ecan2WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4){

	uiaCAN2BufferMensajes[buf][2] = ((uiaCAN2BufferMensajes[buf][2] & 0xFFF0) + dataLength) ;
	
	uiaCAN2BufferMensajes[buf][3] = data1;
	uiaCAN2BufferMensajes[buf][4] = data2;
	uiaCAN2BufferMensajes[buf][5] = data3;
	uiaCAN2BufferMensajes[buf][6] = data4;

}

/*------------------------------------------------------------------------------
 Disable RX Acceptance Filter
 void ecan1DisableRXFilter(int n)
------------------------------------------------------------------------------

n -> Filter number [0-15]
*/

void ecan2DisableRXFilter(int n)
{
    unsigned int *fltEnRegAddr;
    C2CTRL1bits.WIN=1;
    fltEnRegAddr = (unsigned int *)(&C2FEN1);
    *fltEnRegAddr = (*fltEnRegAddr) & (0xFFFF - (0x1 << n));
    C2CTRL1bits.WIN=0;

}



void CAN2ConfigInicializacionDMA1(void){ // Función que no utilizaremos
    /* Este controlador de DMA0 lo vamos a utilizar para transmitir datos */
    
    /* Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup */
    DMA1REQ = 0x0047; /* S22-P6: Indicamos al controlador de DMA0 del CAN1
                       * que su tarea es transmitir datos. */
    DMA1PAD = 0x0542; /* S22-P15: nos indica el valor del registro para escribir
                       * sobre un periférico */
    /* Paso 2 (S22-P16): Peripheral Configuration Setup */
    
    
    /* Paso 3 (S22-P17): Memory Address Initialization */
    DMA1STA = __builtin_dmaoffset(uiaCAN2BufferMensajes);
    /* Paso 4 (S22-P19): DMA Transfer Count Set Up*/
    DMA1CNT = 0x0007; /* S22-P3: estamos indicando el número de transferencias
                       * por DMA que se deben realizar para considerar completa
                       * la transferencia de un bloque de datos.
                       * Este número es DMA1CNT + 1. */
    /* Paso 5 (S22-P19): Operating Mode Set Up */
    DMA1CON = 0xA020; /* S22-P5: 
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

void CAN2ConfigInicializacionDMA3(void){
    /* El controlador de DMA2 Lo vamos a utilizar para leer datos */
    /* Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup */
    DMA3REQ = 0x0037; /* S22-P6: indicamos al controlador que su tarea es leer
                       * datos. */
    DMA3PAD = 0x0540; /* S22-P15: nos indica el valor que tenemos que poner en
                       el registro para poder leer de un periférico. */
    /* Paso 2 (S22-P16): Peripheral Configuration Setup */
    
    
    /* Paso 3 (S22-P17): Memory Address Initialization */
    DMA3STA = __builtin_dmaoffset(uiaCAN2BufferMensajes);
    /* Paso 4 (S22-P19): DMA Transfer Count Set Up*/
    DMA3CNT = 0x0007; /* S22-P3 */
    /* Paso 5 (S22-P19): Operating Mode Set Up */
    DMA3CON = 0x8020; /* S22-P5: 
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

void CAN2ConfigInicializacionCAN(void){
    /* entramos en el modo de configuración */
    C2CTRL1bits.REQOP = 4;
    while(C2CTRL1bits.OPMODE != 4); /* Esperar hasta entrar en el modo 
                                     * de configuración */
    
    /* S21-P21: Definir buffers de mensajes en la RAM del DMA */
    C2FCTRLbits.DMABS = 4; /* valores válidos: 4, 6, 8, 12, 16, 24, 32 */
	
    /* entramos en el modo Normal Operation */
    C2CTRL1bits.REQOP = 0;
	while(C2CTRL1bits.OPMODE != 0); /* Esperar hasta entrar en el modo 
                                     * de operación normal */
    
    
    //C2TR01CONbits.TXEN0=1;			/* S21-P28, Buffer 0 del CAN2 para transmisión */
	C2TR01CONbits.TXEN1=0;			/* S21-P28, Buffer 1 del CAN2 para recepción */
    C2TR01CONbits.TX0PRI=0b11; 		/* S21-P28, prioridad máxima al buffer 0 */
	C2TR01CONbits.TX1PRI=0b11; 		/* S21-P28, prioridad máxima al buffer 1 */
    
    C2CFG1bits.BRP = 0;
}

void CAN2ConfigInicializar(void){
    CAN2ConfigInicializacionCAN(); /* Inicializar CAN2 */
    // CAN2ConfigInicializacionDMA1(); /* Configurar DMA1 para transmitir por CAN2 */
    CAN2ConfigInicializacionDMA3(); /* Configurar DMA3 para recibir por CAN2 */
}


// inicio del copia y pega

void dma1init(void){

	DMA1CON=0x2020;
	DMA1PAD=(int)&C2TXD;		/* ECAN 2 (C2TXD) */
	DMA1CNT=0x0007;	
	DMA1REQ=0x0047; 	/* ECAN 2 Transmit .. H-> p135 librochip */
	DMA1STA= __builtin_dmaoffset(uiaCAN2BufferMensajes);		
	DMA1CONbits.CHEN=1;
			
}


/* Dma Initialization for ECAN2 Reception */
void dma3init(void){

	 DMACS0=0;
     DMA3CON=0x0020;
	 DMA3PAD=(int)&C2RXD;	/* ECAN 2 (C2RXD) */
 	 DMA3CNT=0x0007;
	 DMA3REQ=0x0037;	/* ECAN 2 Receive */
	 DMA3STA=__builtin_dmaoffset(uiaCAN2BufferMensajes);	
	 DMA3CONbits.CHEN=1;
	 
}



void ecan2ClkInit(void){

    /* FCAN is selected to be FCY
    FCAN = 2* FCY = 20MHz */
	C2CTRL1bits.CANCKS = 0x1;

    /*
    Bit Time = (Sync Segment + Propagation Delay + Phase Segment 1 + Phase Segment 2)=20*TQ
    Phase Segment 1 = 6TQ
    Phase Segment 2 = 1Tq
    Propagation Delay = 2Tq
    Sync Segment = 1TQ
    CiCFG1<BRP> =(FCAN /(2 ×N×FBAUD))– 1 = 0 
    */

	/* Synchronization Jump Width set to 1 TQ */
	C2CFG1bits.SJW = 0x00;
	/* Baud Rate Prescaler */
	C2CFG1bits.BRP = BRP_VAL;
	

	/* Phase Segment 1 time is 6 TQ */
	C2CFG2bits.SEG1PH=0x5;
	/* Phase Segment 2 time is set to be programmable */
	C2CFG2bits.SEG2PHTS = 0x1;
	/* Phase Segment 2 time is 1 TQ */
	C2CFG2bits.SEG2PH = 0x00;
	/* Propagation Segment time is 2 TQ */
	C2CFG2bits.PRSEG = 0x1;
	/* Bus line is sampled three times at the sample point */
	C2CFG2bits.SAM = 0x1;
               
}

void ecan2Init(void){
    
    //27.03.2021 Definir puertos físicos del CAN2 (EN URM PRUEBAS)
    TRISRXCAN2 = 1;     //Define as "RX CAN" as input   : RPI96/RF0 RX CANBUS.
    TRISTXCAN2 = 0;     //Define as "TX CAN" as output  : RP97/RF1  TX CANBUS.

    CANSTB2_SetDigitalOutput();
    CANSTB2_SetHigh();
    
/* Request Configuration Mode */

	C2CTRL1bits.REQOP=4;
	while(C2CTRL1bits.OPMODE!=4);

	ecan2ClkInit();

	C2FCTRLbits.DMABS=0b000;		/* 4 CAN Message Buffers in DMA RAM */	

/*	Filter Configuration

	ecan2WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel)

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

	ecan2WriteRxAcptFilter(1,0x1FFEFFFF,ucTipoMensajeCAN2,1,0);

/*	Mask Configuration

	ecan2WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)

	m = 0 to 2 -> Mask Number

	identifier -> SID <10:0> : EID <17:0> 

	mide = 0 -> Match either standard or extended address message if filters match 
	mide = 1 -> Match only message types that correpond to 'exide' bit in filter

	exide = 0 -> Match messages with standard identifier addresses 
	exide = 1 -> Match messages with extended identifier addresses
	
*/

	ecan2WriteRxAcptMask(1,0x1FFFFFFF,ucTipoMensajeCAN2,1);
	
/* Enter Normal Mode */

	C2CTRL1bits.REQOP=0;
	while(C2CTRL1bits.OPMODE!=0);

/* ECAN transmit/receive message control */	
	
	C2RXFUL1=C2RXFUL2=C2RXOVF1=C2RXOVF2=0x0000;
	C2TR01CONbits.TXEN0=1;			/* ECAN2, Buffer 0 is a Transmit Buffer */
	C2TR01CONbits.TXEN1=0;			/* ECAN2, Buffer 1 is a Receive Buffer */
	C2TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C2TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 1 Priority Level */
    
    /* Enable ECAN2 Interrupt */ 
	
	IEC3bits.C2IE = 1;
	C2INTEbits.TBIE = 1;	
	C2INTEbits.RBIE = 1;


}





/*void rx_CAN2(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN2BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
    Nop();
    Nop();
}*/



extern void ecan2WriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{
    unsigned int ucData1;
    unsigned int ucData2;
    unsigned int ucData3;
    unsigned int ucData4;
    
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

    ucData1 = ( data1 << 0x08 ) & 0xFF00;
    ucData1 |= data2;
    ucData2 = ( data3 << 0x08 ) & 0xFF00;
    ucData2 |= data4;
    ucData3 = ( data5 << 0x08 ) & 0xFF00;
    ucData3 |= data6;
    ucData4 = ( data7 << 0x08 ) & 0xFF00;
    ucData4 |= data8;
    
    
    //ecan2WriteTxMsgBufId(0,0x1FFEFFFF,1,0);
    //ecan2WriteTxMsgBufData(0,8,0xaaaa,0xbbbb,0xcccc,0xdddd);

    ecan2WriteTxMsgBufId(0,id,ucTipoMensajeCAN2,0);
    ecan2WriteTxMsgBufData(0,dataLength,ucData1,ucData2,ucData3,ucData4);
    
        //EJECUTAR BUFFER
    C2TR01CONbits.TXREQ0=1;
    

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
void rxECAN2(mIDCAN2 *message)
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
        
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][0] = (rx_CAN2Mensaje.id & 0x00000FF); 
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][1] = ((rx_CAN2Mensaje.id>>8) & 0x00000FF);
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][2] = ((rx_CAN2Mensaje.id>>16) & 0x00000FF);
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][3] = (unsigned char)(uiaCAN2BufferMensajes[message->buffer][2] & 0x000F);         //DATA LENGHT
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][4] = (unsigned char)(uiaCAN2BufferMensajes[message->buffer][3] & 0x00FF);         //DATA0
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][5] = (unsigned char)((uiaCAN2BufferMensajes[message->buffer][3] & 0xFF00) >> 8);  //DATA1
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][6] = (unsigned char)uiaCAN2BufferMensajes[message->buffer][4];                    //DATA2
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][7] = (unsigned char)((uiaCAN2BufferMensajes[message->buffer][4] & 0xFF00) >> 8);  //DATA3
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][8] = (unsigned char)uiaCAN2BufferMensajes[message->buffer][5];                    //DATA4
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][9] = (unsigned char)((uiaCAN2BufferMensajes[message->buffer][5] & 0xFF00) >> 8);  //DATA5
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][10] = (unsigned char)uiaCAN2BufferMensajes[message->buffer][6];                   //DATA6
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][11] = (unsigned char)((uiaCAN2BufferMensajes[message->buffer][6] & 0xFF00) >> 8); //DATA7       
        ucCAN2BUSRXList[ucCAN2BUSRXWrite][12] = 0x01; 
        
        //DJU Añadir procesamiento de mensajes CAN a mayor nivel
        MESSAGES_CAN2_Rx();
	}	
}



void __attribute__((interrupt, no_auto_psv))_C2Interrupt(void)  
{
	IFS3bits.C2IF = 0;        // clear interrupt flag
	if(C2INTFbits.TBIF) //INTERRUPCION POR TRANSMISION
    { 
		C2INTFbits.TBIF = 0;
    } 
    
    if(C2INTFbits.RBIF) //INTERRUPCION POR RECEPCION
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