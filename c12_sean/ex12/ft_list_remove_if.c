/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:57:48 by schuah            #+#    #+#             */
/*   Updated: 2022/06/08 11:30:54 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*temp;

	current = *begin_list;
	while (current != NULL && current->next != NULL)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			current->next = current->next->next;
			temp = current->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		current = current->next;
	}
	current = *begin_list;
	if (current != NULL)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			*begin_list = current->next;
			(*free_fct)(current->data);
			free(current);
		}
	}
}
