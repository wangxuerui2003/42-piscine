/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:15:11 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 22:35:53 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	ft_print_hex(char c)
{
	char	*hextab;

	hextab = "0123456789abcdef";
	write(1, &hextab[c / 16], 1);
	write(1, &hextab[c % 16], 1);
}

void	ft_print_char(char c)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

char	*convert_hex(int num, int len)
{
	char	*ret;

	ret = malloc((len + 1) * sizeof(char));
	ret[len] = 0;
	while (len > 0)
	{
		ret[len - 1] = "0123456789abcdef"[num % 16];
		num /= 16;
		len--;
	}
	return (ret);
}

void	stdin_loop(int total_size)
{
	int		i;
	char	*buf;
	int		buf_pos;

	i = 1;
	buf_pos = 0;
	buf = malloc(17 * sizeof(char));
	buf[16] = 0;
	while (read(0, &buf[buf_pos], 1))
	{
		if (buf_pos == 16)
		{
			display_line(buf_pos, buf, total_size - 16);
			buf[0] = buf[buf_pos];
			buf_pos -= 16;
		}
		total_size++;
		buf_pos++;
	}
}

void	c_stdin_loop(int total_size)
{
	int		i;
	char	*buf;
	int		buf_pos;

	i = 1;
	buf_pos = 0;
	buf = malloc(17 * sizeof(char));
	buf[16] = 0;
	while (read(0, &buf[buf_pos], 1))
	{
		if (buf_pos == 16)
		{
			c_display_line(buf_pos, buf, total_size - 16);
			buf[0] = buf[buf_pos];
			buf_pos -= 16;
		}
		total_size++;
		buf_pos++;
	}
}
