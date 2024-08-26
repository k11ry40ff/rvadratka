#ifndef KERNEL_H
#define KERNEL_H

int solve_square(double a, double b, double c, double* solved_x1, double* solved_x2);

int solve_linear(double b, double c, double * linear_x);

int is_close(double a, double b);

#endif