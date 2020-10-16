/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:40:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/10/15 12:26:00 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_parameters *data, char *argv)
{
	int fd;

	if (!(data->config_file_path = ft_strdup(argv)))
		error_msg(15);
	if ((fd = open(data->config_file_path, O_RDONLY)) < 0)
		error_msg(18);
	else
		close(fd);
}

void	get_save(t_parameters *data, char *argv)
{
	if (!(data->save = ft_strdup(argv)))
		error_msg(15);
}

void	loop_to_get_spawn(t_parameters *data)
{
	int y;
	int x;

	y = -1;
	while (++y < data->map_h)
	{
		x = -1;
		while (++x < data->map_w)
			set_spawn_params(x, y, data);
	}
}

int		main(int argc, char *argv[])
{
	t_parameters data;

	if (argc > 3 || argc == 0)
		error_msg(18);
	get_map(&data, argv[1]);
	parser(&data);
	loop_to_get_spawn(&data);
	data.mlx = mlx_init();
	generate_picture(&data);
	if (!(data.zbuffer = (double*)malloc(sizeof(double) * data.win_w)))
		error_msg(15);
	raycaster(&data);
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", 10) == 0)
			create_image(&data);
		else if (ft_strncmp(argv[2], "--save", 10) != 0)
			error_msg(18);
	}
	hooks_manager(&data);
	return (0);
}
