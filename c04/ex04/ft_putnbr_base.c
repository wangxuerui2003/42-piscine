/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:54:22 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/30 20:14:53 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	check_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (i < ft_strlen(base))
	{
		j = i;
		while (++j < ft_strlen(base))
			if (base[i] == base[j])
				return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_num;

	base_num = ft_strlen(base);
	if (check_valid(base))
	{
		if (nbr < 0)
		{
			if (nbr != -2147483648)
			{
				write(1, "-", 1);
				nbr *= -1;
			}
		}
		if (nbr / base_num != 0)
			ft_putnbr_base(nbr / base_num, base);
		write(1, &base[nbr % base_num], 1);
	}
	else
		return ;
}
