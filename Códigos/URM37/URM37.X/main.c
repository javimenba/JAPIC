/*
 * File:   main.c
 * Author: francisco
 *
 * Created on July 12, 2019, 4:53 PM
 */


#include <xc.h>
#include <pic18f45k50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#include "CONFIGURACION.h"
#include "LCD.h"
#include "mcc_generated_files/mcc.h"
#include "PWM.h"
#include "mcc_generated_files/interrupt_manager.h"
int Ultrasonic();
void velocidad_1();
void velocidad_2();
void velocidad_3();
void Derecho();
void Reversa();
void Giro();
void Sound();

char dat;


void main(void)
{
    SYSTEM_Initialize();
   

    int dis;
    char data[10];
    char c;
    Lcd_Init();
    Lcd_Cmd(LCD_CURSOR_OFF);   

  do{       
       
        
   
       
        
        dis=Ultrasonic();
        sprintf(data," %i",dis);
        strcat(data,"cm \n");	
        Lcd_Out2(2,4,data);
        UART_print(&data);
        velocidad_3();
        __delay_ms(100);
        
         if(dis<10){Sound();}
  }while(1);

 return;  

}

int Ultrasonic(){
    
    float dato;
    TRIGER_LAT = 0; // Trigguer apagado
    T1CON = 0b00000000; // FOSC / 4 Y que el preescaler 1:1; Iniciamoa Con el TMR1ON Apagado
    unsigned int conteo; // Variable para poner el valor del Timer 1
    int distancia; // Variable donde se calcula la distancia recibida

    while (1)
    {   
        Lcd_Cmd(LCD_CLEAR);
        
        TMR1H = 0x00; // Se carga La parte Alta del Timer 1;
        TMR1L = 0x00; // Se carga la Parte Baja del Timer 1
        conteo = 0; // Garantizo que conteo sea 0;
        TRIGER_LAT = 1; // Activamos el Pulso en el Trigguer
        __delay_us(12); //Esperamos 12 Micro Segundos, Minimo deben ser 10.
        TRIGER_LAT = 0; // Apagamos el Pulso del trigguer
        while (!ECCO_PORT); // Esperamos que el Echo se active para poder empezar la cuenta
        TMR1ON = 1; // Ponemos a contar el Timer 1
        while (ECCO_PORT && !TMR1IF); // Hasta que no se apague el ECHO o Se Desborde el Timer esperamos
        TMR1ON = 0; // Apagamos el Conteo.
        if(!TMR1IF){
            conteo|= TMR1H << 8; // Tomamos la parte alta de Tmr1 y lo ponemos en el nibble alto de conteo
            conteo|= TMR1L; // Tomamos la parte baja de TMR1 y lo ponemos en el nibble bajo de conteo
        }else{
            conteo = 0;
            TMR1IF = 0;
        }
        
        
        distancia = ((conteo )/58);
        // distancia = (conteo )/58; hc04
        
   /*
        sprintf(data," %0.0f",distancia);
        strcat(data,"cm \n");	
        Lcd_Out2(2,4,data);
        UART_print(&data);
        __delay_ms(100);
        
    */    
          return distancia;
    }
  
}

void velocidad_1(){
    PWM_CCP1(30,1000);
    PWM_CCP2(30,1000);
}
void velocidad_2(){
    PWM_CCP1(70,1000);
    PWM_CCP2(70,1000);
}
void velocidad_3(){
    PWM_CCP1(99,1000);
    PWM_CCP2(99,1000);
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
}
void Giro(){
    IN1_LAT=1;
    IN2_LAT=0;
    IN3_LAT=0;
    IN4_LAT=0;    
}

void Sound(){
    BUZZER_LAT=1;
    __delay_ms(250);
    BUZZER_LAT=0;
    __delay_ms(250);
}
