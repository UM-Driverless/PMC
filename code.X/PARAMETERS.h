/* 
 * File:   PARAMETERS.h
 * Author: heqro
 *
 * Created on September 3, 2020, 6:21 PM
 */

#ifndef PARAMETERS_H
#define	PARAMETERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FCY 10000000
#define BAUDRATE 9600
    // UART
#define BRG_VAL ((FCY/BAUDRATE)/16)-1 
    // CAN
#define N_CAN 20
#define FTQ = N_CAN * BAUDRATE
#define BRP_VAL		((FCY/(2*FTQ))-1)


#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

