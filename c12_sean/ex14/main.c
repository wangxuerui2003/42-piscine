/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:36:51 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 12:39:15 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"
#include "ft_list_sort.c"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = 0;
	list->data = data;
	return (list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}

int		less_than(void *a, void *b)
{
	return ((*(int *)a) > (*(int *)b));
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;
	t_list	*current;

	index = 1;
	list = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = 9 - index;
		ft_list_push_back(&list, (void *)malloced_index);
		printf("list[%d] = %d\n", index, *malloced_index);
		index++;
	}
	index = 1;
	ft_list_sort(&(list->next), &less_than);
	printf("Sorted\n");
	current = list->next;
	while (index < 10)
	{
		printf("list[%d] = %d\n", index, *((int *)current->data));
		index++;
		current = current->next;
	}
}
