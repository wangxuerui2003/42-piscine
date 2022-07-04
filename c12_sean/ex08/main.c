/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:34:51 by schuah            #+#    #+#             */
/*   Updated: 2022/06/07 22:39:39 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list_reverse.c"
#include "ft_create_elem.c"
#include "ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_reverse(t_list **begin_list);

int		main(void)
{
	t_list *liste;

	liste = 0;
	ft_list_push_front(&liste, "toto");
	ft_list_push_front(&liste, "tutu");
	ft_list_push_front(&liste, "tata");
	ft_list_push_front(&liste, "titi");
	ft_list_reverse(&liste);
	while (liste)
	{
		printf("%s\n", liste->data);
		liste = liste->next;
	}
}

