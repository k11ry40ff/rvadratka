#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "tester.h"
#include "roots_var.h"
#include "input_checking.h"
#include "kernel.h"
#include "compare_var.h"
#include "colors.h"
#include "better_printf.h"
#include "new_liner.h"

void RT_tester_driver() { //test database 
    struct TestBase testbase[] = {
        // test_a, test_b, test_c, expected_x1, expected_x2, expected_res
        {1,     2,    1,     -1,        -1,       ONE_ROOT},
        {0,     0,    0,     NAN,       NAN,      INFINITY_ROOTS},
        {0,     2.5,  -12.5, 5,         5,        ONE_ROOT},
        {1,     2,    3,     NAN,       NAN,      ZERO_ROOTS},
        {1,     0,    0,     0,         0,        ONE_ROOT},
        {2.4,   25.8, -79.5, 2.5,       -13.25,   TWO_ROOTS},
        {46532, 46,   -6461, -0.373121, 0.372133, TWO_ROOTS},
        {1,     0,    0,     0,         0,        ONE_ROOT},
        {0,     2,    0,     0,         0,        ONE_ROOT}

    };

    int number_of_test = 1;

    while (number_of_test != (NUMBER_OF_TEST + 1)) {
        struct TestBase test = testbase[number_of_test - 1];

        RT_tester(test.test_a, test.test_b, test.test_c, test.expected_x1, test.expected_x2, test.expected_res, number_of_test);
        ++number_of_test;
    }
}

void RT_tester (double test_a, double test_b, double test_c, double expected_x1, double expected_x2, int expected_res, int number_of_test) { //testing iteration
    double solved_x1 = NAN, solved_x2 = NAN;
    int res = solve_square(test_a, test_b, test_c, &solved_x1, &solved_x2);

        if (is_close(expected_x1, expected_x2) == BIGGER_1) { // sorting expected roots
            double temp = expected_x1;
            expected_x1 = expected_x2;
            expected_x2 = temp;
        }

        if (is_close(res, expected_res) == EQUAL &&   // number of roots equality
           (is_close(solved_x1, expected_x1) == EQUAL || (isnan(solved_x1) && isnan(expected_x1)))  && // 1 root equality
           (is_close(solved_x2, expected_x2) == EQUAL || (isnan(solved_x2) && isnan(expected_x2)))) {  // 2 root equality

            new_line(1);
            bprintf(GREEN, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Test %d: OK.", number_of_test);
            new_line(1); 
        }
        else {
            new_line(1);
            bprintf(RED, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Err Test %d: a = %lg, b = %lg, c = %lg, Roots = %d, X1 = %lg, X2 = %lg.\n"
                   "Expected: Roots = %d, X1 = %lg, X2 = %lg.",
                   number_of_test, test_a, test_b, test_c, res, solved_x1, solved_x2,
                   expected_res, expected_x1, expected_x2);
            new_line(1);
        }
}