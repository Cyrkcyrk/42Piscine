#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list *ft_list_push_strs(int size, char **strs);

t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	ret->data = data;
	return (ret);
}

void	print_list(t_list *anchor)
{
	while (anchor)
	{
		printf("%s\n", (char*)anchor->data);
		anchor = anchor->next;
	}
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
	
	strs2[0] = "1";
	strs2[1] = "0";
	strs2[2] = "2";
	strs2[3] = "6";
	strs2[4] = "5";
	strs2[5] = "4";
	strs2[6] = "6";
	strs2[7] = "7";
	strs2[8] = "3";
	strs2[9] = "9";

	t_list *anchor1 = ft_list_push_strs(10, strs1);
	t_list *anchor2 = ft_list_push_strs(10, strs2);

	print_list(anchor1);
 	
}
