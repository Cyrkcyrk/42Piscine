/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eantoine <eantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:41:22 by eantoine          #+#    #+#             */
/*   Updated: 2020/08/23 22:56:51 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "triplets.h"
#include "structs.h"
#include "ft_parse_dict.h"

int		int_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (i);
}

int		test_zero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		++i;
	}
	return (1);
}

char	*convert_wo_zero(char *convert)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (convert[i] == '0')
		i++;
	if (!(res = (char*)malloc((ft_strlen(convert) - i) * sizeof(char) + 1)))
		return (NULL);
	while (convert[i])
	{
		res[j] = convert[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

int		ft_convert_arg(char **convert, int argc, char **argv)
{
	if (argc == 2)
		*convert = argv[1];
	if (argc == 3)
		*convert = argv[2];
	if ((argc < 2 || argc > 3) || !int_valid(*convert))
	{
		ft_putstr(ERROR);
		return (0);
	}
	if (test_zero(*convert))
	{
		if (!(*convert = malloc(2 * sizeof(char))))
			return (0);
		(*convert)[0] = '0';
		(*convert)[1] = '\0';
	}
	else if (!(*convert = convert_wo_zero(*convert)))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char		*convert;
	t_key		*dico;
	t_triplet	*triplets;

	dico = NULL;
	if (!(ft_convert_arg(&convert, argc, argv)))
		return (0);
	if (argc == 3)
		dico = ft_parse_dict(argv[1]);
	else if (argc == 2)
		dico = ft_parse_dict(DICT_PATH);
	if (dico == NULL)
		free(convert);
	if (dico == NULL)
		return (0);
	if (!(triplets = ft_create_triplet_tab(convert, dico)))
	{
		ft_free_main(dico, triplets, convert, 0);
		return (0);
	}
	ft_display_triplets(triplets, dico);
	ft_free_main(dico, triplets, convert, 1);
	return (0);
}
