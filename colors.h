#ifndef COLORS_H
#define COLORS_H

//symbol color
const char BLACK[]   = "\x1b[30m";
const char RED[]     = "\x1b[31m";
const char GREEN[]   = "\x1b[32m";
const char YELLOW[]  = "\x1b[33m";
const char BLUE[]    = "\x1b[34m";
const char MAGENTA[] = "\x1b[35m";
const char CYAN[]    = "\x1b[36m";
const char WHITE[]   = "\x1b[37m";
const char DEFAULT[] = "\x1b[39m";

//background
const char BLACK_BG[]   = "\x1b[40m";
const char RED_BG[]     = "\x1b[41m";
const char GREEN_BG[]   = "\x1b[42m";
const char YELLOW_BG[]  = "\x1b[43m";
const char BLUE_BG[]    = "\x1b[44m";
const char MAGENTA_BG[] = "\x1b[45m";
const char CYAN_BG[]    = "\x1b[46m";
const char WHITE_BG[]   = "\x1b[47m";
const char DEFAULT_BG[] = "\x1b[49m";

//clear all settings
const char COLOR_RESET[] = "\x1b[0m";

//settings

const char BOLD[]      = "\x1b[1m";
const char UNDERLINE[] = "\x1b[4m";

#endif