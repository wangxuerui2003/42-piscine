/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnum_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:45:59 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 20:42:20 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	cnum_display_mode(char **files, int count, int size, int i)
{
	int	title;
	int	fd;
	int	file_count;

	title = 0;
	file_count = 0;
	if (count > 3)
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
		if (i != 2 && file_count != 0)
			ft_putstr("\n");
		if (title)
			ft_puttitle(files[i]);
		c_display_file(fd, size, files[i]);
		file_count++;
	}
	return (1);
}
