/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:56:28 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/07 22:31:52 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_file(int fd, char *buf)
{
	int	ret;

	ret = read(fd, buf, BUF);
	while (ret)
	{
		buf[ret] = 0;
		ft_putstr(1, buf);
		ret = read(fd, buf, BUF);
	}
	close(fd);
}

int	main(int ac, char *av[])
{
	int		fd;
	int		i;
	char	buf[BUF + 1];

	i = -1;
	while (buf[++i])
		buf[i] = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(2, CANNOTREAD);
			close(fd);
			return (1);
		}
		display_file(fd, buf);
		return (0);
	}
	else if (ac < 2)
		ft_putstr(2, NAMEMISSING);
	else
		ft_putstr(2, TOOMANYARGS);
	return (1);
}
