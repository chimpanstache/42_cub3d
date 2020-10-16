/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:13:24 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/09 20:31:08 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char rest[OPEN_MAX][BUFFER_SIZE + 1];
	int			nl;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_strdup(rest[fd])))
		return (-1);
	if (!(*line = ft_readline(*line, fd)))
		return (-1);
	if ((nl = ft_check_nl(*line)) >= 0 || (ft_check_nl(rest[fd])) >= 0)
	{
		ft_strcpy(rest[fd], *line + nl + 1);
		if (!(*line = ft_substr(*line, 0, nl)))
			return (-1);
		return (1);
	}
	rest[fd][0] = '\0';
	return (0);
}
