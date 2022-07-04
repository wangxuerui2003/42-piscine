/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:55:21 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/07 17:07:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_putstr(int mode, char *str)
{
	while (*str != 0)
	{
		write(mode, &(*str), 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	c = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c += (nb + '0');
		write(1, &c, 1);
	}
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
	{
		length++;
	}
	return (length);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
