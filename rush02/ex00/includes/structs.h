/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:27:00 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/23 17:10:39 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_triplet
{
	int		nb;
	int		power;
}				t_triplet;

typedef struct	s_key
{
	int		nb;
	int		power;
	char	*str;
}				t_key;

#endif
