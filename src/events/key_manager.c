/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:12:49 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:57:33 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	watch_left(t_parameters *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(RSPEED) - data->diry * sin(RSPEED);
	data->diry = data->olddirx * sin(RSPEED) + data->diry * cos(RSPEED);
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(RSPEED) - data->planey * sin(RSPEED);
	data->planey = data->oldplanex * sin(RSPEED) + data->planey * cos(RSPEED);
}

void	watch_right(t_parameters *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(-RSPEED) - data->diry * sin(-RSPEED);
	data->diry = data->olddirx * sin(-RSPEED) + data->diry * cos(-RSPEED);
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(-RSPEED) - data->planey * sin(-RSPEED);
	data->planey = data->oldplanex * sin(-RSPEED) + data->planey * cos(-RSPEED);
}

void	escape(t_parameters *data)
{
	free_all(data);
	exit(0);
}

int		close_window(t_parameters *data)
{
	free_all(data);
	exit(0);
	return (0);
}
