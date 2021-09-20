/* 
 * File:   TIMER.h
 * Author: 93Urbano
 *
 * Created on 20 de septiembre de 2021, 17:15
 */

// INCLUDES //
#include "xc.h"
#include "TIMER.h"


/*
-----------------------------------------------------------------------------------------
void TIMER1Init (void)      // Timer 1 to generate an interrupt every 250ms o 100ms
-----------------------------------------------------------------------------------------
*/
void TIMER1Init (void)
{
    TIMER1Stop ();
    T1CONBITS.TCS = 0;          // Select internal instruction cycle clock (Fosc / 2)
    T1CONBITS.TGATE = 0;        // Disable Gated Timer mode
    T1CONBITS.TCKPS = 0x3;      // Select 1:256 Prescaler
 // PR1 = 39062;                // Load the period value (250ms/(256*25ns))
//    PR2 = 1562;                 // Load the period value (10ms/(256*25ns))    256 * 25ns = 6,4us   10ms / 6,4us = 1562,5    
    PR1 = 15625;                // Load the period value (100ms/(256*25ns))   
    IPC0bits.T1IP = 0x03;       // Set Timer 1 Interrupt Priority Level
    IFS0bits.T1IF = 0;          // Clear Timer 1 Interrupt Flag
    IEC0bits.T1IE = 1;          // Enable Timer1 interrupt
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Init (void)      // Timer 2 to generate an interrupt every 10ms...1ms con la modificacion
-----------------------------------------------------------------------------------------
*/
void TIMER2Init (void)
{ 
    TIMER2Stop ();
    T2CONBITS.TCS = 0;          // Select internal instruction cycle clock (Fosc / 2)
    T2CONBITS.TGATE = 0;        // Disable Gated Timer mode
    T2CONBITS.TCKPS = 0x3;      // Select 1:256 Prescaler
    TMR2 = 0x00;                // Clear timer register     
//    PR2 = 1562;                 // Load the period value (10ms/(256*25ns))    256 * 25ns = 6,4us   10ms / 6,4us = 1562,5
    PR2 = 156;                  // Load the period value (1ms/(256*25ns))       256 * 25ns = 6,4us   1ms / 6,4us = 156,25    
    
    IPC1bits.T2IP = 0x02;       // Set Timer 2 Interrupt Priority Level
    IFS0bits.T2IF = 0;          // Clear Timer 2 Interrupt Flag
    IEC0bits.T2IE = 1;          // Enable Timer2 interrupt
}

/*
-----------------------------------------------------------------------------------------
void TIMER1Start (void)      // Timer 1 habilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER1Start (void)
{
    T1CONBITS.TON = 1;          // Start Timer1
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Start (void)      // Timer 2 habilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER2Start (void)
{
    T2CONBITS.TON = 1;          // Start Timer2
}

/*
-----------------------------------------------------------------------------------------
void TIMER1Stop (void)      // Timer 1 deshabilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER1Stop (void)
{
    T1CONBITS.TON = 0;          // Stop Timer1
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Stop (void)      // Timer 2 deshabilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER2Stop (void)
{
    T2CONBITS.TON = 0;          // Stop Timer2
}


/* Example code for Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
}

/* Example code for Timer1 ISR */
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
}
