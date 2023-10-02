#include <stdint.h>
#include <unity.h>

#include "uart_static.h"

void setUp(void) {}

void tearDown(void) {}

//String to pass to echo upper
char data[6] = "hello\n";
char *current_location = &data[0];

//functions to pass to echo_uppercase_poiniter
int uart_poll_in(const struct device * dev, char *byte){
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
char *current_expected = &expected_data[0];
void uart_poll_out(const struct device * dev, char byte){
    TEST_ASSERT_EQUAL_CHAR(*current_expected++, byte);
}

void echo_static_linking_test(void){
    echo_uppercase((struct device *) 0);
}


int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(echo_static_linking_test);
    return UNITY_END();
}