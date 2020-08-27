/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:21:46 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 14:35:24 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	sorted;
	int		i;
	char	*buffer;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while (tab[i + 1] != NULL)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				buffer = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = buffer;
				sorted = 0;
			}
			i++;
		}
	}
}
