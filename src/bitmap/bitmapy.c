/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmapy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:37:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/14 13:28:05 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned char	*create_file_header(int bmp_size)
{
	unsigned char *file_header;

	if (!(file_header = ft_calloc(15, sizeof(*file_header))))
		error_msg(15);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(bmp_size);
	file_header[3] = (unsigned char)(bmp_size >> 8);
	file_header[4] = (unsigned char)(bmp_size >> 16);
	file_header[5] = (unsigned char)(bmp_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	return (file_header);
}

unsigned char	*create_image_header(t_parameters *prs)
{
	unsigned char *image_header;

	if (!(image_header = ft_calloc(41, sizeof(*image_header))))
		error_msg(15);
	image_header[0] = (unsigned char)(40);
	image_header[4] = (unsigned char)(prs->win_w);
	image_header[5] = (unsigned char)(prs->win_w >> 8);
	image_header[6] = (unsigned char)(prs->win_w >> 16);
	image_header[7] = (unsigned char)(prs->win_w >> 24);
	image_header[8] = (unsigned char)(prs->win_h);
	image_header[9] = (unsigned char)(prs->win_h >> 8);
	image_header[10] = (unsigned char)(prs->win_h >> 16);
	image_header[11] = (unsigned char)(prs->win_h >> 24);
	image_header[12] = (unsigned char)(1);
	image_header[14] = (unsigned char)(prs->bpp);
	return (image_header);
}

void			calc_bmp_data(t_bmp *bmp, t_parameters *prs)
{
	bmp->bytes_width = prs->win_w * prs->bpp;
	bmp->pad_size = (4 - (bmp->bytes_width) % 4) % 4;
	bmp->bmp_size = 14 + 40 + ((bmp->bytes_width + bmp->pad_size) * prs->win_h);
	bmp->fileheader = create_file_header(bmp->bmp_size);
	bmp->imageheader = create_image_header(prs);
	write(bmp->fd, bmp->fileheader, 14);
	write(bmp->fd, bmp->imageheader, 40);
	free(bmp->fileheader);
	free(bmp->imageheader);
}

void			create_image(t_parameters *prs)
{
	t_bmp bmp;

	if ((bmp.fd = open("firstpic.bmp", O_CREAT | O_EXCL | O_RDWR,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		error_msg(16);
	calc_bmp_data(&bmp, prs);
	bmp.i = (prs->win_h);
	while (--bmp.i > 0)
	{
		bmp.j = -1;
		while (++bmp.j < (prs->win_w))
		{
			bmp.r = prs->addr[bmp.i * prs->l_l + bmp.j * prs->bpp / 8];
			bmp.g = prs->addr[bmp.i * prs->l_l + bmp.j * prs->bpp / 8 + 1];
			bmp.b = prs->addr[bmp.i * prs->l_l + bmp.j * prs->bpp / 8 + 2];
			write(bmp.fd, &bmp.r, 1);
			write(bmp.fd, &bmp.g, 1);
			write(bmp.fd, &bmp.b, 1);
			write(bmp.fd, "\0", 1);
		}
	}
	close(bmp.fd);
	close_window(prs);
}
