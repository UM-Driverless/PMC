/*
 * File:   newmainXC16.c
 * Author: heqro
 *
 * Created on September 3, 2020, 6:35 PM
 */


#include "xc.h"
#include "CAN1Config.h"
#include "CAN2Config.h"
#include "UART1.h"
#include "UART2.h"
#include "SPI.h"
#include "GPIO.h"

// Prototype Declaration
void oscConfig(void);
void clearIntrflags(void);

// Define ECAN Message Buffers
//uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
//uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));


int main(void) {   
    
    /* Configure Oscillator Clock Source 	*/
	oscConfig();

    /* Clear Interrupt Flags 				*/
	clearIntrflags();

    //----------------------------------------------//
    //              INICIALIZACIONES                //
    //----------------------------------------------//
    
    
    //ECAN1 Initialisation 		
    //Configure DMA Channel 0 for ECAN1 Transmit
    //Configure DMA Channel 2 for ECAN1 Receive 
	ecan1Init();
	dma0init();	
	dma2init();

    //ECAN2 Initialisation 		
    //Configure DMA Channel 1 for ECAN2 Transmit
    //Configure DMA Channel 3 for ECAN2 Receive 
	ecan2Init();
	dma1init();	
	dma3init();
    
    //INICIALIZACION UART1
    UART1inicializacion();    

    //INICIALIZACION UART2
    UART2inicializacion();
    
    //INICIALIZACION SPI2
    InicializacionSPI2();
    
    //INICIALIZACION LEDS
    //27.03.2021 DJU Inicializacion LEDs
    GPIO_init();
    
    //--------------------------------//
    //      CODIGO TESTER             //
    //--------------------------------//
    
    //Write a Message in ECAN1 Transmit Buffer	
    //Request Message Transmission			
	ecan1WriteMessage(0x152, 0x08, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22);
	

    //Write a Message in ECAN2 Transmit Buffer
    //Request Message Transmission			
	ecan2WriteMessage(0x001, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08);
	
    /*
    //Write SPI message to RTC
    WriteSPI2(0X39, RTC);

    //Write SPI message to SD
    WriteSPI2(0X59, SD);
    */

    while (1)
    {
        // Add your application code
        LED1_SetHigh();
        LED2_SetHigh();
        LED3_SetHigh();
        Nop();
        
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
	/*__builtin_write_OSCCONH(0x03);		// Initiate Clock Switch to Primary
													// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b011);	// Wait for Clock switch to occur	
    */

/* Wait for PLL to lock */
    /*
	while(OSCCONbits.LOCK!=1) {};
    */
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
