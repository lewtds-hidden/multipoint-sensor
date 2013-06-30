#ifndef _UART_
#define _UART_

#include <string.h>

void init_UART();
void sendchar_UART(char c[]);
void send_UART(unsigned char a);
void sendZ_UART(long int n);
void sendnum_UART(float x);

void init_UART()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;		// Toc do 19200 baud
	TL1=0x00;
	PCON=0x80; 	// Nhan doi toc do baud
	TR1=1;
}

void sendchr_UART(char c[])
{
	unsigned char i;
	for(i=0;i<strlen(c);i++) send_UART(c[i]);
}

void send_UART(unsigned char a)
{
            SBUF=a;
            while(TI==0){}
            TI=0;
}

void sendZ_UART(long int n)
{
	if(n<0)
	{
		send_UART('-');
		n=-n;
	}
	if(n==0) send_UART('0');
	else
	{
		unsigned char a[13];
		unsigned char i;
		for(i=0;n>0;i++)
    {
      a[i]=(n%10)+48;
      n=n/10;
    }
    a[i]='\0';                          
    for(i=strlen(a);i>0;i--) send_UART(a[i-1]);
	}
}

void sendnum_UART(float x)
{
  int pn, ptp;
	if(x<0)
	{
		send_UART('-');
		x=-x;
	}
	pn=x;
	ptp=x*100-pn*100;
	sendZ_UART(pn);
	send_UART('.');
	if (ptp==0) sendchr_UART("00");
	else
	{
		sendZ_UART(ptp);
	}
}

#endif