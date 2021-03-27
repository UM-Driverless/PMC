#include "xc.h"
#include "CAN1Config.h"
#include "PARAMETERS.h"
#include "CAN1Drv.h"

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
    TRIS_STBYCAN1 = 0;  //Define as "CAN STANDBY" as output : drive RG3 "CAN STANDBY" low on the CANBUS chip.
    TRISRXCAN1 = 1;     //Define as "RX CAN" as input   : RPI96/RF0 RX CANBUS.
    TRISTXCAN1 = 0;     //Define as "TX CAN" as output  : RP97/RF1  TX CANBUS.

    STBYCAN1 = 0;       //Poner "CAN STANDBY" low para activar el driver de CAN
    
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

	ecan1WriteRxAcptFilter(1,0x1FFEFFFF,1,1,0);


/*	Mask Configuration

	ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide, unsigned int exide)

	m = 0 to 2 -> Mask Number

	identifier -> SID <10:0> : EID <17:0> 

	mide = 0 -> Match either standard or extended address message if filters match 
	mide = 1 -> Match only message types that correpond to 'exide' bit in filter

	exide = 0 -> Match messages with standard identifier addresses 
	exide = 1 -> Match messages with extended identifier addresses
	
*/

	ecan1WriteRxAcptMask(1,0x1FFFFFFF,1,1);
	

/* Enter Normal Mode */
	C1CTRL1bits.REQOP=0;
	while(C1CTRL1bits.OPMODE!=0);
	
/* ECAN transmit/receive message control */

	C1RXFUL1=C1RXFUL2=C1RXOVF1=C1RXOVF2=0x0000;
	C1TR01CONbits.TXEN0=1;			/* ECAN1, Buffer 0 is a Transmit Buffer */
	C1TR01CONbits.TXEN1=0;			/* ECAN1, Buffer 1 is a Receive Buffer */
	C1TR01CONbits.TX0PRI=0b11; 		/* Message Buffer 0 Priority Level */
	C1TR01CONbits.TX1PRI=0b11; 		/* Message Buffer 1 Priority Level */
		
}