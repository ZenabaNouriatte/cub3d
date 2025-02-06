/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:50:10 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/24 15:45:39 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_top_bottom(t_map *map_data)
{
	int		i;
	int		line_len;

	i = 0;
	line_len = ft_strlen(map_data->map[0]);
	while (i < line_len)
	{
		if (map_data->map[0][i] != '1' && map_data->map[0][i] != ' ')
			return (-1);
		i++;
	}
	line_len = ft_strlen(map_data->map[map_data->map_height - 1]);
	i = 0;
	while (i < line_len)
	{
		if (map_data->map[map_data->map_height - 1][i] != '1' &&
			map_data->map[map_data->map_height - 1][i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_border(t_map *map_data)
{
	int		i;
	int		line_len;

	i = 0;
	while (i < map_data->map_height)
	{
		line_len = ft_strlen(map_data->map[i]);
		if (map_data->map[i][0] != '1' && map_data->map[i][0] != ' ')
			return (-1);
		if (line_len > 0
			&& map_data->map[i][line_len - 1] != '1'
			&& map_data->map[i][line_len - 1] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_spaces(t_map *map_data)
{
	int		i;
	int		j;
	int		line_len;

	i = 0;
	while (i < map_data->map_height)
	{
		line_len = ft_strlen(map_data->map[i]);
		j = 0;
		while (j < line_len)
		{
			if (map_data->map[i][j] == ' ')
			{
				if (top_spaces(map_data, &i, &j) == -1
					|| bottom_spaces(map_data, &i, &j) == -1
					|| borders_spaces(map_data, &i, &j, &line_len) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_border(t_map *map_data)
{
	if (check_top_bottom(map_data) == -1
		|| check_border(map_data) == -1
		|| check_spaces(map_data) == -1)
		return (-1);
	return (0);
}

int	check_side_walls(char **map, int height)
{
	int		i;
	int		line_len;

	i = 1;
	while (i < height - 1)
	{
		line_len = ft_strlen(map[i]);
		if (line_len == 0
			|| (map[i][0] != '1' && map[i][0] != ' ')
			|| (map[i][line_len - 1] != '1' && map[i][line_len - 1] != ' '))
			return (-1);
		i++;
	}
	if (check_wall_gaps(map, height) == -1)
		return (-1);
	return (0);
}
