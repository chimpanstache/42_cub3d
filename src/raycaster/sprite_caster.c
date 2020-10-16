/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:43:46 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 14:32:46 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sort_sprite_distance(t_parameters *p)
{
	int			i;
	t_sprite	buf;

	i = 0;
	while (i < p->nsprite && i + 1 < p->nsprite)
	{
		p->sprites[i].distance = ((p->posx - p->sprites[i].x) *
		(p->posx - p->sprites[i].x) + (p->posy - p->sprites[i].y) *
		(p->posy - p->sprites[i].y));
		p->sprites[i + 1].distance = ((p->posx - p->sprites[i + 1].x) *
		(p->posx - p->sprites[i + 1].x) +
		(p->posy - p->sprites[i + 1].y) *
		(p->posy - p->sprites[i + 1].y));
		if (p->sprites[i].distance < p->sprites[i + 1].distance)
		{
			buf = p->sprites[i];
			p->sprites[i] = p->sprites[i + 1];
			p->sprites[i + 1] = buf;
			i = 0;
		}
		else
			i++;
	}
}

void	init_sprite_values(t_sprite_params *s, t_parameters *p, int i)
{
	s->spritex = 0.5 + p->sprites[i].x - p->posx;
	s->spritey = 0.5 + p->sprites[i].y - p->posy;
	s->invdet = 1.0 / (p->planex * p->diry - p->dirx * p->planey);
	s->transx = s->invdet * (p->diry * s->spritex - p->dirx * s->spritey);
	s->transy = s->invdet * (-p->planey * s->spritex + p->planex * s->spritey);
	s->spritescreenx = (int)((p->win_w / 2) * (1 + s->transx / s->transy));
	s->spriteheight = abs((int)(p->win_h / (s->transy)));
	s->drawstarty = -s->spriteheight / 2 + p->win_h / 2;
	if (s->drawstarty < 0)
		s->drawstarty = 0;
	s->drawendy = s->spriteheight / 2 + p->win_h / 2;
	if (s->drawendy >= p->win_h)
		s->drawendy = p->win_h - 1;
	s->spritewidth = abs((int)(p->win_h / (s->transy)));
	s->drawstartx = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstartx < 0)
		s->drawstartx = 0;
	s->drawendx = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawendx >= p->win_w)
		s->drawendx = p->win_w - 1;
}

void	render_sprite(t_sprite_params *s, int stripe, t_parameters *p)
{
	char	*d;
	int		y;

	s->texx = (int)(256 * (stripe - (-s->spritewidth / 2 + s->spritescreenx)) *
		p->p_t.w / s->spritewidth) / 256;
	if (s->transy > 0 && stripe > 0 && stripe < p->win_w &&
		s->transy < p->zbuffer[stripe])
	{
		y = s->drawstarty - 1;
		while (++y < s->drawendy)
		{
			s->d = (y) * 256 - p->win_h * 128 + s->spriteheight * 128;
			s->texy = ((s->d * p->p_t.h) / s->spriteheight) / 256;
			d = p->p_t.ad + (s->texy * p->p_t.l_l + s->texx *
			(p->p_t.bpp / 8));
			p->color = *(unsigned int*)d;
			if (p->color != 0)
			{
				d = p->addr + (y * p->l_l + stripe * (p->bpp / 8));
				*(unsigned int*)d = p->color;
			}
		}
	}
}
