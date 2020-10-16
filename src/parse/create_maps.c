/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:48:43 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:23:24 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		count_lines(t_parameters *p)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (p->map_i_l[i])
	{
		if (p->map_i_l[i] == '\n')
			j++;
		i++;
	}
	return (++j);
}

int		count_width(t_parameters *p)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (p->map_i_l[i])
	{
		if (p->map_i_l[i] != '\n' && p->map_i_l[i] != 0)
			j++;
		if (p->map_i_l[i] == '\n' || p->map_i_l[i] == 0)
		{
			if (k < j)
				k = j;
			j = 0;
		}
		i++;
	}
	if (k < j)
		k = j;
	return (k);
}

void	create_map(t_parameters *p)
{
	int		i;
	int		j;
	int		k;

	if (!(p->map = (char **)malloc((p->map_h) * sizeof(char *))))
		error_msg(15);
	i = -1;
	while (++i < p->map_h)
		if (!(p->map[i] = (char *)malloc(p->map_w * sizeof(char))))
			error_msg(15);
	k = 0;
	i = -1;
	while (++i < (p->map_h))
	{
		j = -1;
		while (++j <= p->map_w)
		{
			while ((p->map_i_l[k] == '\n' ||
			p->map_i_l[k] == 0) && j < p->map_w)
				p->map[i][j++] = ' ';
			if (p->map_i_l[k] != '\n' && p->map_i_l[k] != 0)
				p->map[i][j] = p->map_i_l[k];
			k++;
		}
	}
}

void	create_map_test(t_parameters *p)
{
	int		i;
	int		j;
	int		k;

	if (!(p->map_to_ff = (char **)malloc((p->map_h) * sizeof(char *))))
		error_msg(15);
	i = -1;
	while (++i < p->map_h)
		if (!(p->map_to_ff[i] = (char *)malloc((p->map_w) * sizeof(char))))
			error_msg(15);
	k = 0;
	i = -1;
	while (++i < (p->map_h))
	{
		j = -1;
		while (++j <= p->map_w)
		{
			if (p->map_i_l[k] != '\n' && p->map_i_l[k] != 0)
				p->map_to_ff[i][j] = p->map_i_l[k];
			while ((p->map_i_l[k] == '\n' ||
			p->map_i_l[k] == 0) && j < p->map_w)
				p->map_to_ff[i][j++] = ' ';
			k++;
		}
	}
}
