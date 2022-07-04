/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:22:51 by wxuerui           #+#    #+#             */
/*   Updated: 2022/05/29 15:41:42 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		check_valid_put(int **tab, int *index, int pos, int num);
int		check_row(int rowleft, int rowright, int **tab, int row);
int		check_col(int colup, int coldown, int **tab, int col);
int		won(int *index, int **tab);
void	tabulate(int **tab);
int		solve(int **tab, int *index, int pos);
int		putnbr(int nbr);

#endif
