/* 
 * File:   AS.h
 * Author: 93Urbano
 *
 * Created on 25 de diciembre de 2021, 13:38
 */

#include "AS.h"
#include "PARAMETERS.h"
#include "MESSAGES.h"
#include "STATEMACHINE.h"

//VARIABLES
unsigned char ucASMissionRequest; 
unsigned char ucASMissionRequestPrev; 
unsigned char ucASMissionTransited;


//FUNCIONES
void ASMisionTransit (void)
{
    switch (ucAMRequest)
    {
        case MANUAL_DRIVING:
            if ( ucASMissionRequest == MANUAL_DRIVING )
            {
                if ( ucASMS == TRUE )
                {
                    //ERROR
                }
                else
                {
                    //TODO ok
                    ucMissionSelected = MANUAL_DRIVING;
                }
            }
            break;
        case ACCELERATION:
            if ( ucASMissionRequest == ACCELERATION )
            {
                ucMissionSelected = ACCELERATION;
            }
            break;
        case SKIDPAD:
            if ( ucASMissionRequest == SKIDPAD )
            {
                ucMissionSelected = SKIDPAD;
            }
            break;
        case AUTOX:
            if ( ucASMissionRequest == AUTOX )
            {
                ucMissionSelected = AUTOX;
            }
            break;
        case TRACKDRIVE:
            if ( ucASMissionRequest == TRACKDRIVE )
            {
                ucMissionSelected = TRACKDRIVE;
            }
            break;
        case EBS_TEST:
            if ( ucASMissionRequest == EBS_TEST )
            {
                ucMissionSelected = EBS_TEST;
            }
            break;
        case INSPECTION:
            if ( ucASMissionRequest == INSPECTION )
            {
                ucMissionSelected = INSPECTION;
            }
            break;
    }
}