/*
 * File:   inicio.c
 * Author: francisco
 *
 * Created on 16 de julio de 2019, 02:43 PM
 */
#include "inicio.h"
#include "mcc_generated_files/pin_manager.h"
/*void Initialize(void)
{



    OSCILLATOR_Initialize();
    Pines();
   
    
}

//void OSCILLATOR_Initialize(void)
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

void Pines(void)
{
    PORTA=0;
    TRISA=0;
    ANSELA=0;
    PORTE=0;
    TRISEbits.RE1=0;
    ANSELE=0;
    PORTC=0;
    TRISCbits.RC6=0;
    ANSELC=0;
    TRISB=0x01 ;
    ANSELB=0;
    LATB=0x10 ;
}*/

void delay_1s(void){

    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
  
}

void Led_parlante(void)
{
    LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
       LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
       LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
    LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
       LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
       LED=1;
    __delay_ms(100);
    LED=0;
    __delay_ms(100); 
}

void Notificar_Buzzer(void)
{
    BUZZER=1;
    delay_1s();
   BUZZER=0;
   delay_1s();
}

void Notificacion(void)
{
Led_parlante();
Notificar_Buzzer();
}