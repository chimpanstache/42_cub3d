/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:23:42 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:14:15 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dest1;
	unsigned char *src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (n > 0 && (*src1 != (unsigned char)c))
	{
		*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	if (n == 0)
		return (NULL);
	*dest1 = (unsigned char)c;
	return (dest1 + 1);
}
