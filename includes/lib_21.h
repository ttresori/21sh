/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_21.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:18:55 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/20 20:28:55 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIB_21_H
# define LIB_21_H

# include "libft/libft.h"
# include <sys/time.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>

# define NB_INPUT_SELECT 7
# define NB_INPUT 1
# define RIGHT_KEY 4414235
# define LEFT_KEY 4479771
# define HOME 4741915
# define END 4610843
# define CTRL_C 3
# define CTRL_D 4
# define DEL 127
# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define TAB 9
# define OPT_B 11241698
# define OPT_F 37574
# define OPT_C 42947
# define OPT_X 8948194
# define OPT_V 10127586
# define OPT_UP 1096489755
# define OPT_DOWN 1113266971

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_lst;

typedef struct		s_env
{
	char			**env;
	size_t			size_env;
}					t_env;
typedef struct		s_term
{
	char			*name_term;
	struct	termios term;
	struct	termios reset;
}					t_term;

t_term				g_term;

typedef struct		s_42sh
{
	t_env			*s_env;
	t_list			*list;
}					t_42sh;

typedef				void(*t_ak)(t_42sh *sh);

int					check_key(t_42sh *sh, long buf);

/***************************************************************************** \
|                              FREE                                           |
\*****************************************************************************/

void				free_all(t_42sh *sh);

/***************************************************************************** \
|                              INIT_STRUCT                                           |
\*****************************************************************************/

int					init_struct(t_42sh *sh, char ***env);

/***************************************************************************** \
|                              MOOVE                                           |
\*****************************************************************************/

void			moove_right(t_42sh *sh);


#endif
