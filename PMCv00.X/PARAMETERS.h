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

// OSCILATOR FREQUENCY //
//#define FCY 10000000 //PMC 
#define FCY 80000000 //URM pruebas
    
// BAUDRATES //
//#define BAUDRATE 1200
//#define BAUDRATE 2400
//#define BAUDRATE 4800
//#define BAUDRATE 9600
//#define BAUDRATE 19200
//#define BAUDRATE 38400
//#define BAUDRATE 57600
#define BAUDRATE 115200

// UART //
#define BRG_VAL ((FCY/BAUDRATE)/16)-1 
    
// CAN //
#define N_CAN 20
#define FTQ = N_CAN * BAUDRATE
#define BRP_VAL		((FCY/(2*FTQ))-1)

// Estructura de datos del mensaje CAN
typedef struct {
    // campo de datos representado por 8 bytes
    unsigned char uc_datos[8];
    // identificador que consta de 11 bits
    unsigned long ul_identificador;
    // buffer que se est� utilizando para guardar el mensaje
    unsigned char uc_buffer_num;
    /* Dado que sabemos que utilizamos formato est�ndar, podemos dejar
     de considerar todas las comprobaciones relativas a si el mensaje tiene
     * un formato de datos u otro.
     * 
     * Dejo las comprobaciones aqu� abajo, por si acaso: */
    
    // identifica si es un mensaje en formato est�ndar o extendido
    // unsigned char estandar_o_extendido;
    
    // identificador de si contamos con mensaje de datos o de RTR
    // Como contamos con un formato de datos b�sico, esto siempre est� a cero
    // unsigned char RTR_o_datos;
}msgCAN;

#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

