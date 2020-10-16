/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:15:12 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/11 19:09:44 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_path(t_parameters *data)
{
	free(data->path.e);
	free(data->path.w);
	free(data->path.n);
	free(data->path.s);
	free(data->path.sp);
}

void	free_all(t_parameters *data)
{
	free_map(data);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->n_t.img)
		mlx_destroy_image(data->mlx, data->n_t.img);
	if (data->s_t.img)
		mlx_destroy_image(data->mlx, data->s_t.img);
	if (data->w_t.img)
		mlx_destroy_image(data->mlx, data->w_t.img);
	if (data->e_t.img)
		mlx_destroy_image(data->mlx, data->e_t.img);
	if (data->p_t.img)
		mlx_destroy_image(data->mlx, data->p_t.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->zbuffer)
		free(data->zbuffer);
	free_path(data);
	free(data->sprites);
}
