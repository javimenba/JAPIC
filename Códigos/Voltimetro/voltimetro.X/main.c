/*
 * File:   main.c
 * Author: francisco
 *
 * Created on July 12, 2019, 3:44 PM
 */


#include <xc.h>
#include <pic18f45k50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LCD.h"
#include "configuracion.h"
void ADC_Init();
int ADC_Read(int);
void Buzzer1();


#define vref 5.00		/* Reference Voltage is 5V*/
#define buzzer LATEbits.LATE1
void main()
{    
    char data[10];    
    int digital;  
    float voltage;
    OSCCON=0x72;		/*Set internal Osc. frequency to 8 MHz*/
    Lcd_Init();		/*Initialize 16x2 LCD*/
    ADC_Init();			/*Initialize 10-bit ADC*/
    ANSELA=0;
    PORTA=0;
    TRISA=0;
    ANSELEbits.ANSE1=0;
    TRISEbits.RE1=0;
    Lcd_Out(1,1,"Voltage is...");

    Lcd_Cmd(LCD_CURSOR_OFF);
    while(1)
    {        
        digital=ADC_Read(5);

	/*Convert digital value into analog voltage*/
        voltage= digital*((float)vref/(float)1024);  
        
	/*It is used to convert integer value to ASCII string*/
        sprintf(data,"%.2f",voltage);

        strcat(data," mV");	/*Concatenate result and unit to print*/
        Lcd_Out2(2,4,data);/*Send string data for printing*/  
        __delay_ms(1000);
    if(voltage==5){
        Buzzer1();
    }    
        
    }
    
}

void ADC_Init()
{    
    TRISA = 0xff;		/*Set as input port*/
    ADCON1 = 0x0e;  		/*Ref vtg is VDD & Configure pin as analog pin*/    
    ADCON2 = 0x92;  		/*Right Justified, 4Tad and Fosc/32. */
    ADRESH=0;  			/*Flush ADC output Register*/
    ADRESL=0;   
}

int ADC_Read(int channel)
{
    int digital;
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);

    /*channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000)& ADC is disabled*/
    ADCON0 |= ((1<<ADON)|(1<<GO));/*Enable ADC and start conversion*/

    /*wait for End of conversion i.e. Go/done'=0 conversion completed*/
    while(ADCON0bits.GO_nDONE==1);

    digital = (ADRESH*256) | (ADRESL);/*Combine 8-bit LSB and 2-bit MSB*/
    //   PORTA=digital;
    return(digital);
}
void Buzzer1(){
    buzzer=1;
    __delay_ms(1000);
    buzzer=0;
    __delay_ms(1000);
}