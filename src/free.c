/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:52:39 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:15:18 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_21.h"

static void free_env(t_42sh *sh)
{
	size_t i;

	i = 0;
	free(sh->s_env);
}

static void	free_term(t_42sh *sh)
{
	free(sh->s_term);
}

static void	free_curs(t_42sh *sh)
{
	free(sh->curs);
}

void	free_all(t_42sh *sh)
{
	free_env(sh);
	free_term(sh);
	free_curs(sh);
	if (sh->str != NULL)
		free(sh->str);
	free(sh);
	exit(0);
}
