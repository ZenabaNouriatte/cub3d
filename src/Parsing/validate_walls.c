/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:40:32 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/23 22:10:56 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_horizontal_walls(int *row, int *col, t_map *map, int j)
{
	while (map->map[*row][*col] && map->map[*row][*col] != '1')
	{
		if (*col == 0)
			return (0);
		(*col)--;
	}
	*col = j;
	while (map->map[*row][*col] && map->map[*row][*col] != '1')
	{
		if (map->map[*row][*col + 1] == '\0')
			return (0);
		(*col)++;
	}
	*col = j;
	return (1);
}

int	validate_vertical_ceiling(int *row, t_map *map, int *col, int j)
{
	while (map->map[*row][j] != '1')
	{
		if (*row == 0)
			return (0);
		if (!validate_horizontal_walls(row, col, map, j))
			return (0);
		if ((size_t)j > ft_strlen(map->map[*row - 1]))
			return (0);
		(*row)--;
	}
	return (1);
}

int	validate_vertical_floor(int *row, t_map *map, int *col, int j)
{
	while (map->map[*row][j] != '1')
	{
		if (map->map[*row + 1] == NULL)
			return (0);
		if (!validate_horizontal_walls(row, col, map, j))
			return (0);
		if (map->map[*row + 1] && (size_t)j > ft_strlen(map->map[*row + 1]))
			return (0);
		(*row)++;
	}
	return (1);
}

int	validate_cell_closure(int *row, t_map *map, int j, int i)
{
	int	col;

	*row = i;
	col = j;
	if (!validate_vertical_ceiling(row, map, &col, j))
		return (0);
	*row = i;
	if (!validate_vertical_floor(row, map, &col, j))
		return (0);
	*row = i;
	return (1);
}

int	validate_closure(t_data *data)
{
	int		i;
	int		j;
	int		row;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == '0')
			{
				if (!validate_cell_closure(&row, &data->map_data, j, i))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
