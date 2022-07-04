/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:36:26 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/05 17:29:34 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

void	ft_putstr(char *str);
void	stdin_loop(void);
void	show_error(char *exe, char *path, char *err_msg);
int		ft_strlen(char *str);
void	ft_write_str(int fd_write, int fd_read, char *buf);
void	display_file(int fd, char *buf);
int		display_mode(char **files, int count);
int		stdin_mode(char **files, int count);

# define BUF 10

#endif
