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

void			moove_right(t_42sh *sh)
{
	struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
	if (sh->curs->line == 0)
	{
		if (sh->curs->column == ((int)ft_strlen(sh->str) + sh->curs->start))
			return ;
	}
	else
	{
		ft_putnbr(((w.ws_col * (sh->curs->line + 1)) - (ft_strlen(sh->str)) + sh->curs->start) - w.ws_row);
	}
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

void			go_last_col(t_42sh *sh)
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

void			moove_left(t_42sh *sh)
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

void			conca_line(t_42sh *sh)
{
	char		*tmp;
	int			i;
	int			len_str;

	i = 0;
	tmp = ft_strdup(sh->str);
	len_str = ft_strlen(sh->str);
	free(sh->str);
	if (!(sh->str = (char*)malloc(sizeof(char) * (len_str - 1))))
		return ;
	while (i < (sh->curs->column - sh->curs->start))
	{
		sh->str[i] = tmp[i];
		i++;
	}
	while (i < len_str)
	{
		sh->str[i] = tmp[i + 1];
		i++;
	}
}

void			delete_one(t_42sh *sh)
{
	tputs(tgoto(tgetstr("dc", NULL), 1, 0), 1, my_outp);
	conca_line(sh);
}