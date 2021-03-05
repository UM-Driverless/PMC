/* 
 * File:   CAN2Drv.h
 * Author: heqro
 *
 * Created on March 5, 2021, 7:53 PM
 */

#ifndef CAN2DRV_H
#define	CAN2DRV_H

#ifdef	__cplusplus
extern "C" {
#endif

// FUNCIONES COPIADAS Y PEGADAS
extern void ecan2WriteRxAcptFilter(int n, long identifier, unsigned int exide,unsigned int bufPnt,unsigned int maskSel);
extern void ecan2WriteRxAcptMask(int m, long identifierMask, unsigned int mide,unsigned int exide);

extern void ecan2WriteTxMsgBufId(unsigned int buf, long txIdentifier, unsigned int ide, unsigned int remoteTransmit);
extern void ecan2WriteTxMsgBufData(unsigned int buf, unsigned int dataLength, unsigned int data1, unsigned int data2, unsigned int data3, unsigned int data4);

extern void ecan2DisableRXFilter(int n);


#ifdef	__cplusplus
}
#endif

#endif	/* CAN2DRV_H */

