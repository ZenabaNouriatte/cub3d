/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:54:28 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/29 17:23:36 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	init_data(&data);
	data.map.map = create_map();
	set_player_position(&data.map);
	// Parsing de la map commence ici
	read_map(argv[1], &data);
	if (!initialize_mlx_connexion(&data.window))
		return (close_window(&data), 1);
	events_init(&data);
	draw_map(&data);
	mlx_loop(data.window.mlx);
	return (0);
}

int	initialize_mlx_connexion(t_window_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->width = 1000;
	data->height = 600;
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"cub3D");
	if (!data->window)
		return (0);
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img.img)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (0);
	return (1);
}