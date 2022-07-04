/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:50:34 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 12:02:20 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>
#include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;
	t_list	*previous;

	current = *begin_list1;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = begin_list2;
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;
	t_list	*list2;

	index = 0;
	list = ft_create_elem(0);
	list2 = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_back(&list, (void *)malloced_index);
		ft_list_push_back(&list2, (void *)malloced_index);
		index++;
	}
	ft_list_merge(NULL, list2->next);
	index = 0;
	list = list->next;
	while (list)
	{
		printf("list[%d]: %d\n", index, *((int *)list->data));
		index++;
		list = list->next;
	}
}
