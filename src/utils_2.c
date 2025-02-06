/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:26:06 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/24 11:23:16 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	calculate_pixel_size(t_map *map_data)
{
	int	max_pixel_width;
	int	max_pixel_height;
	int	pixel_size;

	max_pixel_width = MINIMAP_WIDTH / map_data->map_width;
	max_pixel_height = MINIMAP_HEIGHT / map_data->map_height;
	if (max_pixel_width < max_pixel_height)
		pixel_size = max_pixel_width;
	else
		pixel_size = max_pixel_height;
	if (pixel_size * map_data->map_width > MAX_MINIMAP_SIZE)
		pixel_size = MAX_MINIMAP_SIZE / map_data->map_width;
	if (pixel_size * map_data->map_height > MAX_MINIMAP_SIZE)
		pixel_size = MAX_MINIMAP_SIZE / map_data->map_height;
	if (pixel_size < 1)
		pixel_size = 1;
	return (pixel_size);
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = data->window.img.addr + (y * data->window.img.line_length + x
				* (data->window.img.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
	else
		ft_putstr_fd("Error ft_put_pixel\n", 2);
}
