#include <stdint.h>
#include <unity.h>

#include "map.h"

void setUp(void) {}

void tearDown(void) {}

//Provided function to use for adding
int add5(int x){
    return x + 5;
}

void test_passingadd5(void){
    int input[5] = {0, 1, 2, 3, 4};
    int output[5];
    int expected[5] = {5, 6, 7, 8, 9};

    map(&input[0], &output[0], 5, add5);

    TEST_ASSERT_EQUAL_INT_ARRAY(output, expected, 5);
}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(test_passingadd5);
    return UNITY_END();
}