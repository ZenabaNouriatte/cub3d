/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:15:18 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/29 00:12:29 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls(char **map, int height, int width)
{
	int		i;
	int		line_len;

	i = 0;
	while (i < width)
	{
		line_len = ft_strlen(map[0]);
		if (i < line_len && map[0][i] != '1')
			return (-1);
		line_len = ft_strlen(map[height - 1]);
		if (i < line_len
			&& map[height - 1][i] != '1')
			return (-1);
		i++;
	}
	if (check_side_walls(map, height) == -1)
		return (-1);
	return (0);
}

int	parse_map(t_data *data)
{
	data->map_data.map_height = map_height(data->map_data.map);
	data->map_data.map_width = max_width(data->map_data.map);
	if (check_walls(data->map_data.map, data->map_data.map_height,
			data->map_data.map_width) == -1)
	{
		if (validate_closure(data) == -1
			|| check_map_border(&data->map_data) == -1)
			return (ft_putstr_fd("Error:\nOpen map\n", 2), -1);
	}
	data->map_data.map = replace_by_one(data->map_data.map, data);
	if (set_player_position(&data->map_data) == -1)
		return (-1);
	data->map_data.player.x = data->map_data.square.x + 0.5;
	data->map_data.player.y = data->map_data.square.y + 0.5;
	return (0);
}
