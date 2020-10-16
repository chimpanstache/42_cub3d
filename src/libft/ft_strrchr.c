/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:55:35 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:18:32 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s1;

	s1 = (char *)str + ft_strlen(str);
	while (s1 != (str - 1))
	{
		if (*s1 == c)
			return (s1);
		s1--;
	}
	return (NULL);
}
