#include "xc.h"
#include "UART1.h"

volatile unsigned char ucUART1_RX_DATA;
volatile unsigned char ucUART1_TX_DATA;
int len_1;
int i;

Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));

void UART1inicializacion(){
    
    //Inicializacion de puertos
    TRIS_CTR485         = 0;        //digital output UART1  CTR485
    TRIS_UART1_TX       = 0;        //digital output UART1  TX on RF3
    TRIS_UART1_RX       = 1;        //digital  input UART1  RX on RF2
    
    U1MODEbits.STSEL = 0;			// 1-stop bit
	U1MODEbits.PDSEL = 0;			// No Parity, 8-data bits
	U1MODEbits.ABAUD = 0;			// Autobaud Disabled
    U1MODEbits.BRGH  = 0;        // Standard-Speed mode

	U1BRG = BRG_VAL_115200;					// BAUD Rate Setting for 1115200


	//********************************************************************************
	//  STEP 1:
	//  Configure UART for DMA transfers
	//********************************************************************************/
	/*
    U1STAbits.UTXISEL0 = 0;			// Interrupt after one Tx character is transmitted
	U1STAbits.UTXISEL1 = 0;			                            
	U1STAbits.URXISEL  = 0;			// Interrupt after one RX character is received
    */
    
    //********************************************************************************
	//  New STEP 1:
	//  Enable UART Rx and Tx Interrupt
	//********************************************************************************/
    IFS0bits.U1TXIF     = 0;        //Clear the Transmit Interrupt Flag
    IEC0bits.U1TXIE     = 1;        //Enable UART TX interrupt
    
	IFS0bits.U1RXIF     = 0;        //Clear the Recieve Interrupt Flag
	IEC0bits.U1RXIE     = 1;        //Enable Recieve Interrupts  
    
    IEC4bits.U1EIE      = 1;        //Enable Error (Framing os Overflow) Interrupt for BREAK
	
	//********************************************************************************
	//  STEP 2:
	//  Enable UART Rx and Tx
	//********************************************************************************/
	U1MODEbits.UARTEN   = 1;		// Enable UART
	U1STAbits.UTXEN     = 1;		// Enable UART Tx
    


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

void UART1WriteCharacter (unsigned char c)
{
    char cCaracterRecibido;
    
    while (U1STAbits.TRMT == 0 ); // wait while transmitting  (check 8th bit) 
    U1TXREG = c;
    while (U1STAbits.TRMT == 0 ); // wait while transmitting  

    Nop ();
    Nop ();
    Nop ();
    //
  	cCaracterRecibido = U1RXREG;    //autolectura
    Nop ();
    Nop ();
    Nop ();
    
    IFS0bits.U1RXIF     = 0;
    Nop ();
    Nop ();
    Nop ();    
   
}

extern void UART1WriteString(char s[])
{
   len_1 = sizeof(s);
   for(i = 0; i < len_1; i++) {
       UART1WriteCharacter(s[i]);
   }
}
void UART1ReceiveCharacter (unsigned char c)
{

    Nop ();
    Nop ();
    Nop ();
   
}

/*             INTERRUPCIONES           */

void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void)
{

    IFS0bits.U1TXIF = 0; // Clear TX1 Interrupt flag
    
    //ucUART1_TX_DATA = *pcTramaPorInterrupcionUart1;
    U1TXREG = ucUART1_TX_DATA;
    
}

/*
-----------------------------------------------------------------------------------------
U2RXInterrupt
-----------------------------------------------------------------------------------------
*/
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{            

	ucUART1_RX_DATA = U1RXREG;    
    Nop();
    Nop();

    IFS0bits.U1RXIF = 0; // Clear RX1 Interrupt flag
    Nop();
    Nop();
    
    //OVERFLOW-ERROR?
    if ( U1STAbits.OERR == 1 )  
    {
        U1STAbits.OERR  = 0; //limpiar el overflow implica limpiar el RXG, a partir de 5 caracteres seguidos salta

        IEC0bits.U1RXIE = 0;        // Disable Recieve Interrupts
        IEC0bits.U1RXIE = 1;        // Enable Recieve Interrupts    
    }

    //FRAME-ERROR?
    if ( U1STAbits.FERR == 1 )  //Frame error 
    {
        U1STAbits.FERR = 0;
    }

    //aqui recoger los mensajes leidos en ucUART1_RX_DATA
    UART1ReceiveCharacter(ucUART1_RX_DATA);
    
}

void __attribute__((interrupt, no_auto_psv)) _U1ErrInterrupt(void)
{

    Nop();
    
    if (U1STAbits.FERR == 1)
    {
        U1STAbits.FERR = 0;
    }
    
    //10.03.2021 DJU Limpiar overflow error RS485
    if ( U1STAbits.OERR == 1 )  
    {
        U1STAbits.OERR  = 0;
    }
    
    IFS4bits.U1EIF = 0;         // Clear Error Flag
}

void UART1init(){
    UART1inicializacion();
    UART1DMA5init();
    UART1DMA6init();
}
