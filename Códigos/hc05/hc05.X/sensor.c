/*
 * File:   sensor.c
 * Author: francisco
 *
 * Created on July 16, 2019, 9:09 PM
 */


#include "sensor.h"

void Ini_nRF(){
   
OpenSPI(SPI_FOSC_16, MODE_00, SMPEND);

PORTBbits.RB4=0;
WriteSPI(0x20);
WriteSPI(0x02); //POWER UP, PTX MODE
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x21);  //EN AA REGISTER
WriteSPI(0x00);  //DESABILITA AUTO ? ACKNOLEDGMENT
PORTBbits.RB4=1;
    
PORTBbits.RB4=0;
WriteSPI(0x22);  //EN RXADDR REGISTER
WriteSPI(0x01);  //HABILITA DATOS DEL PIPELINE 0
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x23);  //SETUP AW REGISTER
WriteSPI(0x01);  //LONGITUD DE DIRECCION DE LOS MODOS TX/RX
PORTBbits.RB4=1;


PORTBbits.RB4=0;
WriteSPI(0x24); //SETUP RETR REGISTER
WriteSPI(0x00); //DESHABILITA AUTO ?RETRANSMISION
PORTBbits.RB4=1;
    
PORTBbits.RB4=0;
WriteSPI(0x25); //RF CH REGISTER
WriteSPI(0x01); //CANAL UNO PARA LA COMUNICACION
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x26); //RF SETUP REGISTER
WriteSPI(0x26); // 250 kbps , 0 dbm (MAXIMA POTENCIA, MENOR VELOCIDAD)
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x31); //RX PW P0 REGISTER
WriteSPI(0x0C); //LONGITUD DEL PAQUETE 1?32 BYTES ( 0 1 ? 1 BYTE)
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x2A); //DIRECCION DEL RECEPTOR
WriteSPI(0xA3); //LSBYTE
WriteSPI(0xA3); //SECOND BYTE
WriteSPI(0xA3); //MSB
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x30); //DIRECCION DEL TRANSMISOR
WriteSPI(0xA3); //LSBYTE
WriteSPI(0xA3); //SECOND BYTE
WriteSPI(0xA3); //MSB
PORTBbits.RB4=1;


__delay_ms(100);
           
}


void RXmod_nRF(){
    
    PORTBbits.RB5=0;
    __delay_us(150);
    PORTBbits.RB4=0;
    WriteSPI(0x20);
    WriteSPI(0x03);
    PORTBbits.RB4=1;
    __delay_us(150);
    PORTBbits.RB5=1;
    __delay_us(150);
    
}

void TXmod_nRF(){
    
    PORTBbits.RB5=0;
    __delay_us(150);
    PORTBbits.RB4=0;
    WriteSPI(0x20);
    WriteSPI(0x02);
    PORTBbits.RB4=1;
    __delay_us(150);
    PORTBbits.RB5=1;
    __delay_us(150);
    
}


int Read_Status_nRF(){
    
    unsigned int state=0;
    PORTBbits.RB4=0;
    WriteSPI(0x07);
    state = ReadSPI();
    PORTBbits.RB4=1;
    return state;
    
}


void Clear_Status_nRF(){
    
    PORTBbits.RB4=0;
    WriteSPI(0x27);
    WriteSPI(0x60);
    PORTBbits.RB4=1;
}

unsigned char Read_Char_nRF(){
    
    unsigned char caracter;
    PORTBbits.RB4=0;
    WriteSPI(0x61);
    WriteSPI(0x00);
    caracter = ReadSPI();
    PORTBbits.RB4=1;
    return caracter;
}

void Write_Char_nRF(unsigned char caracter){
    
    PORTBbits.RB4=0;
    WriteSPI(0xA0);
    WriteSPI(0x00);
    WriteSPI(caracter);
    PORTBbits.RB4=1;
    PORTBbits.RB5=1;
    __delay_us(15);
    PORTBbits.RB5=0;
    
    
}

void Read_String_nRF(unsigned char *message){
    
    PORTBbits.RB4=0;
    WriteSPI(0x61);
    WriteSPI(0xFF);
    getsSPI(message,11);
    PORTBbits.RB4=1;
    message[11]= '\0';
}


void Write_String_nRF(unsigned char *message){
    
    message [11]= '\0';
    PORTBbits.RB4=0;
    WriteSPI(0xA0);
    WriteSPI(0x00);
    putsSPI(message);
    PORTBbits.RB4=1;
    
    PORTBbits.RB5=1;
    __delay_us(150);
    PORTBbits.RB5=0;
}

void FlushTx_nRF(){
    
    PORTBbits.RB4=0;
    WriteSPI(0xE1);
    PORTBbits.RB4=1;
}

void FlushRx_nRF(){
    
    PORTBbits.RB4=0;
    WriteSPI(0xE2);
    PORTBbits.RB4=1;
}

