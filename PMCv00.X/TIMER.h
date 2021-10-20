/* 
 * File:   TIMER.h
 * Author: 93Urbano
 *
 * Created on 20 de septiembre de 2021, 17:15
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif


/*
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
PROTOTIPOS DE FUNCIONES
-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
*/
void TIMER1Init (void);
void TIMER2Init (void);
void TIMER1Start (void);
void TIMER2Start (void);
void TIMER1Stop (void);
void TIMER2Stop (void);


extern volatile unsigned char Count1s;
extern volatile unsigned char Count1000ms;

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

