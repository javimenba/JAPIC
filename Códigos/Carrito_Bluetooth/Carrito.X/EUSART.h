#ifndef EUSART1_H
#define EUSART1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: Macro Declarations
*/

#define EUSART1_DataReady  (EUSART1_is_rx_ready())

/**
  Section: Data Type Definitions
*/

typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}eusart1_status_t;

/**
 Section: Global variables
 */
extern volatile uint8_t eusart1TxBufferRemaining;
extern volatile uint8_t eusart1RxCount;

extern void (*EUSART1_RxDefaultInterruptHandler)(void);


void EUSART1_Initialize(void);

bool EUSART1_is_tx_ready(void);

bool EUSART1_is_rx_ready(void);

bool EUSART1_is_tx_done(void);

eusart1_status_t EUSART1_get_last_status(void);


uint8_t EUSART1_Read(void);

void EUSART1_Write(uint8_t txData);


void EUSART1_Receive_ISR(void);

void EUSART1_RxDataHandler(void);

void EUSART1_SetFramingErrorHandler(void (* interruptHandler)(void));

void EUSART1_SetOverrunErrorHandler(void (* interruptHandler)(void));

void EUSART1_SetErrorHandler(void (* interruptHandler)(void));

void EUSART1_SetRxInterruptHandler(void (* interruptHandler)(void));

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  