/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K50
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA0
#define LED_LAT                  LATAbits.LATA0
#define LED_PORT                 PORTAbits.RA0
#define LED_ANS                  ANSELAbits.ANSA0
#define LED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_GetValue()           PORTAbits.RA0
#define LED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set TRIGER aliases
#define TRIGER_TRIS                 TRISBbits.TRISB0
#define TRIGER_LAT                  LATBbits.LATB0
#define TRIGER_PORT                 PORTBbits.RB0
#define TRIGER_WPU                  WPUBbits.WPUB0
#define TRIGER_ANS                  ANSELBbits.ANSB0
#define TRIGER_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define TRIGER_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define TRIGER_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define TRIGER_GetValue()           PORTBbits.RB0
#define TRIGER_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define TRIGER_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define TRIGER_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define TRIGER_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define TRIGER_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define TRIGER_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set ECCO aliases
#define ECCO_TRIS                 TRISBbits.TRISB1
#define ECCO_LAT                  LATBbits.LATB1
#define ECCO_PORT                 PORTBbits.RB1
#define ECCO_WPU                  WPUBbits.WPUB1
#define ECCO_ANS                  ANSELBbits.ANSB1
#define ECCO_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define ECCO_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define ECCO_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define ECCO_GetValue()           PORTBbits.RB1
#define ECCO_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define ECCO_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define ECCO_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define ECCO_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define ECCO_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define ECCO_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IN1 aliases
#define IN1_TRIS                 TRISBbits.TRISB2
#define IN1_LAT                  LATBbits.LATB2
#define IN1_PORT                 PORTBbits.RB2
#define IN1_WPU                  WPUBbits.WPUB2
#define IN1_ANS                  ANSELBbits.ANSB2
#define IN1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IN1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IN1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IN1_GetValue()           PORTBbits.RB2
#define IN1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IN1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IN1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IN1_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IN1_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISBbits.TRISB3
#define IN2_LAT                  LATBbits.LATB3
#define IN2_PORT                 PORTBbits.RB3
#define IN2_WPU                  WPUBbits.WPUB3
#define IN2_ANS                  ANSELBbits.ANSB3
#define IN2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IN2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IN2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IN2_GetValue()           PORTBbits.RB3
#define IN2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IN2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IN2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IN2_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IN2_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set IN3 aliases
#define IN3_TRIS                 TRISBbits.TRISB4
#define IN3_LAT                  LATBbits.LATB4
#define IN3_PORT                 PORTBbits.RB4
#define IN3_WPU                  WPUBbits.WPUB4
#define IN3_ANS                  ANSELBbits.ANSB4
#define IN3_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IN3_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IN3_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IN3_GetValue()           PORTBbits.RB4
#define IN3_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IN3_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IN3_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IN3_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IN3_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define IN3_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IN4 aliases
#define IN4_TRIS                 TRISBbits.TRISB5
#define IN4_LAT                  LATBbits.LATB5
#define IN4_PORT                 PORTBbits.RB5
#define IN4_WPU                  WPUBbits.WPUB5
#define IN4_ANS                  ANSELBbits.ANSB5
#define IN4_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IN4_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IN4_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IN4_GetValue()           PORTBbits.RB5
#define IN4_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IN4_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IN4_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IN4_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IN4_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IN4_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set PWM1 aliases
#define PWM1_TRIS                 TRISCbits.TRISC1
#define PWM1_LAT                  LATCbits.LATC1
#define PWM1_PORT                 PORTCbits.RC1
#define PWM1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define PWM1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define PWM1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define PWM1_GetValue()           PORTCbits.RC1
#define PWM1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define PWM1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set PWM2 aliases
#define PWM2_TRIS                 TRISCbits.TRISC2
#define PWM2_LAT                  LATCbits.LATC2
#define PWM2_PORT                 PORTCbits.RC2
#define PWM2_ANS                  ANSELCbits.ANSC2
#define PWM2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define PWM2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define PWM2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define PWM2_GetValue()           PORTCbits.RC2
#define PWM2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define PWM2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define PWM2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define PWM2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set BUZZER aliases
#define BUZZER_TRIS                 TRISEbits.TRISE1                           //TRISEbits.TRISE1
#define BUZZER_LAT                  LATEbits.LATE1           // LATEbits.LATE1
#define BUZZER_PORT                 PORTEbits.RE1
#define BUZZER_ANS                  ANSELEbits.ANSE1                            // ANSELEbits.ANSE1
#define BUZZER_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define BUZZER_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define BUZZER_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define BUZZER_GetValue()           PORTEbits.RE1
#define BUZZER_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define BUZZER_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define BUZZER_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define BUZZER_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/