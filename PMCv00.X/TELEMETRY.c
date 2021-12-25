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

void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{
    unsigned char s[sizeof(unsigned char)*11]; 
    unsigned char crc = ucPackNumber + data1 + data2 + data3 + data4 + data5 + data6 + data7 + data8;
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
    s[10] = EOF;
    UART1WriteString(s);
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
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = ( uiRPM && 0x00FF );
    ucData2 = ( ( uiRPM && 0xFF00 ) >> 8 );
    ucData3 = ( uiECT && 0x00FF );
    ucData4 = ( ( uiECT && 0xFF00 ) >> 8 );
    
    TELEMETRYSendFrame (VARPACK1, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}
