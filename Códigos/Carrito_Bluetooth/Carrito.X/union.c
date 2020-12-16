/*
 * File:   union.c
 * Author: francisco
 *
 * Created on 15 de julio de 2019, 01:02 AM
 */

#include  "union.h"


void Iniciando(void)
{

    INTERRUPT_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    EUSART1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS INTOSC; IDLEN disabled; IRCF 4MHz; 
    OSCCON = 0x52;
    // INTSRC INTRC_31_25KHz; PLLEN disabled; PRISD disabled; SOSCGO disabled; 
    OSCCON2 = 0x00;
    // SPLLMULT 4xPLL; TUN 0; 
    OSCTUNE = 0x00;
    // ACTSRC SOSC; ACTUD enabled; ACTEN disabled; 
    ACTCON = 0x00;
}
