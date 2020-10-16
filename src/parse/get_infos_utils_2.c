/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:25:40 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:51:03 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_arr_each_line(t_parameters *p, char *l)
{
	char	*trimmed;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(trimmed = ft_strtrim(l, " ")))
		error_msg(15);
	i = -1;
	while (trimmed[++i])
		if (ft_isdigit(trimmed[i]) != 1)
			j++;
	free(trimmed);
	if (j != 0)
	{
		free_arr(p);
		error_msg(12);
	}
}

void	check_flr_clg(t_parameters *prs)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (prs->l[++i])
		if (prs->l[i] == ',')
			j++;
	if (j > 2)
	{
		free(prs->l);
		error_msg(12);
	}
}

void	check_arr(t_parameters *p)
{
	check_arr_each_line(p, p->arr[0]);
	check_arr_each_line(p, p->arr[1]);
	check_arr_each_line(p, p->arr[2]);
}

void	check_arr_2(t_parameters *p)
{
	check_arr_each_line(p, p->arr[1]);
	check_arr_each_line(p, p->arr[2]);
}
