#include "../includes/lib_21.h"

void    print_prompt(t_42sh *sh)
{
	char	buf[256];

	ft_putstr(GREEN);
	ft_putstr(getcwd(buf, 256));
	ft_putstr("?> ");
    ft_putstr(NORMAL); 
    sh->curs->column = 0;
    sh->curs->column = (ft_strlen(buf) + 4);
    sh->curs->line = 0;
    sh->curs->start = sh->curs->column;
}

void   check_for_curs(t_42sh *sh)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    if (sh->curs->column == w.ws_col)
    {
        ft_putchar('\n');
        tputs(tgoto(tgetstr("ch", NULL), 1, 0), 1, my_outp);
	    sh->curs->column = 0;
        sh->curs->line++;
    }
}