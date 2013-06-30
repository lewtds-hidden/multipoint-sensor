//////////////////////////////////////////////////////////////////////////////////////
// Ham khai bao, doc xuat du lieu cho LCD 16*06, hoat dong o che do 16bit			//
//							Created by TuanLa 24/6/2013								//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _LCD_
#define _LCD_

#include <string.h>
#define RS P2_2
#define RW P2_3
#define EN P2_4

#define LCD_Port P0

void WriteLCD_cmd(unsigned char c);
void WriteLCD_data(unsigned char c);
void init_LCD();
void putchr_LCD(char c[]);
void putnum_LCD(float x);
void putZ_LCD(int x);
void goto_LCD(char x, char y);
void clear_LCD();


#endif
