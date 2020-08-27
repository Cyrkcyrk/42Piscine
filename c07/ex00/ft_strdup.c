/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:32:47 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 10:13:08 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (str[len])
		len++;
	ret = malloc((len + 1) * sizeof(char));
	while (str[++i])
		ret[i] = str[i];
	ret[len] = '\0';
	return (ret);
}
