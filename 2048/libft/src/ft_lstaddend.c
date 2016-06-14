/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:10:28 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/09 17:25:23 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst || !new)
		return ;
	list = *alst;
	if (!list)
	{
		*alst = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}
