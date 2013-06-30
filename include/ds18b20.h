//////////////////////////////////////////////////////////////////////////////////////
// Thu vien giao tiep voi DS18B20 																									//
// Created by TuanLa 27/6/2013																											//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _DS18B20_
#define _DS18B20_

#define DQ P1_2

bit init_DS18B20(void);
unsigned char ReadByte_DS18B20(void);
void WriteByte_DS18B20(unsigned char Data);
void Wait_DS18B20();
float Temp_DS18B20(unsigned char d[]);

#endif
