#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

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
	printf("|%s|\n", (char*)elem->data);
}

void	printSTR(void *str)
{
	printf("[%s]\n", (char*)str);
}

int		strcomp(void *param1, void *param2)
{
	char *str1 = (char*)param1;
	char *str2 = (char*)param2;

	int i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int		is_good_str(void *param)
{
	char * str = (char*)param;
	if (str[0] >= '5')
		return (1);
	return (1);
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
	printl(ft_list_find(anchor2, "5", &strcomp));
	print_list(anchor1);
 	
}
