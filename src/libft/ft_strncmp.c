/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:06:03 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:18:09 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char *s_1;
	unsigned char *s_2;

	s_1 = (unsigned char *)str1;
	s_2 = (unsigned char *)str2;
	while (n > 0 && (*s_1 || *s_2))
	{
		if (*s_1 < *s_2 || *s_1 == '\0')
			return (*s_1 - *s_2);
		if (*s_1 > *s_2 || *s_2 == '\0')
			return (*s_1 - *s_2);
		n--;
		s_1++;
		s_2++;
	}
	return (0);
}
