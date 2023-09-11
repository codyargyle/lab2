#pragma once

#ifdef TESTING_ENV
struct device
{
};
void test_uart_out();
void test_uart_in();
#else
#include <drivers/uart.h>
#endif


void echo_uppercase(const struct device *dev);