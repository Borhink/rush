/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 23:28:44 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 18:07:13 by mmazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	move_right(int map[4][4], int *score, char dir)
{
	t_vect2i	p;
	int			m;

	p.y = -1;
	while (++p.y < 4)
	{
		p.x = 4;
		while (--p.x >= 0)
		{
			m = count_empty(p, map, dir);
			if ((p.x - m) && map[p.y][p.x] == 0)
			{
				map[p.y][p.x] = map[p.y][p.x - m - 1];
				map[p.y][p.x - m - 1] = 0;
			}
			m = count_empty(p, map, dir);
			if ((p.x - m) && map[p.y][p.x - m - 1] == map[p.y][p.x])
			{
				map[p.y][p.x] *= 2;
				map[p.y][p.x - m - 1] = 0;
				*score += map[p.y][p.x];
			}
		}
	}
	new_nb(map, 1);
}

static void	move_left(int map[4][4], int *score, char dir)
{
	t_vect2i	p;
	int			m;

	p.y = -1;
	while (++p.y < 4)
	{
		p.x = -1;
		while (++p.x < 4)
		{
			m = count_empty(p, map, dir);
			if ((p.x + m) < 3 && map[p.y][p.x] == 0)
			{
				map[p.y][p.x] = map[p.y][p.x + m + 1];
				map[p.y][p.x + m + 1] = 0;
			}
			m = count_empty(p, map, dir);
			if ((p.x + m) < 3 && map[p.y][p.x + m + 1] == map[p.y][p.x])
			{
				map[p.y][p.x] *= 2;
				map[p.y][p.x + m + 1] = 0;
				*score += map[p.y][p.x];
			}
		}
	}
	new_nb(map, 1);
}

static void	move_down(int map[4][4], int *score, char dir)
{
	t_vect2i	p;
	int			m;

	p.x = -1;
	while (++p.x < 4)
	{
		p.y = 4;
		while (--p.y >= 0)
		{
			m = count_empty(p, map, dir);
			if ((p.y - m) && map[p.y][p.x] == 0)
			{
				map[p.y][p.x] = map[p.y - m - 1][p.x];
				map[p.y - m - 1][p.x] = 0;
			}
			m = count_empty(p, map, dir);
			if ((p.y - m) && map[p.y - m - 1][p.x] == map[p.y][p.x])
			{
				map[p.y][p.x] *= 2;
				map[p.y - m - 1][p.x] = 0;
				*score += map[p.y][p.x];
			}
		}
	}
	new_nb(map, 1);
}

static void	move_up(int map[4][4], int *score, char dir)
{
	t_vect2i	p;
	int			m;

	p.x = -1;
	while (++p.x < 4)
	{
		p.y = -1;
		while (++p.y < 4)
		{
			m = count_empty(p, map, dir);
			if ((p.y + m) < 3 && map[p.y][p.x] == 0)
			{
				map[p.y][p.x] = map[p.y + m + 1][p.x];
				map[p.y + m + 1][p.x] = 0;
			}
			m = count_empty(p, map, dir);
			if ((p.y + m) < 3 && map[p.y + m + 1][p.x] == map[p.y][p.x])
			{
				map[p.y][p.x] *= 2;
				map[p.y + m + 1][p.x] = 0;
				*score += map[p.y][p.x];
			}
		}
	}
	new_nb(map, 1);
}

void		ft_move(int map[4][4], int *score, char dir)
{
	if (dir == 'U' && can_move(map, dir))
		move_up(map, score, dir);
	else if (dir == 'D' && can_move(map, dir))
		move_down(map, score, dir);
	else if (dir == 'R' && can_move(map, dir))
		move_right(map, score, dir);
	else if (dir == 'L' && can_move(map, dir))
		move_left(map, score, dir);
}
