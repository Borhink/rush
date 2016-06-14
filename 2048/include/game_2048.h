/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:03:38 by qhonore           #+#    #+#             */
/*   Updated: 2016/01/31 23:19:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include <time.h>
# include "libft.h"

# define IS_POWER_OF_TWO(x) (((x&(x-1)) == 0) && (x!=0))

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_vect2i
{
	int		x;
	int		y;
}				t_vect2i;

typedef struct	s_env
{
	int		map[4][4];
	int		score;
	int		key;
}				t_env;

void			game_loop(void);

void			draw(t_env *e);

t_vect2i		set_vect2i(int x, int y);

void			new_nb(int map[4][4], int i);

void			ft_move(int map[4][4], int *score, char dir);

int				count_empty(t_vect2i p, int map[4][4], char dir);

int				can_move(int map[4][4], char dir);

void			check_end(int score, int map[4][4]);

#endif
