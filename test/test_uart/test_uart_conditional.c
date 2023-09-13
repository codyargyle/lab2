#include <stdint.h>
#include <unity.h>

#include "uart_hello.h"

void setUp(void) {}

void tearDown(void) {}

// Create counter to keep track of how many bytes to 
// to keep track where we are in the string
int count = 6;
unsigned char testString[6] = "hello\n";

int test_uart_in(unsigned char* byte) {
    if(count > 0){
        *byte = testString[6 - count];
        count--;
        return 1;
    }
    
    return 0;
}

int test_uart_out(unsigned char byte) {
    if(count == 5 && byte == 'H'){
        return 1;
    }
    else if(count == 4 && byte == 'E'){
        return 1;
    }
    else if(count == 3 && byte == 'L'){
        return 1;
    }
    else if(count == 2 && byte == 'L'){
        return 1;
    }
    else if(count == 1 && byte == 'O'){
        return 1;
    }
    else if(count == 0 && byte == '\n'){
        return 1;
    }
    else{
        return 0;
    }
}

int main (void)
{
    // Variables to pass to test
    unsigned char byte;

    UNITY_BEGIN();
    // These test are to make sure that test_uart_in returns a 1 six times
    // and gives us the correct character in the string "hello\n" and finally
    // testing to see that it returns a zero after six times
    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == 'h');
    TEST_ASSERT_TRUE(test_uart_out(byte) != 1);
    TEST_ASSERT_TRUE(test_uart_out('H') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == 'e');
    TEST_ASSERT_TRUE(test_uart_out(byte) != 1);
    TEST_ASSERT_TRUE(test_uart_out('E') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == 'l');
    TEST_ASSERT_TRUE(test_uart_out(byte) != 1);
    TEST_ASSERT_TRUE(test_uart_out('L') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == 'l');
    TEST_ASSERT_TRUE(test_uart_out(byte) != 1);
    TEST_ASSERT_TRUE(test_uart_out('L') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == 'o');
    TEST_ASSERT_TRUE(test_uart_out(byte) != 1);
    TEST_ASSERT_TRUE(test_uart_out('O') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 1);
    TEST_ASSERT_TRUE(byte == '\n');
    TEST_ASSERT_TRUE(test_uart_out('\n') == 1);

    TEST_ASSERT_TRUE(test_uart_in(&byte) == 0);

    return UNITY_END();
}