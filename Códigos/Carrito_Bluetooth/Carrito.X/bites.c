/*
 * File:   bites.c
 * Author: francisco
 *
 * Created on 15 de julio de 2019, 12:56 AM
 */


#include "bites.h"


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x05;
    TRISA = 0xFE;
    TRISB = 0xFF;
    TRISC = 0x87;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELC = 0x04;
    ANSELB = 0x3F;
    ANSELE = 0x05;
    ANSELA = 0x2E;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    INTCON2bits.nRBPU = 1;






   
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// Clear global Interrupt-On-Change flag
    INTCONbits.IOCIF = 0;
}

/**
 End of File
*/