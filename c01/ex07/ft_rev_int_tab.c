/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:01:45 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/06 18:39:50 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int buffer;

	i = 0;
	while (i < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = buffer;
		i++;
	}
}
