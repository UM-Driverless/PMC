#include "xc.h"
#include "UART2.h"


void UART2inicializacion(){
    U2MODEbits.STSEL = 0;			// 1-stop bit
	U2MODEbits.PDSEL = 0;			// No Parity, 8-data bits
	U2MODEbits.ABAUD = 0;			// Autobaud Disabled

	U2BRG = BRG_VAL;					// BAUD Rate Setting for 115200


	//********************************************************************************
	//  STEP 1:
	//  Configure UART for DMA transfers
	//********************************************************************************/
	U2STAbits.UTXISEL0 = 0;			// Interrupt after one Tx character is transmitted
	U2STAbits.UTXISEL1 = 0;			                            
	U2STAbits.URXISEL  = 0;			// Interrupt after one RX character is received

	
	//********************************************************************************
	//  STEP 2:
	//  Enable UART Rx and Tx
	//********************************************************************************/
	U2MODEbits.UARTEN   = 1;		// Enable UART
	U2STAbits.UTXEN     = 1;		// Enable UART Tx


	IEC4bits.U2EIE = 0;
}

void UART2DMA7init(){ //RX
    //********************************************************************************
	//  STEP 3:
	//  Associate DMA Channel 7 with UART Rx
	//********************************************************************************/
	DMA7REQ = 0b0011110;					// Select UART2 Receiver
	DMA7PAD = (volatile unsigned int) &U2RXREG;

	//********************************************************************************
	//  STEP 4:
	//  Configure DMA Channel 1 to:
	//  Transfer data from UART to RAM Continuously
	//  Register Indirect with Post-Increment
	//  Using two ‘ping-pong’ buffers
	//  8 transfers per buffer
	//  Transfer words
	//********************************************************************************/
	//DMA5CON = 0x0002;					// Continuous, Ping-Pong, Post-Inc, Periph-RAM
	DMA7CONbits.AMODE = 0;
	DMA7CONbits.MODE  = 2;
	DMA7CONbits.DIR   = 0;
	DMA7CONbits.SIZE  = 0;
	DMA7CNT = 7;						// 8 DMA requests

	//********************************************************************************
	//  STEP 6:
	//  Associate two buffers with Channel 1 for ‘Ping-Pong’ operation
	//********************************************************************************/
	DMA7STA = __builtin_dmaoffset(UART2_BufferA);
	DMA7STB = __builtin_dmaoffset(UART2_BufferB);

	//********************************************************************************
	//  STEP 8:
	//	Enable DMA Interrupts
	//********************************************************************************/
    IFS4bits.DMA7IF = 0;        // Clear DMA interrupt
    IEC4bits.DMA7IE = 1;        // Enable DMA interrupt

	//********************************************************************************
	//  STEP 9:
	//  Enable DMA Channel 1 to receive UART data
	//********************************************************************************/
	DMA7CONbits.CHEN = 1;			// Enable DMA Channel
} 

void UART2DMA1init(){ //TX
    
	//********************************************************************************
	//  STEP 3:
	//  Associate DMA Channel 1 with UART Tx
	//********************************************************************************/
	DMA1REQ = 0b0011111;					// Select UART2 Transmitter
	DMA1PAD = (volatile unsigned int) &U2TXREG;
	
	//********************************************************************************
	//  STEP 5:
	//  Configure DMA Channel 1 to:
	//  Transfer data from RAM to UART
	//  One-Shot mode
	//  Register Indirect with Post-Increment
	//  Using single buffer
	//  8 transfers per buffer
	//  Transfer words
	//********************************************************************************/
	//DMA6CON = 0x2001;					// One-Shot, Post-Increment, RAM-to-Peripheral
	DMA1CONbits.AMODE = 0;
	DMA1CONbits.MODE  = 1;
	DMA1CONbits.DIR   = 1;
	DMA1CONbits.SIZE  = 0;
	DMA1CNT = 7;						// 8 DMA requests

	//********************************************************************************
	//  STEP 6:
	// Associate one buffer with Channel 0 for one-shot operation
	//********************************************************************************/
	DMA1STA = __builtin_dmaoffset(UART2_BufferA);

	//********************************************************************************
	//  STEP 8:
	//	Enable DMA Interrupts
	//********************************************************************************/
	IFS0bits.DMA1IF  = 0;			// Clear DMA Interrupt Flag
	IEC0bits.DMA1IE  = 1;			// Enable DMA interrupt
    
    //********************************************************************************
	//  STEP 9:
	//  Enable DMA Channel 1 to transmit UART data
	//********************************************************************************/
	DMA1CONbits.CHEN = 1; // habilitar canal de DMA
}

void UART2init(){
    UART2inicializacion();
    UART2DMA1init();
    UART2DMA7init();
}

