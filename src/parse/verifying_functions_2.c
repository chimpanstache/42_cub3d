/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifying_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:42:30 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/14 12:29:22 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		verify_color(t_parameters *prs)
{
	if (prs->clr_clng.r < 0 || prs->clr_clng.r > 255)
		error_msg(2);
	if (prs->clr_clng.g < 0 || prs->clr_clng.g > 255)
		error_msg(2);
	if (prs->clr_clng.b < 0 || prs->clr_clng.b > 255)
		error_msg(2);
	if (prs->clr_flr.r < 0 || prs->clr_flr.r > 255)
		error_msg(3);
	if (prs->clr_flr.g < 0 || prs->clr_flr.g > 255)
		error_msg(3);
	if (prs->clr_flr.b < 0 || prs->clr_flr.b > 255)
		error_msg(3);
	return (0);
}

int		verify_dimensions(t_parameters *prs)
{
	if (prs->size.scrn_w <= 0)
		error_msg(4);
	if (prs->size.scrn_h <= 0)
		error_msg(5);
	return (0);
}

int		verify_infos(t_parameters *prs)
{
	int clr;
	int sz;

	verify_parse(prs);
	free(prs->l);
	clr = verify_color(prs);
	sz = verify_dimensions(prs);
	return (0);
}

int		ft_is_scnd_char(char c)
{
	if (c == 'O' || c == 'E' || c == 'A' || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_is_alpha_maj(char c)
{
	if (c == 'R' || c == 'N' || c == 'S' || c == 'W' ||
	c == 'E' || c == 'F' || c == 'C')
		return (1);
	else
		return (0);
}
