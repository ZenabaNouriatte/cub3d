/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:47:51 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/30 12:49:07 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	txt_error(const char *prefix)
{
	ft_putstr_fd("Error\nMore than one ", 2);
	ft_putstr_fd((char *)prefix, 2);
	ft_putstr_fd(" value\n", 2);
}

int	check_texture(char *line, const char *prefix, char **texture)
{
	int		len;
	char	*temp;
	int		p_len;

	p_len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, p_len) == 0
		&& (line[p_len] == ' ' || line[p_len] == '\t'))
	{
		if (*texture != NULL)
			return (txt_error(prefix), -1);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		temp = ft_substr((const char *)line, 3, len - 3);
		if (!temp)
			return (-1);
		*texture = trim_spaces(temp);
		free(temp);
		if (!*texture)
			return (ft_putstr_fd
				("Error\nFailed to extract texture path\n", 2), -1);
		if (check_texture_path(*texture) == -1)
			return (-1);
	}
	return (0);
}

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int	texture_info(char *line, t_data *data)
{
	line = skip_spaces(line);
	if (!line)
		return (-1);
	if (check_texture(line, "NO", &data->map_data.textures.north) == -1)
		return (-1);
	if (check_texture(line, "SO", &data->map_data.textures.south) == -1)
		return (-1);
	if (check_texture(line, "WE", &data->map_data.textures.west) == -1)
		return (-1);
	if (check_texture(line, "EA", &data->map_data.textures.east) == -1)
		return (-1);
	return (0);
}

int	check_null_texture(t_data *data, char *f_line, char *c_line)
{
	if (data->map_data.textures.west == NULL)
		return (ft_putstr_fd("No WEST texture\n", 2), -1);
	if (data->map_data.textures.north == NULL)
		return (ft_putstr_fd("No NORTH texture\n", 2), -1);
	if (data->map_data.textures.east == NULL)
		return (ft_putstr_fd("No EAST texture\n", 2), -1);
	if (data->map_data.textures.south == NULL)
		return (ft_putstr_fd("No SOUTH texture\n", 2), -1);
	if (f_line == NULL)
		return (ft_putstr_fd("No Floor color\n", 2), -1);
	if (c_line == NULL)
		return (ft_putstr_fd("No Ceiling color\n", 2), -1);
	return (0);
}
