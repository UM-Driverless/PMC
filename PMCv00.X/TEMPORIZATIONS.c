/* 
 * File:   TEMPORIZATIONS.h
 * Author: 93Urbano
 *
 * Created on December 5, 2021, 12:23 PM
 */

#include "TEMPORIZATIONS.h"
#include "STATEMACHINE.h"
#include "PARAMETERS.h"


//VARIABLES
unsigned char ucCount500ms;
unsigned char ucCount1s;
unsigned char ucCount5s;
unsigned char ucCount10s;
unsigned int uiCount1min;


//FUNCIONES
void TEMPORIZATION_10ms (void)
{

}

void TEMPORIZATION_100ms (void)
{
    
}

void TEMPORIZATION_500ms (void)
{
    
}

void TEMPORIZATION_1s (void)
{
    
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

}

void TEMPORIZATION_1mins (void)
{
    
}
