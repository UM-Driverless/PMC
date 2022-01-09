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
        
// get/set CANSTB1 aliases
#define CANSTB1_TRIS                 TRISGbits.TRISG14
#define CANSTB1_LAT                  LATGbits.LATG14
#define CANSTB1_PORT                 PORTGbits.RG14
#define CANSTB1_WPU                  WPUGbits.WPUG14
#define CANSTB1_OD                   ODCONGbits.ODCG14
#define CANSTB1_ANS                  ANSELGbits.ANSELG14
#define CANSTB1_SetHigh()            do { LATGbits.LATG14 = 1; } while(0)
#define CANSTB1_SetLow()             do { LATGbits.LATG14 = 0; } while(0)
#define CANSTB1_Toggle()             do { LATGbits.LATG14 = ~LATGbits.LATG14; } while(0)
#define CANSTB1_GetValue()           PORTGbits.RG14
#define CANSTB1_SetDigitalInput()    do { TRISGbits.TRISG14 = 1; } while(0)
#define CANSTB1_SetDigitalOutput()   do { TRISGbits.TRISG14 = 0; } while(0)
#define CANSTB1_SetPullup()          do { WPUGbits.WPUG14 = 1; } while(0)
#define CANSTB1_ResetPullup()        do { WPUGbits.WPUG14 = 0; } while(0)
#define CANSTB1_SetPushPull()        do { ODCONGbits.ODCG14 = 0; } while(0)
#define CANSTB1_SetOpenDrain()       do { ODCONGbits.ODCG14 = 1; } while(0)
#define CANSTB1_SetAnalogMode()      do { ANSELGbits.ANSELG14 = 1; } while(0)
#define CANSTB1_SetDigitalMode()     do { ANSELGbits.ANSELG14 = 0; } while(0)
    
// get/set CANSTB2 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISG12
#define CANSTB2_LAT                  LATGbits.LATG12
#define CANSTB2_PORT                 PORTGbits.RG12
#define CANSTB2_WPU                  WPUGbits.WPUG12
#define CANSTB2_OD                   ODCONGbits.ODCG12
#define CANSTB2_ANS                  ANSELGbits.ANSELG12
#define CANSTB2_SetHigh()            do { LATGbits.LATG12 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATG12 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATG12 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RG12
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISG12 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISG12 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPUG12 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPUG12 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCG12 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCG12 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELG12 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELG12 = 0; } while(0)
    
 // get/set CTR232 aliases
#define CTR232_TRIS                 TRISBbits.TRISB14
#define CTR232_LAT                  LATBbits.LATB14
#define CTR232_PORT                 PORTBbits.RB14
#define CTR232_WPU                  WPUBbits.WPUB14
#define CTR232_OD                   ODCONBbits.ODCB14
#define CTR232_ANS                  ANSELBbits.ANSELB14
#define CTR232_SetHigh()            do { LATBbits.LATB14 = 1; } while(0)
#define CTR232_SetLow()             do { LATBbits.LATB14 = 0; } while(0)
#define CTR232_Toggle()             do { LATBbits.LATB14 = ~LATBbits.LATB14; } while(0)
#define CTR232_GetValue()           PORTBbits.RB14
#define CTR232_SetDigitalInput()    do { TRISBbits.TRISB14 = 1; } while(0)
#define CTR232_SetDigitalOutput()   do { TRISBbits.TRISB14 = 0; } while(0)
#define CTR232_SetPullup()          do { WPUBbits.WPUB14 = 1; } while(0)
#define CTR232_ResetPullup()        do { WPUBbits.WPUB14 = 0; } while(0)
#define CTR232_SetPushPull()        do { ODCONBbits.ODCB14 = 0; } while(0)
#define CTR232_SetOpenDrain()       do { ODCONBbits.ODCB14 = 1; } while(0)
#define CTR232_SetAnalogMode()      do { ANSELBbits.ANSELB14 = 1; } while(0)
#define CTR232_SetDigitalMode()     do { ANSELBbits.ANSELB14 = 0; } while(0)
    
// get/set CTR485 aliases
#define CTR485_TRIS                 TRISBbits.TRISB15
#define CTR485_LAT                  LATBbits.LATB15
#define CTR485_PORT                 PORTBbits.RB15
#define CTR485_WPU                  WPUBbits.WPUB15
#define CTR485_OD                   ODCONBbits.ODCB15
#define CTR485_ANS                  ANSELBbits.ANSELB15
#define CTR485_SetHigh()            do { LATBbits.LATB15 = 1; } while(0)
#define CTR485_SetLow()             do { LATBbits.LATB15 = 0; } while(0)
#define CTR485_Toggle()             do { LATBbits.LATB15 = ~LATBbits.LATB15; } while(0)
#define CTR485_GetValue()           PORTBbits.RB15
#define CTR485_SetDigitalInput()    do { TRISBbits.TRISB15 = 1; } while(0)
#define CTR485_SetDigitalOutput()   do { TRISBbits.TRISB15 = 0; } while(0)
#define CTR485_SetPullup()          do { WPUBbits.WPUB15 = 1; } while(0)
#define CTR485_ResetPullup()        do { WPUBbits.WPUB15 = 0; } while(0)
#define CTR485_SetPushPull()        do { ODCONBbits.ODCB15 = 0; } while(0)
#define CTR485_SetOpenDrain()       do { ODCONBbits.ODCB15 = 1; } while(0)
#define CTR485_SetAnalogMode()      do { ANSELBbits.ANSELB15 = 1; } while(0)
#define CTR485_SetDigitalMode()     do { ANSELBbits.ANSELB15 = 0; } while(0)
    
    
 // get/set ENT1 aliases
# define ENT1_TRIS                 TRISDbits.TRISD9
# define ENT1_LAT                  LATDbits.LATD9
# define ENT1_PORT                 PORTDbits.RD9
# define ENT1_WPU                  WPUDbits.WPUD9
# define ENT1_OD                   ODCONDbits.ODCD9
# define ENT1_ANS                  ANSELDbits.ANSELD9
# define ENT1_SetHigh()            do { LATDbits.LATD9 = 1; } while(0)
# define ENT1_SetLow()             do { LATDbits.LATD9 = 0; } while(0)
# define ENT1_Toggle()             do { LATDbits.LATD9 = ~LATDbits.LATD9; } while(0)
# define ENT1_GetValue()           PORTDbits.RD9
# define ENT1_SetDigitalInput()    do { TRISDbits.TRISD9 = 1; } while(0)
# define ENT1_SetDigitalOutput()   do { TRISDbits.TRISD9 = 0; } while(0)
# define ENT1_SetPullup()          do { WPUDbits.WPUD9 = 1; } while(0)
# define ENT1_ResetPullup()        do { WPUDbits.WPUD9 = 0; } while(0)
# define ENT1_SetPushPull()        do { ODCONDbits.ODCD9 = 0; } while(0)
# define ENT1_SetOpenDrain()       do { ODCONDbits.ODCD9 = 1; } while(0)
# define ENT1_SetAnalogMode()      do { ANSELDbits.ANSELD9 = 1; } while(0)
# define ENT1_SetDigitalMode()     do { ANSELDbits.ANSELD9 = 0; } while(0)
    
// get/set ENT2 aliases
#define ENT2_TRIS                 TRISDbits.TRISD10
#define ENT2_LAT                  LATDbits.LATD10
#define ENT2_PORT                 PORTDbits.RD10
#define ENT2_WPU                  WPUDbits.WPUD10
#define ENT2_OD                   ODCONDbits.ODCD10
#define ENT2_ANS                  ANSELGbits.ANSELD10
#define ENT2_SetHigh()            do { LATDbits.LATD10 = 1; } while(0)
#define ENT2_SetLow()             do { LATDbits.LATD10 = 0; } while(0)
#define ENT2_Toggle()             do { LATDbits.LATD10 = ~LATDbits.LATD10; } while(0)
#define ENT2_GetValue()           PORTDbits.RD10
#define ENT2_SetDigitalInput()    do { TRISDbits.TRISD10 = 1; } while(0)
#define ENT2_SetDigitalOutput()   do { TRISDbits.TRISD10 = 0; } while(0)
#define ENT2_SetPullup()          do { WPUDbits.WPUD10 = 1; } while(0)
#define ENT2_ResetPullup()        do { WPUDbits.WPUD10 = 0; } while(0)
#define ENT2_SetPushPull()        do { ODCONDbits.ODCD10 = 0; } while(0)
#define ENT2_SetOpenDrain()       do { ODCONDbits.ODCD10 = 1; } while(0)
#define ENT2_SetAnalogMode()      do { ANSELDbits.ANSELD10 = 1; } while(0)
#define ENT2_SetDigitalMode()     do { ANSELDbits.ANSELD10 = 0; } while(0) 
   
// get/set ENT3 aliases
#define ENT3_TRIS                 TRISDbits.TRISD11
#define ENT3_LAT                  LATDbits.LATD11
#define ENT3_PORT                 PORTDbits.RD11
#define ENT3_WPU                  WPUDbits.WPUD11
#define ENT3_OD                   ODCONDbits.ODCD11
#define ENT3_ANS                  ANSELDbits.ANSELD11
#define ENT3_SetHigh()            do { LATDbits.LATD11 = 1; } while(0)
#define ENT3_SetLow()             do { LATDbits.LATD11 = 0; } while(0)
#define ENT3_Toggle()             do { LATDbits.LATD11 = ~LATDbits.LATD11; } while(0)
#define ENT3_GetValue()           PORTDbits.RD11
#define ENT3_SetDigitalInput()    do { TRISDbits.TRISD11 = 1; } while(0)
#define ENT3_SetDigitalOutput()   do { TRISDbits.TRISD11 = 0; } while(0)
#define ENT3_SetPullup()          do { WPUDbits.WPUD11 = 1; } while(0)
#define ENT3_ResetPullup()        do { WPUDbits.WPUD11 = 0; } while(0)
#define ENT3_SetPushPull()        do { ODCONDbits.ODCD11 = 0; } while(0)
#define ENT3_SetOpenDrain()       do { ODCONDbits.ODCD11 = 1; } while(0)
#define ENT3_SetAnalogMode()      do { ANSELDbits.ANSELD11 = 1; } while(0)
#define ENT3_SetDigitalMode()     do { ANSELDbits.ANSELD11 = 0; } while(0) 
    
// get/set ENT4 aliases
#define ENT4_TRIS                 TRISDbits.TRISD0
#define ENT4_LAT                  LATDbits.LATD0
#define ENT4_PORT                 PORTDbits.RD0
#define ENT4_WPU                  WPUDbits.WPUD0
#define ENT4_OD                   ODCONDbits.ODCD0
#define ENT4_ANS                  ANSELDbits.ANSELD0
#define ENT4_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define ENT4_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define ENT4_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define ENT4_GetValue()           PORTDbits.RD0
#define ENT4_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define ENT4_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define ENT4_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define ENT4_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define ENT4_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define ENT4_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define ENT4_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define ENT4_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0) 
    
// get/set ENT5 aliases
#define ENT5_TRIS                 TRISCbits.TRISC13
#define ENT5_LAT                  LATCbits.LATC13
#define ENT5_PORT                 PORTCbits.RC13
#define ENT5_WPU                  WPUCbits.WPUC13
#define ENT5_OD                   ODCONCbits.ODCC13
#define ENT5_ANS                  ANSELCbits.ANSELC13
#define ENT5_SetHigh()            do { LATCbits.LATC13 = 1; } while(0)
#define ENT5_SetLow()             do { LATCbits.LATC13 = 0; } while(0)
#define ENT5_Toggle()             do { LATCbits.LATC13 = ~LATCbits.LATC13; } while(0)
#define ENT5_GetValue()           PORTCbits.RC13
#define ENT5_SetDigitalInput()    do { TRISCbits.TRISC13 = 1; } while(0)
#define ENT5_SetDigitalOutput()   do { TRISCbits.TRISC13 = 0; } while(0)
#define ENT5_SetPullup()          do { WPUCbits.WPUC13 = 1; } while(0)
#define ENT5_ResetPullup()        do { WPUCbits.WPUC13 = 0; } while(0)
#define ENT5_SetPushPull()        do { ODCONCbits.ODCC13 = 0; } while(0)
#define ENT5_SetOpenDrain()       do { ODCONCbits.ODCC13 = 1; } while(0)
#define ENT5_SetAnalogMode()      do { ANSELCbits.ANSELC13 = 1; } while(0)
#define ENT5_SetDigitalMode()     do { ANSELCbits.ANSELC13 = 0; } while(0) 
    
// get/set ENT6 aliases
#define ENT6_TRIS                 TRISCbits.TRISC14
#define ENT6_LAT                  LATCbits.LATC14
#define ENT6_PORT                 PORTCbits.RC14
#define ENT6_WPU                  WPUCbits.WPUC14
#define ENT6_OD                   ODCONCbits.ODCC14
#define ENT6_ANS                  ANSELCbits.ANSELC14
#define ENT6_SetHigh()            do { LATCbits.LATC14 = 1; } while(0)
#define ENT6_SetLow()             do { LATCbits.LATC14 = 0; } while(0)
#define ENT6_Toggle()             do { LATCbits.LATC14 = ~LATCbits.LATC14; } while(0)
#define ENT6_GetValue()           PORTCbits.RC14
#define ENT6_SetDigitalInput()    do { TRISCbits.TRISC14 = 1; } while(0)
#define ENT6_SetDigitalOutput()   do { TRISCbits.TRISC14 = 0; } while(0)
#define ENT6_SetPullup()          do { WPUCbits.WPUC14 = 1; } while(0)
#define ENT6_ResetPullup()        do { WPUCbits.WPUC14 = 0; } while(0)
#define ENT6_SetPushPull()        do { ODCONCbits.ODCC14 = 0; } while(0)
#define ENT6_SetOpenDrain()       do { ODCONCbits.ODCC14 = 1; } while(0)
#define ENT6_SetAnalogMode()      do { ANSELCbits.ANSELC14 = 1; } while(0)
#define ENT6_SetDigitalMode()     do { ANSELCbits.ANSELC14 = 0; } while(0) 
    
// get/set ENT7 aliases
#define ENT7_TRIS                 TRISDbits.TRISD1
#define ENT7_LAT                  LATDbits.LATD1
#define ENT7_PORT                 PORTDbits.RD1
#define ENT7_WPU                  WPUDbits.WPUD1
#define ENT7_OD                   ODCONDbits.ODCD1
#define ENT7_ANS                  ANSELDbits.ANSELD1
#define ENT7_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define ENT7_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define ENT7_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define ENT7_GetValue()           PORTDbits.RD1
#define ENT7_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define ENT7_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define ENT7_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define ENT7_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define ENT7_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define ENT7_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define ENT7_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define ENT7_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0) 
    
// get/set ENT8 aliases
#define ENT8_TRIS                 TRISDbits.TRISD2
#define ENT8_LAT                  LATDbits.LATD2
#define ENT8_PORT                 PORTDbits.RD2
#define ENT8_WPU                  WPUDbits.WPUD2
#define ENT8_OD                   ODCONDbits.ODCD2
#define ENT8_ANS                  ANSELDbits.ANSELD2
#define ENT8_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define ENT8_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define ENT8_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define ENT8_GetValue()           PORTDbits.RD2
#define ENT8_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define ENT8_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define ENT8_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define ENT8_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define ENT8_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define ENT8_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define ENT8_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define ENT8_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0) 
    
// get/set OUT1 aliases
#define OUT1_TRIS                 TRISDbits.TRISD3
#define OUT1_LAT                  LATDbits.LATD3
#define OUT1_PORT                 PORTDbits.RD3
#define OUT1_WPU                  WPUDbits.WPUD3
#define OUT1_OD                   ODCONDbits.ODCD3
#define OUT1_ANS                  ANSELDbits.ANSELD3
#define OUT1_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define OUT1_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define OUT1_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define OUT1_GetValue()           PORTDbits.RD3
#define OUT1_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define OUT1_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define OUT1_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define OUT1_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define OUT1_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define OUT1_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define OUT1_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define OUT1_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0) 
    
    
// get/set OUT2 aliases
#define OUT2_TRIS                 TRISDbits.TRISD4
#define OUT2_LAT                  LATDbits.LATD4
#define OUT2_PORT                 PORTDbits.RD4
#define OUT2_WPU                  WPUDbits.WPUD4
#define OUT2_OD                   ODCONDbits.ODCD4
#define OUT2_ANS                  ANSELDbits.ANSELD4
#define OUT2_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define OUT2_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define OUT2_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define OUT2_GetValue()           PORTDbits.RD4
#define OUT2_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define OUT2_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define OUT2_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define OUT2_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define OUT2_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define OUT2_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define OUT2_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define OUT2_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0) 
    
    
// get/set OUT3 aliases
#define OUT3_TRIS                 TRISDbits.TRISD5
#define OUT3_LAT                  LATDbits.LATD5
#define OUT3_PORT                 PORTDbits.RD5
#define OUT3_WPU                  WPUDbits.WPUD5
#define OUT3_OD                   ODCONDbits.ODCD5
#define OUT3_ANS                  ANSELDbits.ANSELD5
#define OUT3_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define OUT3_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define OUT3_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define OUT3_GetValue()           PORTDbits.RD5
#define OUT3_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define OUT3_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define OUT3_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define OUT3_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define OUT3_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define OUT3_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define OUT3_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define OUT3_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0) 

// get/set OUT3 aliases
#define OUT4_TRIS                 TRISBbits.TRISB8
#define OUT4_LAT                  LATBbits.LATB8
#define OUT4_PORT                 PORTBbits.RB8
#define OUT4_WPU                  WPUBbits.WPUB8
#define OUT4_OD                   ODCONBbits.ODCB8
#define OUT4_ANS                  ANSELBbits.ANSELB8
#define OUT4_SetHigh()            do { LATBbits.LATB8 = 1; } while(0)
#define OUT4_SetLow()             do { LATBbits.LATB8 = 0; } while(0)
#define OUT4_Toggle()             do { LATBbits.LATB8 = ~LATBbits.LATB8; } while(0)
#define OUT4_GetValue()           PORTBbits.RB8
#define OUT4_SetDigitalInput()    do { TRISBbits.TRISB8 = 1; } while(0)
#define OUT4_SetDigitalOutput()   do { TRISBbits.TRISB8 = 0; } while(0)
#define OUT4_SetPullup()          do { WPUBbits.WPUB8 = 1; } while(0)
#define OUT4_ResetPullup()        do { WPUBbits.WPUB8 = 0; } while(0)
#define OUT4_SetPushPull()        do { ODCONBbits.ODCB8 = 0; } while(0)
#define OUT4_SetOpenDrain()       do { ODCONBbits.ODCB8 = 1; } while(0)
#define OUT4_SetAnalogMode()      do { ANSELBbits.ANSELB8 = 1; } while(0)
#define OUT4_SetDigitalMode()     do { ANSELBbits.ANSELB8 = 0; } while(0) 
    
    
// get/set OUT3 aliases
#define VTEMP_TRIS                 TRISBbits.TRISB9
#define VTEMP_LAT                  LATBbits.LATB9
#define VTEMP_PORT                 PORTBbits.RB9
#define VTEMP_WPU                  WPUBbits.WPUB9
#define VTEMP_OD                   ODCONBbits.ODCB9
#define VTEMP_ANS                  ANSELBbits.ANSELB9
#define VTEMP_SetHigh()            do { LATBbits.LATB9 = 1; } while(0)
#define VTEMP_SetLow()             do { LATBbits.LATB9 = 0; } while(0)
#define VTEMP_Toggle()             do { LATBbits.LATB9 = ~LATBbits.LATB9; } while(0)
#define VTEMP_GetValue()           PORTBbits.RB9
#define VTEMP_SetDigitalInput()    do { TRISBbits.TRISB9 = 1; } while(0)
#define VTEMP_SetDigitalOutput()   do { TRISBbits.TRISB9 = 0; } while(0)
#define VTEMP_SetPullup()          do { WPUBbits.WPUB9 = 1; } while(0)
#define VTEMP_ResetPullup()        do { WPUBbits.WPUB9 = 0; } while(0)
#define VTEMP_SetPushPull()        do { ODCONBbits.ODCB9 = 0; } while(0)
#define VTEMP_SetOpenDrain()       do { ODCONBbits.ODCB9 = 1; } while(0)
#define VTEMP_SetAnalogMode()      do { ANSELBbits.ANSELB9 = 1; } while(0)
#define VTEMP_SetDigitalMode()     do { ANSELBbits.ANSELB9 = 0; } while(0) 
    
//variables
extern volatile unsigned char ucEntrada1;
    
    
    
//INICIALIZACION DE GPIO
void GPIO_init (void);
void GPIO_Entradas (void);



#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

