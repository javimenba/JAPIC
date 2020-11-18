#ifndef inicio_H
#define	inicio_H
#include <xc.h>

#include "config.h"
#include "PWM.h"
#include <stdint.h>
#include <stdbool.h>

#define LED3 LATEbits.LE1
#define LED1 LATEbits.LE0
#define LED2 LATCbits.LC2
#define LED LATCbits.LC7
//#define LED LATAbits.LA0
#define BUZZER LATCbits.LATC6
//#define BUZZER LATEbits.LATE1
//#define IN1_LAT LATDbits.LATD0
//#define IN2_LAT LATDbits.LATD1
//#define IN3_LAT LATDbits.LATD2
//#define IN4_LAT LATDbits.LATD3

//#define BUZZER LATEbits.LATE1
#define IN1_LAT LATDbits.LATD4
#define IN2_LAT LATDbits.LATD5
#define IN3_LAT LATDbits.LATD6
#define IN4_LAT LATDbits.LATD7
void Initialize(void);
void OSCILLATOR_Initialize(void);
void Pines(void);
void delay_1s(void);
void delay_500ms(void);
void Led_parlante(void);
void Notificar_Buzzer(void);
void Notificacion(void);
void velocidad_1();
void velocidad_2();
void velocidad_3();
void Derecho();
void Reversa();
void Giro();
void Stop();
#endif	