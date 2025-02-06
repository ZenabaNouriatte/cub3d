/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:32:25 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/23 12:12:51 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_textures(t_data *data, t_textures *textures)
{
	textures->images[0].img = mlx_xpm_file_to_image(data->window.mlx,
			textures->north, &textures->images[0].width,
			&textures->images[0].height);
	if (!textures->images[0].img)
		return (ft_putstr_fd("Error: cannot open north texture xpm\n", 2), 0);
	textures->images[1].img = mlx_xpm_file_to_image(data->window.mlx,
			textures->south, &textures->images[1].width,
			&textures->images[1].height);
	if (!textures->images[1].img)
		return (ft_putstr_fd("Error: cannot open south texture xpm\n", 2), 0);
	textures->images[2].img = mlx_xpm_file_to_image(data->window.mlx,
			textures->east, &textures->images[2].width,
			&textures->images[2].height);
	if (!textures->images[2].img)
		return (ft_putstr_fd("Error: cannot open east texture xpm\n", 2), 0);
	textures->images[3].img = mlx_xpm_file_to_image(data->window.mlx,
			textures->west, &textures->images[3].width,
			&textures->images[3].height);
	if (!textures->images[3].img)
		return (ft_putstr_fd("Error: cannot open west texture xpm\n", 2), 0);
	if (!set_texture_address(textures))
		return (0);
	return (1);
}

int	set_texture_address(t_textures *textures)
{
	textures->images[0].addr = mlx_get_data_addr(textures->images[0].img,
			&textures->images[0].bits_per_pixel,
			&textures->images[0].line_length, &textures->images[0].endian);
	if (!textures->images[0].addr)
		return (ft_putstr_fd("Error: cannot get north texture adress\n", 2), 0);
	textures->images[1].addr = mlx_get_data_addr(textures->images[1].img,
			&textures->images[1].bits_per_pixel,
			&textures->images[1].line_length, &textures->images[1].endian);
	if (!textures->images[1].addr)
		return (ft_putstr_fd("Error: cannot get south texture adress\n", 2), 0);
	textures->images[2].addr = mlx_get_data_addr(textures->images[2].img,
			&textures->images[2].bits_per_pixel,
			&textures->images[2].line_length, &textures->images[2].endian);
	if (!textures->images[2].addr)
		return (ft_putstr_fd("Error: cannot get east texture adress\n", 2), 0);
	textures->images[3].addr = mlx_get_data_addr(textures->images[3].img,
			&textures->images[3].bits_per_pixel,
			&textures->images[3].line_length, &textures->images[3].endian);
	if (!textures->images[3].addr)
		return (ft_putstr_fd("Error: cannot get west texture adress\n", 2), 0);
	return (1);
}

int	get_wall_orientation(t_map *map)
{
	int	orientation;

	orientation = 0;
	if (map->side == 1 && map->ray.y <= 0)
		orientation = NORTH;
	if (map->side == 1 && map->ray.y > 0)
		orientation = SOUTH;
	if (map->side == 0 && map->ray.x > 0)
		orientation = EAST;
	if (map->side == 0 && map->ray.x <= 0)
		orientation = WEST;
	return (orientation);
}
