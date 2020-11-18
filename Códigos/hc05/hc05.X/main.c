/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K50
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LCD.h"
#include "PWM.h"
#include "sensor.h"
int Ultrasonic();
void velocidad_1();
void velocidad_2();
void velocidad_3();
void Derecho();
void Reversa();
void Giro();
void Sound();
void Stop();
/*
                         Main application
 */

int flag_rx=0;
char dato;

void interrupt   alta_prioridad (void)
{
    if (PIR1bits.RCIF)      // Interrupción por recepción EUSART.
    {   
      dato = RCREG1;       // Guardar el dato recibido en "dato"
      flag_rx = 1;        // Indicar que hay datos en el búfer de recepción EUSART.
      
    }
}
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
     Lcd_Init();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    int w;
    char data[10],nrf24;
    int dis,status;
    Lcd_Cmd(LCD_CURSOR_OFF);
    Lcd_Out(1,1,"M&M");
        Ini_nRF();
    __delay_ms(100);
    RXmod_nRF();
    __delay_ms(100);
    FlushRx_nRF();
    while (1)
    {  /*
        if(flag_rx){
            if(dato=='a'){
                w=0;
                do{
                  velocidad_1();
                  //dis=Ultrasonic();
                 // sprintf(data," %i",dis);
                 // strcat(data,"cm \n");	
                 // Lcd_Out2(2,4,data);
                //  UART_print(&data);
                //  __delay_ms(100);
                   UART_print("Velocidad 1");
                   __delay_ms(100);
                  if(dato=='1'){velocidad_1();Derecho(); UART_print("Vamos Derecho: ");}
                  if(dato=='2'){velocidad_1();Reversa(); UART_print("Vamos Pa'atras: ");}
                  if(dato=='3'){Giro(); UART_print("Girando...: ");}
                 // if(dis<8){w=1;Stop(); UART_print("Cuidado guapo");}    
                   if(dato=='b' || dato=='c' ){w=1;}
                }while(w==0);
            }
                if(dato=='b'){
                w=0;
                do{
                  velocidad_2();
                 // dis=Ultrasonic();
                 // sprintf(data," %i",dis);
                  //strcat(data,"cm \n");	
                 // Lcd_Out2(2,4,data);
                 // UART_print(&data);
                 // __delay_ms(100);
                   UART_print("Velocidad 2");
                   __delay_ms(100);
                  if(dato=='1'){velocidad_2();Derecho(); UART_print("Vamos Derecho: ");}
                  if(dato=='2'){velocidad_2();Reversa(); UART_print("Vamos Pa'atras: ");}
                  if(dato=='3'){Giro(); UART_print("Girando...: ");}
                  //if(dis<8){w=1;Stop(); UART_print("Cuidado guapo");}   
                   if(dato=='a' || dato=='c' ){w=1;}
                }while(w==0);
            }
   
        }
  
     */
    status=Read_Status_nRF();
    if(status){FlushRx_nRF();__delay_ms(100); __delay_ms(100); __delay_ms(100); __delay_ms(100); __delay_ms(100); __delay_ms(100); __delay_ms(100);} 
    nrf24=Read_Char_nRF();  
    switch(status)
    {
        case 'a': Derecho(); break;
        case 'b': Reversa(); break;
        case '1': velocidad_1();break;
        case '2': velocidad_2(); break;
        case '3': velocidad_3(); break;
        case 's': Stop(); break;
        
        default: Stop(); break;
    };
}
}

int Ultrasonic(){
    
    float dato;
    TRIGER_LAT = 0; // Trigguer apagado
    T1CON = 0b00000000; // FOSC / 4 Y que el preescaler 1:1; Iniciamoa Con el TMR1ON Apagado
    unsigned int conteo; // Variable para poner el valor del Timer 1
    int distancia; // Variable donde se calcula la distancia recibida

    while (1)
    {   
        
        
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
    Sound();
}
void Giro(){
    PWM_CCP2(85,1000);
    PWM_CCP1(70,1000);
    IN1_LAT=1;
    IN2_LAT=0;
    IN3_LAT=0;
    IN4_LAT=1;
        
}

void Sound(){
    BUZZER_LAT=1;
    __delay_ms(100);
    BUZZER_LAT=0;
    __delay_ms(100);
}
