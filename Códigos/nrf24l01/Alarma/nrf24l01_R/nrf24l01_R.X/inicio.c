/*
 * File:   inicio.c
 * Author: francisco
 *
 * Created on 16 de julio de 2019, 02:43 PM
 */
#include "inicio.h"

void Initialize(void)
{



    OSCILLATOR_Initialize();
    Pines();
   
    
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

void Pines(void)
{
    PORTD=0;
    TRISD=0;
    ANSELD=0;
    PORTA=0;
    TRISA=0;
    ANSELA=0;
    PORTE=0;
    TRISE=0;
    ANSELE=0;
    PORTC=0;
    TRISC=0;
    ANSELC=0;
    TRISB=0x01 ;
    ANSELB=0;
    LATB=0x10 ;
}

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
void delay_500ms(void){

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

void velocidad_1(){
    PWM_CCP1(15,1000);
    PWM_CCP2(15,1000);
}
void velocidad_2(){
    PWM_CCP1(50,1000);
    PWM_CCP2(50,1000);
}
void velocidad_3(){
    PWM_CCP1(99,1000);
    PWM_CCP2(99,1000);
}
void Stop()
{
    PWM_CCP1(0,1000);
    PWM_CCP2(0,1000); 
    IN1_LAT=0;
    IN2_LAT=0;
    IN3_LAT=0;
    IN4_LAT=0;  
}
void Derecho(){
    IN1_LAT=1;
    IN2_LAT=0;
    IN3_LAT=1;
    IN4_LAT=0;    
}
void Reversa(){
    IN1_LAT=0;
    IN2_LAT=1;
    IN3_LAT=0;
    IN4_LAT=1;
    Notificar_Buzzer();
}
void Giro(){
    PWM_CCP2(30,1000);
    PWM_CCP1(10,1000);
    IN1_LAT=1;
    IN2_LAT=0;
    IN3_LAT=0;
    IN4_LAT=1;
        
}


