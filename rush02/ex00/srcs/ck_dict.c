/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:26:58 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 23:04:29 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck_dict.h"

#include <unistd.h>

int		dict_nb_key(char **strs)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (strs[++i] != NULL)
	{
		if (is_line_valid(strs[i]))
			len++;
	}
	return (len);
}

int		check_double_value(t_key *dico)
{
	int i;
	int j;

	i = -1;
	while (dico[++i].str != NULL)
	{
		j = i;
		while (dico[++j].str != NULL)
		{
			if (dico[i].nb == dico[j].nb && dico[i].power == dico[j].power)
				return (0);
		}
	}
	return (1);
}

t_key	*ft_parse_dict(char *path)
{
	t_key *ret;

	if ((ret = parse_dict_strs(parse_dict_file(path))) == NULL)
	{
		return (NULL);
	}
	if (!check_double_value(ret))
	{
		write(2, "Dict Error\n", 11);
		ft_free_dict(ret);
		return (NULL);
	}
	return (ret);
}
