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
//#include "escrituraSD.h"

/* Definimos los buffers de mensajes de los módulos CAN */
uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));
Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));
Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

int main(void) {
    CAN1ConfigInicializar();
    UART1init();
    CAN2ConfigInicializar();
    UART2init();
    return 0;
}
