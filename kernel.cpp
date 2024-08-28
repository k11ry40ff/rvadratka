#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "kernel.h"
#include "compare_var.h"
#include "roots_var.h"

int solve_square(double a, double b, double c, double* solved_x1, double* solved_x2) {
    assert(solved_x1);
    assert(solved_x2);

    if (is_close(a, 0) == EQUAL) {
        double linear_x = NAN;

        int linear_ans = solve_linear(b, c, &linear_x);
        *solved_x1 = *solved_x2 = linear_x;

        return linear_ans;
    }

    else {
        double dscr = b*b - 4*a*c;

        if (dscr < -BORDER) { 
            return ZERO_ROOTS;
        }
        else if (is_close(dscr, 0) == EQUAL) {
            double square_x_b4_check = *solved_x1 = *solved_x2 = (-b) / (2*a);

            if (is_close(square_x_b4_check, 0) == EQUAL) {
                *solved_x1 = *solved_x2 = 0;
            }

            return ONE_ROOT;
        }
        else {
            double double_a = 2*a;
            double sqrt_dscr = sqrt(dscr);
            double b_div_double_a = b / double_a;
            double sqrt_dscr_div_double_a = sqrt_dscr / double_a;

            *solved_x1 = -b_div_double_a - sqrt_dscr_div_double_a;
            *solved_x2 = -b_div_double_a + sqrt_dscr_div_double_a;

            return TWO_ROOTS;
        }
    }
}

int solve_linear(double b, double c, double * linear_x) {
    assert(linear_x);

    if (is_close(b, 0) == EQUAL) {
        if (is_close(c, 0) == EQUAL) {
            return INFINITY_ROOTS;
        }
        else {
            return ZERO_ROOTS;
        }
    }
    else {
        double linear_x_b4_check = *linear_x = (-c) / b;
        if (is_close(linear_x_b4_check, 0) == EQUAL) {
            *linear_x = 0;
        }
        
        return ONE_ROOT;
    }
}

int is_close(double float_1, double float_2) {                                        
    if (fabs(float_1 - float_2) < BORDER) {
        return EQUAL;
    }
    else if (float_1 > float_2) {
        return BIGGER_1;
    }
    else {
        return BIGGER_2;
    }

}