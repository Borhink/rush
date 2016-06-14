/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:12:04 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:47:21 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include <stdlib.h>

int		place_piece(t_env *e, t_map *m)
{
	if ((e->y = check_column(m, e->x)) == -1)
		return (0);
	m->map[e->y][e->x] = 1 + e->turn % 2;
	return (1);
}

int		init_game(t_env *e, t_map *m)
{
	int		x;
	int		y;

	y = -1;
	if (!(m->map = (int**)malloc(sizeof(int*) * m->lines)))
		return (0);
	while (++y < m->lines)
	{
		x = -1;
		if (!(m->map[y] = (int*)malloc(sizeof(int) * m->cols)))
			return (0);
		while (++x < m->cols)
			m->map[y][x] = 0;
	}
	e->red = rand() % 2 + 1;
	e->winner = 0;
	e->turn = -1;
	return (1);
}

void	free_mem(t_map *m)
{
	int		i;

	i = -1;
	while (++i < m->lines && m->map)
		if (m->map[i])
			free(m->map[i]);
	if (m->map)
		free(m->map);
}

int		read_number(int min, int max)
{
	char	*str;
	int		ret;
	int		nb;

	str = NULL;
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (!ft_isdigit(*str) || (nb = ft_atoi(str)) < min || nb > max)
		{
			ft_putstr("Number must be between ");
			ft_putnbr(min);
			ft_putstr(" and ");
			ft_putnbr(max);
			ft_putendl(" included.");
			if (str)
				free(str);
		}
		else
			break ;
	}
	if (str)
		free(str);
	return (ret == -1 ? 0 : nb);
}
