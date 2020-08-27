#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

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
	strs1[0] = "99";
	strs1[1] = "85";
	strs1[2] = "75";
	strs1[3] = "65";
	strs1[4] = "55";
	strs1[5] = "45";
	strs1[6] = "35";
	strs1[7] = "25";
	strs1[8] = "15";
	strs1[9] = "00";
	
	strs2[0] = "90";
	strs2[1] = "81";
	strs2[2] = "71";
	strs2[3] = "61";
	strs2[4] = "51";
	strs2[5] = "41";
	strs2[6] = "31";
	strs2[7] = "21";
	strs2[8] = "11";
	strs2[9] = "10";

	t_list *anchor1 = ft_list_push_strs(10, strs1);
	t_list *anchor2 = ft_list_push_strs(10, strs2);
	t_list *anchor3 = NULL;
	char *str = "0";

	print_list(anchor1);
	printf("------------------\n");
	ft_sorted_list_merge(&anchor3, anchor1, strcomp);
	print_list(anchor3);
 	
}
