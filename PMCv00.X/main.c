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
// mensajes CAN a almacenar en RAM
msgCAN rx_CAN1Mensaje;
msgCAN rx_CAN2Mensaje;
// funciones de manipulación de mensajes CAN
void rx_CAN1(msgCAN* mensaje);
void rx_CAN2(msgCAN* mensaje);


Buffer_A_UART1 UART1_BufferA __attribute__((space(dma)));
Buffer_B_UART1 UART1_BufferB __attribute__((space(dma)));
Buffer_A_UART2 UART2_BufferA __attribute__((space(dma)));
Buffer_B_UART2 UART2_BufferB __attribute__((space(dma)));

int main(void) {
    CAN1ConfigInicializar();
    UART1init();
    CAN2ConfigInicializar();
    UART2init();
    while(1){
        Nop();
    }
    return 0;
}


/*
 Como sabemos qué clase de mensajes se envían, podemos ahorrarnos muchas
 * comprobaciones previas:
 * - Siempre estamos utilizando el formato de datos estándar
 * - RTR siempre estará a cero
 */
void rx_CAN1(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN1BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN1BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
}

void rx_CAN2(msgCAN* mensaje){
    mensaje->ul_identificador = (uiaCAN2BufferMensajes[mensaje->uc_buffer_num][0] & 0x1FFC) >> 2;
    mensaje->uc_datos[0] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3];
    mensaje->uc_datos[1] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][3] & 0xFF00) >> 8);
    mensaje->uc_datos[2] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4];
    mensaje->uc_datos[3] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][4] & 0xFF00) >> 8);
    mensaje->uc_datos[4] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5];
    mensaje->uc_datos[5] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][5] & 0xFF00) >> 8);
    mensaje->uc_datos[6] = (unsigned char) uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6];
    mensaje->uc_datos[7] = (unsigned char) ((uiaCAN2BufferMensajes[mensaje->uc_buffer_num][6] & 0xFF00) >> 8);
}