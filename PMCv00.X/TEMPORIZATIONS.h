/* 
 * File:   TEMPORIZATIONS.h
 * Author: 93Urbano
 *
 * Created on December 5, 2021, 12:23 PM
 */

#ifndef TEMPORIZATIONS_H
#define	TEMPORIZATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

//DEFINES
#define t500ms 5       
#define t1s    10        
#define t5s    50       
#define t10s   100       
#define t1min  600 
    
//VARIABLES
extern unsigned char ucCount500ms;
extern unsigned char ucCount1s;
extern unsigned char ucCount5s;
extern unsigned char ucCount10s;
extern unsigned int uiCount1min;
extern unsigned int uiFastTick;


//FUNCIONES
void TEMPORIZATIONInit (void);
void TEMPORIZATION_10ms (void);
void TEMPORIZATION_100ms (void);
void TEMPORIZATION_500ms (void);
void TEMPORIZATION_1s (void);
void TEMPORIZATION_5s (void);
void TEMPORIZATION_10s (void);
void TEMPORIZATION_1mins (void);
void delay_10ms (unsigned char num);

#ifdef	__cplusplus
}
#endif

#endif	/* TEMPORIZATIONS_H */

