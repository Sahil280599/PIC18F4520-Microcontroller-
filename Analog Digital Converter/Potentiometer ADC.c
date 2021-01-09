#include<xc.h>
#include<pic18f4520.h>

 

#define ldata PORTD
#define rs PORTEbits.RE2
#define en PORTEbits.RE1

 

void delay(int x)
{
  int i,j;
  for(i=0; i<= x;i++)
  {
      for (j=0;j<200;j++)
      ;
  }  
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
void lcdr(char d)
{
    TRISD = 0;
    delay(10);
    lcddata(d);
    TRISD = 255;
    delay(10);
}

void main(){
 int val; 
 char digit_thou, digit_hun, digit_ten, digit_one;
 TRISE = 0;
 TRISD = 0;
 lcdinit();
 ADCON0=0x00;
 ADCON1= 0x0D;
 ADCON2= 0x80;
 while(1){
     ADCON0 = 0;
     ADCON0bits.ADON =1;
     ADCON0bits.GODONE=1;
     while( ADCON0bits.GODONE==1);
     val = (ADRESH<<8)+ADRESL;
     val=val*(5000.0/1023.0);
     digit_thou = val/1000;
     digit_thou = digit_thou + 48;
     digit_hun = (val/100)%10;
     digit_hun = digit_hun + 48;
     digit_ten = (val/10)%10;
     digit_ten = digit_ten + 48;
     digit_one = val%10;
     digit_one = digit_one + 48;
     lcdcmd(0x80);
     lcddata(digit_thou);
     lcddata('.'); //mv daal dena agar mv me chaiye 
     lcddata(digit_hun);
     lcddata(digit_ten);
     lcddata(digit_one);
     lcddata('V');
     
     ADCON0 = 0x04;
     ADCON0bits.ADON =1;
     ADCON0bits.GODONE=1;
     while( ADCON0bits.GODONE==1);
     val = (ADRESH<<8)+ADRESL;
     val=val*(5000.0/1023.0); 
     digit_thou = val/1000 + 48;
     digit_hun = (val/100)%10 + 48;
     digit_ten = (val/10)%10 + 48;
     digit_one = val%10 + 48;
     lcdcmd(0xC0);
     lcddata(digit_thou);
     lcddata('.');
     lcddata(digit_hun);
     lcddata(digit_ten);
     lcddata(digit_one);
     lcddata('V');    
 }
}
