#ifndef NRF24L01_H
#define NRF24L01_H

#include <xc.h>



#define _XTAL_FREQ 4000000
#define CE PORTBbits.RB5  //Chip Eneable, Activa RX mode o TX mode (sbit CE  at PORTB.B3;)
#define CSN PORTBbits.RB4 

// Inicializa 
void Ini_nRF();
// modo receptor
void RXmod_nRF();
// modo trasmisor
void TXmod_nRF();
// lee el registro
int Read_Status_nRF();
// limpia el registro
void Clear_Status_nRF();
//Lee un caracter

unsigned char Read_Char_nRF();
// Manda un caracter
void Write_Char_nRF(unsigned char caracter);
// lee una cadena
void Read_String_nRF(unsigned char *message);
// manda una cadena
void Write_String_nRF(unsigned char *direccion);
// limpia TxFIFO
void FlushTx_nRF();
// limpia RxFIFO
void FlushRx_nRF();
void RF_WRITE_ARRAY(unsigned short direccion, unsigned short num_dat, unsigned short dato[32]);
//
unsigned int RF_READ_ARRAY(unsigned short direccion, unsigned short num_dat);
//
void RF_WRITE_BYTE(unsigned short direccion, unsigned short dato);
//
unsigned short RF_READ_BYTE(unsigned short direccion);
#endif