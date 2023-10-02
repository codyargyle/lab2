#include "uart_pointer.h"

void echo_uppercase_pointer(int (*uart_in)(char *), void (*uart_out)(unsigned char))
{
    char byte, up;

    do {
        if(uart_in(&byte) != 0){
            continue;
        }

        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        uart_out(up);
    } while(byte != '\n');
}