/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 08:19:03 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/27 22:39:10 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_map	m;

	if (ac < 3)
		ft_putendl("Usage : ./puissance4 [LINES] [COLS]");
	else if ((m.lines = ft_atoi(av[1])) < 6 || m.lines > 42)
		ft_putendl("Min lines = 6, max lines = 42");
	else if ((m.cols = ft_atoi(av[2])) < 7 || m.cols > 42)
		ft_putendl("Min columns = 7, max columns = 42");
	else
	{
		srand(time(NULL));
		game_loop(&e, &m);
		free_mem(&m);
	}
	return (0);
}
