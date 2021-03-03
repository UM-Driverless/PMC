/* 
 * File:   CAN1Drv.h
 * Author: heqro
 *
 * Created on March 3, 2021, 12:27 PM
 */

#ifndef CAN1DRV_H
#define	CAN1DRV_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
// función para escribir el identificador en el número de buffer indicado por n_buffer
extern void CAN1Drv_Tx_Msg_Id(unsigned int n_buffer, long tx_identificador);
// escribir los datos en el buffer indicado por n_buffer
extern void CAN1Drv_Tx_Msg_Data(unsigned int n_buffer, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

#endif	/* CAN1DRV_H */

