/* 
 * File:   STATEMACHINE.h
 * Author: 93Urbano
 *
 * Created on December 5, 2021, 12:12 AM
 */

#include "STATEMACHINE.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "TEMPORIZATIONS.h"
#include "AS.h"

//VARIABLES
unsigned char ucASState;
unsigned char ucEBSactivate;
unsigned char ucVehicleStandstill;
unsigned char ucVelFL;
unsigned char ucVelFR;
unsigned char ucVelRL;
unsigned char ucVelRR;
unsigned char ucMissionSelected;
unsigned char ucASMS;
unsigned char ucASBCheckUp;
unsigned char ucTSActive;
unsigned char ucMarcha;
unsigned char ucFlag5sGO;
unsigned char ucR2D;
unsigned char ucASStatePrev;
unsigned char ucBrakeEngaged;
unsigned char ucSMError;
unsigned char ucEBSState;
unsigned char ucASMode;
unsigned char ucSteeringState;
unsigned char ucServiceBrakeState;
unsigned char ucLapCounter;
unsigned char ucConesCountActual;
unsigned int uiConesCountAll;

//FUNCIONES
void STATEMACHINE_Init (void) 
{
    ucASState = AS_OFF;
}


void STATEMACHINE (void) //ejecutar cada poco tiempo
{
    //ANALISIS DE VARIABLES QUE INFLUYEN EN LA MAQUINA
    SM_EBSAnalyse();
    SM_VehicleStandstillAnalyse();
    SM_TractiveSystemAnalyse();
    SM_R2DAnalyse();
    SM_BrakesEngagedAnalyse();
    
    //MAQUINA DE ESTADOS
    if ( ( ucEBSactivate == EBS_ACTIVATED1 ) || ( ucEBSactivate == EBS_ACTIVATED2 ) )
    {
        //analizar si mision finish y VS
        if ( ( ucMissionState == TJ_MISSION_FINISHED ) && ( ucVehicleStandstill == TRUE ) )
        {
            //AS FINISHED
            ucASState = AS_FINISHED;
        }
        else
        {
            //AS EMERGENCY
            ucASState = AS_EMERGENCY;
        }
    }
    else
    {
        if ( ( ucMissionSelected != MANUAL_DRIVING ) && ( ucASMS == TRUE ) && ( ucASBCheckUp == TRUE ) && ( ucTSActive == TRUE ) )
        {
            //ANALIZAR R2D
            if ( ( ucR2D == TRUE ) && ( ucFlag5sGO == TRUE ) && ( ucGOSignal == TRUE ) )
            {
                if ( ucASStatePrev == AS_READY )
                {
                    ucASState = AS_DRIVING;
                }              
            }
            else
            {
                //ANALIZAR BRAKES ENGAGED
                if ( ucBrakeEngaged == TRUE )
                {
                    //si ha transitado a AS READY, empezamos a contar
                    ucCount5s = 0;
                    ucASState = AS_READY;
                }
                else
                {
                    ucASState = AS_OFF;
                }
            }
        }
        else
        {
            //AS OFF
            ucASState = AS_OFF;
        }
    }
    
    //COMPROBACION DE CAMBIO
    if ( ucASStatePrev != ucASState )
    {
        ucASStatePrev = ucASState;
        //Enviamos cambio de estado a CAN
        //ecan1WriteMessage( DV_SYSTEM_STATUS, )
    }
}


void SM_EBSAnalyse (void)
{
    if ( ( ucHDRPRES1 > ucHDRPRES1max ) && ( ucHDRPRES2 > ucHDRPRES2max ) )
    {
        if ( ucNPRES3 > ucNPRES3max ) 
        {
            ucEBSactivate = EBS_ACTIVATED1;
        }
        else if ( ucNPRES4 > ucNPRES4max ) 
        {
            ucEBSactivate = EBS_ACTIVATED2;
        }
        else
        {
            ucEBSactivate = EBS_NONEDV;
        }
        
    }
    else
    {
        if ( ucNPRES3 > ucNPRES3max ) 
        {
            ucEBSactivate = EBS_ERROR1;
        }
        else if ( ucNPRES4 > ucNPRES4max ) 
        {
            ucEBSactivate = EBS_ERROR2;
        }
        else
        {
            ucEBSactivate = EBS_DISACTIVATED;
        }
    }
}

void SM_VehicleStandstillAnalyse (void)
{
    
    if ( ( ucVelFL == 0 ) && ( ucVelFR == 0 ) && ( ucVelRL == 0 ) && ( ucVelRR == 0 ) )
    {
        //si estan paradas todas las ruedas TRUE
        ucVehicleStandstill = TRUE;
    }
    else
    {
        ucVehicleStandstill = FALSE;
    }
    
}

void SM_TractiveSystemAnalyse (void)
{
    if ( ( uiRPM > RALENTI ) && ( ucMarcha == 0 ) )
    {
        ucTSActive = TRUE;
    }
    else
    {
        ucTSActive = FALSE;
    }
}


void SM_R2DAnalyse (void)
{
    if ( ( uiRPM > RALENTI ) && ( ucMarcha != 0 ) )
    {
        ucR2D = TRUE;
    }
    else
    {
        ucR2D = FALSE;
    }
}

void SM_BrakesEngagedAnalyse (void)
{
    //REALMENTE ESTAMOS FRENANDO?
    if ( ( ucHDRPRES1 > ucHDRPRES1max ) && ( ucHDRPRES2 > ucHDRPRES2max ) && ( ucBrakePedalPress == FALSE) )
    {
        //confirmamos que no es el freno de emergencia quien lo ha activado
        if ( ( ucNPRES3 < ucNPRES3min ) && ( ucNPRES4 < ucNPRES4min ) )
        {
            ucBrakeEngaged = TRUE;
        }
        else
        {
            ucBrakeEngaged = TRUE;
            ucSMError = TRUE;
        }
    }
    else
    {
        ucBrakeEngaged = FALSE;
    }
}