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


// INICIALIZACION DE FUNCIONES //
void MESSAGES_CAN1_Rx(void);
void MESSAGES_CAN2_Rx(void);


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
        case CAN1_ID1:
            
            break;
        case 2:
            
            break;
    }

}


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
        case CAN2_ID1: 
            
            break;
        case 2:
            
            break;
    }
}