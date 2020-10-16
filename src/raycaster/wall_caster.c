/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_caster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:38:02 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:09:17 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycast(t_parameters *data, t_rc_params *p, int x)
{
	p->camerax = 2 * x / (double)data->win_w - 1;
	p->raydirx = data->dirx + data->planex * p->camerax;
	p->raydiry = data->diry + data->planey * p->camerax;
	p->mapx = (int)data->posx;
	p->mapy = (int)data->posy;
	if (p->raydiry == 0)
		p->deltadistx = 0;
	else if (p->raydirx != 0)
		p->deltadistx = fabs(1 / p->raydirx);
	if (p->raydirx == 0)
		p->deltadisty = 0;
	else if (p->raydiry != 0)
		p->deltadisty = fabs(1 / p->raydiry);
	p->hit = 0;
}

void	calc_step_and_sidedist(t_rc_params *p, t_parameters *data)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (data->posx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1.0 - data->posx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (data->posy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1.0 - data->posy) * p->deltadisty;
	}
}

void	perform_dda(t_parameters *d, t_rc_params *p)
{
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = p->raydirx < 0 ? NORTH : SOUTH;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = p->raydiry < 0 ? WEST : EAST;
		}
		if (d->map[p->mapx][p->mapy] > 48 && d->map[p->mapx][p->mapy] != 50)
			p->hit = 1;
	}
}

void	calculate_distance_pixel_wallx(t_rc_params *p, t_parameters *d)
{
	if (p->side == NORTH || p->side == SOUTH)
		p->perpwalldist = (p->mapx - d->posx + (1 - p->stepx) / 2) / p->raydirx;
	else
		p->perpwalldist = (p->mapy - d->posy + (1 - p->stepy) / 2) / p->raydiry;
	p->lineheight = (int)(d->win_h / p->perpwalldist);
	p->drawstart = -p->lineheight / 2 + d->win_h / 2;
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = p->lineheight / 2 + d->win_h / 2;
	if (p->drawend >= d->win_h)
		p->drawend = d->win_h - 1;
	if (p->side == NORTH || p->side == SOUTH)
		p->wallx = d->posy + p->perpwalldist * p->raydiry;
	else
		p->wallx = d->posx + p->perpwalldist * p->raydirx;
	p->wallx -= floor((p->wallx));
}

void	getting_ready_to_render(t_rc_params *p, t_parameters *data)
{
	if (p->side == NORTH)
		data->tex = data->n_t;
	if (p->side == SOUTH)
		data->tex = data->s_t;
	if (p->side == EAST)
		data->tex = data->e_t;
	if (p->side == WEST)
		data->tex = data->w_t;
	p->texx = (int)(p->wallx * (double)data->tex.w);
	if ((p->side == NORTH || p->side == SOUTH) && p->raydirx > 0)
		p->texx = data->tex.w - p->texx - 1;
	else if (p->side == 0 && p->raydiry < 0)
		p->texx = data->tex.w - p->texx - 1;
	p->step = 1.0 * data->tex.h / p->lineheight;
	p->texpos = (p->drawstart - data->win_h / 2 + p->lineheight / 2) * p->step;
}
