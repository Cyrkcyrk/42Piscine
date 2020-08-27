/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:10:44 by rmouduri          #+#    #+#             */
/*   Updated: 2020/08/27 11:11:53 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_board.h"

void	free_char_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (++i < g_row)
		if (tab[i] != NULL)
			free(tab[i]);
	free(tab);
}

void	free_int_tab(int **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (++i < g_row)
		if (tab[i] != NULL)
			free(tab[i]);
	free(tab);
}
