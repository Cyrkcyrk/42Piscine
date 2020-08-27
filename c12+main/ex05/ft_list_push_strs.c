/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:06:07 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 00:19:40 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	if (!(tmp = ft_create_elem(data)))
		return ;
	tmp->next = *begin_list;
	*begin_list = tmp;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*anchor;

	anchor = NULL;
	i = -1;
	while (++i < size)
		ft_list_push_front(&anchor, strs[i]);
	return (anchor);
}
