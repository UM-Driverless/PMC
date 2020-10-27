#include "xc.h"
#include "CAN1Config.h"

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
}

/*
 void CANEnvioMsg(int ID, int DLC, char[] data){
    for(int i = 0; i<nose; i++){
        sendSomehowData(data[i]);
    }
}
 * 
 */