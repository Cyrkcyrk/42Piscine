/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_triplets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:40:33 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/23 19:12:04 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "structs.h"

void	ft_display_value(int triplet_nb, int triplet_power, t_key *dico)
{
	int		i;

	i = 0;
	while (dico[i].str)
	{
		if (triplet_nb == dico[i].nb && triplet_power == dico[i].power)
		{
			ft_putstr(dico[i].str);
			return ;
		}
		i++;
	}
}

void	ft_display_triplet(t_triplet triplet, t_key *dico)
{
	if (triplet.nb > 99)
	{
		ft_display_value(triplet.nb / 100, 0, dico);
		ft_putstr(" ");
		ft_display_value(100, 0, dico);
		triplet.nb %= 100;
		if (triplet.nb > 0)
			ft_putstr(" ");
	}
	if (triplet.nb > 19)
	{
		ft_display_value((triplet.nb / 10) * 10, 0, dico);
		triplet.nb %= 10;
		if (triplet.nb > 0)
			ft_putstr(" ");
	}
	if (triplet.nb > 0)
		ft_display_value(triplet.nb, 0, dico);
}

void	ft_display_triplets(t_triplet *triplets, t_key *dico)
{
	int		is_first;
	int		i;

	if (triplets[0].nb == 0)
	{
		ft_display_value(0, 0, dico);
		ft_putstr("\n");
		return ;
	}
	is_first = 1;
	i = -1;
	while (triplets[++i].nb != -1)
	{
		if (triplets[i].nb == 0)
			continue ;
		if (!is_first)
			ft_putstr(" ");
		is_first = 0;
		ft_display_triplet(triplets[i], dico);
		if (triplets[i].power > 0)
			ft_putstr(" ");
		if (triplets[i].power > 0)
			ft_display_value(1, triplets[i].power, dico);
	}
	ft_putstr("\n");
}
