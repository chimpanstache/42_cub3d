/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngmnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:37:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 13:58:11 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_msg_2(int err)
{
	if (err == 10)
		write(1, "error: missing params, map not at eof, or bs in line\n", 54);
	else if (err == 11)
		write(1, "error: invalid dimension line\n", 31);
	else if (err == 12)
		write(1, "error: invalid ceiling or floor or resolution line\n", 52);
	else if (err == 13)
		write(1, "error: invalid texture or C or F line\n", 39);
	else if (err == 14)
		write(1, "error: invalid map or garbage in line\n", 39);
	else if (err == 15)
		write(1, "error: malloc failed\n", 22);
	else if (err == 16)
		write(1, "error: opening failed\n", 23);
	else if (err == 17)
		write(1, "error: texture loading failed\n", 31);
	else if (err == 18)
		write(1, "error: wrong argv\n", 19);
}

void	error_msg(int err)
{
	if (err == 1)
		write(1, "error: map not at eof\n", 23);
	else if (err == 2)
		write(1, "error: invalid ceiling color\n", 30);
	else if (err == 3)
		write(1, "error: invalid floor color\n", 28);
	else if (err == 4)
		write(1, "error: invalid width line\n", 27);
	else if (err == 5)
		write(1, "error: invalid height line\n", 28);
	else if (err == 6)
		write(1, "error: invalid char in map\n", 28);
	else if (err == 7)
		write(1, "error: bad or missing map\n", 27);
	else if (err == 8)
		write(1, "error: invalid map\n", 20);
	else if (err == 9)
		write(1, "error: wrong parameter line or map not at eof\n", 47);
	error_msg_2(err);
	exit(0);
}
