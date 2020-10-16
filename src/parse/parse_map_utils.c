/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:24:31 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:51:34 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_chrstr(int c, const char *str)
{
	int		i;
	char	*s1;

	s1 = (char *)str;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}

void	check_if_space(t_parameters *prs)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (prs->l[++i])
	{
		if (prs->l[i] != ' ')
		{
			j = ft_is_alpha_maj(prs->l[i]);
			j = ft_is_scnd_char(prs->l[i + 1]);
			break ;
		}
	}
	if (j == 0)
	{
		free(prs->l);
		error_msg(13);
	}
}

void	leave_properly(t_parameters *prs, int i)
{
	free(prs->l);
	if (i == 2)
		error_msg(13);
	else if (i == 1)
		error_msg(11);
	else if (i == 3)
		error_msg(12);
}

void	check_bs(t_parameters *prs)
{
	int i;

	i = -1;
	while (prs->l[++i])
	{
		if (prs->l[i] == 'R' && prs->l[i + 1] != ' ')
			leave_properly(prs, 1);
		else if (prs->l[i] == 'O' && ((prs->l[i - 1] != 'N') &&
		(prs->l[i - 1] != 'S')))
			leave_properly(prs, 2);
		else if (prs->l[i] == 'W' && prs->l[i + 1] != 'E')
			leave_properly(prs, 2);
		else if (prs->l[i] == 'A' && prs->l[i - 1] != 'E')
			leave_properly(prs, 2);
		else if (prs->l[i] == 'E' && prs->l[i + 1] == 'E')
			leave_properly(prs, 2);
		else if (prs->l[i] == 'F' && prs->l[i + 1] != ' ')
			leave_properly(prs, 3);
		else if (prs->l[i] == 'C' && prs->l[i + 1] != ' ')
			leave_properly(prs, 3);
	}
}

void	parse_line(t_parameters *prs)
{
	int i;

	i = -1;
	check_if_space(prs);
	check_flr_clg(prs);
	check_bs(prs);
	while (prs->l[++i])
	{
		if (prs->l[i] == 'R')
			prs->parse.r++;
		else if (prs->l[i] == 'N' && prs->l[i + 1] == 'O')
			prs->parse.no++;
		else if (prs->l[i] == 'S' && prs->l[i + 1] == 'O')
			prs->parse.so++;
		else if (prs->l[i] == 'W' && prs->l[i + 1] == 'E')
			prs->parse.we++;
		else if (prs->l[i] == 'E' && prs->l[i + 1] == 'A')
			prs->parse.ea++;
		else if (prs->l[i] == 'S')
			prs->parse.s++;
		else if (prs->l[i] == 'F')
			prs->parse.f++;
		else if (prs->l[i] == 'C')
			prs->parse.c++;
	}
}
