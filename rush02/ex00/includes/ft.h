/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eantoine <eantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:43:39 by eantoine          #+#    #+#             */
/*   Updated: 2020/08/23 23:00:16 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define ERROR "Error\n"
# define DICT_PATH "numbers.dict"
# include <unistd.h>
# include "structs.h"

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strdup(char *src);

void	ft_free_main(t_key *dico, t_triplet *triplets, char *convert,
		int is_triplets_freeable);

#endif
