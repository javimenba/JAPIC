#ifndef inicio_H
#define	inicio_H
#include <xc.h>


#include <stdint.h>
#include <stdbool.h>
#define _XTAL_FREQ 4000000
//#define LED LATEbits.LE1
//#define LED LATAbits.LA0
//#define BUZZER LATCbits.LATC6
//#define BUZZER LATEbits.LATE1

void Initialize(void);
void OSCILLATOR_Initialize(void);
void Pines(void);
void delay_1s(void);
void Led_parlante(void);
void Notificar_Buzzer(void);
void Notificacion(void);
#endif	