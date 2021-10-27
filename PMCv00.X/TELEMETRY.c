/* 
 * File:   TELEMETRY.h
 * Author: DavidJU
 *
 * Created on 20 de octubre de 2021, 10:47
 */



//TELEMETRYSendFrame(PackNumber Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7 Byte8 );
void TELEMETRYSendFrame(unsigned char ucPackNumber, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{
    //AQUI QUIERO QUE CONCATENES TODOS ESTOS CHAR CON UN SOF EOF Y TE CALCULES UN CRC=SUM(SOF-DATA8)
    //SOF PackNumber Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7 Byte8 CRC EOF
    //UART1WriteString(String completo);
}


void TELEMETRYReceiptFrame()
{
    //AQUI QUIERO EL CASO CONTRARIO
    //SOF PackNumber Byte1 Byte2 Byte3 Byte4 Byte5 Byte6 Byte7 Byte8 CRC EOF
    
    /*unsigned char ucPackNumber;
    unsigned char data1;
    unsigned char data2;
    unsigned char data3;
    unsigned char data4;
    unsigned char data5;
    unsigned char data6;
    unsigned char data7;
    unsigned char data8;
    
    ucPackNumber = posicion string pasado por la funcion;
    
    switch (ucPackNumber)
    {
        case PRIMERO:
            ucComando = data1;
            break;
    }*/
    
}
