/* 
 * File:   TELEMETRY.h
 * Author: DavidJU
 *
 * Created on 20 de octubre de 2021, 10:47
 */

#ifndef TELEMETRY_H
#define	TELEMETRY_H

#ifdef	__cplusplus
extern "C" {
#endif
      
//DEFINICIONES
#define VARPACK1    1
#define VARPACK2    2
#define VARPACK3    3
#define VARPACK4    4
#define VARPACK5    5
#define VARPACK6    6
#define VARPACK7    7
#define VARPACK8    8
#define VARPACK9    9
#define VARPACK10    10
    
    
//VARIABLES
extern unsigned char telemetryString[12];
    
//FUNCIONES
void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
void TELEMETRYReceiptFrame(unsigned char s[]);
void TELEMETRYSendVARPACK1 (void);
void TELEMETRYSendVARPACK2 (void);
void TELEMETRYSendVARPACK3 (void);

#ifdef	__cplusplus
}
#endif

#endif	/* TELEMETRY_H */

