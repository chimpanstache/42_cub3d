/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:10:46 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 13:49:53 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_parameters *p)
{
	if (p->map[(int)(p->posx - p->diry * MSPEED)][(int)(p->posy)] == '0')
		p->posx += -p->diry * MSPEED;
	if (p->map[(int)(p->posx)][(int)(p->posy + p->dirx * MSPEED)] == '0')
		p->posy += p->dirx * MSPEED;
}

void	move_right(t_parameters *p)
{
	if (p->map[(int)(p->posx + p->diry * MSPEED)][(int)(p->posy)] == '0')
		p->posx += p->diry * MSPEED;
	if (p->map[(int)(p->posx)][(int)(p->posy - p->dirx * MSPEED)] == '0')
		p->posy += -p->dirx * MSPEED;
}

void	move_forward(t_parameters *p)
{
	if (p->map[(int)(p->posx + p->dirx * MSPEED)][(int)(p->posy)] == '0')
		p->posx += p->dirx * MSPEED;
	if (p->map[(int)(p->posx)][(int)(p->posy + p->diry * MSPEED)] == '0')
		p->posy += p->diry * MSPEED;
}

void	move_backward(t_parameters *p)
{
	if (p->map[(int)(p->posx - p->dirx * MSPEED)][(int)(p->posy)] == '0')
		p->posx -= p->dirx * MSPEED;
	if (p->map[(int)(p->posx)][(int)(p->posy - p->diry * MSPEED)] == '0')
		p->posy -= p->diry * MSPEED;
}
