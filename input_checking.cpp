#include <stdio.h>
#include <math.h>
#include <conio.h>

#include "colors.h"
#include "better_printf.h"
#include "new_liner.h"

const char CONFIRM = '1'; // confirming

int confirm() {
    new_line(1);
    bprintf(YELLOW, DEFAULT_BG, IS_BOLD, IS_UNDERLINE, "Are you sure? %c - YES, any other key - NO.", CONFIRM);
    new_line(2);
    int confirmation_button = getche();
    new_line(1);

    if (confirmation_button == CONFIRM) {
        return 1;
    }
    return 0;
}

int do_check_symbol(char check_symbol) { //checking symbols while inputing coefficients
    if (check_symbol == EOF || check_symbol =='\n' || check_symbol ==' ') {
        ungetc(check_symbol, stdin);
        return 1;
    }
    return 0;
}