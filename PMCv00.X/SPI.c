#include "xc.h"
#include "SPI.h"
#include "PARAMETERS.h"

unsigned int uiaTxBufferSPIA[NUM_TRANSFERENCIAS] __attribute__((space(dma)));
unsigned int uiaTxBufferSPIB[NUM_TRANSFERENCIAS] __attribute__((space(dma)));


void InicializacionSPI2(void)
{
    //Inicialización de puertos
    //Definir puertos físicos SPI2
    TRIS_SCK2 = 0;  //CLK OUT 
    TRIS_SDI2 = 1;  //DATA IN
    TRIS_SDO2 = 0;  //DATA OUT
    TRIS_SS2 = 0;   //digital output slave select SS2
    TRIS_SS1 = 0;   //digital output slave select SS1
    
    CTR_SS2_SD  = 1; //control del puerto fisico SS2 RTC
    CTR_SS1_RTC = 1; //control del puerto fisico SS1 SD
    
    
    SPI2CON1bits.MODE16 = 1; // (S18-P10) - indicamos que vamos a trabajar
                             // en modo 16 bits 
    // Paso 1 (S18-P10): si se utilizan interrupciones, configurar el 
    // controlador de interrupciones //
    IFS2bits.SPI2IF = 0; // limpiar flag interrupciones
    IEC2bits.SPI2IE = 0; // S18-P10 
    // Paso 2 (S18-P10): poner a 1 el bit de Master Mode Enable
    // en el registro de SPI1CON1 (MSTEN). 
    SPI2CON1bits.MSTEN = 1;
    // Paso 3 (S18-P10): limpiar el flag de overflow de recepcion en el 
    // registro de SPI1STAT (SPIROV). 
    SPI2STATbits.SPIROV = 0;
    // Paso 4 (S18-P10): habilitar la operacion del SPI1 poniendo a 1
    // el bit de Enable del SPI1 del registro de SPI1STAT (SPIEN). 
    SPI2STATbits.SPIEN = 1;
    // Paso 5 (S18-P10): escribir los datos a transmitir al registro
    // SPI1BUF. La transmision y la recepcion comienzan tan pronto
    // como se escriban datos en el registro de SPI1BUF. 
}



void InicializacionDMA4(void)
{
    // El canal DMA4 lo vamos a utilizar para transmitir datos a
    // nuestra tarjeta SD por el protocolo SPI 
    
    // Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup 
    DMA4REQ = 0b0001010; // S18-P23: Asociamos el canal DMA4 con el
                         // protocolo de SPI1. 
    DMA4PAD = 0x0248; // S22-P15: nos indica el valor del registro para escribir
                      // sobre un periférico 
    // Paso 2 (S22-P16): Peripheral Configuration Setup 
    
    
    // Paso 3 (S18-P24): Memory Address Initialization 
    DMA4STA = __builtin_dmaoffset(uiaTxBufferSPIA);
    DMA4STB = __builtin_dmaoffset(uiaTxBufferSPIB);
    // Paso 4 (S22-P19): DMA Transfer Count Set Up
    DMA4CNT = NUM_TRANSFERENCIAS - 1; // S22-P3: estamos indicando el número de transferencias
                       // por DMA que se deben realizar para considerar completa
                       // la transferencia de un bloque de datos.
                       // Este número es DMA0CNT + 1. 
    // Paso 5 (S22-P19): Operating Mode Set Up 
    DMA4CON = 0x2002; // S22-P5: 
                      // - Habilitamos el canal de DMA4
                      // - Vamos a transmitir palabras por el canal de DMA
                      // - Leemos de DPSRAM y escribimos en dirección periférica
                      // - Iniciamos interrupción cuando se haya leído la palabra
                      // completa.
                      // - AMODE: 00
                      // - MODE: 10 (modo ping-pong continuo) 
    DMACS0 = 0; // S22-P9: hacemos un Clear en el registro de estado del 
                // controlador //
    DMA4CONbits.CHEN = 1; // habilitamos el canal de DMA 
}

unsigned char WriteSPI2(unsigned char command, unsigned char slave)
{
    unsigned char temp;	
    unsigned char ucDatoLeido;	
    
    switch (slave)
	{
		case RTC:   CTR_SS1_RTC        = 0; break; //control del puerto fisico SS2 RTC
		case SD:    CTR_SS2_SD         = 0; break;//control del puerto fisico SS1 SD
	}
    
    SPI2STATbits.SPIROV = 0;
    
	temp = SPI2BUF;			// dummy read of the SPI1BUF register to clear the SPIRBF flag
    while (SPI2STATbits.SPITBF);	// Wait for free buffer
    
	SPI2BUF = command;		// write the data out to the SPI peripheral
    
    while (!SPI2STATbits.SPIRBF)	// wait for the data to be sent out
		;
    
	ucDatoLeido = SPI2Get (); 
    
    SPI2STATbits.SPIROV = 0;
    
    switch (slave)
	{
		case RTC:   CTR_SS1_RTC        = 1; break; //control del puerto fisico SS2 RTC
		case SD:    CTR_SS2_SD         = 1; break;//control del puerto fisico SS1 SD
	}    
    
    return(ucDatoLeido);
}

unsigned char ReadSPI2 (unsigned char slave)
{
	unsigned char ucDatoLeido;

    switch (slave)
	{
		case RTC:   CTR_SS1_RTC        = 0; break; //control del puerto fisico SS2 RTC
		case SD:    CTR_SS2_SD         = 0; break;//control del puerto fisico SS1 SD
	}

	//SPIROV Clear overflow bit
    //SPI1BUF Iniciate bus cycle 
	SPI1STATbits.SPIROV = 0;
    
    while (SPI2STATbits.SPITBF);	// Wait for free buffer
    
    SPI2BUF = 0x00;    
    
    //SPIRBF make sure the transaction has completed
    //SPIRBF = 0 reception buffer is empty, transaction hasn't been completed yet.
    //SPIRBF = 1 reception buffer si full, transaction has completed. 
    while (!SPI2STATbits.SPIRBF);	// Wait for data byte
    
    ucDatoLeido = SPI2Get ();        			
    
    //SPI1BUF full.
    //SPIROV Clear overflow bit
    //ucDatoLeido = SPI1Get ();
    SPI1STATbits.SPIROV = 0;
    
    switch (slave)
	{
		case RTC:   CTR_SS1_RTC        = 0; break; //control del puerto fisico SS2 RTC
		case SD:    CTR_SS2_SD         = 0; break;//control del puerto fisico SS1 SD
	}
    
    return (ucDatoLeido);
}


