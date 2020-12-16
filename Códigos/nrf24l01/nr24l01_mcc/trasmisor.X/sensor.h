

#ifndef SENSOR_CONFIG_H
#define	SENSOR_CONFIG_H
#include <xc.h>
#include "pconfig.h"
#include "spi.h"
#define _XTAL_FREQ 4000000
void Ini_nRF();
void RXmod_nRF();
void TXmod_nRF();
int Read_Status_nRF();
void Clear_Status_nRF();
unsigned char Read_Char_nRF();
void Write_Char_nRF(unsigned char caracter);
void Read_String_nRF(unsigned char *message);
void Write_String_nRF(unsigned char *message);
void FlushTx_nRF();
void FlushRx_nRF();

#endif