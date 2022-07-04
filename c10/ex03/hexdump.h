/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:11:13 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/07 12:03:23 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>

# define BUF 16

void	ft_putstr(char *str);
void	show_error(char *exe, char *path, char *err_msg);
int		ft_strcmp(char *s1, char *s2);
void	display_line(int buf_pos, char *buf, int current_size);
int		default_option(int count, char **files, int total_size, int i);
int		ft_strlcat(char *dest, char *src, int size);
int		ft_strlen(char *str);
void	ft_print_hex(char c);
void	ft_print_char(char c);
char	*convert_hex(int num, int len);
void	stdin_loop(int total_size);
void	c_stdin_loop(int total_size);
int		c_option(int count, char **files, int total_size, int i);
void	c_display_line(int buf_pos, char *buf, int current_size);
void	default_read_file(int fd, char *buf, int *buf_pos, int *total_size);
void	default_err_show(int total_size, int i, char **files, int count);
void	c_read_file(int fd, char *buf, int *buf_pos, int *total_size);
void	c_err_show(int total_size, int i, char **files, int count);

#endif
