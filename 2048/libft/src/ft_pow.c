/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:27:52 by qhonore           #+#    #+#             */
/*   Updated: 2016/01/29 14:42:48 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int pow)
{
	if (nb == 0 || pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	else if (pow == 1)
		return (nb);
	return (nb * ft_pow(nb, pow - 1));
}