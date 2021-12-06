    /* 
 * File:   MESSAGES.h
 * Author: 93Urbano
 *
 * Created on 19 de agosto de 2021, 22:37
 */

#ifndef MESSAGES_H
#define	MESSAGES_H

//DEFINICIONES
#define DataLength_0        			0
#define DataLength_1        			1
#define DataLength_2        			2
#define DataLength_3        			3
#define DataLength_4        			4
#define DataLength_5        			5
#define DataLength_6        			6
#define DataLength_7        			7
#define DataLength_8        			8


//CAN 1 MSG
#define DRIVING_DYNAMICS_1 0x500
#define DRIVING_DYNAMICS_2 0x501
#define SYSTEM_STATUS 0x502
//Autonomous system msgs
#define AS1 0x511
#define AS2 0x512
#define AS3 0x513
#define AS4 0x514
#define AS5 0x515
//Res msgs
#define NMT_NODE_CONTROL 0x000
#define SYNC 0x080
#define TIME_STAMP 0x100
#define LSS_T 0x7E4
#define LSS_R 0x7E5
#define DV_DRIVING_DYNAMICS_1       0x500
#define DV_DRIVING_DYNAMICS_2       0x501
#define DV_SYSTEM_STATUS            0x502
#define TRAJECTORY_ACT              0x320
#define TRAJECTORY_GPS              0x321
#define TRAJECTORY_IMU              0x322
#define TRAJECTORY_STATE            0x323
//ASB MSG
#define ASB_ANALOG                  0x360
#define ASB_SIGNALS                 0x361
#define ASB_STATE                   0x362
//SEN MSG 
#define SENFL_SIG       0x301
#define SENFR_SIG       0x304
#define SENRL_SIG       0x307
#define SENRR_SIG       0x30A
//RES MSG
#define RES_PDOTR       0x191

//CAN DE ECU
#define ECUID1 0x360
#define ECUID2 0x361
#define ECUID3 0x362
#define ECUID4 0x363
#define ECUID5 0x368
#define ECUID6 0x369
#define ECUID7 0x36A
#define ECUID8 0x36B
#define ECUID9 0x36C
#define ECUID10 0x36D
#define ECUID11 0x36E
#define ECUID12 0x36F
#define ECUID13 0x370
#define ECUID14 0x371
#define ECUID15 0x372
#define ECUID16 0x373
#define ECUID17 0x374
#define ECUID18 0x375
#define ECUID19 0x3E0
#define ECUID20 0x3E1
#define ECUID21 0x3E2
#define ECUID22 0x3E3
#define ECUID23 0x3E4

#ifdef	__cplusplus
extern "C" {
#endif

// INICIALIZACION DE VARIABLES //
extern volatile unsigned long ulCAN1RXID;
extern volatile unsigned char ucCAN1RXDataLenght;
extern volatile unsigned char ucCAN1RXData0;
extern volatile unsigned char ucCAN1RXData1;
extern volatile unsigned char ucCAN1RXData2;
extern volatile unsigned char ucCAN1RXData3;
extern volatile unsigned char ucCAN1RXData4;
extern volatile unsigned char ucCAN1RXData5;
extern volatile unsigned char ucCAN1RXData6;
extern volatile unsigned char ucCAN1RXData7;

extern volatile unsigned long ulCAN2RXID;
extern volatile unsigned char ucCAN2RXDataLenght;
extern volatile unsigned char ucCAN2RXData0;
extern volatile unsigned char ucCAN2RXData1;
extern volatile unsigned char ucCAN2RXData2;
extern volatile unsigned char ucCAN2RXData3;
extern volatile unsigned char ucCAN2RXData4;
extern volatile unsigned char ucCAN2RXData5;
extern volatile unsigned char ucCAN2RXData6;
extern volatile unsigned char ucCAN2RXData7;


//ASB
extern unsigned char ucHDRPRES1;
extern unsigned char ucHDRPRES2;
extern unsigned char ucNPRES1;
extern unsigned char ucNPRES2;
extern unsigned char ucNPRES3;
extern unsigned char ucNPRES4;
extern unsigned char ucA1;
extern unsigned char ucA2;
extern unsigned char ucBrakePedalPress;

//TRAJECTORY
extern unsigned char ucMissionState;

//RES
extern unsigned char ucGOSignal;

//ECU
extern unsigned int uiRPM;

// INICIALIZACION DE FUNCIONES //
extern void MESSAGES_CAN1_Rx(void);
extern void MESSAGES_CAN2_Rx(void);


// DECLARACION DE CONSTANTES DE ID //
#define ID1 0x0FFF


#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGES_H */

