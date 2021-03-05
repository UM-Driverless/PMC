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
#define FTQ         N_CAN*BAUDRATE
#define BRP_VAL		((FCY/(2*FTQ))-1)

// Estructura de datos del mensaje CAN
typedef struct {
    // campo de datos representado por 8 bytes
    unsigned char uc_datos[8];
    // identificador que consta de 11 bits
    unsigned long ul_identificador;
    // buffer que se está utilizando para guardar el mensaje
    unsigned char uc_buffer_num;
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

// COPIADO Y PEGADO

#define CAN_MSG_DATA	0x01 // message type 
#define CAN_MSG_RTR		0x02 // data or RTR
#define CAN_FRAME_EXT	0x03 // Frame type
#define CAN_FRAME_STD	0x04 // extended or standard

/* message structure in RAM */
typedef struct{
	/* keep track of the buffer status */
	unsigned char buffer_status;
	/* RTR message or data message */
	unsigned char message_type;
	/* frame type extended or standard */
	unsigned char frame_type;
	/* buffer being used to reference the message */
	unsigned char buffer;
	/* 29 bit id max of 0x1FFF FFFF 
	*  11 bit id max of 0x7FF */
	unsigned long id; 
	/* message data */
	unsigned char data[8];	
	/* received message data length */
	unsigned char data_length;
}mID;


#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

