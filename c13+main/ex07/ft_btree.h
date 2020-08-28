/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:55:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 19:14:27 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;
typedef struct	s_list
{
	struct s_list	*next;
	int				level;
	t_btree			*data;
}				t_list;
t_btree			*btree_create_node(void *item);

#endif
