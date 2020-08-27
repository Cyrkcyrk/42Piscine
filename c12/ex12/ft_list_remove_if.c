/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:14:15 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 00:22:57 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list *maillon;
	t_list *prev;
	t_list *tmp;

	prev = NULL;
	maillon = *begin_list;
	while (maillon)
	{
		if ((*cmp)(maillon->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = maillon->next;
			else
				prev->next = maillon->next;
			tmp = maillon;
			maillon = maillon->next;
			(*free_fct)(tmp->data);
			free(tmp);
		}
		else
		{
			prev = maillon;
			maillon = maillon->next;
		}
	}
}
