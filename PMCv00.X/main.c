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
#include "TIMER.h"
#include "STATEMACHINE.h"
#include "TEMPORIZATIONS.h"
#include "TELEMETRY.h"
#include "ADC.h"
#include "MESSAGES.h"

// Prototype Declaration
void oscConfig(void);
void clearIntrflags(void);

// Define ECAN Message Buffers
//uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
//uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));

// Select Internal FRC at POR
_FOSCSEL(FNOSC_PRIPLL & IESO_OFF);
// Enable Clock Switching and Configure POSC in XT mode
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_HS);


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


    //ECAN2 Initialisation 		
    //Configure DMA Channel 1 for ECAN2 Transmit
    //Configure DMA Channel 3 for ECAN2 Receive 
	ecan2Init();
    
    
    //INICIALIZACION UART
    UART1init();
    UART2init();

    //ADC INIT
    //ADCInit();
    
    //INICIALIZACION UART1
    //UART1inicializacion();    

    //INICIALIZACION UART2
    //UART2inicializacion();
    
    //INICIALIZACION SPI2
    //InicializacionSPI2();
    
    //INICIALIZACION LEDS
    //27.03.2021 DJU Inicializacion LEDs
    GPIO_init();
    
    //INICIALIZACION TIMER
    TEMPORIZATIONInit();
    TIMER1Init();
    TIMER2Init();
    TIMER1Start();
    TIMER2Start();
    
    //--------------------------------//
    //      CODIGO TESTER             //
    //--------------------------------//
    
    //Write a Message in ECAN1 Transmit Buffer	
    //Request Message Transmission			
	//ecan1WriteMessage(0x002, 0x08, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22);
	//LED1_SetHigh();

    //Write a Message in ECAN2 Transmit Buffer
    //Request Message Transmission			
	//ecan2WriteMessage(0x001, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08);

	//LED2_SetHigh();
    /*
    //Write SPI message to RTC
    WriteSPI2(0X39, RTC);

    //Write SPI message to SD
    WriteSPI2(0X59, SD);
    */
    //ecan1WriteMessage(0x501, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01);
    
    STATEMACHINE_Init();
    //LED1_SetHigh();
    //LED2_SetHigh();
    //LED3_SetHigh();
    //ucASState = AS_READY;

    while (1)
    {
        // Add your application code
        /*LED1_Toggle();
        LED2_Toggle();
        LED3_Toggle();*/
        Nop();
        //ecan1WriteMessage(0x501, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01);
        //ecan1WriteMessage(0xFFF, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08);
        //ecan2WriteMessage(0x001, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01);
        //ecan2WriteMessage(0x004, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08);
        //EJEMPLO MAIN (SOF PackNumber Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7 Byte8 CRC EOF)
        
        //UART1WriteSTring(*string)        
        
        //CREAR FUNCION DE LECTURA DE DIGITALES CONSTANTE
        //GPIO_Entradas();
        
        //ADCRead();
        
        /*EVENTPull();
        STATEMACHINETransition();
        STATEMACHINEAnalysis();*/
        
        //Supervision RES
        RESAnalyse();     
        
        //STATEMACHINE();
        /*if ( ( ucSDC == 0 ) && ( ucASState == AS_DRIVING ) )
        {
            ucASState = AS_EMERGENCY;
        }*/
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

/*  Configure Oscillator to operate the device at 20Mhz
 	Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
 	Fosc= 20M*32/(4*2)=80Mhz for 10M input clock
    FCY = Fosc/2 = 40 MIPS */

	PLLFBDbits.PLLDIV=30;		/* M=32 */
	CLKDIVbits.PLLPOST=0;		/* N1=2 */
	CLKDIVbits.PLLPRE=2;		/* N2=4 */
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
   LED1_Toggle();
   rxECAN1(&rx_CAN1Mensaje); 
}

void __attribute__((interrupt, no_auto_psv)) _DMA3Interrupt(void)
{
   IFS2bits.DMA3IF = 0;          // Clear the DMA3 Interrupt Flag;
   LED2_Toggle();
   rxECAN2(&rx_CAN2Mensaje); 
}


//RES ANALYSE
void RESAnalyse (void)
{
    if ( ucRESMissCount > 3 ) //3segundos
    {
        ucSendRESOperative = TRUE;
    }

}