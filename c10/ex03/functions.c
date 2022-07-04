/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:13:16 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 19:07:12 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

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

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	dest_len;
	int	src_len;

	i = ft_strlen(dest);
	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= ft_strlen(dest))
		return (src_len + size);
	while (src[j] != 0 && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
