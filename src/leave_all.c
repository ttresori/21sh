#include "../includes/lib_21.h"

void        leave_all(t_42sh *sh)
{
    restore_term();
    free_all(sh);
    exit(0);
}