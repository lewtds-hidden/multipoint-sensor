//////////////////////////////////////////////////////////////////////////////////////
// Delay mili giay, dung timer0, che do 16 bit, tuong thich voi thach anh 11.0592MHz //
// Created by TuanLa 24/6/2013																											//
//////////////////////////////////////////////////////////////////////////////////////
#include "delay.h"

void delay_ms(unsigned int t)
{
	while(t--)
	{
		unsigned char temp = 121;
    while(temp--);
	};
}


void delay_us(unsigned int t) // Do chinh xac thap, khoang 8.28 us
{
	while(t--){};
}
