/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_victory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:43:32 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 23:22:59 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	check_map(int map[4][4])
{
	t_vect2i	p;
	int			tmp;

	p.y = -1;
	tmp = 0;
	while (++p.y < 4)
	{
		p.x = -1;
		while (++p.x < 4)
			if (map[p.y][p.x] > tmp)
				tmp = map[p.y][p.x];
	}
	return (tmp);
}

void		check_end(int score, int map[4][4])
{
	enum e_const	s;
	char			*str;

	s = WIN_VALUE;
	if (s == WIN_VALUE)
	{
		if (check_map(map) >= (int)s)
		{
			mvprintw(0, COLS / 2 - 3, "You win");
			if (!can_move(map, 'A'))
			{
				endwin();
				ft_putendl("You win");
			}
		}
		else if (!can_move(map, 'A'))
		{
			endwin();
			ft_putendl("You loose");
		}
		str = ft_itoa(score);
		ft_putendl(str);
		ft_memdel((void**)&str);
	}
}
