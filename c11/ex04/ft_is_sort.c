/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 11:31:46 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 15:52:31 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort_asc(int *tab, int len, int (*f)(int, int))
{
	int i;

	i = -1;
	while (++i < len - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}

int		ft_is_sort_desc(int *tab, int len, int (*f)(int, int))
{
	int i;

	i = -1;
	while (++i < len - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (length <= 1 || tab == 0)
		return (1);
	if (ft_is_sort_asc(tab, length, f) || ft_is_sort_desc(tab, length, f))
		return (1);
	return (0);
}
