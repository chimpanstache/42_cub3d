/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:11:36 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:18:21 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t a;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == len)
			return (NULL);
		a = 0;
		while (str[i + a] == to_find[a] && str[i + a] != '\0')
		{
			if ((i + a) == len)
				return (NULL);
			if (to_find[a + 1] == '\0')
				return ((char *)&str[i]);
			a++;
		}
		i++;
	}
	return (NULL);
}
