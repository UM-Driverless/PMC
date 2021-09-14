/* 
 * File:   GPIO.h
 * Author: DavidJU
 *
 * Created on 13 de septiembre de 2021, 19:08
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

//DECLARACION DE INCLUDES
#include "xc.h"

// get/set LED1 aliases
#define LED1_TRIS                 TRISDbits.TRISD6
#define LED1_LAT                  LATDbits.LATD6
#define LED1_PORT                 PORTDbits.RD6
#define LED1_WPU                  WPUDbits.WPUD6
#define LED1_OD                   ODCONDbits.ODCD6
#define LED1_ANS                  ANSELDbits.ANSELD6
#define LED1_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD6= 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LED1_GetValue()           PORTDbits.RD6
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define LED1_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)
    
// get/set LED2 aliases
#define LED2_TRIS                 TRISDbits.TRISD7
#define LED2_LAT                  LATDbits.LATD7
#define LED2_PORT                 PORTDbits.RD7
#define LED2_WPU                  WPUDbits.WPUD7
#define LED2_OD                   ODCONDbits.ODCD7
#define LED2_ANS                  ANSELDbits.ANSELD7
#define LED2_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define LED2_GetValue()           PORTDbits.RD7
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define LED2_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISFbits.TRISF6
#define LED3_LAT                  LATFbits.LATF6
#define LED3_PORT                 PORTFbits.RF6
#define LED3_WPU                  WPUFbits.WPUF6
#define LED3_OD                   ODCONFbits.ODCF6
#define LED3_ANS                  ANSELFbits.ANSELF6
#define LED3_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define LED3_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define LED3_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define LED3_GetValue()           PORTFbits.RF6
#define LED3_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define LED3_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)
    
    
    
// get/set ENT1 aliases
#define ENT1_TRIS                 TRISDbits.TRISD9
#define ENT1_LAT                  LATDbits.LATD9
#define ENT1_PORT                 PORTDbits.RD9
#define ENT1_WPU                  WPUDbits.WPUD9
#define ENT1_OD                   ODCONDbits.ODCD9
#define ENT1_ANS                  ANSELDbits.ANSELD9
#define ENT1_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define ENT1_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define ENT1_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define ENT1_GetValue()           PORTFbits.RF6
#define ENT1_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define ENT1_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define ENT1_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define ENT1_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define ENT1_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define ENT1_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define ENT1_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define ENT1_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)
    
//INICIALIZACION DE GPIO
void GPIO_init (void);




#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

