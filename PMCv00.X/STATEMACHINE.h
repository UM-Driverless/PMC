/* 
 * File:   STATEMACHINE.h
 * Author: 93Urbano
 *
 * Created on December 5, 2021, 12:12 AM
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H

#ifdef	__cplusplus
extern "C" {
#endif

//DEFINES
//AS STATES
#define AS_OFF          0
#define AS_READY        1
#define AS_DRIVING      2
#define AS_EMERGENCY    3
#define AS_FINISHED     4 
    
//EBS
#define EBS_DISACTIVATED    0
#define EBS_ACTIVATED1      1
#define EBS_ACTIVATED2      2
#define EBS_NONEDV          3
#define EBS_ERROR1          4
#define EBS_ERROR2          5
    
//TJ MISSION
#define TJ_MISSION_READY    0
#define TJ_MISSION_RUN      1
#define TJ_MISSION_FINISHED 2   

//ECU defines
#define RALENTI 500
    
//STATEMACHINE
#define MAX_EVENT 255    
#define EVENTS 0
#define STATES 1
    
//EVENTS LIST
#define EV_NONE 0
#define EV_EBS_ACTIVATED 1
    
//.....


//VARIABLES
extern unsigned char ucASState;
extern unsigned char ucEBSactivate;
extern unsigned char ucVehicleStandstill;
extern unsigned char ucVelFL;
extern unsigned char ucVelFR;
extern unsigned char ucVelRL;
extern unsigned char ucVelRR;
extern unsigned char ucMissionSelected;
extern unsigned char ucASMS;
extern unsigned char ucASBCheckUp;
extern unsigned char ucTSActive;
extern unsigned char ucMarcha; 
extern unsigned char ucNeutra;
extern unsigned char ucFlag5sGO;
extern unsigned char ucR2D;
extern unsigned char ucASStatePrev;
extern unsigned char ucBrakeEngaged;
extern unsigned char ucSMError;
extern unsigned char ucEBSState;
extern unsigned char ucSteeringState;
extern unsigned char ucServiceBrakeState;
extern unsigned char ucLapCounter;
extern unsigned char ucConesCountActual;
extern unsigned int uiConesCountAll;
extern unsigned char ColaEventos[MAX_EVENT][2];
extern unsigned char ucIndiceEscritura;
extern unsigned char ucIndiceLectura;
extern unsigned char ucEvent;
extern unsigned char ucState;
extern unsigned char ucTransitedState;

//FUNCIONES
void STATEMACHINE_Init (void);
void STATEMACHINE (void);
void SM_EBSAnalyse (void);
void SM_VehicleStandstillAnalyse (void);
void SM_TractiveSystemAnalyse (void);
void SM_R2DAnalyse (void);
void SM_BrakesEngagedAnalyse (void);

void EVENTPush (unsigned char ucPushEvent, unsigned char ucPushState);
void EVENTPull (void);
void STATEMACHINETransition (void);
void STATEMACHINEAnalysis (void);
void STATEMACHINE_ASOff (void);
void STATEMACHINE_ASReady (void);
void STATEMACHINE_ASDriving (void);
void STATEMACHINE_ASEmergency (void);
void STATEMACHINE_ASFinished (void);

#ifdef	__cplusplus
}
#endif

#endif	/* STATEMACHINE_H */

