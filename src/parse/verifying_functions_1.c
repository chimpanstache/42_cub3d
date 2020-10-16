/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifying_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:37:20 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/11 19:21:42 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	verify_line(t_parameters *prs)
{
	int i;

	i = 0;
	while (ft_isdigit(prs->l[i]) != 1)
	{
		if (prs->l[i] == 0)
			error_msg(10);
		i++;
	}
}

void	verify_missing_params(t_parameters *prs)
{
	if (prs->parse.r < 1)
		error_msg(10);
	if (prs->parse.no < 1)
		error_msg(10);
	if (prs->parse.so < 1)
		error_msg(10);
	if (prs->parse.we < 1)
		error_msg(10);
	if (prs->parse.ea < 1)
		error_msg(10);
	if (prs->parse.s < 1)
		error_msg(10);
	if (prs->parse.f < 1)
		error_msg(10);
	if (prs->parse.c < 1)
		error_msg(10);
}

void	verify_each_params(t_parameters *prs)
{
	if (prs->parse.r > 1)
		error_msg(9);
	if (prs->parse.no > 1)
		error_msg(9);
	if (prs->parse.so > 1)
		error_msg(9);
	if (prs->parse.we > 1)
		error_msg(9);
	if (prs->parse.ea > 1)
		error_msg(9);
	if (prs->parse.s > 1)
		error_msg(9);
	if (prs->parse.f > 1)
		error_msg(9);
	if (prs->parse.c > 1)
		error_msg(9);
}

void	verify_parse(t_parameters *prs)
{
	if (prs->parse.r == 1 && prs->parse.no == 1 &&
			prs->parse.so == 1 && prs->parse.we == 1 &&
			prs->parse.ea == 1 && prs->parse.s == 1 &&
			prs->parse.f == 1 && prs->parse.c == 1)
		return ;
	else
	{
		free(prs->l);
		verify_each_params(prs);
		verify_missing_params(prs);
	}
}
