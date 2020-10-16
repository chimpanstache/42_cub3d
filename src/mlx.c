/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:07:51 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/13 12:39:53 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_window_properly(t_parameters *data)
{
	mlx_get_screen_size(data->mlx, &data->usr_scrn.x, &data->usr_scrn.y);
	if (data->win_h > data->usr_scrn.y)
		data->win_h = data->usr_scrn.y;
	if (data->win_w > data->usr_scrn.x)
		data->win_w = data->usr_scrn.x;
}

void	check_texture(void *img, t_parameters *data)
{
	if (img == NULL)
	{
		free_all(data);
		error_msg(17);
	}
}

void	generate_picture(t_parameters *d)
{
	set_window_properly(d);
	d->win = mlx_new_window(d->mlx, d->win_w, d->win_h, "cub3d");
	d->w_t.img = mlx_xpm_file_to_image(d->mlx, d->w_t.p, &d->w_t.w, &d->w_t.h);
	check_texture(d->w_t.img, d);
	d->w_t.ad = mlx_get_data_addr(d->w_t.img, &d->w_t.bpp,
	&d->w_t.l_l, &d->w_t.end);
	d->e_t.img = mlx_xpm_file_to_image(d->mlx, d->e_t.p, &d->e_t.w, &d->e_t.h);
	check_texture(d->e_t.img, d);
	d->e_t.ad = mlx_get_data_addr(d->e_t.img, &d->e_t.bpp,
	&d->e_t.l_l, &d->e_t.end);
	d->s_t.img = mlx_xpm_file_to_image(d->mlx, d->s_t.p, &d->s_t.w, &d->s_t.h);
	check_texture(d->s_t.img, d);
	d->s_t.ad = mlx_get_data_addr(d->s_t.img, &d->s_t.bpp,
	&d->s_t.l_l, &d->s_t.end);
	d->n_t.img = mlx_xpm_file_to_image(d->mlx, d->n_t.p, &d->n_t.w, &d->n_t.h);
	check_texture(d->n_t.img, d);
	d->n_t.ad = mlx_get_data_addr(d->n_t.img, &d->n_t.bpp,
	&d->n_t.l_l, &d->n_t.end);
	d->p_t.img = mlx_xpm_file_to_image(d->mlx, d->p_t.p, &d->p_t.w, &d->p_t.h);
	check_texture(d->p_t.img, d);
	d->p_t.ad = mlx_get_data_addr(d->p_t.img, &d->p_t.bpp,
	&d->p_t.l_l, &d->p_t.end);
	d->img = mlx_new_image(d->mlx, d->win_w, d->win_h);
	check_texture(d->img, d);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->l_l, &d->endian);
}

int		view(t_parameters *data)
{
	raycaster(data);
	return (0);
}

void	hooks_manager(t_parameters *data)
{
	int done;

	done = 1;
	while (done != 0)
	{
		mlx_key_hook(data->win, keyhandle, data);
		mlx_hook(data->win, 17, 0, &close_window, data);
		mlx_hook(data->win, 16, 0, &view, data);
		mlx_loop(data->mlx);
	}
}
