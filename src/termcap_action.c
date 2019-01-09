/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:25:43 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:29:19 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_21.h"

int		my_outp(int c)
{
	write(0, &c, 1);
	return (0);
}

void	moove_right(t_42sh *sh)
{
	struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
	if (sh->curs->column < w.ws_col)
	{
		tputs(tgoto(tgetstr("nd", NULL), 1, 0), 1, my_outp);
		sh->curs->column++;
	}
	else
	{
		ft_putchar('\n');
		tputs(tgoto(tgetstr("ch", NULL), 1, 0), 1, my_outp);
		sh->curs->column = 1;
		sh->curs->line++;
	}
}

void	go_last_col(t_42sh *sh)
{
	struct winsize w;

   	ioctl(0, TIOCGWINSZ, &w);
	sh->curs->column = w.ws_col;
	while (w.ws_col > 0)
	{
		tputs(tgoto(tgetstr("nd", NULL), 1, 0), 1, my_outp);
		w.ws_col--;
	}
}

void	moove_left(t_42sh *sh)
{
	if (sh->curs->line == 0)
	{
		if (sh->curs->column > sh->curs->start)
		{
			tputs(tgoto(tgetstr("le", NULL), 1, 0), 1, my_outp);
			sh->curs->column--;
		}
	}
	else
		{
			if (sh->curs->column > 0)
				{
						if (sh->curs->column == 1)
						{
							tputs(tgoto(tgetstr("up", NULL), 1, 0), 1, my_outp);
							sh->curs->line--;
							go_last_col(sh);
						}
						else
						{
							tputs(tgoto(tgetstr("le", NULL), 1, 0), 1, my_outp);
							sh->curs->column--;
						}
				}
		}
}