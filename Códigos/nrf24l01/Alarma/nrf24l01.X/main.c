/*
 * File:   main.c
 * Author: francisco
 *
 * Created on July 16, 2019, 1:51 PM
 */



/*
//sbit IRQ at PORTB.B0;   //Pin de Interrupción utilizado activado por el RF cuando se transmite un dato
#define CE PORTBbits.RB5  //Chip Eneable, Activa RX mode o TX mode (sbit CE  at PORTB.B3;)
#define CSN PORTBbits.RB4  //Chip Select, utilizado para mandar cualquier comando. Se activa pasando de un estado alto a uno bajo. Luego se pone en alto de nuevo
//sbit CSN at PORTB.B5;
//#define CE   PORTB.B3  //sbit CE  at PORTB.B3;   //Chip Eneable, Activa RX mode o TX mode
//#define CSN  PORTB.B5  //sbit CSN at PORTB.B5;   //Chip Select, utilizado para mandar cualquier comando. Se activa pasando de un estado alto a uno bajo. Luego se pone en alto de nuevo

///////////////////////////////////COMANDOS
#define R_REGISTER          0b00000000
#define W_REGISTER          0b00100000
#define R_RX_PAYLOAD        0b01100001
#define W_TX_PAYLOAD        0b10100000
#define FLUSH_TX            0b11100001
#define FLUSH_RX            0b11100010
#define REUSE_TX_PL         0b11100011
#define ACTIVATE            0b01010000    //followed by 0x73 activa R_RX_PL_WID ,  W_ACK_PAYLOAD , and W_TX_PAYLOAD_NOACK  features registers
#define R_RX_PL_WIDa        0b01100000
#define W_ACK_PAYLOAD       0b10101000    //Para escribir Payloads a mandar con el Acknowledge
#define W_TX_PAYLOAD_NO     0b1011000     //Desactiva la función AUTOACK
#define NOP                 0b11111111    //No operation. Se usa para leer el registro STATUS


///////////////////////////////////DIRECCIONES
#define CONFIG             0x00            //Dirección del registro CONFIG del nRF24L01
#define EN_AA              0x01             //Dirección del registro Para activar el Auto Acknowledgment del nRF24L01
#define EN_RXADDR          0x02         //Dirección del registro para activar los Pipes (registro de almacenamiento de la data recibida)
#define SETUP_AW           0x03          //Dirección del registro para determinar el tamaño de bytes para las direcciones de los pipes
#define SETUP_RETR         0x04        //Dirección del registro para configurar la Retransmisión Automática
#define RF_CH              0x05             //Para definir el canal de RF a usar
#define RF_SETUP           0x06          //SETUP del RF
#define STATUS             0x07            //Registro STATUS DEL RF
#define OBSERVE_TX         0x08
#define RPD                0x09
#define RX_ADDR_P0         0x0A        //Receive address data pipe 0. RESET VALUE: 0xE7E7E7E7E7
#define TX_ADDR            0x10           //Transmit address. Used for a PTX device only. RESET VALUE: 0xE7E7E7E7E7
#define RX_PW_P0           0x11          //Payload with

#define FIFO_STATUS        0x17


void RF_WRITE_ARRAY(unsigned short direccion, unsigned short num_dat, unsigned short dato[32]);
unsigned int RF_READ_ARRAY(unsigned short direccion, unsigned short num_dat);
void RF_WRITE_BYTE(unsigned short direccion, unsigned short dato);
unsigned short RF_READ_BYTE(unsigned short direccion);
unsigned short RF_READ_BYTE_RX();
void ini_RF_RX();
void ini_RF_TX();
void TRANSMITE_BYTE_RF_TX(unsigned short dato);


void main(void) { 
    OSCCON = 0x52;
    OSCCON2 = 0x00;
    OSCTUNE = 0x00;
    ACTCON = 0x00;
    PORTA=0;
    TRISA=0;
    ANSELA=0;

    while(1)
    {
      ini_RF_TX();
      RF_WRITE_ARRAY(0x00,10,"hola");
    LED=1;
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    LED=0;
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);
    __delay_ms(100);  
         
   
    
    }
  
    
    return;
}




unsigned short dir=0;
int dn;              //Variable utilizada para el número de datos que se van a atransmitir en el comando
void RF_WRITE_ARRAY(unsigned short direccion, unsigned short num_dat, unsigned short dato[32]){   //FUNCIÓN PARA LA ESCRITURA DE UNA LOCALIDAD DEL nRF24L01. FORMATO:  DIRECCIÓN (EN HEX),  NÚMERO DE BYTES DE DATOS A TRANSMITIR (EN ENTEROS), ARRAY DE BYTES A TRANSMITIR//
          dir=W_REGISTER+direccion;
          __delay_us(2);
          CSN=0;             //Comienza el envío de comando
          __delay_us(2);
          WriteSPI(dir);  //Se manda el comando con la dirección Vía SPI
          for(dn=1;dn<=num_dat;dn++){
           __delay_us(1);
           WriteSPI(dato[dn]); //Se manda el dato deseado
//
//}
}
          __delay_us(2);
          CSN=1;                //Transmisión de datos y comando Finalziada
//
}
unsigned short dummy=0b01010101; //Dummy data para generación del sck para lectura mediante SPI
unsigned short dir0=0;
int dn1;              //Variable utilizada para el número de datos que se van a atransmitir en el comando
unsigned int RF_READ_ARRAY(unsigned short direccion, unsigned short num_dat){   //FUNCIÓN PARA LA ESCRITURA DE UNA LOCALIDAD DEL nRF24L01. FORMATO:  DIRECCIÓN (EN HEX),  NÚMERO DE BYTES DE DATOS A TRANSMITIR (EN ENTEROS), ARRAY DE BYTES A TRANSMITIR//
         unsigned short datRead[32];
         dir0=R_REGISTER+direccion;
         __delay_us(2);
         CSN=0;             //Comienza el envío de comando
         __delay_us(2);
         WriteSPI(dir0);  //Se manda el comando con la dirección Vía SPI
         for(dn=1;dn<=num_dat;dn1++){
          __delay_us(1);
         // datRead[dn1]=ReadSPI(NOP);
          datRead[dn1]=WriteSPI(NOP);
          datRead[dn1]=ReadSPI();

}
         __delay_us(2);
         CSN=1;                //Transmisión de datos y comando Finalziada
         return datRead;
//
}


unsigned short dir1=0,stat=0;
void RF_WRITE_BYTE(unsigned short direccion, unsigned short dato){
         dir1=direccion+W_REGISTER;
         
                __delay_us(2);
                CSN=0;              //Comienza el envío de comando
                __delay_us(2);
                //stat=ReadSPI(dir1);   //Se manda el comando con la dirección Vía SPI
                stat=WriteSPI(dir1);
                __delay_us(5);
                stat=ReadSPI();
                __delay_us(1);
                WriteSPI(dato);   //Se manda el dato deseado
                __delay_us(2);
                CSN=1;               //Transmisión de datos y comando Finalziada
}
unsigned short dir2=0;

unsigned short BYTE_RX=0;  //Byte recibido

unsigned short RF_READ_BYTE(unsigned short direccion){  ///////////FUNCION para LEER UN REGISTRO DEL RF, REGRESA UN BYTE
                 dir2=R_REGISTER+direccion;
                 CSN=0;              //Comienza el envío del comando
                 WriteSPI(dir2);
                 //BYTE_RX=ReadSPI(dummy);
                 BYTE_RX=WriteSPI(dummy);
                 __delay_us(5);
                 BYTE_RX=ReadSPI();
                 CSN=1;
                 return BYTE_RX;
//
}
unsigned short dir3=0;
unsigned short BYTE_RECIBIDO=0;

unsigned short RF_READ_BYTE_RX(){
                 __delay_us(2);
                 CSN=0;              //Comienza el envío de comando
                 __delay_us(2);
                 WriteSPI(R_RX_PAYLOAD);   //Se manda el comando con la dirección Vía SPI
                 __delay_us(1);
                // BYTE_RECIBIDO=ReadSPI(dummy);
                 BYTE_RECIBIDO=WriteSPI(dummy);
                 __delay_us(5);
                 BYTE_RECIBIDO=ReadSPI();
                 __delay_us(2);
                 CSN=1;
                 return BYTE_RECIBIDO;
//
}

unsigned short TX_ADDRES[6]={0xE7,0xE7,0xE7,0xE7,0xE7,0xE7};
void ini_RF_RX(){     //***********FUNCION DE INICIALIZACIÓN DEL MÓDULO RF
    PORTA=0;
    TRISA=0;
 RF_WRITE_BYTE(SETUP_AW,0b00000011);    //Pone a 5 el ancho del campo de direccion
 RF_WRITE_ARRAY(RX_ADDR_P0,5,TX_ADDRES);

 RF_WRITE_BYTE(EN_RXADDR,0b00000001);   //ACTIVA sólo el conducto 1
 RF_WRITE_BYTE(EN_AA,0b00000001);     //Activa los auto ACK para cada conducto (pipe)            0b00000000
 RF_WRITE_BYTE(RX_PW_P0,0b00000001);   //Número de bytes en RX payload en el conducto 0 = 1
 RF_WRITE_BYTE(RF_CH,1);      //Canal 1
 RF_WRITE_BYTE(RF_SETUP,0b00100110);   //Configura a 250Kbps y 0dBm  //0b00100110  , 2Mbps, 0dBm  0b00001110 , 1Mbps, 0dBm 0b00000110
 RF_WRITE_BYTE(CONFIG,0b00111111);     //CONFIGURA EL RF COMO RECEPTOR      //Interrupción por RX_DR    0b00111111
 WriteSPI(FLUSH_TX);
 WriteSPI(FLUSH_RX);

   __delay_us(150);
   LED=0;
   __delay_ms(50);
   LED=1;
   __delay_ms(50);
   LED=0;
   __delay_ms(50);
   LED=1;
   __delay_ms(50);
   LED=0;
}

void ini_RF_TX(){     //FUNCION DE INICIALIZACIÓN DEL MÓDULO RF
   PORTA=0;
   TRISA=0;
   ANSELA=0;
   RF_WRITE_BYTE(SETUP_AW,0b00000011);    //Pone a 5 el ancho del campo de direccion
   RF_WRITE_ARRAY(TX_ADDR,5,TX_ADDRES);
   RF_WRITE_ARRAY(RX_ADDR_P0,5,TX_ADDRES);
   RF_WRITE_BYTE(EN_AA,0b00000001);     //Activa los auto ACK para cada conducto (pipe)
   RF_WRITE_BYTE(EN_RXADDR,0b00000001);   //ACTIVA sólo el conducto 1
   RF_WRITE_BYTE(SETUP_RETR,0x1A);  //0b00010011 Delay defined from end of transmission to start of next transmission, con retransmisión hasta 3 veces
   RF_WRITE_BYTE(RF_CH,1);      //Canal 1
   RF_WRITE_BYTE(RF_SETUP,0b00100110);   //Configura a 250Kbps y 0dBm
   RF_WRITE_BYTE(CONFIG,0b01001110);     //CONFIGURA EL RF COMO TRANSMISOR 0b01011110
   WriteSPI(FLUSH_TX);
   WriteSPI(FLUSH_RX);
  
   __delay_ms(100);
   LED=0;
   __delay_ms(100);
   LED=1;
   __delay_ms(100);
   LED=0;
   __delay_ms(100);
   LED=1;
   __delay_ms(100);
   LED=0;

}

void TRANSMITE_BYTE_RF_TX(unsigned short dato){
     
      RF_WRITE_BYTE(STATUS,0x70); // BORRA INTERRUPT DEL RF
      INTCONbits.GIE=0; //DESACTIVA INTERRUPT
      __delay_us(2);
                 CSN=0;              //Comienza el envío de comando
                __delay_us(2);
                //stat= ReadSPI(W_TX_PAYLOAD);   //Se manda el comando con la dirección Vía SPI
                stat= WriteSPI(W_TX_PAYLOAD);
                __delay_us(5);
                stat= ReadSPI();
                __delay_us(1);
                WriteSPI(dato);   //Se manda el dato deseado
                __delay_us(2);
                CSN=1;               //Transmisión de datos y comando Finalziada
                __delay_us(10);
       INTCONbits.GIE=1; //ACTIVA LAS INTERRUPT
                CE=1;                                 //PULSO
                __delay_us(150);                        //QUE COMIENZA
                CE=0;                                 //CON LA TRANSMISIÓN

//
}*/

#include <xc.h>
#include "inicio.h"
#include "config.h"
#include "sensor.h"






void main(void) {
    
    Initialize();
    __delay_ms(100);
    Ini_nRF();
    __delay_ms(100);
    Notificacion();
    TXmod_nRF();
    Notificacion();
    

    while(1)
    {
     Write_Char_nRF('a');
     delay_1s();
     Notificacion();
    }
    return;
}
