/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:54:28 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/31 15:10:07 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_argc(int argc)
{
	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong argument number\n", 2), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	ft_memset(&data, 0, sizeof(t_data));
	if (check_argc(argc) == -1 || read_parse_file(argv[1], &data) == -1)
		return (1);
	if (parse_map(&data) == -1)
	{
		free_data(&data);
		return (1);
	}
	if (!initialize_mlx_connexion(&data))
		return (close_window(&data), 1);
	init_simulation(&data.map_data);
	if (!get_textures(&data, &data.map_data.textures))
		return (close_window(&data), 1);
	events_init(&data);
	start_simulation(&data);
	draw_minimap(&data);
	mlx_loop(data.window.mlx);
	return (0);
}

int	initialize_mlx_connexion(t_data *data)
{
	t_window_data	*window;

	window = &data->window;
	window->mlx = mlx_init();
	if (!window->mlx)
		return (0);
	window->width = WINDOW_WIDTH;
	window->height = WINDOW_HEIGHT;
	window->window = mlx_new_window(window->mlx, window->width, window->height,
			"cub3D");
	if (!window->window)
		return (free_mlx(data), 0);
	window->img.img = mlx_new_image(window->mlx, window->width, window->height);
	if (!window->img.img)
		return (free_mlx(data), 0);
	window->img.addr = mlx_get_data_addr(window->img.img,
			&window->img.bits_per_pixel, &window->img.line_length,
			&window->img.endian);
	if (!window->img.addr)
		return (free_mlx(data), 0);
	if (initialize_minimap(window, &data->map_data) == 0)
		return (free_mlx(data), 0);
	return (1);
}
