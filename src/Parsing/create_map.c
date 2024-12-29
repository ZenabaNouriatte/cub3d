/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:15:18 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/24 14:15:42 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_height(char *map_path)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		err("Opening file fail",NULL, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	close(fd);
	if (height == 0)
		err("Empty file",NULL, 1);
	return (height);
}

int map_width () // obtenir la chaine la plus longue de la map

void	read_map(char *file_path, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		err("Opening file fail\n");
	data->height = map_height(file_path);
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		error_exit(NULL, data, "Error\nAllocating memory fail \n");
	ft_bzero(data->map, sizeof(char *) * (data->height + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		validate_map_width(line, &data->width, data);
		data->map[i++] = line;
	}
	close(fd);
}

char	**create_map(char **map_path, t_data *data)
{
    map_position(map_path);
    read_map();
    if (validate_map(map_path, &data) == -1)
        return  NULL;
    

}