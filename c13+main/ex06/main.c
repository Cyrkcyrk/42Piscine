/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:51:12 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/27 18:40:18 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_level_count(t_btree *root);

t_btree *btree_create_node(void *item)
{
	t_btree *ret;

	if(!(ret = malloc(sizeof(t_btree))))
		return (NULL);
	ret->right = 0;
	ret->left = 0;
	ret->item = item;
	return (ret);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)(item, (*root)->item) > 0)
		btree_insert_data(&((*root)->right), item, cmpf);
	else
		btree_insert_data(&((*root)->left), item, cmpf);
}

int	comp(void *d1, void *d2)
{
	int* a = d1;
	int* b = d2;
	if (*a > *b)
	{
		printf("[%d | %d] |  1\n", *a, *b);
		return (1);
	}
	else if (*a < *b)
	{
		printf("[%d | %d] | -1\n", *a, *b);
		return (-1);
	}
	else
	{
		printf("[%d | %d] |  0\n", *a, *b);
		return 0;
	}
}

void	printd(void *item)
{
	int *d = item;
	if (item == NULL)
		printf("(null)\n");
	else
		printf("%d\n", *d);
}

int main(void)
{
	t_btree *root = NULL;;
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	btree_insert_data(&root, &tab[5], &comp);
	btree_insert_data(&root, &tab[3], &comp);
	btree_insert_data(&root, &tab[7], &comp);
	btree_insert_data(&root, &tab[2], &comp);
	btree_insert_data(&root, &tab[4], &comp);
	btree_insert_data(&root, &tab[6], &comp);
//	btree_insert_data(&root, &tab[8], &comp);
//	btree_insert_data(&root, &tab[9], &comp);

	printf("%d", btree_level_count(root));
}
