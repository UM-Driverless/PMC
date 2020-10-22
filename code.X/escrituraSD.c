#include "xc.h"
#include "escrituraSD.h"

extern void escrituraSDInicializacionSPI1(void){
    SPI1CON1bits.MODE16 = 1; /* (S18-P10) - indicamos que vamos a trabajar
                              * en modo 16 bits */
    /* Paso 1 (S18-P10): si se utilizan interrupciones, configurar el 
     controlador de interrupciones */
    IFS0bits.SPI1IF = 0; // limpiar flag interrupciones
    IEC0bits.SPI1IE = 0; /* S18-P10 */
    /* Paso 2 (S18-P10): poner a 1 el bit de Master Mode Enable
     * en el registro de SPI1CON1 (MSTEN). */
    SPI1CON1bits.MSTEN = 1;
    /* Paso 3 (S18-P10): limpiar el flag de overflow de recepcion en el 
     * registro de SPI1STAT (SPIROV). */
    SPI1STATbits.SPIROV = 0;
    /* Paso 4 (S18-P10): habilitar la operacion del SPI1 poniendo a 1
     * el bit de Enable del SPI1 del registro de SPI1STAT (SPIEN). */
    SPI1STATbits.SPIEN = 1;
    /* Paso 5 (S18-P10): escribir los datos a transmitir al registro
     * SPI1BUF. La transmision y la recepcion comienzan tan pronto
     * como se escriban datos en el registro de SPI1BUF. */
}

void escrituraSDInicializacionDMA4(void){
    /* El canal DMA4 lo vamos a utilizar para transmitir datos a
     * nuestra tarjeta SD por el protocolo SPI */
    
    /* Paso 1 (S22-P15): DMA Channel to Peripheral Association Setup */
    DMA4REQ = 0b0001010; /* S18-P23: Asociamos el canal DMA4 con el
                          * protocolo de SPI1. */
    DMA4PAD = 0x0248; /* S22-P15: nos indica el valor del registro para escribir
                       * sobre un periférico */
    /* Paso 2 (S22-P16): Peripheral Configuration Setup */
    
    
    /* Paso 3 (S18-P24): Memory Address Initialization */
    DMA4STA = __builtin_dmaoffset(uiaTxBufferSPIA);
    DMA4STB = __builtin_dmaoffset(uiaTxBufferSPIB);
    /* Paso 4 (S22-P19): DMA Transfer Count Set Up*/
    DMA4CNT = NUM_TRANSFERENCIAS - 1; /* S22-P3: estamos indicando el número de transferencias
                       * por DMA que se deben realizar para considerar completa
                       * la transferencia de un bloque de datos.
                       * Este número es DMA0CNT + 1. */
    /* Paso 5 (S22-P19): Operating Mode Set Up */
    DMA4CON = 0x2002; /* S22-P5: 
                       * - Habilitamos el canal de DMA4
                       * - Vamos a transmitir palabras por el canal de DMA
                       * - Leemos de DPSRAM y escribimos en dirección periférica
                       * - Iniciamos interrupción cuando se haya leído la palabra
                       * completa.
                       * - AMODE: 00
                       * - MODE: 10 (modo ping-pong continuo) */
    DMACS0 = 0; /* S22-P9: hacemos un Clear en el registro de estado del 
                 * controlador */
    DMA4CONbits.CHEN = 1; /* habilitamos el canal de DMA */
}