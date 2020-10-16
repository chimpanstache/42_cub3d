/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:12:40 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/09 20:31:58 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(char *line, int fd)
{
	char	*buf;
	int		ret;

	ret = 1;
	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (NULL);
	while (ft_check_nl(line) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(line = ft_strjoin(line, buf)))
		{
			free(buf);
			return (NULL);
		}
		if (ft_check_nl(line) >= 0)
			break ;
	}
	if (ret < 0)
		return (NULL);
	free(buf);
	return (line);
}
