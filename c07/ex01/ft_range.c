/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:38:06 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/30 15:47:40 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	range;
	unsigned int	i;
	int				*arr;
	int				*nul_ptr;

	nul_ptr = 0;
	i = 0;
	if (min >= max)
		return (nul_ptr);
	range = max - min;
	arr = malloc(range * 4);
	while (i < range)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
