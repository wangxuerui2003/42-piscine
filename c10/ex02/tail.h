/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:20:25 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/08 20:42:41 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	free_play(void);
void	show_error(char *exe, char *path, char *err_msg);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		choose_mode(int ac, char **av);
void	ft_puttitle(char *filename);
int		ft_atoi(char *nbr);
int		ft_catoi(char *nbr);
void	display_file(int fd);
int		c_display_mode(char **files, int count, int size, int i);
int		cnum_display_mode(char **files, int count, int size, int i);
void	c_display_file(int fd, int size, char *file);
void	print_help_err(char *exe);
void	print_illegal_err(char *exe, char *file);

# define BUF 10

#endif
