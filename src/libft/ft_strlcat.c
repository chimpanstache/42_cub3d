/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:33:32 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/29 16:17:26 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t ret;

	i = 0;
	j = 0;
	ret = 0;
	while (dst[i])
		i++;
	while (src[ret])
		ret++;
	if (i > size)
		ret = ret + size;
	else
		ret = ret + i;
	while ((i + 1) < size && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ret);
}
