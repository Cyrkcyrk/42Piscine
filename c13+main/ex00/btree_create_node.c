/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:56:56 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 19:17:37 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree *ret;

	if (!(ret = malloc(sizeof(t_btree))))
		return (NULL);
	ret->right = 0;
	ret->left = 0;
	ret->item = item;
	return (ret);
}
