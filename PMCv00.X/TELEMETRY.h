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

void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
void TELEMETRYReceiptFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);

#ifdef	__cplusplus
}
#endif

#endif	/* TELEMETRY_H */

