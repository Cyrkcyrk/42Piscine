/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:57:55 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 00:24:22 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*ret;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	ret = malloc(len * sizeof(int));
	i = 0;
	if (ret == NULL)
		return (-1);
	while (min < max)
	{
		ret[i] = min;
		i++;
		min++;
	}
	*range = ret;
	return (len);
}
