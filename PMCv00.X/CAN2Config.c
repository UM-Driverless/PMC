#include "xc.h"
#include "CAN2Config.h"
#include "PARAMETERS.h"
#include "CAN2Drv.h"
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
    FCAN = FCY = 40MHz */
	C2CTRL1bits.CANCKS = 0x1;

/*
Bit Time = (Sync Segment + Propagation Delay + Phase Segment 1 + Phase Segment 2)=20*TQ
Phase Segment 1 = 8TQ
Phase Segment 2 = 6Tq
Propagation Delay = 5Tq
Sync Segment = 1TQ
CiCFG1<BRP> =(FCAN /(2 ×N×FBAUD))– 1
*/

	/* Synchronization Jump Width set to 4 TQ */
	C2CFG1bits.SJW = 0x3;
	/* Baud Rate Prescaler */
	C2CFG1bits.BRP = BRP_VAL;
	

	/* Phase Segment 1 time is 8 TQ */
	C2CFG2bits.SEG1PH=0x7;
	/* Phase Segment 2 time is set to be programmable */
	C2CFG2bits.SEG2PHTS = 0x1;
	/* Phase Segment 2 time is 6 TQ */
	C2CFG2bits.SEG2PH = 0x5;
	/* Propagation Segment time is 5 TQ */
	C2CFG2bits.PRSEG = 0x4;
	/* Bus line is sampled three times at the sample point */
	C2CFG2bits.SAM = 0x1;
               
}

void ecan2Init(void){
    
    //27.03.2021 Definir puertos físicos del CAN2 (EN URM PRUEBAS)
    TRIS_STBYCAN2 = 0;  //Define as "CAN STANDBY" as output : drive RG3 "CAN STANDBY" low on the CANBUS chip.
    TRISRXCAN2 = 1;     //Define as "RX CAN" as input   : RPI96/RF0 RX CANBUS.
    TRISTXCAN2 = 0;     //Define as "TX CAN" as output  : RP97/RF1  TX CANBUS.

    STBYCAN2 = 0;       //Poner "CAN STANDBY" low para activar el driver de CAN
    
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

	ecan2WriteRxAcptFilter(1,0x1FFEFFFF,1,1,0);

/*	Mask Configuration

	ecan2WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)

	m = 0 to 2 -> Mask Number

	identifier -> SID <10:0> : EID <17:0> 

	mide = 0 -> Match either standard or extended address message if filters match 
	mide = 1 -> Match only message types that correpond to 'exide' bit in filter

	exide = 0 -> Match messages with standard identifier addresses 
	exide = 1 -> Match messages with extended identifier addresses
	
*/

	ecan2WriteRxAcptMask(1,0x1FFFFFFF,1,1);
	
/* Enter Normal Mode */

	C2CTRL1bits.REQOP=0;
	while(C2CTRL1bits.OPMODE!=0);

/* ECAN transmit/receive message control */	
	
	C2RXFUL1=C2RXFUL2=C2RXOVF1=C2RXOVF2=0x0000;
	C2TR01CONbits.TXEN0=1;			/* ECAN2, Buffer 0 is a Transmit Buffer */
	C2TR01CONbits.TXEN1=0;			/* ECAN2, Buffer 1 is a Receive Buffer */
	C2TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C2TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 1 Priority Level */

}