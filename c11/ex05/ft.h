/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:11:50 by wxuerui           #+#    #+#             */
/*   Updated: 2022/06/06 12:49:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putstr(char *str);
int		ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putnbr(int nbr);
int		add(int a, int b);
int		minus(int a, int b);
int		mult(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif
