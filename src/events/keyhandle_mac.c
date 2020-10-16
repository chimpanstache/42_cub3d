/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle_mac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:30:45 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/09 20:24:52 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		keyhandle(int keycode, t_parameters *data)
{
	if (keycode == 123)
		watch_left(data);
	else if (keycode == 124)
		watch_right(data);
	else if (keycode == 13)
		move_forward(data);
	else if (keycode == 1)
		move_backward(data);
	else if (keycode == 2)
		move_right(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 53)
		escape(data);
	raycaster(data);
	return (0);
}
