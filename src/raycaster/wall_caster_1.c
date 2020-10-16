/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_caster_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:38:02 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/11 21:36:51 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rendering_the_picture(t_parameters *d, t_rc_params *p, int x, int y)
{
	char *dst;

	p->texy = (int)p->texpos & (TEXHEIGHT - 1);
	p->texpos += p->step;
	dst = d->tex.ad + (p->texy * d->tex.l_l + p->texx * (d->tex.bpp / 8));
	d->color = *(unsigned int*)dst;
	if (p->side == 1)
		d->color = d->color / 2;
	dst = d->addr + (y * d->l_l + x * (d->bpp / 8));
	*(unsigned int*)dst = d->color;
}

void	wall_caster(t_parameters *d)
{
	t_rc_params		p;
	int				x;
	int				y;

	x = -1;
	while (++x < d->win_w)
	{
		init_raycast(d, &p, x);
		calc_step_and_sidedist(&p, d);
		perform_dda(d, &p);
		calculate_distance_pixel_wallx(&p, d);
		getting_ready_to_render(&p, d);
		y = p.drawstart - 1;
		while (++y < p.drawend)
			rendering_the_picture(d, &p, x, y);
		d->zbuffer[x] = p.perpwalldist;
	}
}
