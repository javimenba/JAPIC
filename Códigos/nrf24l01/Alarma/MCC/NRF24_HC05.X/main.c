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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "inicio.h"
#include "sensor.h"
#include <usart.h>
/*
                         Main application
 */
void Read_Text_UART(char *Output, unsigned int length);
void gets1USART(char *buffer, unsigned char len);

char  nombre[12]=' ';
short int indice=0;
 char read_cadena();


int flag_rx=0;
char dato;

void interrupt alta_prioridad (void)
{   
    if(PIR1bits.RCIF)      // Interrupción por recepción EUSART.
    {   
      
      nombre[indice]= RCREG1;       // Guardar el dato recibido en "dato"
      indice++;
      if((nombre[indice-1]=='*')){flag_rx = 1; indice=0;}
     
      else if(indice==11)
      { indice=0;
      for(int j=0; j<12; j++)
      {
          nombre[j]=' ';
      };
      }
       // dato=RCREG1; 
       // flag_rx = 1;
    }
}
   

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

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
    
    int status,i;
    __delay_ms(100);
    Ini_nRF();
    __delay_ms(100);
    Notificacion();
    TXmod_nRF();
    Notificacion();
     printf("hola");
 while (1)
 {  
 
  if(flag_rx){
      

    
      printf("\n%s",nombre);
      Write_String_nRF(&nombre);
//      printf("%c",dato);
//      Write_Char_nRF(dato);
      delay_1s();

     }
      
}
    return;
}
/**
 End of File
*/

void gets1USART(char *buffer, unsigned char len)
 {
   char i;    // Length counter
   unsigned char data;
 
   for(i=0;i<len;i++)  // Only retrieve len characters
   {
     while(!flag_rx);// Wait for data to be received
 
     data = dato;    // Get a character from the USART
                            // and save in the string
     *buffer = data;
     buffer++;              // Increment the string pointer
   }
 }