/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:52:37 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:07:12 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	f_fill(char **tab, t_point *size, int row, int col)
{
	char	*comp;
	char	*test;

	comp = " ESNW02";
	if (row < 0 || col < 0 || row >= size->y || col >= size->x)
		return ;
	test = ft_chrstr(tab[row][col], comp);
	if (tab[row][col] == 'F' || test == NULL)
		return ;
	if (tab[row][col] == ' ')
		size->space++;
	tab[row][col] = 'F';
	f_fill(tab, size, row - 1, col);
	f_fill(tab, size, row + 1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

void	analyze_map(char **tab, t_point *size)
{
	int i;

	i = -1;
	while (++i < size->x)
		if (tab[0][i] == 'F')
			size->space++;
	i = -1;
	while (++i < size->x)
		if (tab[size->y - 1][i] == 'F')
			size->space++;
	i = -1;
	while (++i < size->y)
		if (tab[i][0] == 'F')
			size->space++;
	i = -1;
	while (++i < size->y)
		if (tab[i][size->x - 1] == 'F')
			size->space++;
}

void	flood_fill(char **tab, t_point *size, t_point *begin)
{
	size->target = tab[begin->y][begin->x];
	f_fill(tab, size, begin->y, begin->x);
	analyze_map(tab, size);
}
