/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 08:52:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 22:01:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "libft.h"
# include <time.h>

# define RED "\033[31mO \033[0m"
# define YELLOW "\033[33mO \033[0m"

typedef struct	s_map
{
	int		cols;
	int		lines;
	int		**map;
}				t_map;

typedef struct	s_env
{
	int		ia;
	int		mode;
	int		winner;
	int		red;
	int		player;
	int		turn;
	int		x;
	int		y;
}				t_env;

void			game_loop(t_env *e, t_map *m);
void			min_max(t_env *e, t_map *m);
void			render(t_env *e, t_map *m);
void			end_render(t_env *e, t_map *m);
void			free_mem(t_map *m);
int			sim_turn(t_env *e, t_map *m, int x);
int				rate(t_env *e, t_map *m, int depth);
int				min(t_env *e, t_map *m, int depth);
int				max(t_env *e, t_map *m, int depth);
int				place_piece(t_env *e, t_map *m);
int				init_game(t_env *e, t_map *m);
int				read_number(int min, int max);
int				main_menu(t_env *e);
int				check_cross(t_env *e, t_map *m, int px, int py);
int				check_diag(t_env *e, t_map *m, int px, int py);
int				check_column(t_map *m, int x);
int				is_victory(t_env *e, t_map *m);

#endif
