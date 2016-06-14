/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:10:04 by qhonore           #+#    #+#             */
/*   Updated: 2016/01/31 23:10:59 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init_colors(void)
{
	start_color();
	init_color(COLOR_BLUE, 1000, 280, 0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_WHITE);
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	init_pair(10, COLOR_YELLOW, COLOR_WHITE);
	init_pair(11, COLOR_BLUE, COLOR_WHITE);
	init_pair(12, COLOR_GREEN, COLOR_WHITE);
	init_pair(13, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(14, COLOR_CYAN, COLOR_WHITE);
	init_pair(15, COLOR_WHITE, COLOR_BLUE);
}

int			main(void)
{
	enum e_const	s;

	s = WIN_VALUE;
	if (s == WIN_VALUE && !IS_POWER_OF_TWO(s))
	{
		ft_putendl("Victory condition is not a power of 2");
		return (0);
	}
	initscr();
	if (COLS < 33 || LINES < 13)
	{
		endwin();
		ft_putstr("Window is too small (33 / 13 min)");
		return (0);
	}
	init_colors();
	srand(time(NULL));
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	game_loop();
	endwin();
	return (0);
}
