/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triplets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:36:36 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/23 21:59:51 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "structs.h"

int			ft_create_nb_triplet(char *str, int id, int len, int *written_len)
{
	char	str_nb[4];
	int		first;
	int		i;

	i = 0;
	while (i < 4)
		str_nb[i++] = 0;
	first = 1;
	i = 0;
	while (first || (id == 0 && len % 3 != 0) || (id != 0 && i < 3))
	{
		str_nb[i] = str[i];
		i++;
		len--;
		first = 0;
	}
	*written_len += ft_strlen(str_nb);
	return (ft_atoi(str_nb));
}

int			is_possible_number(t_triplet triplet, t_key *dico)
{
	int		i;

	i = 0;
	while (dico[i].str)
	{
		if (triplet.power == dico[i].power)
			return (1);
		i++;
	}
	ft_putstr(ERROR);
	return (0);
}

t_triplet	*ft_create_triplet_tab(char *str, t_key *dico)
{
	t_triplet	*triplets;
	int			len;
	int			power;
	int			written_len;
	int			i;

	len = ft_strlen(str);
	power = len / 3;
	if (len % 3 == 0)
		power--;
	if (!(triplets = malloc(sizeof(t_triplet) * (power + 2))))
		return (NULL);
	triplets[power + 1].nb = -1;
	written_len = 0;
	i = 0;
	while (i <= power)
	{
		triplets[i].nb = ft_create_nb_triplet(str + written_len, i,
				len, &written_len);
		triplets[i].power = 3 * (power - i);
		i++;
	}
	if (!is_possible_number(triplets[0], dico))
		return (NULL);
	return (triplets);
}
