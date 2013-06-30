//////////////////////////////////////////////////////////////////////////////////////
// Thu vien giao tiep voi DS18B20 																									//
// Created by TuanLa 27/6/2013																											//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _DS18B20_
#define _DS18B20_

#define DQ P1_2

// Ham khoi tao DS18B20
bit init_DS18B20(void)
{
	bit presence;
	DQ=1;
	delay_us(8);			 //66.24us
	DQ=0;
	delay_us(60);			 //496.8us
	DQ=1;
	delay_us(3);			 //24.84us
	presence = DQ;
	delay_us(60);			 //496.8us
	DQ=1;
	return(presence);
}
/*
// Ham doc 1 bit tu Ds18B20
bit ReadBit_DS18B20(void)
{
	bit b=0;
    DQ=0;
    DQ=1;
    if(DQ) b=1;
    delay_us(8);					//66.24us
  return (b);
}
*/

// Ham doc 1 byte tu DS18B20
unsigned char ReadByte_DS18B20(void)
{
unsigned char i;
unsigned char Data=0;
for (i=8;i>0;i--)
  {
    DQ=0;
    Data >>= 1;						// Tuong duong Data=Data>>1
    DQ=1;
    if(DQ) Data |= 0x80;
    delay_us(8);					//66.24us
  }
  return (Data);
}

// Ham viet 1 byte ra DS18B20
void WriteByte_DS18B20(unsigned char Data)
{
  unsigned char i;
  for (i=8;i>0;i--)
  {
    DQ=0;
    DQ=Data&0x01;
    delay_us(8);					//66.24us
    DQ=1;
    Data >>= 1;
  }
}

void Wait_DS18B20()
{
	DQ=0;
  DQ=1;
	while(!DQ){};
}


// Ham chuyen doi nhiet do va tra ve gia tri nhan duoc
float Temp_DS18B20(unsigned char d[])
{
			if(init_DS18B20()==1) return(-555);							// Khoi tao DS18B20
			else
			{
				float temp=0;
				char i;
				unsigned char a,b;
				WriteByte_DS18B20(0x55);  													// Match ROM
				for(i=7;i>=0;i--) WriteByte_DS18B20(d[i]); 					// Write ROM code
				WriteByte_DS18B20(0x44);														// Convert T
				Wait_DS18B20();																			// Wait convert
				
				init_DS18B20();
				WriteByte_DS18B20(0x55);  													// Match ROM
				for(i=7;i>=0;i--) WriteByte_DS18B20(d[i]); 					// Write ROM code
				WriteByte_DS18B20(0xBE);														// Read Scratchpad
		
				a = ReadByte_DS18B20(); 
				temp=((float)(a&0x0f))/16;				// Lay phan thuc cua gia tri nhiet do
				b = ReadByte_DS18B20(); 				
				a =((a&0xf0)>>4)|((b&0x07)<<4) ;	// Lay phan nguyen cua gia tri nhiet do
				temp=temp+a;
				if((b&0x08)!=0) temp=-temp;
				if(temp!=-127.9375) return(temp);											// Kiem tra xem co dung la co phai giao tiep voi ROM nay khong
				else return(-555);
			}
}
#endif