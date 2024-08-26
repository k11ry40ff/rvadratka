#include <stdio.h>
#include <stdarg.h>

#include "colors.h"
#include "better_printf.h"

const int SETTING_IS_TRUE = 1;

void bprintf(const char* color, const char* bg_color, const int is_bold, const int is_underline, const char* line, ...) { //custom printf
    assert(color);
    assert(bg_color);
    assert(line);
    
    printf(color);
    printf(bg_color); // FIXME asserts


    if (is_bold == SETTING_IS_TRUE) {
        printf(BOLD);
    }
    if (is_underline == SETTING_IS_TRUE) {
        printf(UNDERLINE);
    }

    va_list settings;
    va_start(settings, line);

    vprintf(line, settings);

    va_end(settings);

    printf(COLOR_RESET);
}
