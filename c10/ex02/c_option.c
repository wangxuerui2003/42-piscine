/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:38:23 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 20:40:44 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	display_file(int fd)
{
	int		ret;
	char	buf[BUF + 1];

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUF);
		buf[ret] = 0;
		ft_putstr(buf);
	}
	close(fd);
}

void	c_display_file(int fd, int size, char *file)
{
	int		filesize;
	char	c;
	char	*data;
	int		i;

	c = 0;
	filesize = 0;
	i = 0;
	while (read(fd, &c, 1))
		filesize++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (size >= filesize)
	{
		display_file(fd);
		return ;
	}
	data = malloc(filesize * sizeof(char));
	while (++i && read(fd, &c, 1))
		data[i - 1] = c;
	data[i] = 0;
	ft_putstr(data + filesize - size);
	free(data);
	close(fd);
}

int	c_display_mode(char **files, int count, int size, int i)
{
	int	title;
	int	fd;
	int	file_count;

	title = 0;
	file_count = 0;
	if (count > 4)
		title = 1;
	while (++i < count)
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			show_error(basename(files[0]), files[i], strerror(errno));
			close(fd);
			continue ;
		}
		if (i != 3 && file_count != 0)
			ft_putstr("\n");
		if (title)
			ft_puttitle(files[i]);
		c_display_file(fd, size, files[i]);
		file_count++;
	}
	return (1);
}	
