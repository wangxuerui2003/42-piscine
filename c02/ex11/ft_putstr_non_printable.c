/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:27:04 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 20:42:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		fir;
	int		sec;

	i = 0;
	fir = 0;
	sec = 0;
	while (str[i] != 0)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			fir = str[i] / 16;
			sec = str[i] % 16;
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[fir]);
			ft_putchar("0123456789abcdef"[sec]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
