/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:26:28 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/25 00:23:42 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *next;
	t_list *maillon;
	t_list *prev;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	maillon = *begin_list;
	prev = NULL;
	while (maillon->next)
	{
		next = maillon->next;
		maillon->next = prev;
		prev = maillon;
		maillon = next;
	}
	maillon->next = prev;
	*begin_list = maillon;
}
