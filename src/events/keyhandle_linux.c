/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle_linux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:30:42 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/09 20:23:43 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "keycode.h"

int		keyhandle(int keycode, t_parameters *data)
{
	if (keycode == LEFT_KEY)
		watch_left(data);
	else if (keycode == RIGHT_KEY)
		watch_right(data);
	else if (keycode == W_KEY)
		move_forward(data);
	else if (keycode == S_KEY)
		move_backward(data);
	else if (keycode == D_KEY)
		move_right(data);
	else if (keycode == A_KEY)
		move_left(data);
	else if (keycode == ESC_KEY)
		escape(data);
	raycaster(data);
	return (0);
}
