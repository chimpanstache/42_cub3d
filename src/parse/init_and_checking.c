/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:24:33 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/13 13:58:50 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_prs(t_parameters *prs)
{
	prs->parse.r = 0;
	prs->parse.no = 0;
	prs->parse.so = 0;
	prs->parse.we = 0;
	prs->parse.ea = 0;
	prs->parse.s = 0;
	prs->parse.f = 0;
	prs->parse.c = 0;
	prs->parse.check_map = 0;
	prs->size.scrn_h = -1;
	prs->size.scrn_w = -1;
	prs->clr_clng.r = -1;
	prs->clr_clng.g = -1;
	prs->clr_clng.b = -1;
	prs->clr_flr.r = -1;
	prs->clr_flr.g = -1;
	prs->clr_flr.b = -1;
}

void	init_prs_1(t_parameters *prs)
{
	prs->planey = 0.66;
	prs->dirx = 0.0;
	prs->diry = 0.0;
	prs->planex = 0.0;
	prs->planey = 0.0;
	prs->begin.x = 0;
	prs->begin.y = 0;
	prs->size2.space = 0;
	prs->nsprite = 0;
	prs->time = 0;
	prs->oldtime = 0;
	if (!(prs->map_i_l = ft_strdup("")))
		error_msg(15);
}

int		check_map_place(t_parameters *prs)
{
	if (prs->parse.r == 0 || prs->parse.no == 0
	|| prs->parse.so == 0 || prs->parse.we == 0
	|| prs->parse.ea == 0 || prs->parse.s == 0
	|| prs->parse.f == 0 || prs->parse.c == 0)
		return (1);
	return (0);
}

void	check_empty_lines(t_parameters *prs)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (ft_strlen(prs->l) == 0)
		error_msg(14);
	while (prs->l[++i])
	{
		if (prs->l[i] == ' ')
			j++;
	}
	if (j == i)
		error_msg(14);
}

int		check_line(t_parameters *prs)
{
	int i;
	int j;

	i = -1;
	if (prs->check == 2)
		check_empty_lines(prs);
	while (prs->l[++i])
	{
		j = ft_isalpha(prs->l[i]);
		if (j == 1)
			return (1);
		j = ft_isdigit(prs->l[i]);
		if (j == 1)
			return (2);
		j = ft_isprint(prs->l[i]);
		if (prs->l[i] != ' ' && j == 1)
			error_msg(14);
	}
	return (0);
}
