/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:47:27 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 15:43:22 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int i;

	ret = malloc(length * sizeof(int));
	i = -1;
	while (++i < length)
	{
		ret[i] = (*f)(tab[i]);
	}
	return (ret);
}
