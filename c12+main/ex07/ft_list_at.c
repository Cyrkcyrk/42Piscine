/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:19:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 16:06:43 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

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
