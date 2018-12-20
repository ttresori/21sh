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
	if (init_struct(sh, env) == -1)
		return (-1);
	while (1)
	{
		buf = 0;
		i = read(STDOUT_FILENO, &buf, 4);
		if ((check_key(sh, buf)) == -1)
			return (-1);
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
	if (core(sh, &env) == -1)
		free_all(sh);
	free_all(sh);
	(void)argc;
	(void)argv;
	return (0);
}
	
