/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letran <letran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:24:12 by letran            #+#    #+#             */
/*   Updated: 2020/08/15 23:31:39 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		is_numeric(char c)
{
	if (c >= '1' && c <= '4')
	{
		return (1);
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		is_correct_format(char *str)
{
	int i;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (i < ft_strlen(str))
	{
		if (i % 2 == 0)
		{
			if (is_numeric(str[i]) == 0)
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

void	num_str_to_int(char *str, int *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (is_numeric(str[i]) == 1)
		{
			tab[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}
