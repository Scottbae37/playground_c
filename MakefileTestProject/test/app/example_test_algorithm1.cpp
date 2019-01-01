//
// Created by scottbae37 on 8/29/17.
//

#include "../../test/include/gtest/gtest.h"

extern "C" {
# include "../../src/app/example_algorithm1.h"
}

TEST(APP_Algorithm1Test, computeDistanceLatLong_success_WhenLatIsGreaterThenZero) {
    /* Setup */
    double input1 = 3.111, input2 = 5.5534;
    double result;
    /* Exercise */
    result = computeDistanceLatLong(input1,input2);
    /* Verify */
    EXPECT_NEAR(1.1, result, 0.1);
    /* Teardown */
}

TEST(APP_Algorithm1Test, computeDistanceLatLong_error_WhenLongiIsLessThenZero) {
    /* Setup */
    double input1 = 3.111, input2 = 0;
    double result;
    /* Exercise */

    result = computeDistanceLatLong(input1,input2);
    /* Verify */
    EXPECT_NEAR(0, result, 0.1); /* 0 indicate unknown err */
    /* Teardown */
}

TEST(APP_Algorithm1Test, computeA_success_WhenLatIsGreaterThenZero) {
    /* Setup */
    MyStruct_t data;
    data.lat = 1;
    data.longi = 0;
    int result;
    /* Exercise */

    result = computeA(&data);
    /* Verify */
    EXPECT_EQ(1, result);
    /*
     * #define SUCCESS 1
     * #define FAIL    0
     * */
    /* Teardown */
}

TEST(APP_Algorithm1Test, DISABLED_computeA_fail_WhenLatIsLessThenOrEqualToZero) {
    /* Setup */
    MyStruct_t data;
    data.lat = 0;
    data.longi = 0;
    int result;
    /* Exercise */

    result = computeA(&data);
    /* Verify */
    EXPECT_EQ(1, result);
    /* Teardown */
}
