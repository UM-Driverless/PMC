/* 
 * File:   PARAMETERS.h
 * Author: 93Urbano
 *
 * Created on September 3, 2020, 6:21 PM
 */

#include "PARAMETERS.h"



/*--------------------------------------------------
 * 
 *          ////// PARAMETROS //////////
 * 
  --------------------------------------------------*/
const unsigned char ucTipoMensajeCAN1 = CAN_EXTENDED; // standard CAN1 11bits
const unsigned char ucTipoMensajeCAN2 = CAN_EXTENDED; // standard CAN2 11bits
//LIMITES ASB
unsigned char ucHDRPRES1max;
unsigned char ucHDRPRES2max;
unsigned char ucNPRES1max;
unsigned char ucNPRES2max;
unsigned char ucNPRES3max;
unsigned char ucNPRES4max;
unsigned char ucNPRES3min;
unsigned char ucNPRES4min;


//FUNCIONES
void PARAMETERS_Init(void)
{
    //Consideramos estas presiones como frenos actuados
    ucHDRPRES1max = 200;
    ucHDRPRES2max = 200;
    ucNPRES1max = 200;
    ucNPRES2max = 200;
    ucNPRES3max = 200;
    ucNPRES4max = 200;
    ucNPRES3min = 10; //atmosferica
    ucNPRES4min = 10; //atmosferica
}