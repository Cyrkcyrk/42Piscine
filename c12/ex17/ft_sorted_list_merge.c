/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:41:35 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 13:38:44 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_insert_sort(t_list **begin_list, t_list *to_insert, int (*cmp)())
{
	t_list *maillon;

	maillon = *begin_list;
	if (maillon == NULL || (*cmp)(to_insert->data, maillon->data) < 0)
	{
		*begin_list = to_insert;
		to_insert->next = maillon;
		return ;
	}
	while (maillon->next && (*cmp)(to_insert->data, maillon->next->data) > 0)
		maillon = maillon->next;
	to_insert->next = maillon->next;
	maillon->next = to_insert;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list *prev;

	while (begin_list2)
	{
		prev = begin_list2;
		begin_list2 = begin_list2->next;
		ft_insert_sort(begin_list1, prev, cmp);
	}
}
