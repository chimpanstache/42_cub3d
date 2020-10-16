/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:36:09 by stuntman          #+#    #+#             */
/*   Updated: 2020/10/15 17:24:17 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_spawn_dir(t_parameters *prs, char spwn)
{
	if (spwn == 'N')
		prs->begin.nseorw = 'N';
	if (spwn == 'S')
		prs->begin.nseorw = 'S';
	if (spwn == 'E')
		prs->begin.nseorw = 'E';
	if (spwn == 'W')
		prs->begin.nseorw = 'W';
}

void	ft_check_start(t_parameters *prs, t_point *begin)
{
	char	*str;
	char	*tst;
	int		i;
	int		j;

	i = -1;
	str = "NSEW";
	while (++i < prs->map_h)
	{
		j = -1;
		while (++j < prs->map_w)
		{
			tst = ft_chrstr(prs->map_to_ff[i][j], str);
			if (tst != NULL)
			{
				check_spawn_dir(prs, prs->map_to_ff[i][j]);
				begin->x = j;
				begin->y = i;
			}
		}
	}
}

void	ft_check_nsprite(t_parameters *prs)
{
	int i;
	int j;

	i = -1;
	while (++i < prs->map_h)
	{
		j = -1;
		while (++j < prs->map_w)
		{
			if (prs->map_to_ff[i][j] == '2')
				prs->nsprite++;
		}
	}
}

void	sprite_arr_and_coord(t_parameters *prs)
{
	int i;
	int x;
	int y;

	if (!(prs->sprites = (t_sprite*)malloc(sizeof(t_sprite) * prs->nsprite)))
		error_msg(15);
	i = 0;
	x = -1;
	while (++x < prs->map_h)
	{
		y = -1;
		while (++y < prs->map_w)
		{
			if (prs->map[x][y] == '2')
			{
				(prs->sprites)[i].x = x;
				(prs->sprites)[i].y = y;
				i++;
			}
		}
	}
}

void	parse_map(t_parameters *prs)
{
	prs->map_h = count_lines(prs);
	prs->map_w = count_width(prs);
	if (prs->map_h < 3 || prs->map_w < 3)
		error_msg(8);
	prs->size2.x = prs->map_w;
	prs->size2.y = prs->map_h;
	create_map(prs);
	create_map_test(prs);
	ft_check_start(prs, &prs->begin);
	ft_check_nsprite(prs);
	flood_fill(prs->map_to_ff, &prs->size2, &prs->begin);
	prs->begin.space = prs->size2.space;
	sprite_arr_and_coord(prs);
	free_map_to_ff(prs);
	if (prs->size2.space != 0)
	{
		free_map(prs);
		error_msg(8);
	}
}
