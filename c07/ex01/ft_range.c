/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:43:27 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 10:13:25 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ret;
	int i;

	if (max <= min)
		return (0);
	ret = malloc((max - min) * sizeof(int));
	i = -1;
	while (++i < (max - min))
	{
		ret[i] = min + i;
	}
	return (ret);
}
