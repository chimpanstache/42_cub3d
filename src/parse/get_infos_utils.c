/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:18:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 17:31:41 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(t_parameters *prs, char *path)
{
	char c;

	c = ' ';
	if (!(prs->arr = ft_split(prs->l, c)))
		error_msg(15);
	if (prs->arr[1] == NULL || prs->arr[2] != NULL)
	{
		free_arr(prs);
		error_msg(13);
	}
	if (!(path = ft_strdup(prs->arr[1])))
		error_msg(15);
	free_arr(prs);
	return (path);
}

int		ft_isprint_wtht_space_digit(int c)
{
	if ((33 <= c && c <= 47) || (58 <= c && c <= 126))
		return (1);
	else
		return (0);
}

void	get_color_clng(t_parameters *prs)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(prs->l);
	while (prs->l[--j])
	{
		if (ft_isprint_wtht_space_digit(prs->l[j]) == 1)
			error_msg(12);
		else if (ft_isdigit(prs->l[j]) == 1)
			break ;
	}
	while (ft_isdigit(prs->l[i]) != 1 && (prs->l[i] == ' ' || prs->l[i] == 'C'))
		i++;
	prs->arr = ft_split(&prs->l[i], ',');
	if (prs->arr[1] == NULL || prs->arr[2] == NULL || prs->arr[3] != NULL)
	{
		free_arr(prs);
		error_msg(12);
	}
	check_arr(prs);
	prs->clr_clng.r = ft_atoi(prs->arr[0]);
	prs->clr_clng.g = ft_atoi(prs->arr[1]);
	prs->clr_clng.b = ft_atoi(prs->arr[2]);
	free_arr(prs);
}

void	get_color_flr(t_parameters *prs)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(prs->l);
	while (prs->l[--j])
	{
		if (ft_isprint_wtht_space_digit(prs->l[j]) == 1)
			error_msg(12);
		else if (ft_isdigit(prs->l[j]) == 1)
			break ;
	}
	while (ft_isdigit(prs->l[i]) != 1 && (prs->l[i] == ' ' || prs->l[i] != 'F'))
		i++;
	prs->arr = ft_split(&prs->l[++i], ',');
	if (prs->arr[1] == NULL || prs->arr[2] == NULL || prs->arr[3] != NULL)
	{
		free_arr(prs);
		error_msg(12);
	}
	check_arr(prs);
	prs->clr_flr.r = ft_atoi(prs->arr[0]);
	prs->clr_flr.g = ft_atoi(prs->arr[1]);
	prs->clr_flr.b = ft_atoi(prs->arr[2]);
	free_arr(prs);
}

void	get_screen_size(t_parameters *prs)
{
	char c;

	c = ' ';
	if (!(prs->arr = ft_split(prs->l, c)))
		error_msg(15);
	if (prs->arr[1] == NULL || prs->arr[2] == NULL || prs->arr[3] != NULL)
		error_msg(11);
	check_arr_2(prs);
	prs->size.scrn_w = ft_atoi(prs->arr[1]);
	prs->size.scrn_h = ft_atoi(prs->arr[2]);
	free_arr(prs);
}
