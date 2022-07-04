/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:40:03 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/05 18:07:28 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	stdin_loop(void)
{
	unsigned int	ret;
	char			buffer[10];

	ret = 1;
	while (ret)
	{
		ret = read(0, buffer, 10);
		write(1, &buffer[0], ret);
	}
}

void	show_error(char *exe, char *path, char *err_msg)
{
	if (errno == 0)
		return ;
	ft_putstr(exe);
	ft_putstr(": ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(err_msg);
	ft_putstr("\n");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
