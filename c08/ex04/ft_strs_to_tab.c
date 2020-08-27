/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:08:11 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/17 16:59:13 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (str[len])
		len++;
	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (str[++i])
		ret[i] = str[i];
	ret[len] = '\0';
	return (ret);
}

struct s_stock_str		*ft_if_null(void)
{
	t_stock_str		*tab;

	if (!(tab = malloc(sizeof(t_stock_str))))
		return (NULL);
	if (!(tab[0].str = malloc(sizeof(char))))
		return (NULL);
	tab[0].str = 0;
	return (tab);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*tab;
	int				i;

	if (ac <= 0)
		return (ft_if_null());
	if (!(tab = malloc((ac + 1) * sizeof(t_stock_str))))
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		if (!(tab[i].str = ft_strdup(av[i])))
			return (NULL);
		if (!(tab[i].copy = ft_strdup(av[i])))
			return (NULL);
	}
	if (!(tab[ac].str = malloc(sizeof(char))))
		return (NULL);
	tab[ac].str = 0;
	return (tab);
}
