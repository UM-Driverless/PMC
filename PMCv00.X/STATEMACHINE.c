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
unsigned char ucNeutra;
unsigned char ucSDC;
unsigned char ucFlag5sGO;
unsigned char ucR2D;
unsigned char ucASStatePrev;
unsigned char ucBrakeEngaged;
unsigned char ucSMError;
unsigned char ucEBSState;
unsigned char ucSteeringState;
unsigned char ucServiceBrakeState;
unsigned char ucLapCounter;
unsigned char ucConesCountActual;
unsigned int uiConesCountAll;
unsigned char ColaEventos[MAX_EVENT][2];
unsigned char ucIndiceEscritura;
unsigned char ucIndiceLectura;
unsigned char ucEvent;
unsigned char ucState;
unsigned char ucTransitedState;

//FUNCIONES
void STATEMACHINE_Init (void) 
{
    ucASState = AS_OFF;
}


void EVENTPush (unsigned char ucPushEvent, unsigned char ucPushState)
{
    ColaEventos[ucIndiceEscritura][EVENTS]=ucPushEvent;
    ColaEventos[ucIndiceEscritura][STATES]=ucPushState;
}


void EVENTPull (void)
{
    ucEvent=ColaEventos[ucIndiceLectura][EVENTS];
    ucState=ColaEventos[ucIndiceLectura][STATES];
}


void STATEMACHINETransition (void)
{
    //ANALISIS DE VARIABLES QUE INFLUYEN EN LA MAQUINA
    SM_EBSAnalyse();
    SM_VehicleStandstillAnalyse();
    SM_TractiveSystemAnalyse();
    SM_R2DAnalyse();
    SM_BrakesEngagedAnalyse();
    
    if(ucEvent!=EV_NONE)
    {
        //if de antes por si quieres analizar otras cosas
       
        switch (ucEvent)
        {
            case EV_EBS_ACTIVATED:
                //if realmente sigue activo en este momento?
                if ( ( ucEBSactivate == EBS_ACTIVATED1 ) || ( ucEBSactivate == EBS_ACTIVATED2 ) )
                {
                    if ( ( ucMissionState != TJ_MISSION_FINISHED ) || ( ucVehicleStandstill != TRUE ) )
                    {
                        ucTransitedState = AS_EMERGENCY;
                    }
                }
                break;
        }
    }
}

void STATEMACHINEAnalysis (void)
{
    //Eventos que no requieran ni estar en un estado ni transitar a uno
    switch (ucEvent)
    {
        
    }
    //Analizar en cada estado en el que nos encontremos eventos 
    //que solo se deben ejecutar en ese estado
    switch (ucTransitedState)
    {
        case AS_OFF:
            STATEMACHINE_ASOff();
            break;
        case AS_READY:
            STATEMACHINE_ASReady();
            break;
        case AS_DRIVING:
            STATEMACHINE_ASDriving();
            break;
        case AS_EMERGENCY:
            STATEMACHINE_ASEmergency();
            break;
        case AS_FINISHED:
            STATEMACHINE_ASFinished();
            break;
        default:
            //tenemos un estado no deefinido
            //apuntar error
            break;
    }
}


//ESTADOS DV
void STATEMACHINE_ASOff (void)
{
    switch(ucEvent)
    {
        case EV_NONE:
            //no hago nada
            break;
        case EV_EBS_ACTIVATED:
            
            break;
    }
}

void STATEMACHINE_ASReady (void)
{
    
}

void STATEMACHINE_ASDriving (void)
{
    
}

void STATEMACHINE_ASEmergency (void)
{
    switch(ucEvent)
    {
        case EV_NONE:
            //no hago nada
            break;
        case EV_EBS_ACTIVATED:
            
            break;
    }
}

void STATEMACHINE_ASFinished (void)
{
    
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
        if ( ( ucAMRequest != MANUAL_DRIVING ) && ( ucASMS == TRUE ) && ( ucASBCheckUp == TRUE ) && ( ucTSActive == TRUE ) )
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
    //if ( ( ucHDRPRES1 > ucHDRPRES1max ) && ( ucHDRPRES2 > ucHDRPRES2max ) )
    if ( ( ucHDRPRES1 > ucHDRPRES1max ) )
    {
        if ( ucNPRES3 > ucNPRES3max ) 
        {
            ucEBSactivate = EBS_ACTIVATED1;
        }
        else if ( ucNPRES4 > ucNPRES4max ) 
        {
            ucEBSactivate = EBS_ACTIVATED2;
        }
        else if ( ( ucNPRES3 > ucNPRES3max ) && ( ucNPRES4 > ucNPRES4max ) )
        {
            ucEBSactivate = EBS_ACTIVATEDBOTH;
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
        else if ( ( ucNPRES3 > ucNPRES3max ) && ( ucNPRES4 > ucNPRES4max ) )
        {
            ucEBSactivate = EBS_ERRORBOTH;
        }
        else
        {
            ucEBSactivate = EBS_DISACTIVATED;
        }
    }
}

void SM_VehicleStandstillAnalyse (void)
{
    //solo se van a usar las delanteras
    //ojo que pueden estar bloquedas, habría que comprobar tambien velocidad GPS
    //if ( ( ucVelFL == 0 ) && ( ucVelFR == 0 ) && ( ucVelRL == 0 ) && ( ucVelRR == 0 ) )
    if ( ( ucVelFL == 0 ) && ( ucVelFR == 0 ) )
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
    if ( ( uiRPM > RALENTI ) && ( ucNeutra == 1 ) )
    {
        ucTSActive = TRUE; //Sistema de traccion activo
    }
    else
    {
        ucTSActive = FALSE;
    }
}


void SM_R2DAnalyse (void)
{
    if ( ( uiRPM > RALENTI ) && ( ucNeutra == 0 ) )
    {
        ucR2D = TRUE; //Ready to Drive
    }
    else
    {
        ucR2D = FALSE;
    }
}

void SM_BrakesEngagedAnalyse (void)
{
    //REALMENTE ESTAMOS FERNANDO?
    if ( ( ucHDRPRES1 > ucHDRPRES1max )  && ( ucBrakePedalPress == FALSE ) )
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