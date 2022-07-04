/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:15:49 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/04 17:55:23 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_length(char *str, char *charset)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && !in_charset(str[i], charset))
			length++;
		while (str[i] && !in_charset(str[i], charset))
			i++;
		i++;
	}
	return (length);
}

int	get_next_len(char *str, char *charset)
{
	int	length;

	length = 0;
	while (str[length] && !in_charset(str[length], charset))
		length++;
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (length);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		length;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * (get_length(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < get_length(str, charset))
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		length = get_next_len(str + i, charset);
		result[j] = malloc(sizeof(char) * length);
		if (result[j] == NULL)
			return (NULL);
		ft_strlcpy(result[j], str + i, length + 1);
		j++;
		i += length;
	}
	result[j] = NULL;
	return (result);
}
