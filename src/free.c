/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:45:25 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/24 15:20:35 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_t_map(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->map_data.textures.north)
		free(data->map_data.textures.north);
	if (data->map_data.textures.south)
		free(data->map_data.textures.south);
	if (data->map_data.textures.east)
		free(data->map_data.textures.east);
	if (data->map_data.textures.west)
		free(data->map_data.textures.west);
	if (data->map_data.map)
	{
		i = -1;
		while (data->map_data.map && data->map_data.map[++i])
			free(data->map_data.map[i]);
		free(data->map_data.map);
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_t_map(data);
}

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->map_data.textures.images[i].img)
		{
			mlx_destroy_image(data->window.mlx,
				data->map_data.textures.images[i].img);
			data->map_data.textures.images[i].img = NULL;
			data->map_data.textures.images[i].addr = NULL;
		}
		i++;
	}
}

void	free_mlx(t_data *data)
{
	free_textures(data);
	if (data->window.img.img)
	{
		mlx_destroy_image(data->window.mlx, data->window.img.img);
		data->window.img.img = NULL;
	}
	if (data->window.minimap_img.img)
	{
		mlx_destroy_image(data->window.mlx, data->window.minimap_img.img);
		data->window.minimap_img.img = NULL;
	}
	if (data->window.window)
	{
		mlx_destroy_window(data->window.mlx, data->window.window);
		data->window.window = NULL;
	}
	if (data->window.mlx)
	{
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
		data->window.mlx = NULL;
	}
}
