/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:35:26 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/23 22:39:02 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	calculate_line_height(double wallDistance)
{
	return ((int)WINDOW_HEIGHT / wallDistance);
}

double	calculate_wall_distance(t_map *map)
{
	double	wall_distance;

	if (map->side == 0)
		wall_distance = map->side_dist.x - map->delta_dist.x;
	else
		wall_distance = map->side_dist.y - map->delta_dist.y;
	map->side_dist.y = 0;
	map->side_dist.x = 0;
	return (wall_distance);
}

void	set_line_to_draw(t_map *map)
{
	map->draw_start = -map->line_height / 2 + WINDOW_HEIGHT / 2;
	if (map->draw_start < 0 || map->wall_dist == 0.0 || map->line_height < 0)
		map->draw_start = 0;
	map->draw_end = map->line_height / 2 + WINDOW_HEIGHT / 2;
	if (map->draw_end >= WINDOW_HEIGHT || map->wall_dist == 0.0
		|| map->line_height < 0)
		map->draw_end = WINDOW_HEIGHT - 1;
}

double	get_hit_value(t_map *map)
{
	double	wall_x;

	wall_x = 0;
	if (map->side == 0)
		wall_x = map->player.y + map->wall_dist * map->ray.y;
	if (map->side == 1)
		wall_x = map->player.x + map->wall_dist * map->ray.x;
	wall_x -= floor(wall_x);
	return (wall_x);
}
