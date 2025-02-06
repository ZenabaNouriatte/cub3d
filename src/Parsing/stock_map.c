/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:33:24 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/28 19:27:49 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	process_single_line(t_map_context *context,
	char *line, int map_line_status)
{
	size_t	len;

	if (!context->map_started && map_line_status == 1)
		context->map_started = 1;
	if (context->map_started)
	{
		if (map_line_status != 1)
			return (free_line_map(line, context), -1);
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (context->idx < context->line_total_count)
		{
			context->temp_map[context->idx] = ft_strdup(line);
			if (!context->temp_map[context->idx])
				return (free_line_map(line, context), -1);
			context->idx++;
		}
	}
	return (0);
}

static int	process_map_line(char *line, int fd, char **temp_map,
	t_map_context *context)
{
	int	map_line_status;

	if (is_data_line(line))
		return (0);
	map_line_status = is_map_start(line);
	if (map_line_status == -1)
	{
		free_l(line, fd, temp_map, context);
		ft_putstr_fd("Error\nWrong map configuration\n", 2);
		return (-1);
	}
	if (process_single_line(context, line, map_line_status) == -1)
	{
		free_l(line, fd, temp_map, context);
		return (-1);
	}
	return (0);
}

static char	**stock_map_lines(char **temp_map, int fd, int line_count)
{
	t_map_context	context;
	char			*line;

	ft_memset(&context, 0, sizeof(t_map_context));
	context.temp_map = temp_map;
	context.line_total_count = line_count;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (process_map_line(line, fd, temp_map, &context) == -1)
			return (NULL);
		free(line);
	}
	temp_map[context.idx] = NULL;
	return (temp_map);
}

static char	**stock_map(char *map_path, t_data *data, int line_count)
{
	char	**temp_map;
	char	**result;

	data->map_data.map_fd = open(map_path, O_RDONLY);
	temp_map = malloc(sizeof(char *) * (line_count + 1));
	if (!temp_map)
		return (NULL);
	result = stock_map_lines(temp_map, data->map_data.map_fd, line_count);
	if (!result)
	{
		free(temp_map);
		return (NULL);
	}
	return (temp_map);
}

int	check_and_store_map(char *map_path, t_data *data)
{
	char			**temp_map;
	t_map_info		map_info;

	data->map_data.map_fd = open(map_path, O_RDONLY);
	if (data->map_data.map_fd == -1)
		return (-1);
	if (analyze_map_data(data->map_data.map_fd, &map_info) == -1)
	{
		finish_reading_file(data->map_data.map_fd);
		return (-1);
	}
	finish_reading_file(data->map_data.map_fd);
	if (map_info.total_lines == 0 || map_info.real_height == 0)
		return (-1);
	temp_map = stock_map(map_path, data, map_info.total_lines);
	if (!temp_map)
		return (-1);
	data->map_data.map = temp_map;
	return (0);
}
