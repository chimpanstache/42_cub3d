/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:26:37 by ehafidi           #+#    #+#             */
/*   Updated: 2020/03/09 15:17:50 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		s1_l;
	size_t		s2_l;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!(arr = malloc(sizeof(char) * (s1_l + s2_l + 1))))
		return (0);
	ft_memcpy(arr, s1, s1_l);
	ft_memcpy(arr + s1_l, s2, s2_l);
	arr[s1_l + s2_l] = '\0';
	free((char *)s1);
	return (arr);
}
