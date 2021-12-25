/* 
 * File:   AS.h
 * Author: 93Urbano
 *
 * Created on 25 de diciembre de 2021, 13:38
 */

#ifndef AS_H
#define	AS_H

#ifdef	__cplusplus
extern "C" {
#endif


//MISSIONS
#define MANUAL_DRIVING      0    
#define ACCELERATION        1    
#define SKIDPAD             2       
#define AUTOX               3    
#define TRACKDRIVE          4    
#define EBS_TEST            5    
#define INSPECTION          6   
    
    
//VARIABLES
extern unsigned char ucASMissionRequest; 
extern unsigned char ucASMissionRequestPrev;
extern unsigned char ucASMissionTransited;
   
    
//FUNCIONES
extern void ASMisionTransit (void);
    


#ifdef	__cplusplus
}
#endif

#endif	/* AS_H */

