#ifndef SOLVER_H
#define SOLVER_H

struct VariablesBase  {
    double a, b, c, solved_x1, solved_x2;
};

void clean_input();

int input_and_ans();

int answer_output(int res, double solved_x1, double solved_x2);

#endif