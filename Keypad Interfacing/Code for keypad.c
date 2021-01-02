#include<xc.h>
#include<pic18f4520.h>

#define ldata PORTD
#define rs PORTEbits.RE2
#define en PORTEbits.RE1

#define COL1 PORTBbits.RB0
#define COL2 PORTBbits.RB1
#define COL3 PORTBbits.RB2

#define ROW1 PORTDbits.RD3
#define ROW2 PORTDbits.RD2
#define ROW3 PORTDbits.RD1
#define ROW4 PORTDbits.RD0

#define R1C1 '1'
#define R1C2 '2'
#define R1C3 '3'

#define R2C1 '4'
#define R2C2 '5'
#define R2C3 '6'

#define R3C1 '7'
#define R3C2 '8'
#define R3C3 '9'

#define R4C1 '*'
#define R4C2 '0'
#define R4C3 '#'

void delay(unsigned int value)
{
    int i,j;
    for(i=0;i<=value;i++)
    for(j=0;j<=50;j++);
}

void lcdcmd(unsigned char value)
{
    LATD=value;
    rs=0;
    en=1;
    delay(1);
    en=0;
}

void lcddata(unsigned char value)
{
    LATD=value;
    rs=1;
    en=1;
    delay(1);
    en=0;
}

void lcdinit(void)
{
    lcdcmd(0x38);
    delay(1);
    lcdcmd(0x0E);
    delay(1);
    lcdcmd(0x001);
    delay(1);
    lcdcmd(0x06);
    delay(1);
}

void lcddisplay(int row,unsigned char *str)
{
    int k;
    if(row==1)
    lcdcmd(0x80);
    else lcdcmd(0xC0);
    for(k=0;k<16;k++)
    {
        if(str[k] !=0)
        lcddata(str[k]);
        else break;
    }
    while((k<16)){
        lcddata(' ');
        k++;
    }
}

void lcdr(char c)
{
    TRISD = 0;
    delay(10);
    lcddata(c);
    TRISD = 255;
    delay(10);
}

void main()
{
    ADCON1 = 0x06;
    TRISE = 0;
    TRISD = 0;
    lcdinit();
    
    TRISB =0;
    TRISD = 255;
    PORTB = 255;
    PORTD = 255;
    TRISD = 255;
    
    do
    {
        PORTB = 255;
        delay(10);
        COL1 = 0;
        delay(10);
        if(ROW1 == 0)lcdr(R1C1);
        if(ROW2 == 0)lcdr(R2C1);
        if(ROW3 == 0)lcdr(R3C1);
        if(ROW4 == 0)lcdr(R4C1);
        COL1 = 1;
        
        delay(10);
        
        COL2 = 0;
        delay(10);
        if(ROW1 == 0)lcdr(R1C2);
        if(ROW2 == 0)lcdr(R2C2);
        if(ROW3 == 0)lcdr(R3C2);
        if(ROW4 == 0)lcdr(R4C2);
        COL2 = 1;
        
        delay(10);
        
        COL3 = 0;
        delay(10);
        if(ROW1 == 0)lcdr(R1C3);
        if(ROW2 == 0)lcdr(R2C3);
        if(ROW3 == 0)lcdr(R3C3);
        if(ROW4 == 0)lcdr(R4C3);
        COL3 = 1;
        
        delay(10);
    }while(1);
}
