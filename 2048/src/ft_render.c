/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:40:32 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 23:24:12 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	get_color(int nb)
{
	int		color;

	color = 1;
	while (nb > 2)
	{
		nb /= 2;
		color++;
	}
	return (color);
}

static void	draw_numbers(int map[4][4], t_vect2i s)
{
	t_vect2i	mp;
	t_vect2i	p;
	char		*nb;

	mp.y = -1;
	while (++mp.y < 4)
	{
		mp.x = -1;
		while (++mp.x < 4)
		{
			if (map[mp.y][mp.x] != 0)
			{
				nb = ft_itoa(map[mp.y][mp.x]);
				p.x = (s.x * mp.x) + (s.x / 2) - (ft_strlen(nb) / 2);
				p.y = (s.y * mp.y) + (s.y / 2);
				attron(COLOR_PAIR(get_color(map[mp.y][mp.x])));
				mvprintw(p.y + 3, p.x, nb);
				attroff(COLOR_PAIR(get_color(map[mp.y][mp.x])));
				ft_memdel((void**)&nb);
			}
		}
	}
}

static void	draw_ui(char *score, t_vect2i s)
{
	char	*tmp;

	tmp = ft_strjoin("Score : ", score);
	ft_memdel((void**)&score);
	mvprintw(2, s.x * 2 - (ft_strlen(tmp) / 2), tmp);
	ft_memdel((void**)&tmp);
	mvprintw(s.y * 4 + 4, s.x * 2 - 9, "Press <Esc> to quit");
}

void		draw(t_env *e)
{
	t_vect2i	p;
	t_vect2i	s;

	s = set_vect2i((COLS - 1) / 4, (LINES - 1) / 4 - 1);
	draw_ui(ft_itoa(e->score), s);
	p.y = -1;
	check_end(e->score, e->map);
	while (++p.y <= (s.y * 4) + 1)
	{
		p.x = -1;
		while (++p.x <= (s.x * 4))
		{
			if (p.x < (s.x * 4) && (p.y % (s.y) == 0 || p.y == (s.y * 4)))
			{
				while (p.x < (s.x * 4))
					mvprintw(p.y + 3, p.x, ((p.x++) % (s.x) == 0) ? "+" : "-");
				mvprintw(p.y + 3, p.x, "+");
			}
			else if (p.y < (s.y * 4)
						&& (p.x % (s.x) == 0 || p.x == (s.x * 4)))
				mvprintw(p.y + 3, p.x, "|");
		}
	}
	draw_numbers(e->map, s);
}
