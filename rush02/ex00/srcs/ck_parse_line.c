/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:05:47 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 22:23:44 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck_dict.h"

#include <stdlib.h>
#include <unistd.h>

int		check_if_followed_zero(char *str, int len_trip)
{
	int i;

	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		if (i >= len_trip && str[i] != '0')
			return (0);
	}
	return (1);
}

void	parse_number(t_key *dict, char *str)
{
	char	triplet[4];
	int		i;
	int		len_num;
	int		len_trip;
	int		zero_bf;

	zero_bf = nb_start_at(str);
	len_num = 0;
	while (str[zero_bf + len_num] >= '0' && str[zero_bf + len_num] <= '9')
		len_num++;
	len_trip = (len_num % 3 == 0) ? 3 : len_num % 3;
	i = -1;
	while (++i < len_trip)
		triplet[i] = str[zero_bf + i];
	triplet[len_trip] = '\0';
	if (!check_if_followed_zero(str, len_trip) && len_num >= 4)
	{
		dict->power = -1;
		dict->nb = -1;
	}
	else
	{
		dict->power = len_num - len_trip;
		dict->nb = ft_atoi(triplet);
	}
}

int		parse_line(t_key *key, char *str, int *pos)
{
	if (is_line_valid(str))
	{
		parse_number(key, str);
		if (!(key->str = parse_key(str)))
		{
			write(2, "Malloc Error\n", 13);
			key->str = NULL;
			return (0);
		}
		*pos += 1;
		return (1);
	}
	return (1);
}

t_key	*dict_allocation(char **strs)
{
	int		len;
	t_key	*ret;

	if (strs == NULL)
		return (NULL);
	if ((len = dict_nb_key(strs)) == 0 || valid_table(strs) == 0)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	if (!(ret = malloc((len + 1) * sizeof(t_key))))
	{
		write(2, "Malloc Error\n", 13);
		return (NULL);
	}
	return (ret);
}

t_key	*parse_dict_strs(char **strs)
{
	int		i;
	t_key	*ret;
	int		pos;

	if (!(ret = dict_allocation(strs)))
		return (NULL);
	i = -1;
	pos = 0;
	while (strs[++i] != NULL)
	{
		if (parse_line(&ret[pos], strs[i], &pos) == 0)
		{
			ft_free_strs(strs);
			ft_free_tab_key(ret);
			return (NULL);
		}
	}
	ft_free_strs(strs);
	ret[pos].str = NULL;
	return (ret);
}
