/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:34:12 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/31 12:28:00 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_double_Complex	calculate_ray_direction(t_double_Complex direction,
		t_double_Complex plane, double camera_x)
{
	t_double_Complex	ray;

	ray.x = direction.x + plane.x * camera_x;
	ray.y = direction.y + plane.y * camera_x;
	return (ray);
}

t_double_Complex	calcul_ray_len_until_next_side(t_double_Complex *ray)
{
	t_double_Complex	delta_dist;

	delta_dist.x = fabs(1.0 / ray->x);
	delta_dist.y = fabs(1.0 / ray->y);
	return (delta_dist);
}

/*calcul de la side dist, distance du player jusqu'a la prochaine case*/
t_double_Complex	calculate_side_dist(t_map *map)
{
	t_double_Complex	side_dist;

	if (map->ray.x < 0)
	{
		map->step.x = -1;
		side_dist.x = (map->player.x - map->square.x) * map->delta_dist.x;
	}
	else
	{
		map->step.x = 1;
		side_dist.x = (map->square.x + 1.0 - map->player.x) * map->delta_dist.x;
	}
	if (map->ray.y < 0)
	{
		map->step.y = -1;
		side_dist.y = (map->player.y - map->square.y) * map->delta_dist.y;
	}
	else
	{
		map->step.y = 1;
		side_dist.y = (map->square.y + 1.0 - map->player.y) * map->delta_dist.y;
	}
	return (side_dist);
}

void	increment_ray(t_map *map)
{
	map->hit = false;
	while (map->hit == false)
	{
		if (map->side_dist.x < map->side_dist.y)
		{
			map->side_dist.x += map->delta_dist.x;
			map->square.x += map->step.x;
			map->side = 0;
		}
		else
		{
			map->side_dist.y += map->delta_dist.y;
			map->square.y += map->step.y;
			map->side = 1;
		}
		if (map->map[map->square.y][map->square.x] == IS_WALL)
		{
			map->hit = true;
			map->hit_orientation = get_wall_orientation(map);
		}
	}
}

void	start_simulation(t_data *data)
{
	t_map	*map;
	int		x;

	map = &data->map_data;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		map->square = init_square_to_player_pos(&data->map_data);
		map->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		map->ray = calculate_ray_direction(map->direction, map->plane,
				map->camera_x);
		map->delta_dist = calcul_ray_len_until_next_side(&map->ray);
		map->side_dist = calculate_side_dist(&data->map_data);
		increment_ray(map);
		map->wall_dist = calculate_wall_distance(map);
		map->wall_x = get_hit_value(map);
		map->line_height = calculate_line_height(map->wall_dist);
		set_line_to_draw(map);
		draw_line(data, &data->map_data,
			&map->textures.images[map->hit_orientation], x);
		x++;
	}
	mlx_put_image_to_window(data->window.mlx, data->window.window,
		data->window.img.img, 0, 0);
}
