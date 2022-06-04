/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:50:02 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/25 13:42:51 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == 55 && j == 56 && k == 57)
		return ;
	write(1, ", ", 2);
}

void	generate(char i, char j, char k)
{
	while (i <= 57 && j <= 57 && k <= 57)
	{
		if (i < j && j < k)
			print(i, j, k);
		if (k == 57)
		{
			k -= 9;
			if (j == 57)
			{
				j -= 9;
				i++;
			}
			else
				j++;
		}
		else
			k++;
	}
}

void	ft_print_comb(void)
{
	generate(48, 48, 48);
}
