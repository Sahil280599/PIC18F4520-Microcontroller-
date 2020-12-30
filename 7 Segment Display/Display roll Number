#include <xc.h>
#include <pic18f4520.h>
void delay()
{
    int j;
    for(j=0; j<=10;j++)
    {}
}
void main(void)
{
 int i;
 ADCON1 = 0xFF;
 TRISA = 0;
 TRISD = 0;
 LATA = 0xff;
 while(1)
 {
     LATA = 0;
     LATA2 = 1;
     LATD = 0x4f;
     delay();
     LATA = 0;
     LATA3 = 1;
     LATD = 0x3f;
     delay();
     LATA = 0;
     LATA4 = 1;
     LATD = 0x5b;
     delay();
     LATA = 0;
     LATA5 = 1;
     LATD = 0x07;
     delay();
 }
