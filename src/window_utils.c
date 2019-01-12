#include "../includes/lib_21.h"

int     check_win_size(void)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    return (0);
}