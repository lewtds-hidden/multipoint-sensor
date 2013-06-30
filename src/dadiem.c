#include <REGX51.H>
#include <delay/delay.h>
#include <uart/uart.h>
#include <ds18b20/ds18b20.h>

#define SW16 P3_2
#define SW17 P3_3
#define SW18 P3_4
#define SW19 P3_5

main()
{
    char i=0;
    unsigned char d1[8]= {60, 0, 0, 4, 92, 68, 164, 40};					//But xoa
    unsigned char d2[8]= {66, 0, 0, 1, 38, 5, 160, 40};					//Binh thuong
    unsigned char d3[8]= {112, 0, 0, 4, 110, 203, 153, 40};			//Day dai

    SW16=1;
    SW17=1;
    SW18=1;
    SW19=1;

    init_UART();
    send_UART(10);
    sendchr_UART("Tuan La         ");
    sendchr_UART("QT Vat Ly - K56!");
    send_UART(10);
    sendchr_UART("   MENU:    ");
    send_UART(10);
    sendchr_UART("An SW16 de xem nhiet do t1!");
    send_UART(10);
    sendchr_UART("An SW17 de xem nhiet do t2!");
    send_UART(10);
    sendchr_UART("An SW18 de xem nhiet do t3!");
    send_UART(10);
    sendchr_UART("An SW19 de cap nhat nhiet do ca 3 sensor tung giay!");
    send_UART(10);

    while(1) {
        float t=0;

        if(SW16==0) {
            delay_ms(200);
            t=Temp_DS18B20(d1);
            if(t!=-555) {
                sendchr_UART("  t1 =    ");
                sendnum_UART(t);
                send_UART(10);
            } else {
                sendchr_UART("Error connecting to Sensor1");
                send_UART(10);
            };
        }

        if(SW17==0) {
            delay_ms(200);
            t=Temp_DS18B20(d2);
            if(t!=-555) {
                sendchr_UART("  t2 =    ");
                sendnum_UART(t);
                send_UART(10);
            } else {
                sendchr_UART("Error connecting to Sensor2");
                send_UART(10);
            };
        }

        if(SW18==0) {
            delay_ms(200);
            t=Temp_DS18B20(d3);
            if(t!=-555) {
                sendchr_UART("  t3 =    ");
                sendnum_UART(t);
                send_UART(10);
            } else {
                sendchr_UART("Error connecting to Sensor3");
                send_UART(10);
            };
        }

        if(SW19==0) {
            delay_ms(200);
            while(1) {
                t=Temp_DS18B20(d1);
                sendchr_UART("  t1 =    ");
                if(t!=-555) sendnum_UART(t);
                else sendchr_UART("Error");

                t=Temp_DS18B20(d2);
                sendchr_UART("  t2 =    ");
                if(t!=-555) sendnum_UART(t);
                else sendchr_UART("Error");

                t=Temp_DS18B20(d3);
                sendchr_UART("  t3 =    ");
                if(t!=-555) sendnum_UART(t);
                else sendchr_UART("Error");

                send_UART(10);
                delay_ms(1000);
            }
        }
    };
}
