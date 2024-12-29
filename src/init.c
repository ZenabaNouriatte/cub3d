/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:44:39 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 21:47:27 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_t_map(t_data *data)
{
    data->map.map = NULL;
    data->map.map_fd = -1;
    data->map.player.x = -1;
    data->map.player.y = -1;
    data->map.initial_vue = '\0';
    data->map.textures.north = NULL;
    data->map.textures.south = NULL;
    data->map.textures.east = NULL;
    data->map.textures.west = NULL;
    data->map.textures.floor = -1;
    data->map.textures.ceiling = -1;
    data->map.position.x = -1;
    data->map.position.y = -1;
    data->map.initial_vue = '\0';
}

static void init_window(t_data *data)
{
    data->window.mlx = NULL;
    data->window.window = NULL;
    data->window.img.img = NULL;
    data->window.img.addr = NULL;
    data->window.img.bits_per_pixel = 0;
    data->window.img.line_length = 0;
    data->window.img.endian = 0;
    data->window.width = 0;
    data->window.height = 0;

}

int init_data(t_data *data)
{
    if (!data)
    {
        err("Invalid data pointer",NULL, 0);
        return (-1);
    }
    init_t_map(data);
    init_window(data);
    return (0);
}
