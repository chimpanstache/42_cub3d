/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:45:28 by stuntman          #+#    #+#             */
/*   Updated: 2020/10/15 17:07:35 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map_char(char *map_i_l)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (map_i_l[++i])
	{
		if (ft_chrstr(map_i_l[i], "012NSEW \n") == NULL)
		{
			free(map_i_l);
			error_msg(6);
		}
	}
	i = -1;
	while (map_i_l[++i])
	{
		if (ft_chrstr(map_i_l[i], "NSEW") != NULL)
			j++;
	}
	if (j != 1)
	{
		free(map_i_l);
		error_msg(7);
	}
	return (0);
}

void	parse_loop(t_parameters *p)
{
	int h;

	h = 0;
	while ((p->ret = get_next_line(p->fd, &p->l)))
	{
		p->check = check_line(p);
		if (p->check == 1)
		{
			parse_line(p);
			get_info_line(p);
		}
		if (p->check == 2)
		{
			verify_parse(p);
			if (!(p->l = ft_strjoin(p->l, "\n")))
				error_msg(15);
			if (!(p->map_i_l = ft_strjoin(p->map_i_l, p->l)))
			{
				free(p->l);
				error_msg(15);
			}
		}
		h++;
		free(p->l);
	}
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	adjust_values(t_parameters *p)
{
	p->scr_h = p->size.scrn_h;
	p->scr_w = p->size.scrn_w;
	p->win_h = p->size.scrn_h;
	p->win_w = p->size.scrn_w;
	p->posx = p->begin.x;
	p->posy = p->begin.y;
	p->flr_color = create_trgb(0, p->clr_flr.r, p->clr_flr.g, p->clr_flr.b);
	p->clg_color = create_trgb(0, p->clr_clng.r, p->clr_clng.g, p->clr_clng.b);
	p->w_t.p = p->path.w;
	p->n_t.p = p->path.n;
	p->s_t.p = p->path.s;
	p->e_t.p = p->path.e;
	p->p_t.p = p->path.sp;
}

void	parser(t_parameters *p)
{
	init_prs(p);
	init_prs_1(p);
	p->i = 0;
	p->l = NULL;
	p->fd = open(p->config_file_path, O_RDONLY);
	parse_loop(p);
	if (!(p->map_i_l = ft_strjoin(p->map_i_l, p->l)))
	{
		free(p->l);
		error_msg(15);
	}
	free(p->config_file_path);
	p->error = verify_infos(p);
	p->error = check_map_char((char*)p->map_i_l);
	parse_map(p);
	adjust_values(p);
}
