/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:43:43 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 15:21:56 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list	*list)
{
	void	*temp;

	temp = list->data;
	list->data = list->next->data;
	list->next->data = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		length;
	int		index1;
	int		index2;
	void	*temp;
	t_list	*list;

	length = 0;
	list = begin_list;
	while (list != NULL)
	{
		length++;
		list = list->next;
	}
	index1 = -1;
	while (++index1 < length - 1)
	{
		index2 = index1;
		list = begin_list;
		while (list != NULL && list->next != NULL && index2 < length - 1)
		{
			ft_swap(list);
			list = list->next;
			index2++;
		}
	}
}
