/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:05:27 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/22 18:18:16 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_forward_back(t_map *map_data, char operator,
		t_double_Complex *dir, t_double_Complex *player)
{
	t_int_Complex	square;
	int				new_x;
	int				new_y;

	new_x = (int)new_position(player->x, dir->x, operator);
	new_y = (int)new_position(player->y, dir->y, operator);
	square = init_square_to_player_pos(map_data);
	map_data->map[(int)player->y][(int)player->x] = IS_EMPTY;
	if (is_walkable(map_data->map[new_y][square.x])
		&& is_walkable(map_data->map[square.y][new_x]))
	{
		player->y = new_position(player->y, dir->y, operator);
		player->x = new_position(player->x, dir->x, operator);
	}
	map_data->map[(int)player->y][(int)player->x] = map_data->initial_vue;
}

void	move_player_left_right(t_map *map_data, int keycode,
		t_double_Complex *dir, t_double_Complex *player)
{
	t_int_Complex	square;
	double			new_x;
	double			new_y;

	new_y = 0;
	new_x = 0;
	if (keycode == A_KEY)
	{
		new_x = new_position(player->x, dir->y, '+');
		new_y = new_position(player->y, dir->x, '-');
	}
	if (keycode == D_KEY)
	{
		new_x = new_position(player->x, dir->y, '-');
		new_y = new_position(player->y, dir->x, '+');
	}
	square = init_square_to_player_pos(map_data);
	map_data->map[(int)player->y][(int)player->x] = IS_EMPTY;
	if (is_walkable(map_data->map[(int)new_y][square.x])
		&& is_walkable(map_data->map[square.y][(int)new_x]))
	{
		player->y = new_y;
		player->x = new_x;
	}
	map_data->map[(int)player->y][(int)player->x] = map_data->initial_vue;
}

void	rotate_camera(t_map *map, double rotspeed)
{
	t_double_Complex	*dir;
	t_double_Complex	*plane;
	double				old_dirx;
	double				old_plane_x;

	plane = &map->plane;
	old_plane_x = map->plane.x;
	dir = &map->direction;
	old_dirx = dir->x;
	dir->x = dir->x * cos(rotspeed) - dir->y * sin(rotspeed);
	dir->y = old_dirx * sin(rotspeed) + dir->y * cos(rotspeed);
	plane->x = plane->x * cos(rotspeed) - plane->y * sin(rotspeed);
	plane->y = old_plane_x * sin(rotspeed) + plane->y * cos(rotspeed);
}

double	new_position(double pos, double dir, char operator)
{
	double	movespeed;

	movespeed = 0.1;
	if (operator == '+')
		return (pos + dir * movespeed);
	if (operator == '-')
		return (pos - dir * movespeed);
	return (pos);
}

int	is_walkable(char c)
{
	return (c == IS_EMPTY);
}
