/*
 * File:   newmainXC16.c
 * Author: heqro
 *
 * Created on September 3, 2020, 6:35 PM
 */


#include "xc.h"
#include "CAN1Config.h"
#include "CAN2Config.h"

/* Definimos los buffers de mensajes de los módulos CAN */
uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));

int main(void) {
    CAN1ConfigInicializacionCAN(); /* Inicializar CAN1 */
    CAN1ConfigInicializacionDMA0(); /* Configurar DMA0 para transmitir por CAN1 */
    CAN1ConfigInicializacionDMA2(); /* Configurar DMA2 para recibir por CAN1 */
    CAN2ConfigInicializacionCAN(); /* Inicializar CAN2 */
    // CAN2ConfigInicializacionDMA1(); /* Configurar DMA1 para transmitir por CAN2 */
    CAN2ConfigInicializacionDMA3(); /* Configurar DMA3 para recibir por CAN2 */
    
    return 0;
}
