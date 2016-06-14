/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:45:31 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 20:46:37 by mmazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		new_nb(int map[4][4], int i)
{
	int		pos;
	int		nb;

	while (i--)
	{
		pos = rand() % 16;
		while (map[pos / 4][pos % 4] != 0)
			pos = rand() % 16;
		nb = ft_pow(2, (rand() % 2) + 1);
		map[pos / 4][pos % 4] = nb;
	}
}