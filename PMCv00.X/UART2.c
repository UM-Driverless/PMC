#include "xc.h"
#include "UART2.h"

volatile unsigned char ucUART2_RX_DATA;
volatile unsigned char ucUART2_TX_DATA;
int len_2;
int j;

Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

void UART2inicializacion(){
        
    //Inicializacion de puertos
    TRIS_CTR232         = 0;        //digital output UART1  CTR232
    TRIS_UART2_TX       = 0;        //digital output UART1  TX on RF3
    TRIS_UART2_RX       = 1;        //digital  input UART1  RX on RF2
    
    U2MODEbits.STSEL = 0;			// 1-stop bit
	U2MODEbits.PDSEL = 0;			// No Parity, 8-data bits
	U2MODEbits.ABAUD = 0;			// Autobaud Disabled
    U2MODEbits.BRGH     = 0;        // Standard-Speed mode

	U2BRG = BRG_VAL_115200;					// BAUD Rate Setting for 115200


	//********************************************************************************
	//  STEP 1:
	//  Configure UART for DMA transfers
	//********************************************************************************/
	/*
    U2STAbits.UTXISEL0 = 0;			// Interrupt after one Tx character is transmitted
	U2STAbits.UTXISEL1 = 0;			                            
	U2STAbits.URXISEL  = 0;			// Interrupt after one RX character is received
    */
    
	//********************************************************************************
	//  New STEP 1:
	//  Enable UART Rx and Tx Interrupt
	//********************************************************************************/
    IFS1bits.U2TXIF     = 0;        //Clear the Transmit Interrupt Flag
    IEC1bits.U2TXIE     = 1;        //Enable UART TX interrupt
    
	IFS1bits.U2RXIF     = 0;        //Clear the Recieve Interrupt Flag
	IEC1bits.U2RXIE     = 1;        //Enable Recieve Interrupts  
    
    IEC4bits.U2EIE      = 1;        //Enable Error (Framing os Overflow) Interrupt for BREAK
    
	//********************************************************************************
	//  STEP 2:
	//  Enable UART Rx and Tx
	//********************************************************************************/
	U2MODEbits.UARTEN   = 1;		// Enable UART
	U2STAbits.UTXEN     = 1;		// Enable UART Tx
    
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

void UART2WriteCharacter (unsigned char c)
{
    char cCaracterRecibido;
    
    while (U2STAbits.TRMT == 0 ); // wait while transmitting   
    U2TXREG = c;
    while (U2STAbits.TRMT == 0 ); // wait while transmitting  

    Nop ();
    Nop ();
    Nop ();
    //
  	cCaracterRecibido = U2RXREG;    //autolectura
    Nop ();
    Nop ();
    Nop ();
    
    IFS1bits.U2RXIF     = 0;
    Nop ();
    Nop ();
    Nop ();    
   
}

void UART2WriteString(char s[])
{
   len_2 = sizeof(s); 
   for(j = 0; j < len_2; j++) {
       UART2WriteCharacter(s[j]);
   }
}

void UART2ReceiveCharacter (unsigned char c)
{

    Nop ();
    Nop ();
    Nop ();
   
}

/*             INTERRUPCIONES           */

void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void)
{

    IFS1bits.U2TXIF = 0; // Clear TX1 Interrupt flag
    
    //ucUART2_TX_DATA = *pcTramaPorInterrupcionUart1;
    U2TXREG = ucUART2_TX_DATA;
    
}

/*
-----------------------------------------------------------------------------------------
U2RXInterrupt
-----------------------------------------------------------------------------------------
*/
void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{            

	ucUART2_RX_DATA = U2RXREG;    
    Nop();
    Nop();

    IFS1bits.U2RXIF = 0; // Clear RX1 Interrupt flag
    Nop();
    Nop();
    
    //OVERFLOW-ERROR?
    if ( U2STAbits.OERR == 1 )  
    {
        U2STAbits.OERR  = 0; //limpiar el overflow implica limpiar el RXG, a partir de 5 caracteres seguidos salta

        IEC1bits.U2RXIE = 0;        // Disable Recieve Interrupts
        IEC1bits.U2RXIE = 1;        // Enable Recieve Interrupts    
    }

    //FRAME-ERROR?
    if ( U2STAbits.FERR == 1 )  //Frame error 
    {
        U2STAbits.FERR = 0;
    }

    //aqui recoger los mensajes leidos en ucUART1_RX_DATA
    UART2ReceiveCharacter(ucUART2_RX_DATA);
    
}

void __attribute__((interrupt, no_auto_psv)) _U2ErrInterrupt(void)
{

    Nop();
    
    if (U2STAbits.FERR == 1)
    {
        U2STAbits.FERR = 0;
    }
    
    //10.03.2021 DJU Limpiar overflow error RS485
    if ( U2STAbits.OERR == 1 )  
    {
        U2STAbits.OERR  = 0;
    }
    
    IFS4bits.U2EIF = 0;         // Clear Error Flag
}

void UART2init(){
    UART2inicializacion();
    UART2DMA1init();
    UART2DMA7init();
}

