/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:25:38 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/21 21:45:07 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nb)
{
	char	c;

	if (nb / 10 != 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			print(nb / 10 * -1);
		}
		else
		{
			print(nb / 10);
		}
	}
	nb %= 10;
	if (nb < 0)
	{
		nb *= -1;
	}
	c = nb + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= -2147483648 && nb <= 2147483647)
	{
		if (nb == 0)
		{
			write(1, "0", 1);
		}
		else
		{
			print(nb);
		}
	}
}
