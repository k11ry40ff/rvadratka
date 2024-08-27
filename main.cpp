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

int main() { // program repeating cycle
    greetings();
    
    int exit = choice();
    return exit;
}


