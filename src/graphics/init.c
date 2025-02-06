/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:16:44 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/22 18:12:06 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_double_Complex	set_initial_direction(char initial_vue)
{
	t_double_Complex	direction_vector;

	if (initial_vue == 'N')
	{
		direction_vector.x = 0;
		direction_vector.y = -1;
	}
	if (initial_vue == 'S')
	{
		direction_vector.x = 0;
		direction_vector.y = 1;
	}
	if (initial_vue == 'W')
	{
		direction_vector.x = -1;
		direction_vector.y = 0;
	}
	if (initial_vue == 'E')
	{
		direction_vector.x = 1;
		direction_vector.y = 0;
	}
	return (direction_vector);
}

t_double_Complex	set_plane_vector(char initial_vue)
{
	t_double_Complex	plane;

	if (initial_vue == 'N')
	{
		plane.x = 0.66;
		plane.y = 0.0;
	}
	if (initial_vue == 'S')
	{
		plane.x = -0.66;
		plane.y = 0.0;
	}
	if (initial_vue == 'W')
	{
		plane.x = 0.0;
		plane.y = -0.66;
	}
	if (initial_vue == 'E')
	{
		plane.x = 0.0;
		plane.y = 0.66;
	}
	return (plane);
}

t_int_Complex	init_square_to_player_pos(t_map *map)
{
	t_int_Complex	square;

	square.x = (int)map->player.x;
	square.y = (int)map->player.y;
	return (square);
}

void	init_simulation(t_map *map)
{
	map->direction = set_initial_direction(map->initial_vue);
	map->plane = set_plane_vector(map->initial_vue);
}
