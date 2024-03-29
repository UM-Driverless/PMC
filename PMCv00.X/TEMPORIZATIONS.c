/* 
 * File:   TEMPORIZATIONS.h
 * Author: 93Urbano
 *
 * Created on December 5, 2021, 12:23 PM
 */

#include "TEMPORIZATIONS.h"
#include "STATEMACHINE.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "CAN1Config.h"
#include "GPIO.h"
#include "TELEMETRY.h"


//VARIABLES
unsigned char ucCount20ms;
unsigned char ucCount500ms;
unsigned char ucCount1s;
unsigned char ucCount5s;
unsigned char ucCount10s;
unsigned int uiCount1min;
unsigned int uiFastTick;


//FUNCIONES
void TEMPORIZATIONInit (void)
{
    ucCount500ms = 0;
    ucCount1s = 0;
    ucCount5s = 0;
    ucCount10s = 0;
    uiCount1min = 0;
    uiFastTick = 0;
}


void TEMPORIZATION_10ms (void)
{
    uiFastTick++;
}

void TEMPORIZATION_20ms (void)
{
    
}

void TEMPORIZATION_100ms (void) //10Hz
{
    //MESSAGESSystemStatusSend();
    GPIO_Entradas();
    
}

void TEMPORIZATION_500ms (void)
{
    //ecan1WriteMessage(0x345, 5, (uiRPM & 0xFF), ((uiRPM >> 8) & 0xFF), (uiECTC & 0xFF), (uiAirTempC & 0xFF), 0, 0, 0, 0);
    //ecan1WriteMessage(DV_DRIVING_DYNAMICS_1, DataLength_8, ucSpeedActual, ucSpeedTarget, ucSteeringAngleActual, ucSteeringAngleTarget, ucBrakeHDRActual, ucBrakeHDRTarget, ucMotorMovementActual, ucMotorMovementTarget);
    /*TELEMETRYSendVARPACK1();
    TELEMETRYSendVARPACK2();
    TELEMETRYSendVARPACK3();
    TELEMETRYSendVARPACK4();
    TELEMETRYSendVARPACK5();
    TELEMETRYSendVARPACK6();
    TELEMETRYSendVARPucASMSACK7();*/
    ucRESSupervisor = FALSE;
    if ( ucSendRESOperative == TRUE )
    {
        ecan1WriteMessage(RES_OPERATIONALMODE, DataLength_2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
        ucSendRESOperative = FALSE;
    }
    ecan1WriteMessage(PMC_STATE, DataLength_4, ucASMS, ucASState, ucAMRequest, ucSDC, 0, 0, 0, 0);
}

void TEMPORIZATION_1s (void)
{
    ecan1WriteMessage(DV_SYSTEM_STATUS, DataLength_5, ucASState+1, 0, 0, 0, 0, 0x00, 0x00, 0x00);
    LED3_Toggle();
    if ( ucRESSupervisor == FALSE )
    {
        ucRESMissCount ++;
    }
    
    
}

void TEMPORIZATION_5s (void)
{
    if ( ucASState == AS_READY )
    {
        ucFlag5sGO = TRUE;
    }
}

void TEMPORIZATION_10s (void)
{
    //ucASState = AS_DRIVING;
}

void TEMPORIZATION_1mins (void)
{
    
}


/*
-----------------------------------------------------------------------------------------
void delay_10ms (unsigned char num)
-----------------------------------------------------------------------------------------
*/
void delay_10ms (unsigned char num)
{
    uiFastTick = 0;                         //fast_tick increments every 10ms
    while (uiFastTick < num);               // wait here until 'num' ticks occur
    uiFastTick = 0;
}