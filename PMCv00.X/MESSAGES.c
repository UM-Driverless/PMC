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


//ASSIS
unsigned char ucASState_prev;

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
unsigned char ucAS_DRIVING_MODE;
unsigned char ucPWMOUT;
unsigned char ucWDOUT;
unsigned char ucSDC_EBS_RDY;
unsigned char ucEVALVS;
unsigned char ucHeartbeat;
unsigned char ucErrorid;
unsigned char ucRequest_AS_State;

//TRAJECTORY
unsigned char ucMissionState;
unsigned char ucThrottle;
unsigned char ucClutch;
unsigned char ucBrake;
unsigned char ucSteering;
unsigned char ucGear;
unsigned char ucError_id;
unsigned char ucGPIO;
unsigned char ucMissionState;
unsigned char ucAMtransit;
unsigned char ucAMtransited;

//PMC
unsigned char ucLatitude1;
unsigned char ucLatitude2;
unsigned char ucLatitude3;
unsigned char ucAltitude1;
unsigned char ucAltitude2;
unsigned char ucAltitude3;
unsigned char ucSpeed1;
unsigned char ucSpeed2;
unsigned char ucAnalog0; // Analog
unsigned char ucAnalog1;
unsigned char ucAnalog2;
unsigned char ucAnalog3;
unsigned char ucAnalog4;
unsigned char ucAnalog5;
unsigned char ucElectronic_box_temp;
unsigned char ucSeconds; //Timestap
unsigned char ucMinutes;
unsigned char ucHours;
unsigned char ucDay;
unsigned char ucMonth;
unsigned char ucYear;
unsigned char ucETC; //ECU
unsigned char ucAirTemp;
unsigned char ucTPS;
unsigned char ucASMode;//State  
//RES
unsigned char ucGOSignal;
unsigned char ucRequestedState;
unsigned char ucAddressedNodeID;

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

//SEN
unsigned char ucAx;
unsigned char ucAy;
unsigned char ucAz;
unsigned char ucGx;
unsigned char ucGy;
unsigned char ucGz;
unsigned char ucMx;
unsigned char ucMy;

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
            ucAS_DRIVING_MODE   = ucCAN1RXData1;
            ucPWMOUT            = ucCAN1RXData2;
            ucWDOUT             = ucCAN1RXData3;
            ucSDC_EBS_RDY       = ucCAN1RXData4;
            ucEVALVS            = ucCAN1RXData5;
            break;
        case ASB_STATE:
            /*ucHeartbeat        = ucCAN1RXData0;
            ucErrorid          = ucCAN1RXData2;
            ucRequest_AS_State = ucCAN1RXData3;*/
            break;
        case TRAJECTORY_STATE:
            ucError_id     = ucCAN1RXData0;
            ucGPIO         = ucCAN1RXData1;
            //ucAMtransit    = ucCAN1RXData3;
            ucAMtransited  = ucCAN1RXData4;
            ucMissionState = ucCAN1RXData2;
            ucASMissionRequest = ucCAN1RXData3;
            if ( ucASMissionRequest != ucASMissionRequestPrev ) 
            {
                ASMisionTransit();
            }
            ucASMissionRequestPrev = ucASMissionRequest;
            ucASMissionTransited = ucCAN1RXData4;
            //La xavier se ha enterado perfectamente de lo que tiene que hacer
            if ( ucASMissionTransited == ucMissionSelected )
            {
                //if ucFLAG que permite el GOOO
                //MANDAR EN PMC_STATE LA SEÑAL DE GO
                ecan1WriteMessage(PMC_STATE, DataLength_2, ucASMS, ucMissionSelected, 0, 0, 0, 0, 0, 0);
            }
            break;
        case SENFL_IMU:
            /*ucAx = ucCAN1RXData0;
            ucAy = ucCAN1RXData1;
            ucAz = ucCAN1RXData2;
            ucGx = ucCAN1RXData3;
            ucGy = ucCAN1RXData4;
            ucGz = ucCAN1RXData5;
            ucMx = ucCAN1RXData6;
            ucMy = ucCAN1RXData7;*/
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
        case RES_PDOTR:
            //ucGOSignal = ( ( ucCAN1RXData0 & 0x06 ) >> 1 );
            break;
        case STEERW_DV:
            ucAMRequest = ucCAN1RXData0;
            if ( ucAMRequest != ucAMRequestPrev )
            {
                ASMisionTransit();
            }
            ucAMRequest = ucAMRequestPrev;
            break;
        case ASSIS_R:
             
            break;
            
        case ASSIS_C:
            
            break;
            
        case ASSIS_L:
            
            break;
        case TRAJECTORY_ACT:
            ucThrottle   =ucCAN1RXData0; 
            ucClutch     = ucCAN1RXData1;
            ucBrake      = ucCAN1RXData2;
            ucSteering   = ucCAN1RXData3;
            ucGear       = ucCAN1RXData4;
            break;
        case TRAJECTORY_GPS:
            //Variable latitude data 0-2
            //Variable altitude data 3-5
            //Variable speed data 6-7
            break;
        case TRAJECTORY_IMU:
            /*ucAx = ucCAN1RXData0;
            ucAy = ucCAN1RXData1;
            ucAz = ucCAN1RXData2;
            ucGx = ucCAN1RXData3;
            ucGy = ucCAN1RXData4;
            ucGz = ucCAN1RXData5;
            ucMx = ucCAN1RXData6;
            ucMy = ucCAN1RXData7;*/
            break;
        case PMC_GPS:
            ucLatitude1 =ucCAN1RXData0;
            ucLatitude2 =ucCAN1RXData1;
            ucLatitude3 = ucCAN1RXData2;
            ucAltitude1 = ucCAN1RXData3;
            ucAltitude2 = ucCAN1RXData4;
            ucAltitude3 = ucCAN1RXData5;
            ucSpeed1    = ucCAN1RXData6;
            ucSpeed2    = ucCAN1RXData7;
            break;
        case PMC_IMU:
          /*  ucAx = ucCAN1RXData0;
            ucAy = ucCAN1RXData1;
            ucAz = ucCAN1RXData2;
            ucGx = ucCAN1RXData3;
            ucGy = ucCAN1RXData4;
            ucGz = ucCAN1RXData5;
            ucMx = ucCAN1RXData6;
            ucMy = ucCAN1RXData7;*/
            break;
        case PMC_ANALOG:
            /*ucAnalog0             = ucCAN1RXData0;
            ucAnalog1             = ucCAN1RXData1;
            ucAnalog2             = ucCAN1RXData2;
            ucAnalog3             = ucCAN1RXData3;
            ucAnalog4             = ucCAN1RXData4;
            ucElectronic_box_temp = ucCAN1RXData5;*/
            break;
        case PMC_TIMESTAMP:
           /* ucSeconds = ucCAN1RXData0;
            ucMinutes = ucCAN1RXData1;
            ucHours   = ucCAN1RXData2;
            ucDay     = ucCAN1RXData3;
            ucMonth   = ucCAN1RXData4;
            ucYear    = ucCAN1RXData5;*/
            break;
        case PMC_DIGITAL: //bytes troceados 
            break;
        case PMC_ECU1:
            
           /* ucETC     = ucCAN1RXData2;
            ucAirTemp = ucCAN1RXData3;
            ucTPS     = ucCAN1RXData4;*/
            break;
        case PMC_ECU2:
            break;
        case PMC_STATE:
            //ucASMode =ucCAN1RXData0;
            break;
        case NMT_NODE_CONTROL:
            /*ucRequestedState = ucCAN1RXData0;
            ucAddressedNodeID = ucCAN1RXData1;*/
            break;
        case SYNC:
            break;
        case EMERGENCY:
            break;
        case TIME_STAMP:
            break;
        case RES_PDORC:
            break;
        case RES_SDOTR:
            break;
        case RES_SDORC:
            break;
        case RES_NMTMON:
            ////ucEmptyByte = ucCAN1RXData0;
            break;
        case LSS_T:
            break;
        case LSS_R:
            break;
            
        default:
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
            uiRPM = ucCAN2RXData1;
            uiRPM |= (ucCAN2RXData0 << 8 );
            uiMAPkPa = ucCAN2RXData3;
            uiMAPkPa |= (ucCAN2RXData2 << 8 );
            uiMAPb = uiMAPkPa / 1000; //bares
            uiECUTPS = ucCAN2RXData5;
            uiECUTPS |= (ucCAN2RXData4 << 8 );
            uiECUTPS = uiECUTPS / 10; //%
            //uiCoolantP = ucCAN2RXData6;
            //uiCoolantP |= (ucCAN2RXData7 << 8 );
            break;
        case ECUID2:
            uiFuelP = ucCAN2RXData1;
            uiFuelP |= (ucCAN2RXData0 << 8 );
            uiFuelP = uiFuelP / 1000; //bares
            uiOilP = ucCAN2RXData3;
            uiOilP |= (ucCAN2RXData2 << 8 );
            uiOilP = uiOilP / 1000; //bares
            uiECUAPPS = ucCAN2RXData5;
            uiECUAPPS |= (ucCAN2RXData4 << 8 );
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
            uiLambda = ucCAN2RXData1;
            uiLambda |= (ucCAN2RXData0 << 8 );
            uiLambda = uiLambda / 10; //0.01Lambda
            break;
        case ECUID6:
            //trigger home counters
            break;
        case ECUID7:
            //knock
            break;
        case ECUID8:
            uiECUBrakeP = ucCAN2RXData1;
            uiECUBrakeP |= (ucCAN2RXData0 << 8 );
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
            uiBatV = ucCAN2RXData1;
            uiBatV |= (ucCAN2RXData0 << 8 );
            uiBatV = uiBatV / 10; //voltios
            break;
        case ECUID19:
            uiECTK = ucCAN2RXData1;
            uiECTK |= (ucCAN2RXData0 << 8 );
            uiECTC = ( uiECTK / 10 ) - 273;
            uiAirTempK = ucCAN2RXData3;
            uiAirTempK |= (ucCAN2RXData2 << 8 );
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