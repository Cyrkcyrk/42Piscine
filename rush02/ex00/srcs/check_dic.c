/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eantoine <eantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:30:54 by eantoine          #+#    #+#             */
/*   Updated: 2020/08/23 22:21:46 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_dble_key(int line, char **str)
{
	int j;
	int k;
	int cpteur;

	j = line + 1;
	k = 0;
	{
		while (str[j])
		{
			cpteur = 0;
			k = 0;
			while ((str[line][k] >= '0' && str[line][k] <= '9')
				|| (str[j][k] >= '0' && str[j][k] <= '9'))
			{
				if (str[line][k] == str[j][k])
					cpteur++;
				k++;
			}
			if (k == cpteur)
				return (0);
			j++;
		}
	}
	return (1);
}

int	valid_table(char **tbl)
{
	int i;

	i = 0;
	while (tbl[i])
	{
		if (!(check_dble_key(i, tbl)))
			return (0);
		i++;
	}
	return (1);
}
