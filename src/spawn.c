/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:16:20 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/11 21:46:51 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_spawn_params_2(int x, int y, t_parameters *d)
{
	if (d->map[y][x] == 'N' || d->map[y][x] == 'S' ||
	d->map[y][x] == 'E' || d->map[y][x] == 'W')
	{
		d->map[y][x] = '0';
		d->posx = y + 0.5;
		d->posy = x + 0.5;
	}
}

void	set_spawn_params(int x, int y, t_parameters *d)
{
	if (d->map[y][x] == 'N')
	{
		d->dirx = -1.0;
		d->planey = 0.66;
	}
	if (d->map[y][x] == 'S')
	{
		d->dirx = 1.0;
		d->planey = -0.66;
	}
	if (d->map[y][x] == 'E')
	{
		d->diry = 1.0;
		d->planex = 0.66;
	}
	if (d->map[y][x] == 'W')
	{
		d->diry = -1.0;
		d->planex = -0.66;
	}
	set_spawn_params_2(x, y, d);
}
