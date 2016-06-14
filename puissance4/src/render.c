/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 21:43:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:49:58 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	print_flat_line(int cols)
{
	ft_putstr("+---");
	while (--cols > 1)
		ft_putstr("----");
	ft_putstr("----+\n");
}

static void	print_cols_nb(int cols)
{
	int		i;

	i = 0;
	ft_putstr("|");
	while (++i <= cols)
	{
		ft_putchar(' ');
		ft_putnbr(i);
		if (i < 10)
			ft_putchar(' ');
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void		render(t_env *e, t_map *m)
{
	int		x;
	int		y;

	y = -1;
	ft_putstr("\033[1;1H\033[2J");
	print_flat_line(m->cols);
	while (++y < m->lines)
	{
		x = -1;
		while (++x < m->cols)
		{
			ft_putstr("| ");
			if (m->map[y][x] == 0)
				ft_putstr("  ");
			else
				ft_putstr(m->map[y][x] == e->red ? RED : YELLOW);
		}
		ft_putstr("|\n");
		print_flat_line(m->cols);
	}
	print_cols_nb(m->cols);
}

void		end_render(t_env *e, t_map *m)
{
	render(e, m);
	if (e->winner == 0)
		ft_putendl("Draw.");
	else if (e->winner == e->red)
		ft_putendl("\033[31mRed\033[0m win.");
	else
		ft_putendl("\033[33mYellow\033[0m win.");
}
