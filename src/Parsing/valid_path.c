/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:41:20 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/12 20:23:47 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_map_path(char *map_path)
{
	int		len;
	int		fd;
	char	buf[1];
	int		ret;

	len = ft_strlen(map_path);
	if (len < 4)
		return (ft_putstr_fd("Error\nFile name too short\n", 2), -1);
	if (ft_strcmp(&map_path[len - 4], ".cub") != 0)
		return (ft_putstr_fd("Error\nWrong file extension\n", 2), -1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open file\n", 2), -1);
	ret = read(fd, buf, 1);
	close(fd);
	if (ret <= 0)
		return (ft_putstr_fd
			("Error\nEmpty file / Name is a directory\n", 2), -1);
	return (0);
}

int	check_texture_path(char *t_path)
{
	int		len;
	int		fd;
	char	buf[1];
	int		ret;

	len = ft_strlen(t_path);
	if (len < 4)
		return (ft_putstr_fd("Error\nTexture File name too short\n", 2), -1);
	if (ft_strcmp(&t_path[len - 4], ".xpm") != 0)
		return (ft_putstr_fd("Error\nWrong texture file extension\n", 2), -1);
	fd = open(t_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open texture file\n", 2), -1);
	ret = read(fd, buf, 1);
	close(fd);
	if (ret <= 0)
		return (ft_putstr_fd
			("Error\nEmpty texture file / Name is a directory\n", 2), -1);
	return (0);
}
