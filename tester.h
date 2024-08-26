#ifndef TESTER_H
#define TESTER_H

struct TestBase {
    double test_a, test_b, test_c, expected_x1, expected_x2;
    int expected_res;
};

const int NUMBER_OF_TEST = 9; // number of sctructs in TestBase_data

void RT_tester_driver();

void RT_tester (double test_a, double test_b, double test_c, double expected_x1, double expected_x2, int expected_res, int number_of_test);

#endif