#include <stdio.h>
#include <conio.h>

#include "solver.h"
#include "tester.h"
#include "roots_var.h"
#include "input_checking.h"
#include "kernel.h"
#include "compare_var.h"
#include "colors.h"
#include "better_printf.h"
#include "new_liner.h"
#include "greetings.h"

void greetings() {
    new_line(1);
    bprintf(WHITE, BLACK_BG, IS_BOLD, IS_NOT_UNDERLINE, "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
    new_line(1);
    bprintf(BLUE, BLACK_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ  SQUARE EQUATION SOLVER  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
    new_line(1);
    bprintf(RED, BLACK_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
    new_line(2);

    bprintf(DEFAULT, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "%c - solve square equation, %c - start testing, any other key - exit.", SOLVER_BUTTON, TESTER_BUTTON);
    new_line(2);    
}

int choice() {
    int input_button = getche();
    new_line(1);

    return input_button;
}

int work(int input_button) {  

    while (true) {
        if (input_button == SOLVER_BUTTON) {
            int input_test = input_and_ans();

            switch(input_test) {
                case true:
                    break;
                case ANSWER_OUTPUT_FAIL:
                    return 1;
                default:
                    new_line(1);
                    bprintf(RED, DEFAULT_BG, IS_BOLD, IS_UNDERLINE, "some problems with switch in main with solver");
                    new_line(1);
                    return 1;
            }
        }
        else if (input_button == TESTER_BUTTON) {
            if (confirm()) {
                RT_tester_driver();
            }
        }
        else {
            if (confirm()) {
                break;
            }
        }
        new_line(1);

        bprintf(DEFAULT, DEFAULT_BG, IS_NOT_BOLD, IS_NOT_UNDERLINE, "Try again? %c - solve square equation, %c - start testing , any other key - exit.", SOLVER_BUTTON, TESTER_BUTTON);
        new_line(2);

        input_button = getche();
        new_line(1);
    }
    new_line(1);

    bprintf(BLUE, WHITE_BG, IS_BOLD, IS_NOT_UNDERLINE, "Well, okay :(");
    new_line(1);
    
    return 0;
}