/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazouz <mmazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:47:11 by mmazouz           #+#    #+#             */
/*   Updated: 2016/01/31 20:47:55 by mmazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			count_empty(t_vect2i p, int map[4][4], char dir)
{
	int		n;

	n = 0;
	while (dir == 'R' && (p.x - n) && map[p.y][p.x - n - 1] == 0)
		n++;
	while (dir == 'L' && (p.x + n) < 3 && map[p.y][p.x + n + 1] == 0)
		n++;
	while (dir == 'D' && (p.y - n) && map[p.y - n - 1][p.x] == 0)
		n++;
	while (dir == 'U' && (p.y + n) < 3 && map[p.y + n + 1][p.x] == 0)
		n++;
	return (n);
}
