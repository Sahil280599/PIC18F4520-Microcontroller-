#include <xc.h>
#include <pic18f4520.h>

// calculation register value 
// time_delay=(65536-(TMR0H*256+TMR0L))*(4000000*pre_scalar/Fosc) //16bit
// time_delay=(256-TMR0L)*(4000000*pre_scalar/Fosc) // 8BIT
// pre_scalar=128 with 16 bit timer value as 0xB!e0

void t0_8bitdelay()
{
    T0CON=0x47;
    TMR0L=56;
    T0CONbits.TMR0ON=1;
    while(INTCONbits.TMR0IF==0);
    T0CONbits.TMR0ON=0;
    INTCONbits.TMR0IF=0;
}

void t0_16bitdelay()
{
    T0CON=0x02;
    TMR0H=0xB1;
    TMR0L=0xE0;
    T0CONbits.TMR0ON=1;
    while(INTCONbits.TMR0IF==0);
    T0CONbits.TMR0ON=0;
    INTCONbits.TMR0IF=0;
}

void main(void)
{
    TRISD=0x00;
    while(1)
    {
        LATDbits.LATD4^=1;
        t0_16bitdelay();
    }
}
