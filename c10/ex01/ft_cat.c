/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:42:52 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/05 22:22:51 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	main(int ac, char *av[])
{
	if (ac < 2)
		stdin_loop();
	else
	{
		if (av[ac - 2][0] == '>')
		{
			if (!stdin_mode(av, ac))
				return (1);
		}
		else
		{
			if (!display_mode(av, ac))
				return (1);
		}
	}		
	return (0);
}

void	ft_write_str(int fd_write, int fd_read, char *buf)
{
	int	ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd_read, buf, BUF);
		buf[ret] = 0;
		write(fd_write, buf, ft_strlen(buf));
	}
	close(fd_read);
}

int	stdin_mode(char **files, int count)
{
	int		fd_read;
	int		fd_write;
	int		i;
	char	buf[BUF + 1];

	i = 1;
	fd_write = open(files[count - 1], O_WRONLY | O_CREAT);
	close(fd_write);
	fd_write = open(files[count - 1], O_WRONLY | O_CREAT | O_APPEND);
	while (i < count - 1)
	{
		fd_read = open(files[i], O_RDONLY);
		if (fd_read == -1)
		{
			show_error(basename(files[0]), files[i], strerror(errno));
			return (0);
		}
		ft_write_str(fd_write, fd_read, buf);
		i++;
	}
	close(fd_write);
	return (1);
}

void	display_file(int fd, char *buf)
{
	int	ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUF);
		buf[ret] = 0;
		ft_putstr(buf);
	}
	close(fd);
}

int	display_mode(char **files, int count)
{
	int		fd;
	int		i;
	char	buf[BUF + 1];

	i = 1;
	while (i < count)
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			show_error(basename(files[0]), files[i], strerror(errno));
			close(fd);
			i++;
			continue ;
		}
		display_file(fd, buf);
		i++;
	}
	return (1);
}
