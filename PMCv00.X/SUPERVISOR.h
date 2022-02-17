/* 
 * File:   SUPERVISOR.h
 * Author: DavidJU
 *
 * Created on February 17, 2022, 11:29 PM
 */

#ifndef SUPERVISOR_H
#define	SUPERVISOR_H

#ifdef	__cplusplus
extern "C" {
#endif

//SYSTEMS
#define PMC     0
#define XAVIER  1
#define ASB     2
#define ETC     3
#define SENFR   4
#define SENFL   5
#define SENRR   6
#define SENRL   7
#define ASSIC   8
#define ASSIR   9
#define ASSIL   10
#define STEER   11
#define SHIFTER 12
#define STEER_W 13
#define AMI     14    


//FUNCIONES
void SUPERVISORbySystems (unsigned char ucSystem);


#ifdef	__cplusplus
}
#endif

#endif	/* SUPERVISOR_H */

