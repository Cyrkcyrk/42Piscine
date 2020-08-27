/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:10:44 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 14:36:31 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1) && (s2) && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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
