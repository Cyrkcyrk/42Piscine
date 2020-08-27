/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:05:08 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 16:38:20 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_list	list_create_elem(t_btree *data, int level)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	ret->level = level;
	ret->data = data;
	return (ret);
}

/*
int		btree_nb_node(b_tree *root)
{
	if (root = NULL)
		return (0);
	return (1 + btree_nb_node(root->left) + btree_nb_node(root->right));
}
*/

t_list	*add_child_to_queue(t_btree *root, t_list *queue)
{
	t_list *last;

	last = queue;
	if (root->left == 0 && root->right == 0)
		return ;
	while(queue->next)
		queue = queue->next;
	if (root->left != 0)
	{
		if(!(last->next = list_create_elem(root->left, queue->level + 1)))
			return (NULL);
		last = last->next;
	}
	if (root->right != 0)
	{
		if(!(last->next = list_create_elem(root->left, queue->level + 1)))
			return (NULL);
		last = last->next;
	}
	return (last);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
		int current_level, int is_first_elem))
{
	t_list *queue;
	t_list *prev;
	int		first_elem;

	nb_total_node = btree_nb_node(root);
	if (root == NULL)
		return;
	if (!(queue = malloc(nb_total_node * sizeof(t_btree))))
		return ;
	if (!(queue = list_create_elem(root, 0)))
		return (NULL);
	first_elem = 1;
	while (queue)
	{
		if (first_elem)
		{
			first_elem = 0;
			(*applyf)(queue->data, queue->level, 1);
		}
		else
			(*applyf)(queue->data, queue->level, 0);
		if (!(add_child_to_queue(queue->data)))
			return (NULL);
		prev = queue;
		queue = queue->next;
		free(prev);
	}
}
