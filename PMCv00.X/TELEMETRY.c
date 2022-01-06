/* 
 * File:   TELEMETRY.h
 * Author: DavidJU
 *
 * Created on 20 de octubre de 2021, 10:47
 */
#include<stdio.h> 
#include <string.h>
#include "UART1.h"
#include "TELEMETRY.h"
#include "MESSAGES.h"

//VARIABLES
unsigned char s[11];


//FUNCIONES
void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{ 
    unsigned char crc;
    
    //Hay que ver si enviarlo numero a numero en ASCII o hacer una transformacion, aunque los valores 0=NULL no los envía.
    
    crc = ucPackNumber + data1 + data2 + data3 + data4 + data5 + data6 + data7 + data8;
    s[0] = ucPackNumber;
    s[1] = data1;
    s[2] = data2;
    s[3] = data3;
    s[4] = data4;
    s[5] = data5;
    s[6] = data6;
    s[7] = data7;
    s[8] = data8;
    s[9] = crc;
    s[10] = 0x0D; //salto de carro
    UART1WriteString(s);
    UART1WriteString ("\r\n"); //salto de linea
}


void TELEMETRYReceiptFrame(unsigned char s[])
{
    unsigned char ucComando;
    
    unsigned char ucPackNumber = s[0];
    unsigned char data1 = s[1];
    unsigned char data2 = s[2];
    unsigned char data3 = s[3];
    unsigned char data4 = s[4];
    unsigned char data5 = s[5];
    unsigned char data6 = s[6];
    unsigned char data7 = s[7];
    unsigned char data8 = s[8];
        
    switch (ucPackNumber)
    {
        case 1:
            ucComando = data1;
            break;
        case 2:
            ucComando = data2;
            break;
        case 3:
            ucComando = data3;
            break;
        case 4:
            ucComando = data4;
            break;
        case 5:
            ucComando = data5;
            break;
        case 6:
            ucComando = data6;
            break;
        case 7:
            ucComando = data7;
            break;
        case 8:
            ucComando = data8;
            break;    
    }
    
}

void TELEMETRYSendVARPACK1 (void)
{
    unsigned char ucData1=0;
    unsigned char ucData2=0;
    unsigned char ucData3=0;
    unsigned char ucData4=0;
    unsigned char ucData5=0;
    unsigned char ucData6=0;
    unsigned char ucData7=0;
    unsigned char ucData8=0;
    
    ucData1=1;
    ucData2=1;
    ucData3=1;
    ucData4=1;
    ucData5=1;
    ucData6=1;
    ucData7=1;
    ucData8=1;
    
    ucData1 = ( uiRPM & 0x00FF );
    ucData2 = ( ( uiRPM & 0xFF00 ) >> 8 );
    ucData3 = ( uiECT & 0x00FF );
    ucData4 = ( ( uiECT & 0xFF00 ) >> 8 );
    
    //puedo comprobar aqui si los datos son 0, y si lo son enviar un 1 o algo
    
    TELEMETRYSendFrame (VARPACK1, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}
