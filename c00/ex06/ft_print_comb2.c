/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:13:05 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/21 16:48:43 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int i, int j)
{
	char	ai[2];
	char	aj[2];

	ai[0] = i / 10 + 48;
	ai[1] = i % 10 + 48;
	aj[0] = j / 10 + 48;
	aj[1] = j % 10 + 48;
	write(1, &ai[0], 1);
	write(1, &ai[1], 1);
	write(1, " ", 1);
	write(1, &aj[0], 1);
	write(1, &aj[1], 1);
	if (i != 98)
		write(1, ", ", 2);
}	

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99 && j <= 99)
	{
		if (i < 99 && j > i)
			print(i, j);
		if (j == 99)
		{
			j -= 99;
			i++;
		}
		j++;
	}
}
