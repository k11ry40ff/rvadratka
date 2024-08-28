#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#include "colors.h"
#include "better_printf.h"

void bprintf(const char* color, const char* bg_color, const int is_bold, const int is_underline, const char* line, ...) { //custom printf
    assert(color);
    assert(bg_color);
    assert(line);

    printf("%s", color);
    printf("%s", bg_color);

    if (is_bold == IS_BOLD) {
        printf(BOLD);
    }
    if (is_underline == IS_UNDERLINE) {
        printf(UNDERLINE);
    }

    va_list settings;
    va_start(settings, line);

    vprintf(line, settings);

    va_end(settings);

    printf(COLOR_RESET);
}
