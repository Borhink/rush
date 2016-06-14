/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 21:40:07 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:59:16 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int			max(t_env *e, t_map *m, int depth)
{
	int		maxi;
	int		cur;
	int		x;
	int		y;

	if (depth > e->ia || e->turn + depth == 42 || is_victory(e, m))
		return (rate(e, m, depth - 1));
	e->player = 1 + e->player % 2;
	maxi = -1000000;
	x = -1;
	while (++x < m->cols)
	{
		if ((y = sim_turn(e, m, x)) != -1)
		{
			if (rate(e, m, depth) >= maxi)
				cur = min(e, m, depth + 1);
			if (cur > maxi)
				maxi = cur;
			m->map[y][x] = 0;
		}
	}
	e->player = 1 + e->player % 2;
	return (maxi);
}

int			min(t_env *e, t_map *m, int depth)
{
	int		mini;
	int		cur;
	int		x;
	int		y;

	if (depth > e->ia || e->turn + depth == 42 || is_victory(e, m))
		return (rate(e, m, depth - 1));
	e->player = 1 + e->player % 2;
	mini = 1000000;
	x = -1;
	while (++x < m->cols)
	{
		if ((y = sim_turn(e, m, x)) != -1)
		{
			if (rate(e, m, depth) <= mini)
				cur = max(e, m, depth + 1);
			if (cur < mini)
				mini = cur;
			m->map[y][x] = 0;
		}
	}
	e->player = 1 + e->player % 2;
	return (mini);
}
