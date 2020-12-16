//******************************************************************************
//        Software License Agreement
//
// ©2016 Microchip Technology Inc. and its subsidiaries. You may use this
// software and any derivatives exclusively with Microchip products.
//
// THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
// EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
// WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
// PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION WITH ANY
// OTHER PRODUCTS, OR USE IN ANY APPLICATION.
//
// IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
// INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
// WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
// BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
// FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
// ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
// THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
//
// MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS.
//******************************************************************************
//
// Memory Map
//   -----------------
//   |    0x0000     |   Reset vector
//   |               |
//   |    0x0008     |   High Priority Interrupt vector
//   |               |
//   |    0x0018     |   Low Priority Interrupt vector
//   |               |
//   |  Boot Block   |   (this program)
//   |               |
//   |    0x500     |   Re-mapped Reset Vector (Actual address
//   |    0x508     |   Re-mapped High Priority Interrupt Vector
//   |    0x518     |   Re-mapped Low Priority Interrupt Vector
//   |       |       |
//   |               |
//   |  Code Space   |   User program space
//   |               |
//   |       |       |
//   |               |
//   | End of Flash  |
//   -----------------
//
//
//
//
// *****************************************************************************
/*
#define  READ_VERSION   0
#define  READ_FLASH     1
#define  WRITE_FLASH    2
#define  ERASE_FLASH    3
#define  READ_EE_DATA   4
#define  WRITE_EE_DATA  5
#define  READ_CONFIG    6
#define  WRITE_CONFIG   7
#define  CALC_CHECKSUM  8
#define  RESET_DEVICE   9



// *****************************************************************************
    #include <xc.h>       // Standard include
    #include <stdint.h>
    #include <stdbool.h>
    #include "bootload.h"
    #include "mcc.h"

// *****************************************************************************
void     Get_Buffer (void);     // generic comms layer
uint8_t  Get_Version_Data(void);
uint8_t  Read_Flash(void);
uint8_t  Write_Flash(void);
uint8_t  Erase_Flash(void);
uint8_t  Read_EE_Data(void);
uint8_t  Write_EE_Data(void);
uint8_t  Read_Config(void);
uint8_t  Write_Config(void);
uint8_t  Calc_Checksum(void);
void     StartWrite(void);
void     BOOTLOADER_Initialize(void);
void     Run_Bootloader(void);
bool     Bootload_Required (void);

// *****************************************************************************
#define	MINOR_VERSION	0x00       // Version
#define	MAJOR_VERSION	0x01
#define ERROR_ADDRESS_OUT_OF_RANGE   0xFE
#define ERROR_INVALID_COMMAND        0xFF
#define COMMAND_SUCCESS              0x01

// To be device independent, these are set by mcc in memory.h
#define  LAST_WORD_MASK              (WRITE_FLASH_BLOCKSIZE - 1)
#define  NEW_RESET_VECTOR            0x500
#define  NEW_INTERRUPT_VECTOR_HIGH   0x508
#define  NEW_INTERRUPT_VECTOR_LOW    0x518

#define _str(x)  #x
#define str(x)  _str(x)
// *****************************************************************************


// *****************************************************************************
    uint16_t check_sum;      // Checksum accumulator
    uint16_t counter;        // General counter
    uint8_t rx_data;
    uint8_t tx_data;
    bool reset_pending  = false;
// Force variables into Unbanked for 1-cycle accessibility 
    uint8_t EE_Key_1    __at(0x0) = 0;
    uint8_t EE_Key_2    __at(0x1) = 0;


frame_t  frame;

// *****************************************************************************
// The bootloader code does not use any interrupts.
// However, the application code may use interrupts.
// The interrupt vector on a PIC18F is located at
// address 0x0008 (High) and 0x0018 (Low). 
// The following function will be located
// at the interrupt vector and will contain a jump to
// the new application interrupt vectors
// *****************************************************************************

    asm ("psect  intcode,global,reloc=2,class=CODE,delta=1");
    asm ("GOTO " str(NEW_INTERRUPT_VECTOR_HIGH));

    asm ("psect  intcodelo,global,reloc=2,class=CODE,delta=1");
    asm ("GOTO " str(NEW_INTERRUPT_VECTOR_LOW));

// *****************************************************************************
void BOOTLOADER_Initialize ()
{
    if (Bootload_Required () == true)
    {
        Run_Bootloader ();     // generic comms layer
    }
    STKPTR = 0x00;
    asm ("goto  "  str(NEW_RESET_VECTOR));
}

// *****************************************************************************
bool Bootload_Required ()
{

// ******************************************************************
//  Check the reset vector for code to initiate bootloader
// ******************************************************************
                                    // This section reads the application start
                                    // vector to see if the location is blank
    TBLPTR = NEW_RESET_VECTOR;      // (0xFF) or not.  If blank, it runs the
                                    // bootloader.  Otherwise, it assumes the
                                    // application is loaded and instead runs the
                                    // application.
    EECON1 = 0x80;
    asm("TBLRD *+");
    if (TABLAT == 0xFF)
    {
        return (true);
    }
	return (false);
}

// *****************************************************************************
uint8_t  ProcessBootBuffer()
{
    uint8_t   len;
    EE_Key_1 = frame.EE_key_1;
    EE_Key_2 = frame.EE_key_2;
	
// Test the command field and sub-command.
    switch (frame.command)
    {
    case    READ_VERSION:
        len = Get_Version_Data();
        break;
    case    WRITE_FLASH:
        len = Write_Flash();
        break;
    case    ERASE_FLASH:
        len = Erase_Flash();
        break;
    case    READ_CONFIG:
        len = Read_Config();
        break;
    case    WRITE_CONFIG:
        len = Write_Config();
        break;
    case    CALC_CHECKSUM:
        len = Calc_Checksum();
        break;
    case    RESET_DEVICE:
        reset_pending = true;
        len = 9;
        break;
    default:
        frame.data[0] = ERROR_INVALID_COMMAND;
        len = 10;
    }
    return (len);
}

// *****************************************************************************
// Commands
//
//        Cmd     Length----------------   Address---------------
// In:   [<0x00> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00>]
// OUT:  [<0x00> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00> <VERL><VERH>]
// *****************************************************************************
uint8_t  Get_Version_Data()
{
    frame.data[0] = MINOR_VERSION;
    frame.data[1] = MAJOR_VERSION;
    frame.data[2] = 0;       // Max packet size (256)
    frame.data[3] = 1;
    frame.data[4] = 0;
    frame.data[5] = 0;
    TBLPTRU = 0x3F;
    TBLPTRH = 0xFF;               // Get device ID
    TBLPTRL = 0xFE;
    EECON1 = 0xC0;       // Setup writes
    asm("TBLRD *+");  //    EECON1bits.RD   = 1;
    frame.data[6] = TABLAT;
    asm("TBLRD *+");   //    EECON1bits.RD   = 1;
    frame.data[7] = TABLAT;
    frame.data[8] = 0;
    frame.data[9] = 0;

    frame.data[10] = ERASE_FLASH_BLOCKSIZE;
    frame.data[11] = WRITE_FLASH_BLOCKSIZE;

    TBLPTRU = 0x30;
    TBLPTRH = 0x00;
    TBLPTRL = 0x00;
//    EECON1 = 0xC0;       // Setup writes  Hasn't changed sincelast assignment.
    for (uint8_t  i= 12; i < 16; i++)
    {
        asm("TBLRD *+");
        frame.data[i] = TABLAT;
    }

    return  25;   // total length to send back 9 byte header + 16 byte payload
}



// *****************************************************************************
// Write Flash
//        Cmd     Length----- Keys------   Address---------------  Data ---------
// In:   [<0x02> <0x00><0x00><0x55><0xAA> <0x00><0x00><0x00><0x00> <Data>..<data>]
// OUT:  [<0x02> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00> <0x01>]
// *****************************************************************************
uint8_t Write_Flash()
{
    TBLPTRL = frame.address_L;
    TBLPTRH = frame.address_H;
    TBLPTRU = frame.address_U;
	EECON1 = 0xA4;       // Setup writes
    for (uint16_t  i = 0; i < frame.data_length; i ++)
    {
        TABLAT = frame.data[i];
        if (TBLPTR >= END_FLASH)
        {
            frame.data[0] = ERROR_ADDRESS_OUT_OF_RANGE;
            return (10);
        }
        asm("TBLWT *+");
        if (((TBLPTRL & LAST_WORD_MASK) == LAST_WORD_MASK)
          || (i == frame.data_length - 1))
        {
            asm("TBLRD *-");
            StartWrite();
            asm("TBLRD *+");
        }
    }
    frame.data[0] = COMMAND_SUCCESS;
    EE_Key_1 = 0x00;  // erase EE Keys
    EE_Key_2 = 0x00;
    return (10);
}

// *****************************************************************************
// Erase Program Memory
// Erases data_length rows from program memory
//        Cmd     Length----- Keys------   Address---------------  Data ---------
// In:   [<0x03> <0x00><0x00><0x55><0xAA> <0x00><0x00><0x00><0x00>]
// OUT:  [<0x03> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00> <0x01>]
// *****************************************************************************
uint8_t Erase_Flash ()
{
    TBLPTRL = frame.address_L;
    TBLPTRH = frame.address_H;
    TBLPTRU = frame.address_U;
    for (uint16_t i=0; i < frame.data_length; i++)
    {
        if (TBLPTR >= END_FLASH)
        {
            frame.data[0] = ERROR_ADDRESS_OUT_OF_RANGE;
            return (10);
        }
        EECON1 = 0x94;       // Setup writes
        StartWrite();
        TBLPTR += ERASE_FLASH_BLOCKSIZE;
    }
    frame.data[0]  = COMMAND_SUCCESS;
    frame.EE_key_1 = 0x00;  // erase EE Keys
    frame.EE_key_2 = 0x00;
    return (10);
}


// *****************************************************************************
// Read Config Words
//        Cmd     Length-----              Address---------------  Data ---------
// In:   [<0x06> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00>]
// OUT:  [<0x06> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00> <Data>..<data>]
// *****************************************************************************
uint8_t Read_Config ()
{
    TBLPTRL = frame.address_L;
    TBLPTRH = frame.address_H;
    TBLPTRU = frame.address_U;
	EECON1   = 0xC0;
    for (uint8_t  i = 0; i < frame.data_length; i++)
    {
        asm("TBLRD *+");
        frame.data[i] = TABLAT;
    }
    return (9 + frame.data_length);           // 9 byte header + 4 bytes config words
}

// *****************************************************************************
// Write Config Words
//        Cmd     Length-----              Address---------------  Data ---------
// In:   [<0x07> <0x00><0x00><0x55><0xAA> <0x00><0x00><0x00><0x00> <Data>..<data>]
// OUT:  [<0x07> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00>]
// *****************************************************************************
uint8_t Write_Config ()
{
    TBLPTRL = frame.address_L;
    TBLPTRH = frame.address_H;
    TBLPTRU = frame.address_U;
    if (TBLPTR > 0x20000F)    
        EECON1 = 0xC4;       // Setup writes
    else
        EECON1 = 0x84;
    for (uint8_t  i= 0; i < frame.data_length; i ++)
    {
        TABLAT = frame.data[i];
        asm("TBLWT *");
        StartWrite();
        ++ TBLPTRL;
    }
    frame.data[0] = COMMAND_SUCCESS;
    EE_Key_1 = 0x00;  // erase EE Keys
    EE_Key_2 = 0x00;
    return (10);
}

// *****************************************************************************************
// Calculate Checksum
// In:	[<0x08><DataLengthL><DataLengthH> <unused><unused> <ADDRL><ADDRH><ADDRU><unused>...]
// OUT:	[9 byte header + ChecksumL + ChecksumH]
//        Cmd     Length-----              Address---------------  Data ---------
// In:   [<0x08> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00>]
// OUT:  [<0x08> <0x00><0x00><0x00><0x00> <0x00><0x00><0x00><0x00> <CheckSumL><CheckSumH>]
// *****************************************************************************
uint8_t Calc_Checksum()
{
#if END_FLASH > 0xFFFF
    uint24_t  i;
    uint24_t  length;
#else
    uint16_t  i;
    uint16_t  length;
#endif 

    TBLPTRL = frame.address_L;
    TBLPTRH = frame.address_H;
    TBLPTRU = frame.address_U;
    EECON1 = 0x80;
    check_sum = 0;
    length = frame.data_length;
#if END_FLASH > 0xFFFF
    length += ((uint24_t) frame.EE_key_1) << 16;
#endif 
    for (i = 0; i < length; i += 2)
    {
        asm("TBLRD *+");
        check_sum += (uint16_t)TABLAT;
        asm("TBLRD *+");
        check_sum += (uint16_t)TABLAT << 8;
     }
     frame.data[0] = (uint8_t) (check_sum & 0x00FF);
     frame.data[1] = (uint8_t)((check_sum & 0xFF00) >> 8);
     return (11);
}




// *****************************************************************************
// Unlock and start the write or erase sequence.
// *****************************************************************************
void StartWrite()
{
    EECON2 = EE_Key_1;
    EECON2 = EE_Key_2;
    EECON1bits.WR = 1;       // Start the write
    NOP();
    NOP();
    return;
}

// *****************************************************************************
// Check to see if a device reset had been requested.  We can't just reset when
// the reset command is issued.  Instead we have to wait until the acknowledgement
// is finished sending back to the host.  Then we reset the device.
// *****************************************************************************
void Check_Device_Reset ()
{
    if (reset_pending == true)
    {
        RESET();
    }
    return;
}

// *****************************************************************************
// *****************************************************************************
*/