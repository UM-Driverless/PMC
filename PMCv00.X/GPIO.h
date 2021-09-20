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
#define ENT1_SetHigh()            do { LATFbits.LATD9= 1; } while(0)
#define ENT1_SetLow()             do { LATFbits.LATD9 = 0; } while(0)
#define ENT1_Toggle()             do { LATFbits.LATD9 = ~LATFbits.LATF6; } while(0)
#define ENT1_GetValue()           PORTFbits.RD9
#define ENT1_SetDigitalInput()    do { TRISFbits.TRISD9 = 1; } while(0)
#define ENT1_SetDigitalOutput()   do { TRISFbits.TRISF6D9 = 0; } while(0)
#define ENT1_SetPullup()          do { WPUFbits.WPUD9 = 1; } while(0)
#define ENT1_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define ENT1_SetPushPull()        do { ODCONFbits.ODCD9 = 0; } while(0)
#define ENT1_SetOpenDrain()       do { ODCONFbits.ODCD9 = 1; } while(0)
#define ENT1_SetAnalogMode()      do { ANSELFbits.ANSELD9 = 1; } while(0)
#define ENT1_SetDigitalMode()     do { ANSELFbits.ANSELD9 = 0; } while(0)
    
// get/set CANSTB1 aliases
#define CANSTB1_TRIS                 TRISGbits.TRISG14
#define CANSTB1_LAT                  LATGbits.LATG14
#define CANSTB1_PORT                 PORTGbits.RG14
#define CANSTB1_WPU                  WPUGbits.WPUG14
#define CANSTB1_OD                   ODCONGbits.ODCG14
#define CANSTB1_ANS                  ANSELGbits.ANSELG14
#define CANSTB1_SetHigh()            do { LATGbits.LATG14 = 1; } while(0)
#define CANSTB1_SetLow()             do { LATGbits.LATG14 = 0; } while(0)
#define CANSTB1_Toggle()             do { LATGbits.LATG14 = ~LATFbits.LATG14; } while(0)
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
#define CANSTB2_TRIS                 TRISGbits.TRISRB14
#define CANSTB2_LAT                  LATGbits.LATRB14
#define CANSTB2_PORT                 PORTGbits.RRB14
#define CANSTB2_WPU                  WPUGbits.WPURB14
#define CANSTB2_OD                   ODCONGbits.ODCRB14
#define CANSTB2_ANS                  ANSELGbits.ANSELRB14
#define CANSTB2_SetHigh()            do { LATGbits.LATRB14 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRB14 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRB14 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRB14
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRB14 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRB14 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURB14 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURB14 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRB14 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRB14 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRB14 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRB14 = 0; } while(0)
    
// get/set CTR485 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRB15
#define CANSTB2_LAT                  LATGbits.LATRB15
#define CANSTB2_PORT                 PORTGbits.RRB15
#define CANSTB2_WPU                  WPUGbits.WPURB15
#define CANSTB2_OD                   ODCONGbits.ODCRB15
#define CANSTB2_ANS                  ANSELGbits.ANSELRB15
#define CANSTB2_SetHigh()            do { LATGbits.LATRB15 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRB15 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRB15 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRB15
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRB15 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRB15 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURB15 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURB15 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRB15 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRB15 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRB15 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRB15 = 0; } while(0)
    
    
 // get/set ENT1 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD9
#define CANSTB2_LAT                  LATGbits.LATRD9
#define CANSTB2_PORT                 PORTGbits.RRD9
#define CANSTB2_WPU                  WPUGbits.WPURD9
#define CANSTB2_OD                   ODCONGbits.ODCRD9
#define CANSTB2_ANS                  ANSELGbits.ANSELRD9
#define CANSTB2_SetHigh()            do { LATGbits.LATRD9 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD9 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD9 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD9
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD9 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD9 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD9 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD9 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD9 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD9 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD9 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD9 = 0; } while(0) 
    
// get/set ENT2 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD10
#define CANSTB2_LAT                  LATGbits.LATRD10
#define CANSTB2_PORT                 PORTGbits.RRD10
#define CANSTB2_WPU                  WPUGbits.WPURD10
#define CANSTB2_OD                   ODCONGbits.ODCRD10
#define CANSTB2_ANS                  ANSELGbits.ANSELRD10
#define CANSTB2_SetHigh()            do { LATGbits.LATRD10 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD10 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD10 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD10
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD10 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD10 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD10 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD10 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD10 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD10 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD10 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD10 = 0; } while(0) 
   
// get/set ENT3 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD11
#define CANSTB2_LAT                  LATGbits.LATRD11
#define CANSTB2_PORT                 PORTGbits.RRD11
#define CANSTB2_WPU                  WPUGbits.WPURD11
#define CANSTB2_OD                   ODCONGbits.ODCRD11
#define CANSTB2_ANS                  ANSELGbits.ANSELRD11
#define CANSTB2_SetHigh()            do { LATGbits.LATRD11 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD11 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD11 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD11
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD11 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD11 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD11 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD11 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD11 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD11 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD11 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD11 = 0; } while(0) 
    
// get/set ENT4 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD0
#define CANSTB2_LAT                  LATGbits.LATRD0
#define CANSTB2_PORT                 PORTGbits.RRD0
#define CANSTB2_WPU                  WPUGbits.WPURD0
#define CANSTB2_OD                   ODCONGbits.ODCRD0
#define CANSTB2_ANS                  ANSELGbits.ANSELRD0
#define CANSTB2_SetHigh()            do { LATGbits.LATRD0 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD0 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD0 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD0
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD0 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD0 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD0 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD0 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD0 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD0 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD0 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD0 = 0; } while(0) 
    
// get/set ENT5 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRC13
#define CANSTB2_LAT                  LATGbits.LATRC13
#define CANSTB2_PORT                 PORTGbits.RRC13
#define CANSTB2_WPU                  WPUGbits.WPURC13
#define CANSTB2_OD                   ODCONGbits.ODCRC13
#define CANSTB2_ANS                  ANSELGbits.ANSELRC13
#define CANSTB2_SetHigh()            do { LATGbits.LATRC13 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRC13 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRC13 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRC13
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRC13 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRC13 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURC13 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURC13 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRC13 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRC13 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRC13 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRC13 = 0; } while(0) 
    
// get/set ENT6 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRC14
#define CANSTB2_LAT                  LATGbits.LATRC14
#define CANSTB2_PORT                 PORTGbits.RRC14
#define CANSTB2_WPU                  WPUGbits.WPURC14
#define CANSTB2_OD                   ODCONGbits.ODCRC14
#define CANSTB2_ANS                  ANSELGbits.ANSELRC14
#define CANSTB2_SetHigh()            do { LATGbits.LATRC14 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRC14 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRC14 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRC14
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRC14 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRC14 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURC14 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURC14 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRC14 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRC14 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRC14 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRC14 = 0; } while(0) 
    
// get/set OUT1 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD3
#define CANSTB2_LAT                  LATGbits.LATRD3
#define CANSTB2_PORT                 PORTGbits.RRD3
#define CANSTB2_WPU                  WPUGbits.WPURD3
#define CANSTB2_OD                   ODCONGbits.ODCRD3
#define CANSTB2_ANS                  ANSELGbits.ANSELRD3
#define CANSTB2_SetHigh()            do { LATGbits.LATRD3 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD3 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD3 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD3
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD3 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD3 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD3 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD3 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD3 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD3 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD3 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD3 = 0; } while(0) 
    
    
// get/set OUT2 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD4
#define CANSTB2_LAT                  LATGbits.LATRD4
#define CANSTB2_PORT                 PORTGbits.RRD4
#define CANSTB2_WPU                  WPUGbits.WPURD4
#define CANSTB2_OD                   ODCONGbits.ODCRD4
#define CANSTB2_ANS                  ANSELGbits.ANSELRD4
#define CANSTB2_SetHigh()            do { LATGbits.LATRD4 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD4 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD4 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD4
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD4 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD4 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD4 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD4 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD4 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD4 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD4 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD4 = 0; } while(0) 
    
    
// get/set OUT3 aliases
#define CANSTB2_TRIS                 TRISGbits.TRISRD5
#define CANSTB2_LAT                  LATGbits.LATRD5
#define CANSTB2_PORT                 PORTGbits.RRD5
#define CANSTB2_WPU                  WPUGbits.WPURD5
#define CANSTB2_OD                   ODCONGbits.ODCRD5
#define CANSTB2_ANS                  ANSELGbits.ANSELRD5
#define CANSTB2_SetHigh()            do { LATGbits.LATRD5 = 1; } while(0)
#define CANSTB2_SetLow()             do { LATGbits.LATRD5 = 0; } while(0)
#define CANSTB2_Toggle()             do { LATGbits.LATRD5 = ~LATGbits.LATG12; } while(0)
#define CANSTB2_GetValue()           PORTGbits.RRD5
#define CANSTB2_SetDigitalInput()    do { TRISGbits.TRISRD5 = 1; } while(0)
#define CANSTB2_SetDigitalOutput()   do { TRISGbits.TRISRD5 = 0; } while(0)
#define CANSTB2_SetPullup()          do { WPUGbits.WPURD5 = 1; } while(0)
#define CANSTB2_ResetPullup()        do { WPUGbits.WPURD5 = 0; } while(0)
#define CANSTB2_SetPushPull()        do { ODCONGbits.ODCRD5 = 0; } while(0)
#define CANSTB2_SetOpenDrain()       do { ODCONGbits.ODCRD5 = 1; } while(0)
#define CANSTB2_SetAnalogMode()      do { ANSELGbits.ANSELRD5 = 1; } while(0)
#define CANSTB2_SetDigitalMode()     do { ANSELGbits.ANSELRD5 = 0; } while(0) 
//INICIALIZACION DE GPIO
void GPIO_init (void);




#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

