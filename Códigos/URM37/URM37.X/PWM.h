#ifndef PWM_H
#define PWM_H

#include <xc.h>

#define _XTAL_FREQ 16000000
void PWM_CCP1( unsigned int duty, unsigned int fpwm);
void PWM_CCP2( unsigned int duty, unsigned int fpwm);
#endif
