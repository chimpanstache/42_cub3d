/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:40:25 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/14 14:31:29 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(const char c, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	forward(char const *s1, char const *set)
{
	size_t		i;

	i = 0;
	while (s1[i] && match(s1[i], set))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			trstart;
	size_t			trend;
	size_t			i;
	char			*arr;

	if (s1 == 0 || set == 0)
		return (0);
	trstart = forward(s1, set);
	trend = ft_strlen(s1);
	while (match(s1[trend - 1], set) && trend != trstart)
		trend--;
	if (!(arr = malloc(sizeof(*arr) * (trend - trstart + 1))))
		return (0);
	i = 0;
	while (i < trend - trstart)
	{
		arr[i] = s1[trstart + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
