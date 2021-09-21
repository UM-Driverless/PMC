/* 
 * File:   TIMER.h
 * Author: 93Urbano
 *
 * Created on 20 de septiembre de 2021, 17:15
 */

// INCLUDES //
#include "xc.h"
#include "TIMER.h"
#include "GPIO.h"

volatile unsigned char Count1s;


/*
-----------------------------------------------------------------------------------------
void TIMER1Init (void)      // Timer 1 to generate an interrupt every 100ms
-----------------------------------------------------------------------------------------
*/
void TIMER1Init (void)
{
    TIMER1Stop ();
    T1CONbits.TCS = 0;          // Select internal instruction cycle clock (Fosc / 2)
    T1CONbits.TGATE = 0;        // Disable Gated Timer mode
    T1CONbits.TCKPS = 0x3;      // Select 1:256 Prescaler
    TMR1 = 0x00;                // Clear timer register  
    //calculated
    //PR1 = 1953;               // Load the period value Ttimer=256*(2/10MHz)=0,0000512=51.2us PR1=100ms/51.2us=1953.125
    //estimated
    PR1 = 1464;                 // 1.334s-1953.12 por regla 3 1s-1464
    IPC0bits.T1IP = 0x03;       // Set Timer 1 Interrupt Priority Level
    IFS0bits.T1IF = 0;          // Clear Timer 1 Interrupt Flag
    IEC0bits.T1IE = 1;          // Enable Timer1 interrupt
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Init (void)      // Timer 2 to generate an interrupt every 10ms
-----------------------------------------------------------------------------------------
*/
void TIMER2Init (void)
{ 
    TIMER2Stop ();
    T2CONbits.TCS = 0;          // Select internal instruction cycle clock (Fosc / 2)
    T2CONbits.TGATE = 0;        // Disable Gated Timer mode
    T2CONbits.TCKPS = 0x3;      // Select 1:256 Prescaler
    TMR2 = 0x00;                // Clear timer register     
    //calculated
    //PR2 = 195;               // Load the period value Ttimer=256*(2/10MHz)=0,0000512=51.2us PR1=10ms/51.2us=195.3125
    //estimated
    PR2 = 146;                 // 1.334s-1953.12 por regla 3 1s-1464 (146)
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
    T1CONbits.TON = 1;          // Start Timer1
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Start (void)      // Timer 2 habilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER2Start (void)
{
    T2CONbits.TON = 1;          // Start Timer2
}

/*
-----------------------------------------------------------------------------------------
void TIMER1Stop (void)      // Timer 1 deshabilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER1Stop (void)
{
    T1CONbits.TON = 0;          // Stop Timer1
}

/*
-----------------------------------------------------------------------------------------
void TIMER2Stop (void)      // Timer 2 deshabilitado para funcionar
-----------------------------------------------------------------------------------------
*/
void TIMER2Stop (void)
{
    T2CONbits.TON = 0;          // Stop Timer2
}


/* Example code for Timer1 ISR */   //100ms
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
    
    if (++Count1s >= 10)
    {
        LED1_Toggle();
        LED2_Toggle();
        LED3_Toggle();
        
        Count1s = 0;
    }
    
    
}

/* Example code for Timer1 ISR */   //10ms
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    /* Interrupt Service Routine code goes here */
    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
}
