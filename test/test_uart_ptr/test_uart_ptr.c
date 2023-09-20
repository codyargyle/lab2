#include <stdint.h>
#include <unity.h>

#include "uart_pointer.h"

void setUp(void) {}

void tearDown(void) {}

//String to pass to echo upper
char data[6] = "hello\n";
char *current_location = &data[0];

//functions to pass to echo_uppercase_poiniter
int ptr_uart_in(char *byte){
    *byte = *current_location;
    if(*current_location == '\n'){
        current_location = &data[0];
    }
    else{
        current_location++;
    }
    return 0;
}

char expected_data[6] = "HELLO\n";
char *current_expected = &data[0];
void ptr_uart_out(char byte){
    TEST_ASSERT_EQUAL_CHAR(*current_expected++, byte);
}

void echo_ptr_test(void){
    echo_uppercase_pointer(ptr_uart_in, ptr_uart_out);
}


int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(echo_ptr_test);
    return UNITY_END();
}