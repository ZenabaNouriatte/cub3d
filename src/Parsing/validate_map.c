/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:32:07 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 14:22:18 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int valid_map(t_map *map)
{
    if (map_position(map) == -1) // si il y a une map et check sa position
        return (Error("No map / Bad map position"));
    if (is_empty_line(map->map) == -1)
        return (Error("Empty line on map"));
    if (check_players(map->map) == -1)
        return (Error("Invalid player on map"));
    if (valid_player(map->map) == -1)
        return (Error("Invalid player number"));
    if (valid_wall(map->map) == -1)
        return (Error("Invalid walls"));
    return (0);
}

int valid_info(t_map *map, char **map_path)
{
    return 0;
}

int validate_map(t_map *map, char **map_path)
{
    if (valid_map(&map) == -1 
        || valid_info(&map, map_path) == -1
        || valid_path(map_path) == -1)
    {
        //free les ressources a free
        return (-1);
    }
    return (0);
}