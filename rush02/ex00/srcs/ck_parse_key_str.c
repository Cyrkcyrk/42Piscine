/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_parse_key_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:22:21 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 22:19:49 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck_dict.h"

#include <stdlib.h>

int		nb_start_at(char *str)
{
	int i;
	int seen_number;
	int zero_before;

	zero_before = 0;
	seen_number = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] != '0')
			seen_number = 1;
		if (seen_number == 0 && str[i] == '0' && str[i + 1] != ' '
				&& str[i + 1] != ':')
			zero_before++;
		i++;
	}
	return (zero_before);
}

int		is_line_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= ' ' && str[i] <= '~')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int		key_start_pos(char *str)
{
	int i;

	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int		key_len(char *str, int start)
{
	int prev_space;
	int len;

	len = 0;
	prev_space = 0;
	while (str[start] >= ' ' && str[start] <= '~')
	{
		if (str[start] == ' ' && prev_space == 0)
		{
			prev_space = 1;
			len += 1;
		}
		else if (str[start] != ' ')
		{
			prev_space = 0;
			len += 1;
		}
		start++;
	}
	return (len);
}

char	*parse_key(char *str)
{
	int		i;
	int		j;
	char	*ret;
	int		prev_space;

	i = key_start_pos(str);
	if (!(ret = malloc((key_len(str, i) + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	prev_space = 0;
	while (str[++i - 1] >= ' ' && str[i - 1] <= '~')
	{
		if (str[i - 1] == ' ' && prev_space == 0)
		{
			prev_space = 1;
			ret[j++] = ' ';
		}
		else if (str[i - 1] != ' ')
		{
			prev_space = 0;
			ret[j++] = str[i - 1];
		}
	}
	ret[j] = '\0';
	return (ret);
}
