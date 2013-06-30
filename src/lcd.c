//////////////////////////////////////////////////////////////////////////////////////
// Ham khai bao, doc xuat du lieu cho LCD 16*06, hoat dong o che do 16bit			//
//							Created by TuanLa 24/6/2013								//
//////////////////////////////////////////////////////////////////////////////////////

#include "lcd.h"

void WriteLCD_cmd(unsigned char c)
{
    RS=0;
    RW=0;
    LCD_Port=c;
    EN=1;
    EN=0;
    delay_ms(5);
}

void WriteLCD_data(unsigned char c)
{
    RS=1;
    RW=0;
    LCD_Port=c;
    EN=1;
    EN=0;
    delay_ms(5);
}

void init_LCD()
{
    delay_ms(16);
    WriteLCD_cmd(0x38);
    WriteLCD_cmd(0x38);
    WriteLCD_cmd(0x38);
    WriteLCD_cmd(0x38); //Function set: 16bit,2 lines, font 5*8
    WriteLCD_cmd(0x0C); //Set Display on,off control: Display, no cursor, no blinking
    WriteLCD_cmd(0x01); //Clear Display
    WriteLCD_cmd(0x06); //Entry mode 1
}

// Ham in mot ki tu/chuoi ra man hinh
void putchr_LCD(char c[])
{
    unsigned char i;
    for(i=0; i<strlen(c); i++) WriteLCD_data(c[i]);
}

// Ham in so nguyen (chi su dung trong nay)
void putZ_LCD(int x)
{
    if(x==0) putchr_LCD("0");
    else {
        unsigned char a[13];
        int i;
        for(i=0; x>0; i++) {
            a[i]=(x%10)+48;
            x=x/10;
        }
        a[i]='\0';
        for(i=strlen(a); i>0; i--) {
            WriteLCD_data(a[i-1]);
        }
    }
}

// Ham in mot so ra man hinh, neu la so thuc thi in 2 so sau dau phay
void putnum_LCD(float x)
{
    int pn, ptp;
    if(x<0) {
        putchr_LCD("-");
        x=-x;
    }
    pn=x;
    ptp=x*100-pn*100;
    putZ_LCD(pn);
    putchr_LCD(".");
    if (ptp==0) putchr_LCD("00");
    else {
        putZ_LCD(ptp);
    }
}

// Ham chuyen den mot vi tri tri trong man hinh
void goto_LCD(char x, char y)
{
    if (y==1) WriteLCD_cmd(127+x);
    else if (y==2) WriteLCD_cmd(191+x);
}

// Ham xoa LCD
void clear_LCD()
{
    WriteLCD_cmd(0x01);
}
