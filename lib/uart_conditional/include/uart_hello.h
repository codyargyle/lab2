#pragma once
#ifndef TESTING_ENV
#include <drivers/uart.h>
#else
int test_uart_out(unsigned char byte);
int test_uart_in(unsigned char* byte);
struct device{};
#endif


void echo_uppercase(const struct device *dev);
