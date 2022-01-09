/* 
 * File:   ADC.h
 * Author: 93Urbano
 *
 * Created on 8 de enero de 2022, 23:17
 */

#include "xc.h"
#include "ADC.h"

//FUNCIONES
void ADCInit (void)
{
    AD1CON1bits.FORM = 3; // Data Output Format: Signed Fraction (Q15 format)
    AD1CON1bits.SSRC = 7; // Internal Counter (SAMC) ends sampling and starts conversion
    AD1CON1bits.ASAM = 1; // ADC Sample Control: Sampling begins immediately after
     // conversion
    AD1CON1bits.AD12B = 0; // 10-bit ADC operation
    //AD1CON2bits.SIMSAM = 0; // Sequential sampling of channels
    AD1CON2bits.CHPS = 1; // Converts channels CH0/CH1
    AD1CON3bits.ADRC = 0; // ADC Clock is derived from Systems Clock
    AD1CON3bits.SAMC = 0; // Auto Sample Time = 0 * TAD
    AD1CON3bits.ADCS = 2; // ADC Conversion Clock TAD = TCY * (ADCS + 1) = (1/40M) * 3 =
     // 75 ns (13.3 MHz)
     // ADC Conversion Time for 10-bit Tconv = 12 * TAD = 900 ns (1.1 MHz)
    AD1CON1bits.ADDMABM = 0; // DMA buffers are built in conversion order mode
    AD1CON2bits.SMPI = 0; // SMPI must be 0
    //AD1CHS0/AD1CHS123: Analog-to-Digital Input Select Register
    AD1CHS0bits.CH0SA = 0; // MUXA +ve input selection (AIN0) for CH0
    AD1CHS0bits.CH0NA = 0; // MUXA -ve input selection (VREF-) for CH0
    AD1CHS123bits.CH123SA = 0; // MUXA +ve input selection (AIN0) for CH1
    AD1CHS123bits.CH123NA = 0; // MUXA -ve input selection (VREF-) for CH1
    //AD1PCFGH/AD1PCFGL: Port Configuration Register
    AD1PCFGL = 0xFFFF;
    AD1PCFGH = 0xFFFF;
    AD1PCFGLbits.PCFG9 = 0; // AN9 as Analog Input
    IFS0bits.AD1IF = 0; // Clear the Analog-to-Digital interrupt flag bit
    IEC0bits.AD1IE = 0; // Do Not Enable Analog-to-Digital interrupt
    AD1CON1bits.ADON = 1; // Turn on the ADC
}

void ADCRead (unsigned char ucAnalogChannel)
{
    unsigned int value;
    
    AD1CON1bits.SAMP = 0; // Start converting
    while (!AD1CON1bits.DONE) // Conversion done?
    AD1CON1bits.DONE = 0; // Clear conversion done status bit
    value = ADC1BUF0;
    return (value); // If yes, then get the ADC value
}