/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:32:07 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/31 18:00:08 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_start(char *line)
{
	int		i;
	int		has_map_element;

	i = 0;
	has_map_element = 0;
	if (is_data_line(line) == 1)
		return (0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			has_map_element = 1;
		}
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (-1);
		i++;
	}
	if (has_map_element == 1)
		return (has_map_element);
	else
		return (0);
}

int	is_data_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'F' || line[i] == 'C')
		&& (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (1);
	if ((ft_strncmp(line + i, "NO", 2) == 0
			|| ft_strncmp(line + i, "SO", 2) == 0
			|| ft_strncmp(line + i, "EA", 2) == 0
			|| ft_strncmp(line + i, "WE", 2) == 0)
		&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		return (1);
	return (0);
}

int	analyze_map_data(int fd, t_map_info *map_info)
{
	map_info->map_start = -1;
	map_info->real_height = 0;
	map_info->total_lines = 0;
	get_map_line(fd, map_info);
	if (map_info->map_start == -1
		|| map_info->real_height == 0
		|| map_info->total_lines == 0)
	{
		return (ft_putstr_fd("Error\nNo map\n", 2), -1);
	}
	if (map_info->total_lines != map_info->real_height)
		return (ft_putstr_fd("Error\nWrong map configuration\n", 2), -1);
	return (0);
}

int	get_map_line(int fd, t_map_info *map_info)
{
	char		*line;
	int			current_line;
	int			in_map;

	current_line = 0;
	in_map = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_line++;
		if (handle_line_processing(line, current_line, &in_map, map_info))
		{
			free(line);
			continue ;
		}
		if (in_map && is_map_start(line))
			map_info->real_height++;
		if (in_map)
			map_info->total_lines++;
		free(line);
	}
	return (in_map);
}

int	handle_line_processing(char *line, int current_line,
	int *in_map, t_map_info *map_info)
{
	if (!*in_map)
	{
		if (is_data_line(line))
			return (1);
		if (is_map_start(line))
		{
			map_info->map_start = current_line;
			*in_map = 1;
		}
	}
	return (0);
}
