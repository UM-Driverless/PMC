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
        // Estructura de datos del mensaje CAN
typedef struct {
    // campo de datos representado por 8 bytes
    unsigned char datos[8];
    // identificador que consta de 11 bits
    unsigned long identificador;
    // buffer que se está utilizando para guardar el mensaje
    
    /* Dado que sabemos que utilizamos formato estándar, podemos dejar
     de considerar todas las comprobaciones relativas a si el mensaje tiene
     * un formato de datos u otro.
     * 
     * Dejo las comprobaciones aquí abajo, por si acaso: */
    
    // identifica si es un mensaje en formato estándar o extendido
    // unsigned char estandar_o_extendido;
    
    // identificador de si contamos con mensaje de datos o de RTR
    // Como contamos con un formato de datos básico, esto siempre está a cero
    // unsigned char RTR_o_datos;
    
}msgCAN;

#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

