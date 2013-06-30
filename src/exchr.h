//////////////////////////////////////////////////////////////////////////////////////
//							 Ham khoi tao cac ki tu dac biet				   	    //
// 				               Created by TuanLa 24/6/2013  						//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXCHR_
#define _EXCHR_

#define chr1 0x00
#define chr2 0x01
#define chr3 0x02
#define chr4 0x03
#define chr5 0x04
#define chr6 0x05
#define chr7 0x06
#define chr8 0x07

void exchr1(unsigned char c[8]);
void exchr2(unsigned char c[8]);
void exchr3(unsigned char c[8]);
void exchr4(unsigned char c[8]);
void exchr5(unsigned char c[8]);
void exchr6(unsigned char c[8]);
void exchr7(unsigned char c[8]);
void exchr8(unsigned char c[8]);

void exchr1(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(64+i);
		WriteLCD_data(c[i]);
	}
}

void exchr2(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(72+i);
		WriteLCD_data(c[i]);
	}
}

void exchr3(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(80+i);
		WriteLCD_data(c[i]);
	}
}

void exchr4(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(88+i);
		WriteLCD_data(c[i]);
	}
}

void exchr5(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(96+i);
		WriteLCD_data(c[i]);
	}
}

void exchr6(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(104+i);
		WriteLCD_data(c[i]);
	}
}

void exchr7(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(112+i);
		WriteLCD_data(c[i]);
	}
}

void exchr8(unsigned char c[8])
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WriteLCD_cmd(120+i);
		WriteLCD_data(c[i]);
	}
}

#endif