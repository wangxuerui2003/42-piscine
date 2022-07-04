/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:29:58 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 22:20:16 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	display_line(int buf_pos, char *buf, int current_size)
{
	int		i;

	ft_putstr(convert_hex(current_size, 7));
	i = 0;
	if (buf != NULL)
	{
		ft_putstr(" ");
		while (i < 16)
		{
			if (i < buf_pos)
				ft_print_hex(buf[i]);
			if (i != buf_pos - 1)
				ft_putstr(" ");
			if (i > buf_pos)
				ft_putstr("  ");
			i++;
		}
	}
	if (i > buf_pos)
		ft_putstr("  ");
	ft_putstr("\n");
}

void	default_err_show(int total_size, int i, char **files, int count)
{
	show_error(basename(files[0]), files[i], strerror(errno));
	if (total_size == 0 && i == count - 1)
		show_error(basename(files[0]), files[i], "Bad file descriptor");
}

void	default_read_file(int fd, char *buf, int *buf_pos, int *total_size)
{
	while (read(fd, &buf[*buf_pos], 1))
	{
		if (*buf_pos == 16)
		{
			display_line(*buf_pos, buf, (*total_size) - 16);
			buf[0] = buf[*buf_pos];
			*buf_pos -= 16;
		}
		(*total_size)++;
		(*buf_pos)++;
	}
	if (*buf_pos == 16)
	{
		display_line(*buf_pos, buf, *total_size);
		*buf_pos -= 16;
	}
	close(fd);
}

void	display_end(int *total_size, int *buf_pos, char *buf)
{
	if (*total_size != 0)
	{
		if (*buf_pos)
			display_line(*buf_pos, buf, *total_size - *buf_pos);
		display_line(0, NULL, *total_size);
	}
	free(buf);
}

int	default_option(int count, char **files, int total_size, int i)
{
	int		fd;
	char	*buf;
	int		buf_pos;

	buf_pos = 0;
	buf = malloc(17 * sizeof(char));
	if (!buf)
		return (0);
	buf[16] = 0;
	while (++i < count)
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			default_err_show(total_size, i, files, count);
			close(fd);
			if (i != count - 1)
				errno = 0;
			continue ;
		}
		default_read_file(fd, buf, &buf_pos, &total_size);
	}
	display_end(&total_size, &buf_pos, buf);
	return (1);
}
