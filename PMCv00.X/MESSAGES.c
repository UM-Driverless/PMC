/* 
 * File:   MESSAGES.c
 * Author: 93Urbano
 *
 * Created on August 19, 2021, 6:21 PM
 */

/*
 * Este archivo incluye las funciones necesarias para realizar acciones según los
 * mensajes recibidos vía CAN 
 */


// INCLUDES //
#include "xc.h"
#include "CAN1Config.h"
#include "CAN2Config.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "STATEMACHINE.h"
#include "GPIO.h"
#include "AS.h"

// INICIALIZACION DE VARIABLES //
volatile unsigned long ulCAN1RXID;
volatile unsigned char ucCAN1RXDataLenght;
volatile unsigned char ucCAN1RXData0;
volatile unsigned char ucCAN1RXData1;
volatile unsigned char ucCAN1RXData2;
volatile unsigned char ucCAN1RXData3;
volatile unsigned char ucCAN1RXData4;
volatile unsigned char ucCAN1RXData5;
volatile unsigned char ucCAN1RXData6;
volatile unsigned char ucCAN1RXData7;

volatile unsigned long ulCAN2RXID;
volatile unsigned char ucCAN2RXDataLenght;
volatile unsigned char ucCAN2RXData0;
volatile unsigned char ucCAN2RXData1;
volatile unsigned char ucCAN2RXData2;
volatile unsigned char ucCAN2RXData3;
volatile unsigned char ucCAN2RXData4;
volatile unsigned char ucCAN2RXData5;
volatile unsigned char ucCAN2RXData6;
volatile unsigned char ucCAN2RXData7;


//ASB
unsigned char ucHDRPRES1;
unsigned char ucHDRPRES2;
unsigned char ucNPRES1;
unsigned char ucNPRES2;
unsigned char ucNPRES3;
unsigned char ucNPRES4;
unsigned char ucA1;
unsigned char ucA2;
unsigned char ucBrakePedalPress;

//TRAJECTORY
unsigned char ucMissionState;

//RES
unsigned char ucGOSignal;

//ECU
unsigned int uiRPM;
unsigned int uiMAP;
unsigned int uiTPS;
unsigned int uiECT;
unsigned int uiFuelP;
unsigned int uiOilP;

//DV
unsigned char ucSpeedActual;
unsigned char ucSpeedTarget;
unsigned char ucSteeringAngleActual;
unsigned char ucSteeringAngleTarget;
unsigned char ucBrakeHDRActual;
unsigned char ucBrakeHDRTarget;
unsigned char ucMotorMovementActual;
unsigned char ucMotorMovementTarget;

//STEERING WHEELL
unsigned char ucAMRequest;
unsigned char ucAMRequestPrev;


// INICIALIZACION DE FUNCIONES //
void MESSAGES_CAN1_Rx(void);
void MESSAGES_CAN2_Rx(void);


//DV CAN1
void MESSAGES_CAN1_Rx(){
    
    ulCAN1RXID          = ( ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][0] ) | ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][1] << 8 ) | ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][2] << 16 ) );
    ucCAN1RXDataLenght  = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][3] );
    ucCAN1RXData0       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][4] );
    ucCAN1RXData1       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][5] );
    ucCAN1RXData2       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][6] );
    ucCAN1RXData3       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][7] ); 
    ucCAN1RXData4       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][8] );
    ucCAN1RXData5       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][9] );
    ucCAN1RXData6       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][10] );
    ucCAN1RXData7       = ( ucCAN1BUSRXList[ucCAN1BUSRXWrite][11] ); 
    switch ( ulCAN1RXID )  
    {
        case ASB_ANALOG:
            ucHDRPRES1 = ucCAN1RXData0;
            ucHDRPRES2 = ucCAN1RXData1;
            ucNPRES1 = ucCAN1RXData2;
            ucNPRES2 = ucCAN1RXData3;
            ucNPRES3 = ucCAN1RXData4;
            ucNPRES4 = ucCAN1RXData5;
            ucA1 = ucCAN1RXData6;
            ucA2 = ucCAN1RXData7;
            break;
        case TRAJECTORY_STATE:
            ucMissionState = ucCAN1RXData2;
            ucASMissionRequest = ucCAN1RXData3;
            if ( ucASMissionRequest != ucASMissionRequestPrev ) 
            {
                ASMisionTransit();
            }
            ucASMissionRequest != ucASMissionRequestPrev;
            ucASMissionTransited = ucCAN1RXData4;
            //La xavier se ha enterado perfectamente de lo que tiene que hacer
            if ( ucASMissionTransited == ucMissionSelected )
            {
                //ucFLAG que permite el GOOO
            }
            break;
        case SENFL_SIG:
            ucVelFL = ucCAN1RXData4;
            break;
        case SENFR_SIG:
            ucVelFR = ucCAN1RXData4;
            break;
        case SENRL_SIG:
            ucVelRL = ucCAN1RXData4;
            break;
        case SENRR_SIG:
            ucVelRR = ucCAN1RXData4;
            break;
        case ASB_SIGNALS:
            ucBrakePedalPress = ucCAN1RXData0;
            break;
        case RES_PDOTR:
            ucGOSignal = ( ( ucCAN1RXData0 & 0x06 ) >> 1 );
            break;
        case STEERW_DV:
            ucAMRequest = ucCAN1RXData0;
            if ( ucAMRequest != ucAMRequestPrev )
            {
                ASMisionTransit();
            }
            ucAMRequest = ucAMRequestPrev;
            break;
    }

}


//ECU CAN2
void MESSAGES_CAN2_Rx(){
    
    ulCAN2RXID          = ( ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][0] ) | ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][1] << 8 ) | ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][2] << 16 ) );
    ucCAN2RXDataLenght  = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][3] );
    ucCAN2RXData0       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][4] );
    ucCAN2RXData1       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][5] );
    ucCAN2RXData2       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][6] );
    ucCAN2RXData3       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][7] ); 
    ucCAN2RXData4       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][8] );
    ucCAN2RXData5       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][9] );
    ucCAN2RXData6       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][10] );
    ucCAN2RXData7       = ( ucCAN2BUSRXList[ucCAN2BUSRXWrite][11] ); 
    
    switch ( ulCAN2RXID )  
    {
        case ECUID1: 
            uiRPM = ucCAN2RXData0;
            uiRPM |= (ucCAN2RXData1 << 8 );
            uiMAP = ucCAN2RXData2;
            uiMAP |= (ucCAN2RXData3 << 8 );
            uiTPS = ucCAN2RXData4;
            uiTPS |= (ucCAN2RXData5 << 8 );
            //uiCoolantP = ucCAN2RXData6;
            //uiCoolantP |= (ucCAN2RXData7 << 8 );
            break;
        case ECUID2:
            uiFuelP = ucCAN2RXData0;
            uiFuelP |= (ucCAN2RXData1 << 8 );
            uiOilP = ucCAN2RXData2;
            uiOilP |= (ucCAN2RXData3 << 8 );
            /*uiEngineDemand = ucCAN2RXData4;
            uiEngineDemand |= (ucCAN2RXData5 << 8 );
            uiWastegatePressure = ucCAN2RXData6;
            uiWastegatePressure |= (ucCAN2RXData7 << 8 );*/
            break;
        case ECUID3:
            
            break;
        case ECUID4:
            
            break;
        case ECUID5:
            
            break;
        case ECUID6:
            
            break;
        case ECUID7:
            
            break;
        case ECUID8:
            
            break;
        case ECUID9:
            
            break;
        case ECUID10:
            
            break;
        case ECUID11:
            
            break;
        case ECUID12:
            
            break;
            
    }
}

void MESSAGESSystemStatusSend(void)
{
    unsigned char ucData1;
    unsigned char ucData2;
    unsigned char ucData3;
    unsigned char ucData4;
    unsigned char ucData5;
    
    
    ucData1 = ( ucASState && 0x07 );
    ucData1 |= ( ucEBSState << 3 );
    ucData1 |= ( ucMissionSelected << 5 );
    ucData2 = ucSteeringState;
    ucData2 = ( ucServiceBrakeState << 1 );
    ucData2 = ( ( ucLapCounter && 0x0F ) << 3 );
    ucData2 = ( ( ucConesCountActual && 0x01 ) << 7 );
    ucData3 = ( ( ucConesCountActual && 0xFE ) >> 1 );
    ucData3 = ( ( uiConesCountAll && 0x01 ) << 7 );
    ucData4 = ( uiConesCountAll && 0x1FE );
    ucData5 = ( uiConesCountAll && 0xFE00 );
    
    
    ecan1WriteMessage(SYSTEM_STATUS, DataLength_5, ucData1, ucData2, ucData3, ucData4, ucData5, 0x00, 0x00, 0x00);
}