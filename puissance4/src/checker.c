/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:15:19 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:35:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_cross(t_env *e, t_map *m, int px, int py)
{
	int		x;
	int		y;
	int		aligned;

	aligned = 0;
	x = px;
	while (x < m->cols && m->map[py][x++] == e->player)
		aligned++;
	x = px - 1;
	while (x >= 0 && m->map[py][x--] == e->player)
		aligned++;
	if (aligned >= 4)
		return (1);
	aligned = 0;
	y = py;
	while (y < m->lines && m->map[y++][px] == e->player)
		aligned++;
	y = py - 1;
	while (y >= 0 && m->map[y--][px] == e->player)
		aligned++;
	return (aligned >= 4 ? 1 : 0);
}

int		check_diag(t_env *e, t_map *m, int px, int py)
{
	int		x;
	int		y;
	int		aligned;

	aligned = 0;
	x = px;
	y = py;
	while (y < m->lines && x < m->cols && m->map[y++][x++] == e->player)
		aligned++;
	x = px - 1;
	y = py - 1;
	while (y >= 0 && x >= 0 && m->map[y--][x--] == e->player)
		aligned++;
	if (aligned >= 4)
		return (1);
	aligned = 0;
	x = px;
	y = py;
	while (y >= 0 && x < m->cols && m->map[y--][x++] == e->player)
		aligned++;
	x = px - 1;
	y = py + 1;
	while (y < m->lines && x >= 0 && m->map[y++][x--] == e->player)
		aligned++;
	return (aligned >= 4 ? 1 : 0);
}

int		check_column(t_map *m, int x)
{
	int		y;

	y = 0;
	if (m->map[y][x])
		return (-1);
	while (y + 1 < m->lines && !m->map[y + 1][x])
		y++;
	return (y);
}

int		is_victory(t_env *e, t_map *m)
{
	int		x;
	int		y;

	y = -1;
	while (++y < m->lines)
	{
		x = -1;
		while (++x < m->cols)
		{
			if (check_cross(e, m, x, y) || check_diag(e, m, x, y))
				return (e->player);
		}
	}
	return (0);
}
