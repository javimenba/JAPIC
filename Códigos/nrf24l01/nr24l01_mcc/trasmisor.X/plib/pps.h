#ifndef __PPS_H
#define __PPS_H
/******************************************************************************
 // *                  PERIPHERAL PIN SELECT PERIPHERAL LIBRARY HEADER FILE
 ******************************************************************************
 * FileName:        		pps.h
 * Dependencies:    	See include below
 * Processor:       		PIC18
 * Compiler:        		MCC18
 * Company:         		Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *****************************************************************************/

#include <pconfig.h>

 
#if	defined (PPS_V1) || defined (PPS_V1_1) || defined (PPS_V2) || defined (PPS_V2_1) \
	|| defined (PPS_V3) || defined (PPS_V3_1)
#define IN_PIN_PPS_RP0				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP1				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP2				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP3				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RP4				4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP5				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP6				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP7				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP8				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP9				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP10				10  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP11				11  /* Assign RP11 as Input Pin */
#define IN_PIN_PPS_RP12				12  /* Assign RP12 as Input Pin */
#define IN_PIN_PPS_RP13				13  /* Assign RP13 as Input Pin */
#endif

#if	defined (PPS_V1_1) || defined (PPS_V2_1)
#define IN_PIN_PPS_RP14				14  /* Assign RP14 as Input Pin */
#define IN_PIN_PPS_RP15				15  /* Assign RP15 as Input Pin */
#define IN_PIN_PPS_RP16				16  /* Assign RP16 as Input Pin */
#endif

#if	defined (PPS_V1) || defined (PPS_V2) || defined (PPS_V2_1) || defined (PPS_V3_1)
#define IN_PIN_PPS_RP17				17  /* Assign RP17 as Input Pin */
#define IN_PIN_PPS_RP18				18  /* Assign RP18 as Input Pin */
#endif

#if	defined (PPS_V2) || defined (PPS_V2_1) || defined (PPS_V3_1)
#define IN_PIN_PPS_RP19				19  /* Assign RP19 as Input Pin */
#define IN_PIN_PPS_RP20				20  /* Assign RP20 as Input Pin */
#define IN_PIN_PPS_RP21				21  /* Assign RP21 as Input Pin */
#define IN_PIN_PPS_RP22				22  /* Assign RP22 as Input Pin */
#define IN_PIN_PPS_RP23				23  /* Assign RP23 as Input Pin */
#define IN_PIN_PPS_RP24				24  /* Assign RP24 as Input Pin */
#define IN_PIN_PPS_VSS				31  /* Input Pin tied to Vss */
#endif

#if	defined (PPS_V4)
/***********GROUP 4n ****************************/
#define IN_PIN_PPS_RP0				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP4				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP8				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP12				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RP16 			4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP20				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP24				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP28				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP32				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP36				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP40				0x0A  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP44				0x0B  /* Assign RP11 as Input Pin */

/***********GROUP (4n+1) ****************************/
#define IN_PIN_PPS_RP1				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP5				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP9				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP13				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RP17 			4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP21				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP25				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP29				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP33				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP37				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP41				0x0A  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP45				0x0B  /* Assign RP11 as Input Pin */

/***********GROUP (4n+2) ****************************/
#define IN_PIN_PPS_RP2				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP6				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP10				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP14				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RP18 			4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP22				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP26				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP30				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP34				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP38				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP42				0x0A  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP46				0x0B  /* Assign RP11 as Input Pin */

/***********GROUP (4n+3) ****************************/
#define IN_PIN_PPS_RP3				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP7				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP11				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP15				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RP19 			4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP23				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP27				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP31				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP35				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP39				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP43				0x0A  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP47				0x0B  /* Assign RP11 as Input Pin */
#endif

#if	defined (PPS_V1) || defined (PPS_V1_1) || defined (PPS_V2) || defined (PPS_V2_1) \
	|| defined (PPS_V3) || defined (PPS_V3_1)
#define IN_FN_PPS_INT1				RPINR1	/* Assign External Interrupt 1 (INTR1) to the corresponding RPn pin*/
#define IN_FN_PPS_INT2				RPINR2	/* Assign External Interrupt 2 (INTR2) to the corresponding RPn pin*/
#define IN_FN_PPS_INT3				RPINR3	/* Assign External Interrupt 3 (INTR3) to the corresponding RPn pin*/
#define IN_FN_PPS_T0CK				RPINR4	/* Assign Timer0 External Clock (T0CK) to the corresponding RPn pin*/
#define IN_FN_PPS_T3CK				RPINR6	/* Assign Timer3 External Clock (T3CK) to the corresponding RPn pin*/
#define IN_FN_PPS_IC1				RPINR7	/* Assign Input Capture 1 (IC1) to the corresponding RPn pin*/
#define IN_FN_PPS_IC2				RPINR8	/* Assign Input Capture 2 (IC2) to the corresponding RPn pin*/
#define IN_FN_PPS_T1G				RPINR12	/* Assign Timer1 External Gate Input (TG1) to the corresponding RPn pin*/
#define IN_FN_PPS_T3G				RPINR13	/* Assign Timer3 External Gate Input (TG3) to the corresponding RPn pin*/
#define IN_FN_PPS_RX2DT2			RPINR16 /* Assign EUSART2 Synchronous/Asynchronous Receive (RX2/DT2)  to the corresponding RPn pin*/
#define IN_FN_PPS_CK2				RPINR17	/* Assign EUSART2 Clock Input (CK2) to the corresponding RPn pin*/
#define IN_FN_PPS_SDI2				RPINR21	/* Assign SDI2 Data Input (SDI2) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK2IN			RPINR22	/* Assign SCK2 Clock Input (SCK2IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SS2IN				RPINR23	/* Assign SS2 Slave Select Input (SS2IN) to the corresponding RPn pin*/
#define IN_FN_PPS_FLT0				RPINR24	/* Assign PWM Fault Input (FLT0)  to the corresponding RPn pin*/

#if defined (PPS_V3) || defined (PPS_V3_1)
#define IN_FN_PPS_T5CK				RPINR15	/* Assign Timer5 External Clock (T5CK) to the corresponding RPn pin*/
#define IN_FN_PPS_IC3				RPINR9	/* Assign Input Capture 3 (IC3) to the corresponding RPn pin*/
#define IN_FN_PPS_T5G				RPINR14	/* Assign Timer5 External Gate Input (TG5) to the corresponding RPn pin*/
#endif

#endif


#if	defined (PPS_V4)
/***********GROUP 4n ****************************/
#define IN_FN_PPS_SDI1				RPINR8_9	/* Assign SDI1 Data input (SDI1) to the corresponding RPn pin*/
#define IN_FN_PPS_FLT0				RPINR14_15	/* Assign PWM Fault Input (FLT0) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC0				RPINR18_19	/* Assign Input Capture 1 (IOC0) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC4				RPINR22_23	/* Assign Input Capture 1 (IOC4) to the corresponding RPn pin*/
#define IN_FN_PPS_MDCIN1			RPINR30_31	/* Assign MDCIN1 to the corresponding RPn pin*/
#define IN_FN_PPS_T0CKI				RPINR38_39	/* Assign Timer0 External Clock (T0CKI) to the corresponding RPn pin*/
#define IN_FN_PPS_T5G				RPINR44_45	/* Assign Timer5 External Gate Input (T5G) to the corresponding RPn pin*/
#define IN_FN_PPS_U3RX				RPINR4_5	/* Assign EUSART3 Synchronous/Asynchronous Receive (RX3/DT3) to the corresponding RPn pin*/
#define IN_FN_PPS_U3RX				RPINR4_5	/* Assign EUSART3 Synchronous/Asynchronous Receive (RX3/DT3) to the corresponding RPn pin*/
#define IN_FN_PPS_U4RX				RPINR6_7	/* Assign EUSART4 Synchronous/Asynchronous Receive (RX4/DT4) to the corresponding RPn pin*/
#define IN_FN_PPS_CCP5				RPINR32_33 /* Assign CCP5  to the corresponding RPn pin*/
#define IN_FN_PPS_CCP8				RPINR36_37	/* Assign CCP8 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO0				RPINR46_47	/* Assign PBIO0 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO4				RPINR50_51	/* Assign PBIO4 to the corresponding RPn pin*/

/***********GROUP (4n+1) ****************************/
#define IN_FN_PPS_SDI2				RPINR12_13	/* Assign SDI1 Data input (SDI2) to the corresponding RPn pin*/
#define IN_FN_PPS_INT1				RPINR26_27	/* Assign External Interrupt 1 (INTR1) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC1				RPINR18_19	/* Assign Input Capture 1 (IOC1) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC5				RPINR22_23	/* Assign Input Capture 1 (IOC5) to the corresponding RPn pin*/
#define IN_FN_PPS_MDCIN2			RPINR30_31	/* Assign MDCIN2 to the corresponding RPn pin*/
#define IN_FN_PPS_T1CKI				RPINR40_41	/* Assign Timer1 External Clock (T1CKI) to the corresponding RPn pin*/
#define IN_FN_PPS_T1G				RPINR40_41	/* Assign Timer1 External Gate Input (T1G) to the corresponding RPn pin*/
#define IN_FN_PPS_T3CKI				RPINR42_43	/* Assign Timer3 External Clock (T3CKI) to the corresponding RPn pin*/
#define IN_FN_PPS_T3G				RPINR42_43	/* Assign Timer3 External Gate Input (T3G) to the corresponding RPn pin*/
#define IN_FN_PPS_T5CKI				RPINR44_45	/* Assign Timer5 External Clock (T5CKI) to the corresponding RPn pin*/
#define IN_FN_PPS_U3TX				RPINR4_5	/* Assign EUSART3 Synchronous/Asynchronous Transmit (TX3/DT3) to the corresponding RPn pin*/
#define IN_FN_PPS_U4TX				RPINR6_7	/* Assign EUSART4 Synchronous/Asynchronous Transmit (TX4/DT4) to the corresponding RPn pin*/
#define IN_FN_PPS_CCP7				RPINR34_35 /* Assign CCP7  to the corresponding RPn pin*/
#define IN_FN_PPS_CCP9				RPINR36_37	/* Assign CCP9 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO1				RPINR46_47	/* Assign PBIO1 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO5				RPINR50_51	/* Assign PBIO5 to the corresponding RPn pin*/

/***********GROUP (4n+2) ****************************/
#define IN_FN_PPS_SS1				RPINR10_11	/* Assign SS1 (SS1) to the corresponding RPn pin*/
#define IN_FN_PPS_INT2				RPINR26_27	/* Assign External Interrupt 2 (INTR2) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC2				RPINR20_21	/* Assign Input Capture 2 (IOC2) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC6				RPINR24_25	/* Assign Input Capture 6 (IOC6) to the corresponding RPn pin*/
#define IN_FN_PPS_MDMIN				RPINR28_29	/* Assign MDMIN to the corresponding RPn pin*/
#define IN_FN_PPS_U1TX				RPINR0_1	/* Assign EUSART1 Synchronous/Asynchronous Transmit (TX1/DT1) to the corresponding RPn pin*/
#define IN_FN_PPS_U2RX				RPINR2_3	/* Assign EUSART2 Synchronous/Asynchronous Receive (RX2/DT2) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK2				RPINR10_11	/* Assign SCK2 to the corresponding RPn pin*/
#define IN_FN_PPS_ECCP3				RPINR16_17  /* Assign ECCP3 to the corresponding RPn pin*/
#define IN_FN_PPS_CCP6				RPINR34_35  /* Assign CCP6  to the corresponding RPn pin*/
#define IN_FN_PPS_CCP10				RPINR38_39	/* Assign CCP10 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO2				RPINR48_49	/* Assign PBIO2 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO6				RPINR52_53	/* Assign PBIO6 to the corresponding RPn pin*/

/***********GROUP (4n+3) ****************************/
#define IN_FN_PPS_SS2				RPINR12_13	/* Assign SS2 (SS2) to the corresponding RPn pin*/
#define IN_FN_PPS_INT3				RPINR28_29	/* Assign External Interrupt 3 (INTR3) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC3				RPINR20_21	/* Assign Input Capture 3 (IOC3) to the corresponding RPn pin*/
#define IN_FN_PPS_IOC7				RPINR24_25	/* Assign Input Capture 7 (IOC7) to the corresponding RPn pin*/
#define IN_FN_PPS_U1RX				RPINR0_1	/* Assign EUSART1 Synchronous/Asynchronous Receive (RX1/DT1) to the corresponding RPn pin*/
#define IN_FN_PPS_U2TX				RPINR2_3	/* Assign EUSART2 Synchronous/Asynchronous Transmit (RX2/DT2) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK1				RPINR8_9	/* Assign SCK1 to the corresponding RPn pin*/
#define IN_FN_PPS_ECCP1				RPINR14_15  /* Assign ECCP1 to the corresponding RPn pin*/
#define IN_FN_PPS_ECCP2				RPINR16_17  /* Assign ECCP2  to the corresponding RPn pin*/
#define IN_FN_PPS_CCP4				RPINR32_33	/* Assign CCP4 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO3				RPINR48_49	/* Assign PBIO2 to the corresponding RPn pin*/
#define IN_FN_PPS_PBIO7				RPINR52_53	/* Assign PBIO6 to the corresponding RPn pin*/

#endif

/*********************************************************************
 Macro:          	iPPSInput(fn,pin)
 
 PreCondition:     None 
 
 Side Effects:     None
 
 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.
 
 Parameters:  	fn - function to be assigned for particular pin
			  * IN_FN_PPS_INT1
			  * IN_FN_PPS_INT2
			  * IN_FN_PPS_INT3
			  * IN_FN_PPS_T0CK
			  * IN_FN_PPS_T3CK
			  * IN_FN_PPS_IC1
			  * IN_FN_PPS_IC2
			  * IN_FN_PPS_T1G
			  * IN_FN_PPS_T3G
			  * IN_FN_PPS_RX2DT2
			  * IN_FN_PPS_CK2
			  * IN_FN_PPS_SDI2
			  * IN_FN_PPS_SCK2IN
			  * IN_FN_PPS_SS2IN
			  * IN_FN_PPS_FLT0
			  
			  For 47J53 Family
			  * IN_FN_PPS_T5CK
			  * IN_FN_PPS_IC3
			  * IN_FN_PPS_T5G
			  
			pin - pin number(x) for which functionality has to be assigned
			  * IN_PIN_PPS_RP0
			  * IN_PIN_PPS_RP1
			  * IN_PIN_PPS_RP2
			  * IN_PIN_PPS_RP3
			  * IN_PIN_PPS_RP4
			  * IN_PIN_PPS_RP5
			  * IN_PIN_PPS_RP6
			  * IN_PIN_PPS_RP7
			  * IN_PIN_PPS_RP8
			  * IN_PIN_PPS_RP9
			  * IN_PIN_PPS_RP10
			  * IN_PIN_PPS_RP11
			  * IN_PIN_PPS_RP12
			  * IN_PIN_PPS_RP13
			   
			   For V1_1 & V2_1
			  * IN_PIN_PPS_RP14
			  * IN_PIN_PPS_RP15
			  * IN_PIN_PPS_RP16

			  * IN_PIN_PPS_RP17
			  * IN_PIN_PPS_RP18
			  * IN_PIN_PPS_RP19
			  * IN_PIN_PPS_RP20
			  * IN_PIN_PPS_RP21
			  * IN_PIN_PPS_RP22
			  * IN_PIN_PPS_RP23
			  * IN_PIN_PPS_RP24
			  * IN_PIN_PPS_VSS
			
 Returns: 		None		
 
 Note:            	None
 ********************************************************************/
 
#define iPPSInput(fn,pin)		    fn=pin

/*********************************************************************
 Macro:          	PPSInput(fn,pin)
 
 PreCondition:     None 
 
 Side Effects:     None
 
 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.
 
 Parameters:  	fn - function to be assigned for particular pin
			  * PPS_INT1
			  * PPS_INT2
			  * PPS_INT3
			  * PPS_T0CK
			  * PPS_T3CK
			  * PPS_IC1
			  * PPS_IC2
			  * PPS_T1G
			  * PPS_T3G
			  * PPS_RX2DT2
			  * PPS_CK2
			  * PPS_SDI2
			  * PPS_SCK2IN
			  * PPS_SS2IN
			  * PPS_FLT0

			  For 47J53 Family
			  * PPS_T5CK
			  * PPS_IC3
			  * PPS_T5G
			  
			pin - pin number(x) for which functionality has to be assigned
			  * PPS_RP0
			  * PPS_RP1
			  * PPS_RP2
			  * PPS_RP3
			  * PPS_RP4
			  * PPS_RP5
			  * PPS_RP6
			  * PPS_RP7
			  * PPS_RP8
			  * PPS_RP9
			  * PPS_RP10
			  * PPS_RP11
			  * PPS_RP12
			  * PPS_RP13
			   
			   For V1_1 & V2_1
			  * PPS_RP14
			  * PPS_RP15
			  * PPS_RP16

			  * PPS_RP17
			  * PPS_RP18
			  * PPS_RP19
			  * PPS_RP20
			  * PPS_RP21
			  * PPS_RP22
			  * PPS_RP23
			  * PPS_RP24
			  * PPS_VSS
			
 Returns: 		None		
 
 Note:            	None
 ********************************************************************/
 
#define __mk_in_fn(fn)			IN_FN_##fn
#define __mk_in_pin(pin)		IN_PIN_##pin
#define PPSInput(fn,pin)	    	iPPSInput(__mk_in_fn(fn),__mk_in_pin(pin))

/*----------------------------------------------------------------------------------------------------*/
/*SEction:  Remappable Peripheral Outputs: 																	  */
/*----------------------------------------------------------------------------------------------------*/

#if	defined (PPS_V1) || defined (PPS_V2) || defined (PPS_V1_1) || defined (PPS_V2_1) \
	|| defined (PPS_V3) || defined (PPS_V3_1)
	
#define OUT_FN_PPS_NULL				 0  /* RPn tied to default port pin */
#define OUT_FN_PPS_C1OUT			 1  /* RPn tied to comparator 1 output */
#define OUT_FN_PPS_C2OUT			 2  /* RPn tied to comparator 2 output */
#define OUT_FN_PPS_ULPWU			13  /* RPn tied to Ultra Low Power Wake Up Event */
#define OUT_FN_PPS_CCP1P1A			14  /* RPn tied to ECCP1/CCP1 compare or PWM output channel A */
#define OUT_FN_PPS_P1B			    15  /* RPn tied to ECCP1 Enhanced PWM output, channel B */
#define OUT_FN_PPS_P1C			    16  /* RPn tied to ECCP1 Enhanced PWM output, channel C */
#define OUT_FN_PPS_P1D			    17  /* RPn tied to ECCP1 Enhanced PWM output, channel D */
#define OUT_FN_PPS_CCP2P2A			18  /* RPn tied to ECCP2/CCP2 compare or PWM output */
#define OUT_FN_PPS_P2B			    19  /* RPn tied to ECCP2 Enhanced PWM output, channel B */
#define OUT_FN_PPS_P2C			    20  /* RPn tied to ECCP2 Enhanced PWM output, channel C */
#define OUT_FN_PPS_P2D			    21  /* RPn tied to ECCP2 Enhanced PWM output, channel D */

#if	defined (PPS_V3) || defined (PPS_V3_1)
#define OUT_FN_PPS_C3OUT			 3  /* RPn tied to comparator 3 output */
#define OUT_FN_PPS_TX2CK2			 6  /* RPn tied to EUSART 2 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_DT2               7  /* RPn tied to EUSART 2 Synchronous Transmit*/
#define OUT_FN_PPS_SDO2				 10  /* RPn tied to SPI2 Data Output */
#define OUT_FN_PPS_SCK2 			11  /* RPn tied to SPI2 Clock Output */
#define OUT_FN_PPS_SSDMA			12  /* RPn tied to SPI DMA Slave Select */
#define OUT_FN_PPS_CCP3P3A			22  /* RPn tied to ECCP3/CCP3 compare or PWM output */
#define OUT_FN_PPS_P3B			    23  /* RPn tied to ECCP3 Enhanced PWM output, channel B */
#define OUT_FN_PPS_P3C			    24  /* RPn tied to ECCP3 Enhanced PWM output, channel C */
#define OUT_FN_PPS_P3D			    25  /* RPn tied to ECCP3 Enhanced PWM output, channel D */
#else
#define OUT_FN_PPS_TX2CK2			 5  /* RPn tied to EUSART 2 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_DT2               6  /* RPn tied to EUSART 2 Synchronous Transmit*/
#define OUT_FN_PPS_SDO2				 9  /* RPn tied to SPI2 Data Output */
#define OUT_FN_PPS_SCK2 			10  /* RPn tied to SPI2 Clock Output */
#define OUT_FN_PPS_SSDMA			12  /* RPn tied to SPI DMA Slave Select */
#endif


#if	defined (PPS_V4)
/***********GROUP 4n ****************************/
#define OUT_FN_PPS_U2BCLK				1  /* RPn tied to U2BCLK port pin */
#define OUT_FN_PPS_U3RX_DT			 	2  /* RPn tied to EUSART3 Synchronous/Asynchronous Receive (RX3/DT3) output */
#define OUT_FN_PPS_U4RX_DT			 	3  /* RPn tied to EUSART4 Synchronous/Asynchronous Receive (TRX4/DT4) output */
#define OUT_FN_PPS_SDO2					4  /* RPn tied to SPI2 Data Output */
#define OUT_FN_PPS_P1D					5  /* RPn tied to ECCP1 Enhanced PWM output, channel D */
#define OUT_FN_PPS_P2D			    	6  /* RPn tied to ECCP2 Enhanced PWM output, channel D */
#define OUT_FN_PPS_P3B			    	7  /* RPn tied to ECCP3 Enhanced PWM output, channel B */
#define OUT_FN_PPS_CTPLS			    8  /* RPn tied to CTPLS */
#define OUT_FN_PPS_CCP5					9  /* RPn tied to CCP5 compare or PWM output */
#define OUT_FN_PPS_CCP8			    	0x0A  /* RPn tied to CCP8 compare or PWM output */
#define OUT_FN_PPS_C1OUT			    0x0B  /* RPn tied to comparator 1 */
#define OUT_FN_PPS_PBIO0			    0x0D  /* RPn tied to PBIO0 */
#define OUT_FN_PPS_PBIO4			    0x0E  /* RPn tied to PBIO4 */

/***********GROUP (4n+1) ****************************/
#define OUT_FN_PPS_U1BCLK				1  /* RPn tied to U1BCLK port pin */
#define OUT_FN_PPS_U3TX_CK			 	2  /* RPn tied to EUSART3 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_U4TX_CK			 	3  /* RPn tied to EUSART4 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_SDO1					4  /* RPn tied to SPI1 Data Output */
#define OUT_FN_PPS_P1C					5  /* RPn tied to ECCP1 Enhanced PWM output, channel C */
#define OUT_FN_PPS_P2C			    	6  /* RPn tied to ECCP2 Enhanced PWM output, channel C */
#define OUT_FN_PPS_P3C			    	7  /* RPn tied to ECCP3 Enhanced PWM output, channel C */
#define OUT_FN_PPS_CCP7			    	8  /* RPn tied to CCP7 compare or PWM output */
#define OUT_FN_PPS_CCP9					9  /* RPn tied to CCP9 compare or PWM output */
#define OUT_FN_PPS_C2OUT			    0x0A  /* RPn tied to comparator 2 */
#define OUT_FN_PPS_PBIO1			    0x0D  /* RPn tied to PBIO1 */
#define OUT_FN_PPS_PBIO5			    0x0E  /* RPn tied to PBIO5 */

/***********GROUP (4n+2) ****************************/
#define OUT_FN_PPS_U1TX_CK			 	1  /* RPn tied to EUSART1 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_U2RX_DT			 	2  /* RPn tied to EUSART2 Synchronous/Asynchronous Receive (RX2/DT2) */
#define OUT_FN_PPS_U3BCLK				3  /* RPn tied to U3BCLK port pin */
#define OUT_FN_PPS_U4BCLK				4  /* RPn tied to U4BCLK port pin */
#define OUT_FN_PPS_SCK2					5  /* RPn tied to SPI2 Clock Output */
#define OUT_FN_PPS_P1B					6  /* RPn tied to ECCP1 Enhanced PWM output, channel B */
#define OUT_FN_PPS_P2B			    	7  /* RPn tied to ECCP2 Enhanced PWM output, channel B */
#define OUT_FN_PPS_ECCP3P3A			    8  /* RPn tied to ECCP3/CCP3 compare or PWM output */
#define OUT_FN_PPS_CCP6					9  /* RPn tied to CCP6 compare or PWM output */
#define OUT_FN_PPS_CCP10				0x0A  /* RPn tied to CCP10 compare or PWM output */
#define OUT_FN_PPS_PBIO2			    0x0D  /* RPn tied to PBIO2 */
#define OUT_FN_PPS_PBIO6			    0x0E  /* RPn tied to PBIO6 */

/***********GROUP (4n+3) ****************************/
#define OUT_FN_PPS_U1RX_DT			 	1  /* RPn tied to EUSART1 Synchronous/Asynchronous Receive (RX1/DT1) */
#define OUT_FN_PPS_U2TX_CK			 	2  /* RPn tied to EUSART2 Asynchronous Transmit / Asynchronous Clock Output */
#define OUT_FN_PPS_SCK1					3  /* RPn tied to SPI1 Clock Output */
#define OUT_FN_PPS_ECCP1P1A			    4  /* RPn tied to ECCP1/CCP1 compare or PWM output */
#define OUT_FN_PPS_ECCP2P2A			    5  /* RPn tied to ECCP2/CCP2 compare or PWM output */
#define OUT_FN_PPS_P3D					6  /* RPn tied to ECCP3 Enhanced PWM output, channel D */
#define OUT_FN_PPS_MDOUT				7  /* RPn tied to MDOUT port pin */
#define OUT_FN_PPS_CCP4					8  /* RPn tied to CCP4 compare or PWM output */
#define OUT_FN_PPS_C3OUT			    9  /* RPn tied to comparator 3 */
#define OUT_FN_PPS_PBIO3			    0x0D  /* RPn tied to PBIO3 */
#define OUT_FN_PPS_PBIO7			    0x0E  /* RPn tied to PBIO7 */
#endif


#define OUT_PIN_PPS_RP0				RPOR0	/* Assign RP0 as Output Pin */
#define OUT_PIN_PPS_RP1				RPOR1	/* Assign RP1 as Output Pin */
#define OUT_PIN_PPS_RP2				RPOR2	/* Assign RP2 as Output Pin */
#define OUT_PIN_PPS_RP3				RPOR3	/* Assign RP3 as Output Pin */
#define OUT_PIN_PPS_RP4				RPOR4	/* Assign RP4 as Output Pin */
#define OUT_PIN_PPS_RP5				RPOR5	/* Assign RP5 as Output Pin */
#define OUT_PIN_PPS_RP6				RPOR6	/* Assign RP6 as Output Pin */
#define OUT_PIN_PPS_RP7				RPOR7	/* Assign RP7 as Output Pin */
#define OUT_PIN_PPS_RP8				RPOR8	/* Assign RP8 as Output Pin */
#define OUT_PIN_PPS_RP9				RPOR9	/* Assign RP9 as Output Pin */
#define OUT_PIN_PPS_RP10			RPOR10	/* Assign RP10 as Output Pin */
#define OUT_PIN_PPS_RP11			RPOR11	/* Assign RP11 as Output Pin */
#define OUT_PIN_PPS_RP12			RPOR12	/* Assign RP12 as Output Pin */
#define OUT_PIN_PPS_RP13			RPOR13	/* Assign RP13 as Output Pin */
#if	defined (PPS_V1) || defined (PPS_V2) || defined (PPS_V1_1) || defined (PPS_V2_1)
#define OUT_PIN_PPS_RP14			RPOR14	/* Assign RP14 as Output Pin */
#define OUT_PIN_PPS_RP15			RPOR15	/* Assign RP15 as Output Pin */
#define OUT_PIN_PPS_RP16			RPOR16	/* Assign RP16 as Output Pin */
#endif
#define OUT_PIN_PPS_RP17			RPOR17	/* Assign RP17 as Output Pin */
#define OUT_PIN_PPS_RP18			RPOR18	/* Assign RP18 as Output Pin */

#endif
 
#if	defined (PPS_V2) || defined (PPS_V2_1) || defined (PPS_V3) || defined (PPS_V3_1)
#define OUT_PIN_PPS_RP19			RPOR19	/* Assign RP19 as Output Pin */
#define OUT_PIN_PPS_RP20			RPOR20	/* Assign RP20 as Output Pin */
#define OUT_PIN_PPS_RP21			RPOR21	/* Assign RP21 as Output Pin */
#define OUT_PIN_PPS_RP22			RPOR22	/* Assign RP22 as Output Pin */
#define OUT_PIN_PPS_RP23			RPOR23	/* Assign RP23 as Output Pin */
#define OUT_PIN_PPS_RP24			RPOR24	/* Assign RP24 as Output Pin */
#endif


#if	defined (PPS_V4)
/***********GROUP 4n ****************************/
#define OUT_PIN_PPS_RP0				RPOR0_1	/* Assign RP0 as Output Pin */
#define OUT_PIN_PPS_RP4				RPOR4_5	/* Assign RP4 as Output Pin */
#define OUT_PIN_PPS_RP8				RPOR8_9	/* Assign RP8 as Output Pin */
#define OUT_PIN_PPS_RP12			RPOR12_13	/* Assign RP12 as Output Pin */
#define OUT_PIN_PPS_RP16			RPOR16_17	/* Assign RP16 as Output Pin */
#define OUT_PIN_PPS_RP20			RPOR20_21	/* Assign RP20 as Output Pin */
#define OUT_PIN_PPS_RP24			RPOR24_25	/* Assign RP24 as Output Pin */
#define OUT_PIN_PPS_RP28			RPOR28_29	/* Assign RP28 as Output Pin */
#define OUT_PIN_PPS_RP32			RPOR32_33	/* Assign RP32 as Output Pin */
#define OUT_PIN_PPS_RP36			RPOR36_37	/* Assign RP36 as Output Pin */
#define OUT_PIN_PPS_RP40			RPOR40_41	/* Assign RP40 as Output Pin */
#define OUT_PIN_PPS_RP44			RPOR44_45	/* Assign RP44 as Output Pin */

/***********GROUP (4n+1) ****************************/
#define OUT_PIN_PPS_RP1				RPOR0_1	/* Assign RP1 as Output Pin */
#define OUT_PIN_PPS_RP5				RPOR4_5	/* Assign RP5 as Output Pin */
#define OUT_PIN_PPS_RP9				RPOR8_9	/* Assign RP9 as Output Pin */
#define OUT_PIN_PPS_RP13			RPOR12_13	/* Assign RP13 as Output Pin */
#define OUT_PIN_PPS_RP17			RPOR16_17	/* Assign RP17 as Output Pin */
#define OUT_PIN_PPS_RP21			RPOR20_21	/* Assign RP21 as Output Pin */
#define OUT_PIN_PPS_RP25			RPOR24_25	/* Assign RP25 as Output Pin */
#define OUT_PIN_PPS_RP29			RPOR28_29	/* Assign RP29 as Output Pin */
#define OUT_PIN_PPS_RP33			RPOR32_33	/* Assign RP33 as Output Pin */
#define OUT_PIN_PPS_RP37			RPOR36_37	/* Assign RP37 as Output Pin */
#define OUT_PIN_PPS_RP41			RPOR40_41	/* Assign RP41 as Output Pin */
#define OUT_PIN_PPS_RP45			RPOR44_45	/* Assign RP45 as Output Pin */

/***********GROUP (4n+2) ****************************/
#define OUT_PIN_PPS_RP2				RPOR2_3	/* Assign RP2 as Output Pin */
#define OUT_PIN_PPS_RP6				RPOR6_7	/* Assign RP6 as Output Pin */
#define OUT_PIN_PPS_RP10			RPOR10_11	/* Assign RP10 as Output Pin */
#define OUT_PIN_PPS_RP14			RPOR14_15	/* Assign RP14 as Output Pin */
#define OUT_PIN_PPS_RP18			RPOR18_19	/* Assign RP18 as Output Pin */
#define OUT_PIN_PPS_RP22			RPOR22_23	/* Assign RP22 as Output Pin */
#define OUT_PIN_PPS_RP26			RPOR26_27	/* Assign RP26 as Output Pin */
#define OUT_PIN_PPS_RP30			RPOR30_31	/* Assign RP30 as Output Pin */
#define OUT_PIN_PPS_RP34			RPOR34_35	/* Assign RP34 as Output Pin */
#define OUT_PIN_PPS_RP38			RPOR38_39	/* Assign RP38 as Output Pin */
#define OUT_PIN_PPS_RP42			RPOR42_43	/* Assign RP42 as Output Pin */
#define OUT_PIN_PPS_RP46			RPOR46	/* Assign RP46 as Output Pin */

/***********GROUP (4n+3) ****************************/
#define OUT_PIN_PPS_RP3				RPOR2_3	/* Assign RP3 as Output Pin */
#define OUT_PIN_PPS_RP7				RPOR6_7	/* Assign RP7 as Output Pin */
#define OUT_PIN_PPS_RP11			RPOR10_11	/* Assign RP11 as Output Pin */
#define OUT_PIN_PPS_RP15			RPOR14_15	/* Assign RP15 as Output Pin */
#define OUT_PIN_PPS_RP19			RPOR18_19	/* Assign RP19 as Output Pin */
#define OUT_PIN_PPS_RP23			RPOR22_23	/* Assign RP23 as Output Pin */
#define OUT_PIN_PPS_RP27			RPOR26_27	/* Assign RP27 as Output Pin */
#define OUT_PIN_PPS_RP31			RPOR30_31	/* Assign RP31 as Output Pin */
#define OUT_PIN_PPS_RP35			RPOR34_35	/* Assign RP35 as Output Pin */
#define OUT_PIN_PPS_RP39			RPOR38_39	/* Assign RP39 as Output Pin */
#define OUT_PIN_PPS_RP43			RPOR42_43	/* Assign RP43 as Output Pin */
#endif

/*********************************************************************
  Macro:          	iPPSOutput(pin,fn)
 
  PreCondition:     None 
 
  Side Effects:     None
 
  Overview:          The macro assigns given pin as output pin by configuring register RPORx.
 
  Parameters:  	fn - function to be assigned for particular pin
			  * OUT_FN_PPS_NULL
			  * OUT_FN_PPS_C1OUT
			  * OUT_FN_PPS_C2OUT
			  * OUT_FN_PPS_TX2CK2
			  * OUT_FN_PPS_DT2
			  * OUT_FN_PPS_SDO2
			  * OUT_FN_PPS_SCK2
			  * OUT_FN_PPS_SSDMA
			  * OUT_FN_PPS_ULPWU
			  * OUT_FN_PPS_CCP1P1A
			  * OUT_FN_PPS_P1B
			  * OUT_FN_PPS_P1C
			  * OUT_FN_PPS_P1D
			  * OUT_FN_PPS_CCP2P2A
			  * OUT_FN_PPS_P2B
			  * OUT_FN_PPS_P2C
			  * OUT_FN_PPS_P2D
			  
			  For 47J53 Family
			  * OUT_FN_PPS_CCP3P3A
			  * OUT_FN_PPS_P3B
			  * OUT_FN_PPS_P3C
			  * OUT_FN_PPS_P3D
			  
			pin - pin number(x) for which functionality has to be assigned
			  * OUT_PIN_PPS_RP0
			  * OUT_PIN_PPS_RP1
			  * OUT_PIN_PPS_RP2
			  * OUT_PIN_PPS_RP3
			  * OUT_PIN_PPS_RP4
			  * OUT_PIN_PPS_RP5
			  * OUT_PIN_PPS_RP6
			  * OUT_PIN_PPS_RP7
			  * OUT_PIN_PPS_RP8
			  * OUT_PIN_PPS_RP9
			  * OUT_PIN_PPS_RP10
			  * OUT_PIN_PPS_RP11
			  * OUT_PIN_PPS_RP12
			  * OUT_PIN_PPS_RP13
			  * OUT_PIN_PPS_RP14
			  * OUT_PIN_PPS_RP15
			  * OUT_PIN_PPS_RP16
			  * OUT_PIN_PPS_RP17
			  * OUT_PIN_PPS_RP18
			  V2,V2_1,V3 & V3_1
			  * OUT_PIN_PPS_RP19
			  * OUT_PIN_PPS_RP20
			  * OUT_PIN_PPS_RP21
			  * OUT_PIN_PPS_RP22
			  * OUT_PIN_PPS_RP23
			  * OUT_PIN_PPS_RP24			  
			
  Returns: 		None		
 
  Note:            	None
 ********************************************************************/
 
#define iPPSOutput(pin,fn)		    pin=fn

/*********************************************************************
  Macro:          	PPSOutput(pin,fn)
 
  PreCondition:     None 
 
  Side Effects:     None
 
  Overview:          The macro assigns given pin as output pin by configuring register RPORx.
 
  Parameters:  	fn - function to be assigned for particular pin
			  * PPS_NULL
			  * PPS_C1OUT
			  * PPS_C2OUT
			  * PPS_TX2CK2
			  * PPS_DT2
			  * PPS_SDO2
			  * PPS_SCK2
			  * PPS_SSDMA
			  * PPS_ULPWU
			  * PPS_CCP1P1A
			  * PPS_P1B
			  * PPS_P1C
			  * PPS_P1D
			  * PPS_CCP2P2A
			  * PPS_P2B
			  * PPS_P2C
			  * PPS_P2D
			  
			  For 47J53 Family
			  * PPS_CCP3P3A
			  * PPS_P3B
			  * PPS_P3C
			  * PPS_P3D			
			
			pin - pin number(x) for which functionality has to be assigned
			  * PPS_RP0
			  * PPS_RP1
			  * PPS_RP2
			  * PPS_RP3
			  * PPS_RP4
			  * PPS_RP5
			  * PPS_RP6
			  * PPS_RP7
			  * PPS_RP8
			  * PPS_RP9
			  * PPS_RP10
			  * PPS_RP11
			  * PPS_RP12
			  * PPS_RP13
			  * PPS_RP14
			  * PPS_RP15
			  * PPS_RP16
			  * PPS_RP17
			  * PPS_RP18
			  V2,V2_1,V3,V3_1
			  * PPS_RP19
			  * PPS_RP20
			  * PPS_RP21
			  * PPS_RP22
			  * PPS_RP23
			  * PPS_RP24			  
			
  Returns: 		None		
 
  Note:            	None
 ********************************************************************/
 
#define __mk_out_fn(fn)			OUT_FN_##fn
#define __mk_out_pin(pin)		OUT_PIN_##pin
#define PPSOutput(pin,fn)		    iPPSOutput(__mk_out_pin(pin),__mk_out_fn(fn))


#if	defined (PPS_V4)
/*********************************************************************
  Macro:          	PPSUnLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
 ********************************************************************/
#define  PPSUnLock()  				(OSCCON2bits.IOLOCK=0)

/*********************************************************************
  Macro:          	PPSLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
 ********************************************************************/
#define  PPSLock() 					(OSCCON2bits.IOLOCK=1)

#else
/*********************************************************************
  Macro:          	PPSUnLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
 ********************************************************************/
#define  PPSUnLock()  				{EECON2 = 0b01010101; EECON2 = 0b10101010; PPSCONbits.IOLOCK = 0;}

/*********************************************************************
  Macro:          	PPSLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
 ********************************************************************/
#define  PPSLock() 					{EECON2 = 0b01010101; EECON2 = 0b10101010; PPSCONbits.IOLOCK = 1;}

#endif

#endif /*__PPS_H */
