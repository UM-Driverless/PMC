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

/* Definimos los buffers de mensajes de los m�dulos CAN */
uiaTablaMensajesCAN1 uiaCAN1BufferMensajes __attribute__((space(dma),aligned(CAN1_MSG_BUF_LENGTH*16)));
uiaTablaMensajesCAN2 uiaCAN2BufferMensajes __attribute__((space(dma),aligned(CAN2_MSG_BUF_LENGTH*16)));

int main(void) {
    CAN1ConfigInicializar();
    CAN2ConfigInicializar();
    return 0;
}
