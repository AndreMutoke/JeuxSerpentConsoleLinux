#include <stdio.h>

// +++ TERMINAL CONTROL +++

#define TC_NRM "\x1B[0m"
#define TC_RED "\x1B[1;31m"
#define TC_GRN "\x1B[1;32m"
#define TC_YEL "\x1B[1;33m"
#define TC_BLU "\x1B[1;34m"
#define TC_MAG "\x1B[1;34m"
#define TC_CYN "\x1B[1;36m"
#define TC_WTH "\x1B[1;37m"

#define TC_B_NRM "\x1B[0m"
#define TC_B_RED "\x1B[0;31m"
#define TC_B_GRN "\x1B[0;32m"
#define TC_B_YEL "\x1B[0;33m"
#define TC_B_BLU "\x1B[0;34m"
#define TC_B_MAG "\x1B[0;34m"
#define TC_B_CYN "\x1B[0;36m"
#define TC_B_WTH "\x1B[0;37m"

#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED "\x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WTH "\x1B[47m"

#define TC_clear_screen() puts("\x1B[2J")
#define tc_move_cursor(X,Y) printf("\033[%d;%dH", Y, X)


int main(int argc, char* argv[])
{
    TC_clear_screen();
    tc_move_cursor(25, 5);
    printf("%s%sHello world\n%s", TC_RED, TC_BG_RED, TC_NRM);
    
    return 0;
}