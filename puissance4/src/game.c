/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:36:09 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:50:49 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	ia_turn(t_env *e, t_map *m)
{
	min_max(e, m);
}

static void	player_turn(t_env *e, t_map *m)
{
	ft_putstr("Turn of player ");
	if (e->player == e->red)
		ft_putstr("\033[31mRed");
	else
		ft_putstr("\033[33mYellow");
	ft_putstr("\033[0m :\nChoose a column between 1 and ");
	ft_putnbr(m->cols);
	ft_putstr(".\n");
	e->y = -1;
	while (e->y == -1)
	{
		if (!(e->x = read_number(1, m->cols)))
			return ;
		(e->x)--;
		if (!(place_piece(e, m)))
			ft_putendl("Column already full");
	}
}

void		game_loop(t_env *e, t_map *m)
{
	if (!main_menu(e) || !init_game(e, m))
		return ;
	while (++e->turn < 42 && !(e->winner))
	{
		e->player = e->turn % 2 + 1;
		render(e, m);
		if (e->mode == 1 || (e->mode == 2 && e->player == e->red))
			player_turn(e, m);
		else
			ia_turn(e, m);
		e->player = e->turn % 2 + 1;
		e->winner = is_victory(e, m);
	}
	end_render(e, m);
}
