/*
 * File:   main.c
 * Author: francisco
 *
 * Created on 9 de julio de 2019, 11:09 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "LCD.h"
#include "teclado.h"

#define _XTAL_FREQ 4000000 
#define  LED LATAbits.LA7                 
#define BOCINA LATEbits.LE1
void main(void) {
    TRISA=0;
    ANSELA=0;
    PORTA=0;
    TRISE=0;
    ANSELE=0;
    OSCCON=0b01010111;
    ANSELD=0;
    int_teclado();
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
            // -------

    char key;
        while(1){
       key =Recuperar();
       Lcd_Chr_CP(key);
      
       
    }
    return;
}
