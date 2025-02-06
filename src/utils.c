/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:09:40 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/23 22:35:25 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_get_pixel(t_img_data *image, int x, int y)
{
	char	*pxl;

	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		pxl = image->addr + (y * image->line_length + x * (image->bits_per_pixel
					/ 8));
		return (*(unsigned int *)pxl);
	}
	else
		ft_putstr_fd("Error ft_get_pixel\n", 2);
	return (0);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_player_position(t_map *map_data, char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (is_player(map[y][x]))
		{
			if (map_data->square.x != -1 || map_data->square.y != -1)
				return (ft_putstr_fd("Error\nOne player only\n", 2), -1);
			map_data->square.x = x;
			map_data->square.y = y;
			map_data->initial_vue = map[y][x];
		}
		x++;
	}
	return (0);
}

int	set_player_position(t_map *map_data)
{
	int		y;
	char	**map;

	map_data->square.x = -1;
	map_data->square.y = -1;
	y = 0;
	map = map_data->map;
	while (map[y])
	{
		if (check_player_position(map_data, map, y) == -1)
			return (-1);
		y++;
	}
	if (map_data->square.x == -1 || map_data->square.y == -1)
		return (ft_putstr_fd("Error\nOne player needed\n", 2), -1);
	return (0);
}
