/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:26:12 by ehafidi           #+#    #+#             */
/*   Updated: 2020/03/09 15:17:14 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	if (!s)
	{
		if (!(copy = (char *)malloc(sizeof(*copy) * (1))))
			return (NULL);
		copy[i] = '\0';
		return (copy);
	}
	if (!(copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
