/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:35:14 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 22:01:28 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	check_pair(t_map *m, int player, int x, int y)
{
	int		nb;
	int		i;

	i = 1;
	while (x - i >= 0 && m->map[y][x - i] == player)
		i++;
	i = ft_pow(i, i * 2);
	nb = x - i >= 0 && !m->map[y][x - i] ? i : i - 1;
	i = 1;
	while (x - i >= 0 && y - i >= 0 && m->map[y - i][x - i] == player)
		i++;
	i = ft_pow(i, i * 2);
	nb += x - i >= 0 && y - i >= 0 && !m->map[y - i][x - i] ? i : i - 1;
	i = 1;
	while (y - i >= 0 && m->map[y - i][x] == player)
		i++;
	i = ft_pow(i, i * 2);
	nb += y - i >= 0 && m->map[y - i][x] == 0 ? i : i - 1;
	return (nb);
}

static int	nb_pairs(t_map *m, int player)
{
	int		x;
	int		y;
	int		nb;

	nb = 0;
	y = -1;
	while (++y < m->lines)
	{
		x = -1;
		while (++x < m->cols)
		{
			if (m->map[y][x] == player)
			{
				nb += check_pair(m, player, x, y);
			}
		}
	}
	return (nb);
}

int			sim_turn(t_env *e, t_map *m, int x)
{
	int		y;

	if ((y = check_column(m, x)) == -1)
		return (-1);
	m->map[y][x] = e->player;
	return (y);
}

int			rate(t_env *e, t_map *m, int depth)
{
	int		win;

	if ((win = is_victory(e, m)) || e->turn + depth == 42)
	{
		if (win == 0)
			return (0);
		else if (win == 1 + e->turn % 2)
			return (100000 - depth);
		else
			return (-100000 + depth);
	}
	return (nb_pairs(m, 1 + e->turn % 2) -
	nb_pairs(m, 1 + (e->turn + 1) % 2));
}

void		min_max(t_env *e, t_map *m)
{
	int		maxi;
	int		cur;
	int		x;
	int		y;
	int		best;

	maxi = -1000000;
	x = -1;
	while (++x < m->cols)
	{
		if ((y = sim_turn(e, m, x)) != -1)
		{
			if (rate(e, m, 0) >= maxi)
				cur = min(e, m, 1);
			if (cur > maxi)
			{
				maxi = cur;
				best = x;
			}
			m->map[y][x] = 0;
		}
	}
	y = check_column(m, best);
	m->map[y][best] = 1 + e->turn % 2;
}
