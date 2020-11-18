
#ifndef LCD_LIB_H
#define LCD_LIB_H

#define LCD_RS PORTDbits.RD0
#define LCD_RW PORTDbits.RD1
#define LCD_EN PORTDbits.RD3
#define LCD_D4 PORTDbits.RD4
#define LCD_D5 PORTDbits.RD5
#define LCD_D6 PORTDbits.RD6
#define LCD_D7 PORTDbits.RD7
#define _XTAL_FREQ 4000000

void Lcd_Port(char a)
{
    if(a & 1)
        LCD_D4 = 1;
    else 
        LCD_D4 = 0;
    
    if(a & 2)
        LCD_D5 = 1;
    else 
        LCD_D5 = 0;
    
    if(a & 4)
        LCD_D6 = 1;
    else 
        LCD_D6= 0;
    if(a & 8)
        LCD_D7 = 1;
    else 
        LCD_D7 = 0;
}

void Lcd_Cmd(char a)
{
    LCD_RS = 0;
    LCD_RW = 0;
    Lcd_Port(a);
    LCD_EN =1;
    __delay_ms(4);
    LCD_EN=0;
        
}

void Lcd_clear(void){
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(unsigned char a, unsigned char b)
{
    unsigned char temp,z,y;
    if(a == 1){
        temp = 0x80 + b -1;
        z = temp >> 4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
    else if (a == 2)
    {
        temp = 0xC0 + b -1;
        z = temp >> 4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
}

void Lcd_Init(){
    
    Lcd_Port(0x00);
    __delay_ms(20);
    Lcd_Port(0x03);
    __delay_ms(5);
    Lcd_Port(0x03);
    __delay_ms(11);
    Lcd_Port(0x03);
    ///////////////
    Lcd_Port(0x02);
    Lcd_Port(0x02);
    Lcd_Port(0x08);
    Lcd_Port(0x00);
    Lcd_Port(0x0C);
    Lcd_Port(0x00);
    Lcd_Port(0x06);
    
     
}

void Lcd_Write_char(char a){
    
    char temp, y;
    temp = a & 0xF0;
    y = a & 0xF0;
    LCD_RS = 1;
    Lcd_Port( y >> 4);
    LCD_EN = 1;
    __delay_us(40);
    LCD_EN=0;
    Lcd_Port(temp);
    LCD_EN = 1;
    __delay_us(40);
    LCD_EN = 0;
}

void Lcd_Write_String(const char *a){
    
    int i;
    for(i=0; a[i]!='\0' ;i++){
        Lcd_Write_char(a[i]);
    }
    
}

void Lcd_Shift_Right(){
    
        Lcd_Cmd(0x01);
        Lcd_Cmd(0x0C);
        
    }

void Lcd_Shift_Left(){
    
        Lcd_Cmd(0x01);
        Lcd_Cmd(0x08);
        
    }

#endif