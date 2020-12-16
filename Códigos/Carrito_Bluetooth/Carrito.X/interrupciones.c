/*
 * File:   interrupciones.c
 * Author: francisco
 *
 * Created on 15 de julio de 2019, 12:58 AM
 */


#include "interrupciones.h"
#include "union.h"

void  INTERRUPT_Initialize (void)
{
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    RCONbits.IPEN = 0;
}
