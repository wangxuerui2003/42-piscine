/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:32:07 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 20:37:21 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	if (begin_list != NULL)
	{
		while (begin_list != NULL)
		{
			(*free_fct)(begin_list->data);
			temp = begin_list->next;
			free(begin_list);
			begin_list = temp;
		}
	}
}
