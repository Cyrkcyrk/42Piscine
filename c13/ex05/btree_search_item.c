/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:43:59 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 14:38:24 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
{
	char cmp;

	if (( cmp = (*cmpf)(data_ref, root->item)) == 0)
		return (root);
	else if (cmp < 0)
	{
		if (root->left != 0)
			return (btree_search_item(root->left, data_ref, cmpf));
		else
			return (NULL);
	}
	else
	{
		if (root->right != 0)
			return (btree_search_item(root->right, data_ref, cmpf));
		else
			return (NULL);
	}
}
