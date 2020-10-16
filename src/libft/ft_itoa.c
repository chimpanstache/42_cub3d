/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:17:11 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/14 14:30:40 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigit(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				len;
	char			*arr;

	sign = 0;
	len = countdigit(n);
	if (!(arr = malloc(sizeof(*arr) * ((len + 1)))))
		return (0);
	arr[len] = 0;
	if (n < 0)
	{
		sign = 1;
		nb = (unsigned int)(n * -1);
		arr[0] = '-';
	}
	else
		nb = (unsigned int)n;
	while (len-- > sign)
	{
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (arr);
}
