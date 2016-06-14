/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:42:41 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 23:26:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init_map(int map[4][4])
{
	t_vect2i	p;

	srand(time(NULL));
	p.y = -1;
	while (++p.y < 4)
	{
		p.x = -1;
		while (++p.x < 4)
			map[p.y][p.x] = 0;
	}
	new_nb(map, 2);
}

static void	ft_play(t_env *e)
{
	while ((e->key = getch()) != 27)
	{
		if (!can_move(e->map, 'A'))
			break ;
		if (e->key == KEY_LEFT)
			ft_move(e->map, &(e->score), 'L');
		else if (e->key == KEY_UP)
			ft_move(e->map, &(e->score), 'U');
		else if (e->key == KEY_DOWN)
			ft_move(e->map, &(e->score), 'D');
		else if (e->key == KEY_RIGHT)
			ft_move(e->map, &(e->score), 'R');
		if (COLS < 33 || LINES < 13)
		{
			endwin();
			ft_putendl("Window is too small (33 / 13 min)");
			return ;
		}
		clear();
		draw(e);
		refresh();
	}
}

void		game_loop(void)
{
	t_env	e;

	init_map(e.map);
	clear();
	draw(&e);
	refresh();
	ft_play(&e);
}
