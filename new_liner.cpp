#include <stdio.h>

#include "new_liner.h"

const int NEW_LINE = '\n';

void new_line(int how_many) { //making new lines
    for (unsigned i = 0; i < how_many; i++ ) {
        putc(NEW_LINE, stdout);
    } 
}