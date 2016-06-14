/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:52:38 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 19:10:02 by mmazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	can_move_up(int map[4][4], char dir)
{
	t_vect2i	p;
	int			m;

	p.x = -1;
	m = 0;
	while (++p.x < 4)
	{
		p.y = -1;
		while (++p.y < 4)
		{
			if (map[p.y][p.x])
				if (p.y && map[p.y - 1][p.x] == 0)
					return (1);
			m = count_empty(p, map, dir);
			if ((p.y + m) < 3 && map[p.y + m + 1][p.x] == map[p.y][p.x])
				return (1);
		}
	}
	return (0);
}

static int	can_move_down(int map[4][4], char dir)
{
	t_vect2i	p;
	int			m;

	p.x = -1;
	m = 0;
	while (++p.x < 4)
	{
		p.y = 4;
		while (--p.y >= 0)
		{
			if (map[p.y][p.x])
				if (p.y < 3 && map[p.y + 1][p.x] == 0)
					return (1);
			m = count_empty(p, map, dir);
			if ((p.y - m) > 0 && map[p.y - m - 1][p.x] == map[p.y][p.x])
				return (1);
		}
	}
	return (0);
}

static int	can_move_left(int map[4][4], char dir)
{
	t_vect2i	p;
	int			m;

	p.y = -1;
	m = 0;
	while (++p.y < 4)
	{
		p.x = -1;
		while (++p.x < 4)
		{
			if (map[p.y][p.x])
				if (p.x && map[p.y][p.x - 1] == 0)
					return (1);
			m = count_empty(p, map, dir);
			if ((p.x + m) < 3 && map[p.y][p.x + m + 1] == map[p.y][p.x])
				return (1);
		}
	}
	return (0);
}

static int	can_move_right(int map[4][4], char dir)
{
	t_vect2i	p;
	int			m;

	p.y = -1;
	m = 0;
	while (++p.y < 4)
	{
		p.x = 4;
		while (--p.x >= 0)
		{
			if (map[p.y][p.x])
				if (p.x < 3 && map[p.y][p.x + 1] == 0)
					return (1);
			m = count_empty(p, map, dir);
			if ((p.x - m) && map[p.y][p.x - m - 1] == map[p.y][p.x])
				return (1);
		}
	}
	return (0);
}

int			can_move(int map[4][4], char dir)
{
	if (dir == 'U')
		return (can_move_up(map, dir));
	else if (dir == 'D')
		return (can_move_down(map, dir));
	else if (dir == 'L')
		return (can_move_left(map, dir));
	else if (dir == 'R')
		return (can_move_right(map, dir));
	return (can_move_up(map, 'U') + can_move_down(map, 'D')
			+ can_move_left(map, 'L') + can_move_right(map, 'R'));
}
