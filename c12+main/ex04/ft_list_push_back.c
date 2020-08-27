/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:00:31 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 00:19:02 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;
	t_list *maillon;

	if (!(tmp = ft_create_elem(data)))
		return ;
	if (*begin_list == NULL)
		*begin_list = tmp;
	else
	{
		maillon = *begin_list;
		while (maillon->next)
			maillon = maillon->next;
		maillon->next = tmp;
	}
}
