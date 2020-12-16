#include "teclado.h"




 void int_teclado()
{            
    INTCON2bits.RBPU=0; // resistencias pull-up
    ANSELB=0;
}
 
unsigned char Teclado(void){
    
  
    TRISB = 0xF0;
    PORTB = 0xFF;
  
    PORTBbits.RB0=0;
    if(PORTBbits.RB4==0){return '1';}
    if(PORTBbits.RB5==0){return '2';}
    if(PORTBbits.RB6==0){return '3';}
    if(PORTBbits.RB7==0){return 'A';}
    PORTBbits.RB0=1;
    //--------------------------------------
    PORTBbits.RB1=0;
    if(PORTBbits.RB4==0){return '4';}
    if(PORTBbits.RB5==0){return '5'; }
    if(PORTBbits.RB6==0){return '6';}
    if(PORTBbits.RB7==0){return 'B';}
    PORTBbits.RB1=1;
    //-------------------------------------
    PORTBbits.RB2=0;
    if(PORTBbits.RB4==0){return '7';}
    if(PORTBbits.RB5==0){return '8';}
    if(PORTBbits.RB6==0){return '9';}
    if(PORTBbits.RB7==0){return 'C';}
    PORTBbits.RB2=1;
    //-------------------------------------
    PORTBbits.RB3=0;
    if(PORTBbits.RB4==0){return '*';}
    if(PORTBbits.RB5==0){return '0';}
    if(PORTBbits.RB6==0){return '#';}
    if(PORTBbits.RB7==0){return 'D';}
    PORTBbits.RB3=1;

    return ' ';
}

char Recuperar(void){
    
    char tecl = ' ' ;
    
    tecl =Teclado();
    
    return tecl;
    
}