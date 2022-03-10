/* 
 * File:   TELEMETRY.h
 * Author: DavidJU
 *
 * Created on 20 de octubre de 2021, 10:47
 */
#include <stdio.h> 
#include <string.h>
#include "UART1.h"
#include "TELEMETRY.h"
#include "MESSAGES.h"
#include "AS.h"
#include "STATEMACHINE.h"

//VARIABLES
unsigned char telemetryString[12];


//FUNCIONES
void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{ 
    unsigned char crc;
    
    //Hay que ver si enviarlo numero a numero en ASCII o hacer una transformacion, aunque los valores 0=NULL no los envía.
    
    crc = ucPackNumber + data1 + data2 + data3 + data4 + data5 + data6 + data7 + data8;
    telemetryString[0] = 0x01;  //SOH
    telemetryString[1] = ucPackNumber;
    telemetryString[2] = data1;
    telemetryString[3] = data2;
    telemetryString[4] = data3;
    telemetryString[5] = data4;
    telemetryString[6] = data5;
    telemetryString[7] = data6;
    telemetryString[8] = data7;
    telemetryString[9] = data8;
    telemetryString[10] = crc;
    telemetryString[11] = 0x04; //EOT
    UART1WriteString(telemetryString);
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

//ECU DATA 1
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
    
    ucData1 = UARTHexToASCII ( uiRPM & 0x000F );
    ucData2 = UARTHexToASCII ( ( uiRPM & 0x00F0 ) >> 4 );
    ucData3 = UARTHexToASCII ( ( uiRPM & 0x0F00 ) >> 8 );
    ucData4 = UARTHexToASCII ( ( uiRPM & 0xF000 ) >> 12 );
    ucData5 = UARTHexToASCII ( uiECTC & 0x000F );
    ucData6 = UARTHexToASCII ( ( uiECTC & 0x00F0 ) >> 4 );
    ucData7 = UARTHexToASCII ( uiLambda & 0x000F );
    ucData8 = UARTHexToASCII ( ( uiLambda & 0x00F0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK1, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}


//ECU DATA 2
void TELEMETRYSendVARPACK2 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( uiMAPb & 0x000F );
    ucData2 = UARTHexToASCII ( ( uiMAPb & 0x00F0 ) >> 4 );
    ucData3 = UARTHexToASCII ( uiFuelP & 0x000F );
    ucData4 = UARTHexToASCII ( ( uiFuelP & 0x00F0 ) >> 4 );
    ucData5 = UARTHexToASCII ( uiECUTPS & 0x000F );
    ucData6 = UARTHexToASCII ( ( uiECUTPS & 0x00F0 ) >> 4 );
    ucData7 = UARTHexToASCII ( uiECUAPPS & 0x000F );
    ucData8 = UARTHexToASCII ( ( uiECUAPPS & 0x00F0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK2, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}

//ECU DATA 3
void TELEMETRYSendVARPACK3 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( uiBatV & 0x000F );
    ucData2 = UARTHexToASCII ( ( uiBatV & 0x00F0 ) >> 4 );
    ucData3 = UARTHexToASCII ( uiECUBrakeP & 0x000F );
    ucData4 = UARTHexToASCII ( ( uiECUBrakeP & 0x00F0 ) >> 4 );
    ucData5 = UARTHexToASCII ( uiAirTempC & 0x000F );
    ucData6 = UARTHexToASCII ( ( uiAirTempC & 0x00F0 ) >> 4 );
    ucData7 = UARTHexToASCII ( uiOilP & 0x000F );
    ucData8 = UARTHexToASCII ( ( uiOilP & 0x00F0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK3, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}

//DV_DRIVING_DYNAMICS_1 1
void TELEMETRYSendVARPACK4 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( ucSpeedActual & 0x0F );
    ucData2 = UARTHexToASCII ( ( ucSpeedActual & 0xF0 ) >> 4 );
    ucData3 = UARTHexToASCII ( ucSpeedTarget & 0x0F );
    ucData4 = UARTHexToASCII ( ( ucSpeedTarget & 0xF0 ) >> 4 );
    ucData5 = UARTHexToASCII ( ucSteeringAngleActual & 0x0F );
    ucData6 = UARTHexToASCII ( ( ucSteeringAngleActual & 0xF0 ) >> 4 );
    ucData7 = UARTHexToASCII ( ucSteeringAngleTarget & 0x0F );
    ucData8 = UARTHexToASCII ( ( ucSteeringAngleTarget & 0xF0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK4, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}

//DV_DRIVING_DYNAMICS_1 2
void TELEMETRYSendVARPACK5 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( ucBrakeHDRActual & 0x0F );
    ucData2 = UARTHexToASCII ( ( ucBrakeHDRActual & 0xF0 ) >> 4 );
    ucData3 = UARTHexToASCII ( ucBrakeHDRTarget & 0x0F );
    ucData4 = UARTHexToASCII ( ( ucBrakeHDRTarget & 0xF0 ) >> 4 );
    ucData5 = UARTHexToASCII ( ucMotorMovementActual & 0x0F );
    ucData6 = UARTHexToASCII ( ( ucMotorMovementActual & 0xF0 ) >> 4 );
    ucData7 = UARTHexToASCII ( ucMotorMovementTarget & 0x0F );
    ucData8 = UARTHexToASCII ( ( ucMotorMovementTarget & 0xF0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK5, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}

//DV_SYSTEM_STATUS
void TELEMETRYSendVARPACK6 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( ucASState & 0x0F );
    ucData2 = UARTHexToASCII ( ucEBSState & 0x0F );
    ucData3 = UARTHexToASCII ( ucMissionSelected & 0x0F );
    ucData4 = UARTHexToASCII ( ucSteeringState & 0x0F );
    ucData5 = UARTHexToASCII ( ucServiceBrakeState & 0x0F );
    ucData6 = UARTHexToASCII ( ucLapCounter & 0x0F );
    ucData7 = UARTHexToASCII ( ucConesCountActual & 0x0F );
    ucData8 = UARTHexToASCII ( ( ucConesCountActual & 0xF0 ) >> 4 );
    
    TELEMETRYSendFrame (VARPACK6, ucData1, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}

//Varios DV
void TELEMETRYSendVARPACK7 (void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    unsigned char ucData6;
    unsigned char ucData7;
    unsigned char ucData8;
    
    ucData1 = UARTHexToASCII ( ucASMS & 0x0F );
    ucData2 = UARTHexToASCII ( ucGOSignal & 0x0F );
    /*ucData3 = UARTHexToASCII ( ucMissionSelected & 0x0F );
    ucData4 = UARTHexToASCII ( ucSteeringState & 0x0F );
    ucData5 = UARTHexToASCII ( ucServiceBrakeState & 0x0F );
    ucData6 = UARTHexToASCII ( ucLapCounter & 0x0F );
    ucData7 = UARTHexToASCII ( ucConesCountActual & 0x0F );
    ucData8 = UARTHexToASCII ( ( ucConesCountActual & 0xF0 ) >> 4 );
    */
    TELEMETRYSendFrame (VARPACK7, ucASMS, ucData2, ucData3, ucData4, ucData5, ucData6, ucData7, ucData8);
}