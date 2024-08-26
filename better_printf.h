#ifndef BETTER_PRINTF_H
#define BETTER_PRINTF_H

const int IS_BOLD     = 1;
const int IS_NOT_BOLD = 0;

const int IS_UNDERLINE     = 1;
const int IS_NOT_UNDERLINE = 0;

void bprintf(const char* color, const char* bg_color, const int is_bold, const int is_underline, const char* line, ...);

#endif          