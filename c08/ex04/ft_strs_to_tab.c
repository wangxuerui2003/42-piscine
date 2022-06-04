/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:01:49 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/02 21:54:18 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup_str;
	int		i;

	dup_str = malloc(ft_strlen(src) + 1);
	i = 0;
	while (i < ft_strlen(src))
	{
		dup_str[i] = src[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*p_str;

	i = 0;
	p_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (p_str == NULL)
		return (NULL);
	while (i < ac)
	{
		p_str[i].str = av[i];
		p_str[i].size = ft_strlen(av[i]);
		p_str[i].copy = ft_strdup(av[i]);
		i++;
	}
	p_str[i].str = 0;
	p_str[i].copy = 0;
	p_str[i].size = 0;
	return (p_str);
}
