/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:05:31 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/24 18:58:21 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	max_width(char **map)
{
	int		max_width;
	int		current_width;
	int		i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

static void	shorter_len(int len, t_data *data, char **map, int *i)
{
	char	*new_line;

	if (len != data->map_data.map_width)
	{
		new_line = malloc(sizeof(char) * (data->map_data.map_width + 1));
		if (!new_line)
		{
			ft_putstr_fd("Error\nMemory allocation failed\n", 2);
			return ;
		}
		ft_memcpy(new_line, map[*i], len);
		while (len < data->map_data.map_width)
			new_line[len++] = '1';
		new_line[len] = '\0';
		free(map[*i]);
		map[*i] = new_line;
	}
}

char	**replace_by_one(char **map, t_data *data)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		shorter_len(len, data, map, &i);
		i++;
	}
	return (map);
}
