 
 /*
 * File:   main.c
 * Author: francisco
 *
 * Created on July 16, 2019, 1:51 PM
 */


#include <xc.h>
#include "inicio.h"
#include "config.h"
#include "sensor.h"
#include  "lcd.h"
#include "PWM.h"




void main(void) {
    unsigned char registro[12],carro;
    int status;
    Lcd_Init();
    Lcd_Cmd(LCD_CURSOR_OFF);
    Initialize();
    __delay_ms(100);
    Ini_nRF();
    __delay_ms(100);
  
    Notificacion();
    RXmod_nRF();
    __delay_ms(100);
    Notificacion();
    FlushRx_nRF();

   
    while(1)
    {
        
    status=Read_Status_nRF();
    if(status){FlushRx_nRF();delay_1s();}
    Read_String_nRF(registro);
    __delay_ms(100);
    Lcd_Out2(1,1,&registro);
   /* switch(registro)
    {
        case 'a': LED1=1;delay_1s();LED1=0; delay_1s();
        break;
        
        case 'b': LED=1; LED1=1; LED2=1; LED3=1;delay_1s(); LED=0; LED1=0; LED2=0; LED3=0; delay_1s();
        break;
        
        case 'c': Notificar_Buzzer(); 
        break;
        
        default : LED2=1; __delay_ms(100); LED2=0; __delay_ms(100);
    
    };
    
*/ 
//    carro=Read_Char_nRF();
//   // Led_parlante();
//    switch(carro){
//        case'a': LED1=1;LED2=0; LED3=0; LED=0; break;
//        case'b': LED3=1;LED1=0; LED2=0; LED=0; break;
//        case'c': LED2=1;LED3=0; LED1=0; LED=0; break;
//        case'd': LED=1;LED3=0; LED1=0; LED2=0; break;
//        case'f': LED2=0;LED3=0; LED1=0; LED=0; Notificar_Buzzer(); break;
//        default: LED2=0;LED3=0; LED1=0; LED=0; delay_500ms();LED=1; LED2=1;LED3=1; LED1=1; delay_500ms();  break;
//            
//    };
    
    }
   
}

