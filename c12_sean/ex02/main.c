/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:31:27 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 14:45:35 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_size.c"
#include "ft_create_elem.c"
#include <stdio.h>
/*
int	ft_list_size(t_list *begin_list)
{
	if (begin_list->next == 0)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}
*/
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = (*begin_list);
	*begin_list = new_list;
}

int	main(void)
{
	int		index;
	t_list	*list;

	list = ft_create_elem(0);
	index = 0;
	while (index++ < 10)
		ft_list_push_front(&list, 0);
	printf("size: %d\n", ft_list_size(list));
}
