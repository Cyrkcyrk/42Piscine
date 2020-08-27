/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:38:37 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 22:55:59 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck_dict.h"

#include <stdlib.h>

void	ft_free_strs(char **strs)
{
	int i;

	i = -1;
	while (strs[++i] != NULL)
	{
		free(strs[i]);
	}
	free(strs);
}

void	ft_free_tab_key(t_key *tab)
{
	int i;

	i = -1;
	while (tab[++i].str != NULL)
	{
		free(tab[i].str);
	}
	free(tab);
}

void	ft_free_dict(t_key *tab)
{
	ft_free_tab_key(tab);
}

void	ft_free_main(t_key *dico, t_triplet *triplets, char *convert,
		int is_triplets_freeable)
{
	if (is_triplets_freeable)
		free(triplets);
	free(convert);
	ft_free_dict(dico);
}
