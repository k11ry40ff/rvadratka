#include <stdio.h>
#include <math.h>

#include "solver.h"
#include "roots_var.h"
#include "kernel.h"
#include "input_checking.h"
#include "colors.h"
#include "better_printf.h"
#include "new_liner.h"

const int IF_ENOUGH_INPUT = 4;

void clean_input() { // skipping wrong input
    while (getchar() != '\n') {}
}

int input_and_ans() { // input  + calling ans_output
    struct VariablesBase variables {NAN, NAN, NAN, NAN, NAN};
    
    new_line(1);
    bprintf(DEFAULT, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Enter values of a, b, c.");
    new_line(2);
    char check_symbol = 0;

    if (scanf("%lg %lg %lg%c", &(variables.a), &(variables.b), &(variables.c), &check_symbol) == IF_ENOUGH_INPUT && do_check_symbol(check_symbol)) { // valid input

        int res = solve_square(variables.a, variables.b, variables.c, &variables.solved_x1, &variables.solved_x2);
        answer_output(res, variables.solved_x1, variables.solved_x2);
    }
    else {  // wrong input
        
        new_line(1);
        bprintf(RED, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Wrong input.");
        new_line(1);
    }
    clean_input();
    return true;
}

int answer_output(int res, double solved_x1, double solved_x2) {  // answer output
    new_line(1);
    switch(res) {
        case ZERO_ROOTS:
            bprintf(CYAN, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "0 roots.");
            new_line(1);
            return true;
        case ONE_ROOT:
            bprintf(CYAN, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "1 root - x = %lg.", solved_x1);
            new_line(1);
            return true;
        case TWO_ROOTS:
            bprintf(CYAN, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "2 roots - x1 = %lg and x2 = %lg.", solved_x1, solved_x2);
            new_line(1);
            return true;
        case INFINITY_ROOTS:
            bprintf(CYAN, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Infinitely many roots.");
            new_line(1);
            return true;
        default:
            bprintf(RED, DEFAULT_BG, IS_BOLD, IS_UNDERLINE, "some problems with switch in main with answer_output.");
            return ANSWER_OUTPUT_FAIL;
    }
}

