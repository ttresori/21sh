/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:55:43 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:17:29 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_21.h"

static t_env	*init_env(char ***env)
{
	t_env	*s_env;
	
	s_env = NULL;
	if (!(s_env = (t_env*)malloc(sizeof(t_env))))
		return (s_env);
	s_env->env = *env;
	return (s_env);
}

void	init_term()
{
	struct winsize w;

	if (tgetent(NULL, getenv("TERM")) == -1)
	{
		ft_putendl("Set term or a valide term.");
		exit(0);
	}
	if (tcgetattr(0, &g_term.term) == -1)
		exit(0);
	if (tcgetattr(0, &g_term.reset) == -1)
		exit(0);
	g_term.term.c_lflag &= ~(ICANON);
	g_term.term.c_lflag &= ~(ECHO);
	g_term.term.c_lflag &= ~(ISIG);
	g_term.term.c_cc[VMIN] = 1;
	g_term.term.c_cc[VTIME] = 1;
	ioctl(0, TIOCGWINSZ, &w);
	if (tcsetattr(0, TCSANOW, &g_term.term) == -1)
		exit(0);
}

void	restore_term(void)
{
	if (tcsetattr(0, 0, &g_term.reset))
		return ;
}

int		init_struct(t_42sh *sh, char ***env)
{
	if (!(sh->s_term = (t_term*)malloc(sizeof(t_term))))
		return (-1);
	g_term = *sh->s_term;
	init_term();
	sh->s_env = init_env(env);
	return (0);
}
