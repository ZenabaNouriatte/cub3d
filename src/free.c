/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:45:25 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 21:47:32 by zmogne           ###   ########.fr       */
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
	if (data->map.textures.north)
		free(data->map.textures.north);
	if (data->map.textures.south)
		free(data->map.textures.south);
	if (data->map.textures.east)
		free(data->map.textures.east);
	if (data->map.textures.west)
		free(data->map.textures.west);
	if (data->map.map)
	{
		i = -1;
		while (data->map.map[++i])
			free(data->map.map[i]);
		free(data->map.map);
	}
	init_t_map(data);
}

void	free_window(t_data *data)
{
	(void)data;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_t_map(data);
	free_window(data);
	data->window.mlx = NULL;
	data->window.window = NULL;
}
