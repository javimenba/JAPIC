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
WriteSPI(0x02);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x21);
WriteSPI(0x00);
PORTBbits.RB4=1;
    
PORTBbits.RB4=0;
WriteSPI(0x22);
WriteSPI(0x01);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x23);
WriteSPI(0x01);
PORTBbits.RB4=1;


PORTBbits.RB4=0;
WriteSPI(0x24);
WriteSPI(0x00);
PORTBbits.RB4=1;
    
PORTBbits.RB4=0;
WriteSPI(0x25);
WriteSPI(0x01);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x26);
WriteSPI(0x26);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x31);
WriteSPI(0x0C);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x2A);
WriteSPI(0xA3);
WriteSPI(0xA3);
WriteSPI(0xA3);
PORTBbits.RB4=1;

PORTBbits.RB4=0;
WriteSPI(0x30);
WriteSPI(0xA3);
WriteSPI(0xA3);
WriteSPI(0xA3);
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


unsigned short dir=0;
int dn;              //Variable utilizada para el número de datos que se van a atransmitir en el comando
void RF_WRITE_ARRAY(unsigned short direccion, unsigned short num_dat, unsigned short dato[32]){   //FUNCIÓN PARA LA ESCRITURA DE UNA LOCALIDAD DEL nRF24L01. FORMATO:  DIRECCIÓN (EN HEX),  NÚMERO DE BYTES DE DATOS A TRANSMITIR (EN ENTEROS), ARRAY DE BYTES A TRANSMITIR//
          dir=direccion;
          __delay_us(2);
          CSN=0;             //Comienza el envío de comando
          __delay_us(2);
          WriteSPI(dir);  //Se manda el comando con la dirección Vía SPI
          for(dn=1;dn<=num_dat;dn++){
           __delay_us(1);
           WriteSPI(dato[dn]); //Se manda el dato deseado
//
//}
}
          __delay_us(2);
          CSN=1;                //Transmisión de datos y comando Finalziada
//
}
unsigned short dummy=0b01010101; //Dummy data para generación del sck para lectura mediante SPI
unsigned short dir0=0;
int dn1;              //Variable utilizada para el número de datos que se van a atransmitir en el comando
unsigned int RF_READ_ARRAY(unsigned short direccion, unsigned short num_dat){   //FUNCIÓN PARA LA ESCRITURA DE UNA LOCALIDAD DEL nRF24L01. FORMATO:  DIRECCIÓN (EN HEX),  NÚMERO DE BYTES DE DATOS A TRANSMITIR (EN ENTEROS), ARRAY DE BYTES A TRANSMITIR//
         unsigned short datRead[32];
         dir0=0b00000000+direccion;
         __delay_us(2);
         CSN=0;             //Comienza el envío de comando
         __delay_us(2);
         WriteSPI(dir0);  //Se manda el comando con la dirección Vía SPI
         for(dn=1;dn<=num_dat;dn1++){
          __delay_us(1);
         datRead[dn1]=WriteSPI(0xFF);
         datRead[dn1]==ReadSPI();
        
    

}
         __delay_us(2);
         CSN=1;                //Transmisión de datos y comando Finalziada
         return datRead;
//
}


unsigned short dir1=0,stat=0;
void RF_WRITE_BYTE(unsigned short direccion, unsigned short dato){
         dir1=direccion;
         
                __delay_us(2);
                CSN=0;              //Comienza el envío de comando
                __delay_us(2);
                //stat=ReadSPI(dir1);   //Se manda el comando con la dirección Vía SPI
                stat=WriteSPI(dir1);
                __delay_us(5);
                stat=ReadSPI();
                __delay_us(1);
                WriteSPI(dato);   //Se manda el dato deseado
                __delay_us(2);
                CSN=1;               //Transmisión de datos y comando Finalziada
}
unsigned short dir2=0;

unsigned short BYTE_RX=0;  //Byte recibido

unsigned short RF_READ_BYTE(unsigned short direccion){  ///////////FUNCION para LEER UN REGISTRO DEL RF, REGRESA UN BYTE
                 dir2=direccion;
                 CSN=0;              //Comienza el envío del comando
                 WriteSPI(dir2);
                 //BYTE_RX=ReadSPI(dummy);
                 BYTE_RX=WriteSPI(dummy);
                 __delay_us(5);
                 BYTE_RX=ReadSPI();
                 CSN=1;
                 return BYTE_RX;
//
}