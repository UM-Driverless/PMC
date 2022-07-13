/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on 13 de septiembre de 2021, 19:08
 */

#include "xc.h"
#include "GPIO.h"
#include "STATEMACHINE.h"


//variables
volatile unsigned char ucEntrada1;

//INICIALIZACION DE GPIO

void GPIO_init (void)
{
    //LEDS
    LED1_SetDigitalOutput();
    LED2_SetDigitalOutput();
    LED3_SetDigitalOutput();
    
    //ENTRADAS
    ENT1_SetDigitalInput();
    ENT2_SetDigitalInput();
    ENT3_SetDigitalInput();
    ENT4_SetDigitalInput();
    ENT5_SetDigitalInput();
    ENT6_SetDigitalInput();
    ENT7_SetDigitalInput();
    ENT8_SetDigitalInput();
    
    //SALIDAS
    OUT1_SetDigitalOutput();
    OUT2_SetDigitalOutput();
    OUT3_SetDigitalOutput();
    OUT4_SetDigitalOutput();
    
}

//ejecutar cada 500ms
void GPIO_Entradas (void)
{
    ucASMS = ENT1_GetValue();
    ucNeutra = !ENT2_GetValue();
    /*ucEntrada3 = ENT3_GetValue();
    ucEntrada4 = ENT4_GetValue();
    ucEntrada5 = ENT5_GetValue();
    ucEntrada6 = ENT6_GetValue();
    ucEntrada7 = ENT7_GetValue();
    ucEntrada8 = ENT8_GetValue();*/
}