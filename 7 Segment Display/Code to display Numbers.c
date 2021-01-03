#include <xc.h>
#include <pic18f4520.h>
void delay()
{
    int j;
    for(j=0; j<=5000;j++)
    {}
}
unsigned char a[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main(void)
{
 int i;
 ADCON1 = 0xFF;
 TRISA = 0;
 TRISD = 0;
 LATA = 0xFF;
 while(1)
{
for(i=0;i<10;i++)
{
    LATD = a[i];
    delay();
}   
} 
}
