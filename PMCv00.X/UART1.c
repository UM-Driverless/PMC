#include "xc.h"
#include "UART1.h"

void UART1inicializacion(){
    U1MODEbits.STSEL = 0;			// 1-stop bit
	U1MODEbits.PDSEL = 0;			// No Parity, 8-data bits
	U1MODEbits.ABAUD = 0;			// Autobaud Disabled

	U1BRG = BRG_VAL;					// BAUD Rate Setting for 1115200


	//********************************************************************************
	//  STEP 1:
	//  Configure UART for DMA transfers
	//********************************************************************************/
	U1STAbits.UTXISEL0 = 0;			// Interrupt after one Tx character is transmitted
	U1STAbits.UTXISEL1 = 0;			                            
	U1STAbits.URXISEL  = 0;			// Interrupt after one RX character is received

	
	//********************************************************************************
	//  STEP 2:
	//  Enable UART Rx and Tx
	//********************************************************************************/
	U1MODEbits.UARTEN   = 1;		// Enable UART
	U1STAbits.UTXEN     = 1;		// Enable UART Tx


	IEC4bits.U1EIE = 0;
}

void UART1DMA5init(){ //RX
    //********************************************************************************
	//  STEP 3:
	//  Associate DMA Channel 1 with UART Rx
	//********************************************************************************/
	DMA5REQ = 0x001E;					// Select UART2 Receiver
	DMA5PAD = (volatile unsigned int) &U2RXREG;

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
	DMA5CONbits.AMODE = 0;
	DMA5CONbits.MODE  = 2;
	DMA5CONbits.DIR   = 0;
	DMA5CONbits.SIZE  = 0;
	DMA5CNT = 7;						// 8 DMA requests

	//********************************************************************************
	//  STEP 6:
	//  Associate two buffers with Channel 1 for ‘Ping-Pong’ operation
	//********************************************************************************/
	DMA5STA = __builtin_dmaoffset(UART1_BufferA);
	DMA5STB = __builtin_dmaoffset(UART1_BufferB);

	//********************************************************************************
	//  STEP 8:
	//	Enable DMA Interrupts
	//********************************************************************************/
	IFS3bits.DMA5IF  = 0;			// Clear DMA interrupt
	IEC3bits.DMA5IE  = 1;			// Enable DMA interrupt

	//********************************************************************************
	//  STEP 9:
	//  Enable DMA Channel 1 to receive UART data
	//********************************************************************************/
	DMA5CONbits.CHEN = 1;			// Enable DMA Channel
} 

void UART1DMA6init(){ //TX
    
	//********************************************************************************
	//  STEP 3:
	//  Associate DMA Channel 0 with UART Tx
	//********************************************************************************/
	DMA6REQ = 0x001F;					// Select UART2 Transmitter
	DMA6PAD = (volatile unsigned int) &U2TXREG;
	
	//********************************************************************************
	//  STEP 5:
	//  Configure DMA Channel 0 to:
	//  Transfer data from RAM to UART
	//  One-Shot mode
	//  Register Indirect with Post-Increment
	//  Using single buffer
	//  8 transfers per buffer
	//  Transfer words
	//********************************************************************************/
	//DMA6CON = 0x2001;					// One-Shot, Post-Increment, RAM-to-Peripheral
	DMA6CONbits.AMODE = 0;
	DMA6CONbits.MODE  = 1;
	DMA6CONbits.DIR   = 1;
	DMA6CONbits.SIZE  = 0;
	DMA6CNT = 7;						// 8 DMA requests

	//********************************************************************************
	//  STEP 6:
	// Associate one buffer with Channel 0 for one-shot operation
	//********************************************************************************/
	DMA6STA = __builtin_dmaoffset(UART1_BufferA);

	//********************************************************************************
	//  STEP 8:
	//	Enable DMA Interrupts
	//********************************************************************************/
	IFS4bits.DMA6IF  = 0;			// Clear DMA Interrupt Flag
	IEC4bits.DMA6IE  = 1;			// Enable DMA interrupt

}

void UART1init(){
    UART1inicializacion();
    UART1DMA5init();
    UART1DMA6init();
}
