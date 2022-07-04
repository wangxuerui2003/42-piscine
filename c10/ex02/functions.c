/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:32:00 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 13:08:22 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

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

void	free_play(void)
{
	unsigned int	ret;
	char			buffer[10];

	ret = 1;
	while (ret)
		ret = read(0, buffer, 10);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
