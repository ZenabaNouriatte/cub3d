/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:09:40 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/29 16:50:39 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function that translate trgb to an int value if you need it
int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < data->window.width && y >= 0 && y < data->window.height)
	{
		pxl = data->window.img.addr + (y * data->window.img.line_length + x
				* (data->window.img.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
	else
		ft_putendl_fd("Error ft_put_pixel", 2);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_walkable(char c)
{
	return (c == '0');
}

int	is_wall(char c)
{
	return (c == '1');
}

// THOSE ARE TEST FUNCTIONS
char	**create_map(void)
{
	char	**map;

	map = malloc(6 * sizeof(char *));
	map[0] = ft_strdup("111111111111");
	map[1] = ft_strdup("100000000001");
	map[2] = ft_strdup("10000N000001");
	map[3] = ft_strdup("100000000001");
	map[4] = ft_strdup("111111111111");
	map[5] = NULL;
	return (map);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '1')
				mlx_string_put(data->window.mlx, data->window.window, x * 10, (y
						* 10) + 10, 0xFF0000, "1");
			if (data->map.map[y][x] == '0')
				mlx_string_put(data->window.mlx, data->window.window, x * 10, (y
						* 10) + 10, 0xFFFFFF, "0");
			if (is_player(data->map.map[y][x]))
				mlx_string_put(data->window.mlx, data->window.window, x * 10, (y
						* 10) + 10, 0x0000FF, "N");
			x++;
		}
		y++;
	}
}

void	set_player_position(t_map *map_data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = map_data->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{
				map_data->player.x = x;
				map_data->player.y = y;
				map_data->initial_vue = 'N';
			}
			x++;
		}
		y++;
	}
}
