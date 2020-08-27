/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:03:47 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 13:47:50 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	invert_node(t_list **begin_list, t_list **prev, t_list **maillon,
	int *sorted)
{
	*sorted = 0;
	if (*prev == NULL)
		*begin_list = (*maillon)->next;
	else
		(*prev)->next = (*maillon)->next;
	*prev = (*maillon)->next;
	(*maillon)->next = (*prev)->next;
	(*prev)->next = *maillon;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*maillon;
	int		sorted;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		maillon = *begin_list;
		prev = NULL;
		while (maillon->next)
		{
			if ((*cmp)(maillon->data, maillon->next->data) > 0)
				invert_node(begin_list, &prev, &maillon, &sorted);
			else
			{
				prev = maillon;
				maillon = maillon->next;
			}
		}
	}
}
