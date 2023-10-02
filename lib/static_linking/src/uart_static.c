#include "uart_static.h"

void echo_uppercase(const struct device *dev)
{
    char byte, up;

    do {
        #ifndef TESTING_ENV
        if (uart_poll_in(dev, &byte) != 0) {
            continue;
        }
        #else
        if(test_uart_in(&byte) != 0){
            continue;
        }
        #endif

        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        #ifndef TESTNG_ENV
        uart_poll_out(dev, up);
        #else
        test_uart_out(byte)
        #endif
    } while(byte != '\n');
}