/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on 13 de septiembre de 2021, 19:08
 */

#include "xc.h"
#include "GPIO.h"


//variables
volatile unsigned char ucEntrada1;

//INICIALIZACION DE GPIO

void GPIO_init (void)
{
    LED1_SetDigitalOutput();
    LED2_SetDigitalOutput();
    LED3_SetDigitalOutput();
    
    //ENT1_SetDigitalInput();
    
    
}

void GPIO_Entradas (void)
{
    //ucEntrada1 = ENT1_GetValue();
    //ucEntr...
}