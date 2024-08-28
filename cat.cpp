#include <stdio.h>

#include "cat.h"
#include "new_liner.h"
#include "colors.h"
#include "better_printf.h"

void cat() {

    puts(" ,_     _");     
    puts(" |\\\\_,-~/");                            
    puts(" / _  _ |    ,--.");
    puts("(  @  @ )   / ,-'");
    puts(" \\  _T_/-._( (");
    puts(" /         `. \\");
    puts("|         _  \\ |");
    puts(" \\ \\ ,  /      |");
    puts("  || |-_\\__   /");
    puts(" ((_/`(____,-'");
    new_line(1);
    bprintf(MAGENTA, GREEN_BG, IS_BOLD, IS_UNDERLINE, "Vot eto prikol - poltorashka)))");
    new_line(2);
    bprintf(CYAN, DEFAULT_BG, IS_BOLD, IS_UNDERLINE, "0 roots anyway :)");
    new_line(1);
    

}