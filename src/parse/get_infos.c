/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:16:29 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/14 16:57:27 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_arr(t_parameters *p)
{
	int		i;

	i = 0;
	while (p->arr[i] != NULL)
	{
		free(p->arr[i]);
		i++;
	}
	free(p->arr);
}

void	free_map(t_parameters *p)
{
	int		i;

	i = -1;
	while (++i < p->map_h)
		free(p->map[i]);
	free(p->map);
}

void	free_map_to_ff(t_parameters *p)
{
	int		i;

	i = -1;
	while (++i < p->map_h)
		free(p->map_to_ff[i]);
	free(p->map_to_ff);
}

void	get_info_line(t_parameters *p)
{
	int		i;
	t_path	path;

	i = -1;
	while (p->l[++i])
	{
		if (p->l[i] == 'R' && p->l[i + 1] == ' ')
			get_screen_size(p);
		else if (p->l[i] == 'N' && p->l[i + 1] == 'O' && p->l[i + 2] == ' ')
			p->path.n = get_path(p, path.n);
		else if (p->l[i] == 'S' && p->l[i + 1] == 'O' && p->l[i + 2] == ' ')
			p->path.s = get_path(p, path.s);
		else if (p->l[i] == 'W' && p->l[i + 1] == 'E' && p->l[i + 2] == ' ')
			p->path.w = get_path(p, path.w);
		else if (p->l[i] == 'E' && p->l[i + 1] == 'A' && p->l[i + 2] == ' ')
			p->path.e = get_path(p, path.e);
		else if (p->l[i] == 'S' && p->l[i + 1] == ' ')
			p->path.sp = get_path(p, path.sp);
		else if (p->l[i] == 'F' && p->l[i + 1] == ' ')
			get_color_flr(p);
		else if (p->l[i] == 'C' && p->l[i + 1] == ' ')
			get_color_clng(p);
	}
}
