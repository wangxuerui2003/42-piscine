/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:04:54 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 15:42:02 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	putnbr(int nbr)
{
	char	c;

	c = 0;
	c = nbr + '0';
	write(1, &c, 1);
}

void	tabulate(int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
