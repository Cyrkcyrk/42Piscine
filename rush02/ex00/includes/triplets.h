/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:23:57 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/23 21:58:13 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIPLETS_H
# define TRIPLETS_H

# include "structs.h"

t_triplet	*ft_create_triplet_tab(char *str, t_key *dico);
void		ft_display_triplets(t_triplet *triplets, t_key *dico);

#endif
