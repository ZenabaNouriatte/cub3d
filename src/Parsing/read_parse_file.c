/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:55:47 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/24 18:33:05 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	search_info(char *line, char **f_line, char **c_line, t_data *data)
{
	if (texture_info(line, data) == -1)
		return (-1);
	if (color_info(line, f_line, c_line) == -1)
		return (-1);
	return (0);
}

static int	valid_info(t_data *data, char *c_line, char *f_line)
{
	if (check_null_texture(data, f_line, c_line) == -1)
		return (-1);
	data->map_data.textures.ceiling = color_nbr(c_line);
	data->map_data.textures.floor = color_nbr(f_line);
	if (data->map_data.textures.ceiling == -1
		|| data->map_data.textures.floor == -1)
		return (-1);
	return (0);
}

static int	read_and_exit(t_data *data, char *line, char *f_line, char *c_line)
{
	if (f_line)
		free(f_line);
	if (c_line)
		free(c_line);
	if (data->map_data.map_fd != 0)
	{
		finish_reading_file(data->map_data.map_fd);
	}
	if (line)
		free(line);
	if (data->map_data.map_fd != -1)
		close(data->map_data.map_fd);
	free_data(data);
	return (-1);
}

static int	get_file_line(int fd, t_data *data, char **f_line, char **c_line)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (search_info(line, f_line, c_line, data) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

int	read_parse_file(char *map_path, t_data *data)
{
	char	*f_line;
	char	*c_line;

	c_line = NULL;
	f_line = NULL;
	if (check_map_path(map_path) == -1)
		return (read_and_exit(data, NULL, f_line, c_line));
	data->map_data.map_fd = open(map_path, O_RDONLY);
	if (data->map_data.map_fd == -1)
		read_and_exit(data, NULL, f_line, c_line);
	if (get_file_line(data->map_data.map_fd, data, &f_line, &c_line) == -1)
		return (read_and_exit(data, NULL, f_line, c_line));
	close(data->map_data.map_fd);
	data->map_data.map_fd = -1;
	if (valid_info(data, f_line, c_line) == -1
		|| check_and_store_map(map_path, data) == -1)
		return (read_and_exit(data, NULL, f_line, c_line));
	free(f_line);
	free(c_line);
	return (0);
}
