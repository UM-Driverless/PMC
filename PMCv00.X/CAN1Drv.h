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


// FUNCIONES COPIADAS Y PEGADAS
extern void ecan1WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel);
extern void ecan1WriteRxAcptMask(int m, long identifierMask, unsigned int mide,unsigned int exide);

extern void ecan1WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
extern void ecan1WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

extern void ecan1DisableRXFilter(int n);


#endif	/* CAN1DRV_H */

