#include "../includes/lib_21.h"

void        lexer(char *line, t_42sh *sh)
{
    if (ft_strncmp(line, "exit", 4) == 0)
        leave_all(sh);
}