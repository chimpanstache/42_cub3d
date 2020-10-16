/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:10:20 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:16:51 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *s1;

	s1 = (char *)str;
	while (*s1)
	{
		if (*s1 == c)
			return (s1);
		s1++;
	}
	if (c == '\0')
		return (s1);
	return (NULL);
}
