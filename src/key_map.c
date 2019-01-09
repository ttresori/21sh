/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:18:08 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:29:02 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_21.h"

const long		input_tab[NB_INPUT] = {RIGHT_KEY, LEFT_KEY, CTRL_C};
const t_ak		action_tab[NB_INPUT] = {moove_right, moove_left, leave_all};

int		check_key(t_42sh *sh, long buf)
{
	int i;

	i = 0;
	while (i < NB_INPUT)
	{
		if (input_tab[i] == buf)
		{
				action_tab[i](sh);
				return (1);
		}
			i++;
	}
	return (0);
}
