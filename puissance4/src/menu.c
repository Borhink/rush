/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:12:34 by qhonore           #+#    #+#             */
/*   Updated: 2016/02/28 21:50:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		main_menu(t_env *e)
{
	ft_putstr("\033[1;1H\033[2J");
	ft_putendl("+-------- PUISSANCE 4 --------+");
	ft_putendl("|        Choose a mode        |");
	ft_putendl("|      1-Versus     2-IA      |");
	ft_putendl("+-----------------------------+");
	if (!(e->mode = read_number(1, 2)))
		return (0);
	else if (e->mode == 2)
	{
		ft_putstr("\033[1;1H\033[2J");
		ft_putendl("+-------- PUISSANCE 4 --------+");
		ft_putendl("|     Choose a difficulty     |");
		ft_putendl("| 1-Easy   2-Medium   3-Hard  |");
		ft_putendl("+-----------------------------+");
		return (!(e->ia = read_number(1, 3)) ? 0 : 1);
	}
	return (1);
}
