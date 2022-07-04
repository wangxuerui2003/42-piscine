/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:53:33 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/07 17:07:52 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>

# define NAMEMISSING "File name missing.\n"
# define TOOMANYARGS "Too many arguments.\n"
# define CANNOTREAD "Cannot read file.\n"
# define BUF 10

void	ft_putnbr(int nbr);
void	ft_putstr(int mode, char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);

#endif
