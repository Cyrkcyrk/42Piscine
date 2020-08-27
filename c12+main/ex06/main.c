#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	ret->data = data;
	return (ret);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	if(!(tmp = ft_create_elem(data)))
		return ;
	tmp->next = *begin_list;
	*begin_list = tmp;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*anchor;

	anchor = NULL;
	i = -1;
	while (++i < size)
		ft_list_push_front(&anchor, strs[i]);
	return (anchor);
}

void	print_list(t_list *anchor)
{
	while (anchor)
	{
		printf("%s\n", (char*)anchor->data);
		anchor = anchor->next;
	}
}

void	printl(t_list *elem)
{
	printf("%s\n", (char*)elem->data);
}

void printSTR(void *str)
{
	printf("%s\n", (char*)str);
}
int		main(void)
{
	char **strs1;
	char **strs2;
	
	strs1 = malloc(10 * sizeof(char*));
	strs2 = malloc(10 * sizeof(char*));
	strs1[9] = "Bonjour";
	strs1[8] = "je";
	strs1[7] = "suis";
	strs1[6] = "cyrille";
	strs1[5] = "et";
	strs1[4] = "j";
	strs1[3] = "aime";
	strs1[2] = "le";
	strs1[1] = "gateau";
	strs1[0] = ":D";
	
	strs2[0] = "0";
	strs2[1] = "1";
	strs2[2] = "2";
	strs2[3] = "3";
	strs2[4] = "4";
	strs2[5] = "5";
	strs2[6] = "6";
	strs2[7] = "7";
	strs2[8] = "8";
	strs2[9] = "9";

	t_list *anchor1 = ft_list_push_strs(10, strs1);
	t_list *anchor2 = ft_list_push_strs(10, strs2);
	t_list *anchor3 = NULL;

	ft_list_clear(anchor1, &printSTR);
	ft_list_clear(anchor2, &printSTR);
	ft_list_clear(anchor3, &printSTR);	
	free(strs1);
	free(strs2);
	write(1, "YOUSK2", 6);
 	
}
