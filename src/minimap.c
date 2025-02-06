/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:09:16 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/23 22:26:47 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	initialize_minimap(t_window_data *data, t_map *map_data)
{
	int	pixel_size;
	int	minimap_width;
	int	minimap_height;

	pixel_size = calculate_pixel_size(map_data);
	if (pixel_size == 0)
		pixel_size = 1;
	minimap_width = map_data->map_width * pixel_size;
	minimap_height = map_data->map_height * pixel_size;
	data->minimap_img.img = mlx_new_image(data->mlx, minimap_width,
			minimap_height);
	if (!data->minimap_img.img)
		return (0);
	data->minimap_img.addr = mlx_get_data_addr(data->minimap_img.img,
			&data->minimap_img.bits_per_pixel, &data->minimap_img.line_length,
			&data->minimap_img.endian);
	if (!data->minimap_img.addr)
		return (0);
	return (pixel_size);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	offset;
	int	minimap_width;
	int	minimap_height;
	int	pixel_size;

	pixel_size = calculate_pixel_size(&data->map_data);
	minimap_width = data->map_data.map_width * pixel_size;
	minimap_height = data->map_data.map_height * pixel_size;
	if (x >= minimap_width || y >= minimap_height || x < 0 || y < 0)
		return ;
	offset = y * data->window.minimap_img.line_length + x
		* (data->window.minimap_img.bits_per_pixel / 8);
	*(int *)(data->window.minimap_img.addr + offset) = color;
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	pixel_size;

	i = 0;
	pixel_size = calculate_pixel_size(&data->map_data);
	while (i < pixel_size)
	{
		j = 0;
		while (j < pixel_size)
		{
			put_pixel(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_cell(t_data *data, int y, int pixel_size)
{
	int		x;
	int		color;

	x = 0;
	color = 0;
	while (data->map_data.map[y][x])
	{
		if (data->map_data.map[y][x] == '1')
		{
			if (data->map_data.textures.floor == 0x000000)
				color = 0x1f1f1f;
			else
				color = data->map_data.textures.floor;
		}
		else if (data->map_data.map[y][x] == '0')
			color = 0xFFFFFF;
		else if (is_player(data->map_data.map[y][x]))
			color = data->map_data.textures.ceiling;
		draw_square(data, x * pixel_size, y * pixel_size, color);
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	int		pixel_size;
	int		y;

	pixel_size = calculate_pixel_size(&data->map_data);
	y = 0;
	while (data->map_data.map[y])
	{
		draw_minimap_cell(data, y, pixel_size);
		y++;
	}
	mlx_put_image_to_window(data->window.mlx, data->window.window,
		data->window.minimap_img.img, 10, 10);
}
