/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:14:49 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:22:44 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_21.h"

int		core(t_42sh *sh, char ***env)
{
	long	buf;
	int		i;

	buf = 0;
	i = 0;
	if (init_struct(sh, env) == -1)
		return (-1);
	while (1)
	{
		print_prompt(sh);
		buf = 0;
		i = 0;
		if (!(sh->str = (char*)malloc(sizeof(char) * 255)))
			return (-1);
		sh->str[0] = '\0';
		while (buf != '\n')
		{
			buf = 0;
			read(STDOUT_FILENO, &buf, 4);
			if (check_key(sh, buf) == 0)
			{
				sh->str[i] = buf;
				sh->str[i + 1] = '\0';
				if (sh->str[i] != '\n')
				{
					ft_putchar(sh->str[i++]);
					check_for_curs(sh);
					sh->curs->column++;
				}
				else
				{
					ft_putchar('\n');
					break ;
				}
			}
		}
		if (i > 0)
		{
			sh->str[i] = '\0';
			sh->input = ft_strdup(sh->str);
			ft_putstr(sh->input);
			lexer(sh->input, sh);
			free(sh->str);
			free(sh->input);
		}
	}
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	t_42sh	*sh;

	if (env[0] == NULL)
	{
		ft_putstr_fd("Please, set the env :\nsee [setenv]", 0);
		return (-1);
	}
	if (!(sh = (t_42sh*)malloc(sizeof(t_42sh))))
		return (-1);
	if (!(sh->curs = (t_curs*)malloc(sizeof(t_curs))))
		return (-1);
	if (core(sh, &env) == -1)
		leave_all(sh);
	else
		leave_all(sh);
	(void)argc;
	(void)argv;
	return (0);
}

