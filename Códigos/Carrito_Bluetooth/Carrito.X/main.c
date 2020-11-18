/*
 * File:   main.c
 * Author: francisco
 *
 * Created on 15 de julio de 2019, 12:51 AM
 */



#include "union.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int flag_rx=0;
char dato;

void interrupt alta_prioridad (void)
{
    if (PIR1bits.RCIF)      // Interrupción por recepción EUSART.
    {   
      dato = RCREG1;       // Guardar el dato recibido en "dato"
      flag_rx = 1;        // Indicar que hay datos en el búfer de recepción EUSART.
      
    }
}

void main(void) {
    Iniciando();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    int w;
    
    while (1)
    {
        if(flag_rx){
        
            switch(dato){
                case 'a':     BUZZER_LAT=0;
                              LED_LAT^=1;
                              __delay_ms(1000);
                              break;
                default:      BUZZER_LAT^=1; __delay_ms(500);      
            };
   
        }
  
      
}
 
}
