#pragma once
#ifndef TESTING_ENV
int test_uart_out(unsigned char byte);
int test_uart_in(unsigned char* byte);
struct device{};
#else
#include <drivers/uart.h>
#endif


void echo_uppercase(const struct device *dev);
