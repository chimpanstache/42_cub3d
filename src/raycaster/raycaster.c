/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:26:34 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/13 12:30:05 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint_floor_ceiling(t_parameters *data)
{
	char	*dst;
	int		y;
	int		x;

	y = -1;
	while (++y < data->win_h / 2)
	{
		x = -1;
		while (++x < data->win_w)
		{
			dst = data->addr + (y * data->l_l + x * (data->bpp / 8));
			*(unsigned int*)dst = data->clg_color;
		}
	}
	y = (data->win_h / 2) - 1;
	while (++y < (data->win_h))
	{
		x = -1;
		while (++x < data->win_w)
		{
			dst = data->addr + (y * data->l_l + x * (data->bpp / 8));
			*(unsigned int*)dst = data->flr_color;
		}
	}
}

int		raycaster(t_parameters *data)
{
	int					i;
	int					stripe;
	t_sprite_params		s;

	paint_floor_ceiling(data);
	wall_caster(data);
	sort_sprite_distance(data);
	i = -1;
	while (++i < data->nsprite)
	{
		init_sprite_values(&s, data, i);
		stripe = s.drawstartx - 1;
		while (++stripe < s.drawendx)
			render_sprite(&s, stripe, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
