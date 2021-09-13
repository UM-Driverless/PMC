/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on 13 de septiembre de 2021, 19:08
 */

#include "xc.h"
#include "GPIO.h"

//INICIALIZACION DE GPIO

void GPIO_init (void)
{
    LED1_SetDigitalOutput();
    LED2_SetDigitalOutput();
    LED3_SetDigitalOutput();
    
}