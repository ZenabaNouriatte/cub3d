/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:47:03 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/23 22:03:33 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	top_spaces(t_map *map_data, int *i, int *j)
{
	int	upper_line_len;

	if (*i > 0)
	{
		upper_line_len = ft_strlen(map_data->map[*i - 1]);
		if (*j < upper_line_len
			&& map_data->map[*i - 1][*j] != '1'
			&& map_data->map[*i - 1][*j] != ' ')
			return (-1);
	}
	return (0);
}

int	bottom_spaces(t_map *map_data, int *i, int *j)
{
	int	lower_line_len;

	if (*i < map_data->map_height - 1)
	{
		lower_line_len = ft_strlen(map_data->map[*i + 1]);
		if (*j < lower_line_len
			&& map_data->map[*i + 1][*j] != '1'
			&& map_data->map[*i + 1][*j] != ' ')
			return (-1);
	}
	return (0);
}

int	borders_spaces(t_map *map_data, int *i, int *j, int *line_len)
{
	if (*j > 0 && map_data->map[*i][*j - 1] != '1'
		&& map_data->map[*i][*j - 1] != ' ')
		return (-1);
	if (*j < *line_len - 1
		&& map_data->map[*i][*j + 1] != '1'
		&& map_data->map[*i][*j + 1] != ' ')
		return (-1);
	return (0);
}

int	check_gap_between(char **map, int curr_len, int next_len, int i)
{
	int	j;

	j = 0;
	while (j < curr_len)
	{
		if (j >= next_len && map[i][j] == '0')
			return (-1);
		j++;
	}
	j = 0;
	while (j < next_len)
	{
		if (j >= curr_len && map[i + 1][j] == '0')
			return (-1);
		j++;
	}
	return (0);
}

int	check_wall_gaps(char **map, int height)
{
	int		i;
	int		curr_len;
	int		next_len;

	i = 0;
	while (i < height - 1)
	{
		curr_len = ft_strlen(map[i]);
		next_len = ft_strlen(map[i + 1]);
		if (check_gap_between(map, curr_len, next_len, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
