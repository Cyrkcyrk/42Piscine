/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:04:34 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 20:59:00 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	if (nbr == 0)
		return (begin_list);
	if (begin_list == NULL)
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		if (begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		len;
	t_list	*right;
	t_list	*left;
	void	*buff;

	len = ft_list_size(begin_list);
	i = -1;
	while (++i < len / 2)
	{
		left = ft_list_at(begin_list, i);
		right = ft_list_at(begin_list, len - i - 1);
		buff = left->data;
		left->data = right->data;
		right->data = buff;
	}
}
