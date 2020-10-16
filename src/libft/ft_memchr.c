/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:02:55 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:14:25 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *sbis;

	sbis = (char *)s;
	while (n > 0)
	{
		if (*sbis == c)
			return (sbis);
		sbis++;
		s++;
		n--;
	}
	return (NULL);
}
