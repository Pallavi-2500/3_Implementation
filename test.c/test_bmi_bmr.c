#include "unity.h"
#include "bmi_bmr.h"/* The unit to be tested. */

void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run after every test, put unit clean-up calls here. */

void test_bmiResult(void)
{
    //All tests should pass
    TEST_ASSERT_EQUAL_STRING("normal weighted", bmiResult(19)); 
    TEST_ASSERT_EQUAL_STRING("normal weighted", bmiResult(22)); 
    TEST_ASSERT_EQUAL_STRING("overweight", bmiResult(25));
    TEST_ASSERT_EQUAL_STRING("underweight", bmiResult(15));  
}
void test_bmrResult(int gender, double weight, double height, double age) 
{
    //All tests should pass
    TEST_ASSERT_EQUAL_FLOAT(1191.50, bmrResult(1, 50, 150, 17));
    TEST_ASSERT_EQUAL_FLOAT(1605.00, bmrResult(2, 65, 168, 20));
    TEST_ASSERT_EQUAL_FLOAT(1414.00, bmrResult(1, 70, 160, 25));
    TEST_ASSERT_EQUAL_FLOAT(1751.25, bmrResult(2, 80, 173, 27));
}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(test_bmiResult); 
    RUN_TEST(test_bmrResult);
    return UNITY_END();
}  