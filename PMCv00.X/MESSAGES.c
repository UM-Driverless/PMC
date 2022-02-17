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

//ETC
unsigned char ucAPPS1;
unsigned char ucAPPS2; 
unsigned char ucTPS1;
unsigned char ucTPS2; 
unsigned char ucAPPS_STATE; 
unsigned char ucTPS_STATE; 
unsigned char ucCLUTCHState;
unsigned char ucETB_STATE; 

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
unsigned int uiMAPkPa; //0.1kPa
unsigned int uiMAPb; //bar
unsigned int uiECUTPS;
unsigned int uiECUAPPS;
unsigned int uiECTK; //kelvin
unsigned int uiECTC; //celsious
unsigned int uiFuelP;
unsigned int uiOilP;
unsigned int uiAirTempK; //kelvin
unsigned int uiAirTempC; //celsious
unsigned int uiLambda;
unsigned int uiECUBrakeP; //kPA
unsigned int uiBatV; 
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
        case ETC_SIGNAL:
            ucAPPS1 = ucCAN1RXData0;
            ucAPPS2 = ucCAN1RXData1; 
            ucTPS1 = ucCAN1RXData2;
            ucTPS2 = ucCAN1RXData3; 
            break;
        case ETC_STATE:
            ucTPS_STATE = ucCAN1RXData0; 
            ucAPPS_STATE = ucCAN1RXData1; 
            ucCLUTCHState = ucCAN1RXData2;
            ucETB_STATE = ucCAN1RXData3; 
            break;
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
        case ASB_SIGNALS:
            ucBrakePedalPress = ucCAN1RXData0;
            break;
        case ASB_STATE:
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
            uiMAPkPa = ucCAN2RXData2;
            uiMAPkPa |= (ucCAN2RXData3 << 8 );
            uiMAPb = uiMAPkPa / 1000; //bares
            uiECUTPS = ucCAN2RXData4;
            uiECUTPS |= (ucCAN2RXData5 << 8 );
            uiECUTPS = uiECUTPS / 10; //%
            //uiCoolantP = ucCAN2RXData6;
            //uiCoolantP |= (ucCAN2RXData7 << 8 );
            break;
        case ECUID2:
            uiFuelP = ucCAN2RXData0;
            uiFuelP |= (ucCAN2RXData1 << 8 );
            uiFuelP = uiFuelP / 1000; //bares
            uiOilP = ucCAN2RXData2;
            uiOilP |= (ucCAN2RXData3 << 8 );
            uiOilP = uiOilP / 1000; //bares
            uiECUAPPS = ucCAN2RXData4;
            uiECUAPPS |= (ucCAN2RXData5 << 8 );
            uiECUAPPS = uiECUAPPS / 10; //%
            /*uiEngineDemand = ucCAN2RXData4;
            uiEngineDemand |= (ucCAN2RXData5 << 8 );
            uiWastegatePressure = ucCAN2RXData6;
            uiWastegatePressure |= (ucCAN2RXData7 << 8 );*/
            break;
        case ECUID3:
            //no used
            break;
        case ECUID4:
            //no used
            break;
        case ECUID5:
            uiLambda = ucCAN2RXData0;
            uiLambda |= (ucCAN2RXData1 << 8 );
            uiLambda = uiLambda / 10; //0.01Lambda
            break;
        case ECUID6:
            //trigger home counters
            break;
        case ECUID7:
            //knock
            break;
        case ECUID8:
            uiECUBrakeP = ucCAN2RXData0;
            uiECUBrakeP |= (ucCAN2RXData1 << 8 );
            uiECUBrakeP = uiECUBrakeP / 100; //bares
            break;
        case ECUID9:
            //wheelspeed
            break;
        case ECUID10:
            //no used
            break;
        case ECUID11:
            //no used
            break;
        case ECUID12:
            //no used
            break;
        case ECUID15:
            uiBatV = ucCAN2RXData0;
            uiBatV |= (ucCAN2RXData1 << 8 );
            uiBatV = uiBatV / 10; //voltios
            break;
        case ECUID19:
            uiECTK = ucCAN2RXData0;
            uiECTK |= (ucCAN2RXData1 << 8 );
            uiECTC = ( uiECTK / 10 ) - 273;
            uiAirTempK = ucCAN2RXData2;
            uiAirTempK |= (ucCAN2RXData3 << 8 );
            uiAirTempC = ( uiAirTempK / 10 ) - 273;
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
    
    
    ecan1WriteMessage(DV_SYSTEM_STATUS, DataLength_5, ucData1, ucData2, ucData3, ucData4, ucData5, 0x00, 0x00, 0x00);
}