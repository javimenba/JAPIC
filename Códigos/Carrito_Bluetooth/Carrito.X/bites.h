#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H



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
#define BUZZER_TRIS                 TRISEbits.TRISE1
#define BUZZER_LAT                  LATEbits.LATE1
#define BUZZER_PORT                 PORTEbits.RE1
#define BUZZER_ANS                  ANSELEbits.ANSE1
#define BUZZER_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define BUZZER_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define BUZZER_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define BUZZER_GetValue()           PORTEbits.RE1
#define BUZZER_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define BUZZER_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define BUZZER_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define BUZZER_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)


void PIN_MANAGER_Initialize (void);


void PIN_MANAGER_IOC(void);



#endif 