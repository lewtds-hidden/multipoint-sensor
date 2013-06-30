#ifndef _UART_
#define _UART_

#include <string.h>

void init_UART();
void sendchar_UART(char c[]);
void send_UART(unsigned char a);
void sendZ_UART(long int n);
void sendnum_UART(float x);

#endif
