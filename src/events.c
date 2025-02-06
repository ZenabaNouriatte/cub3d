/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:23:21 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/24 15:19:44 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_data *data)
{
	free_mlx(data);
	free_data(data);
	exit(0);
	return (0);
}

int	close_window_handler(int keycode, t_data *data)
{
	if (keycode == CROSS_BTN)
		close_window(data);
	return (0);
}

int	move_player_handler(int keycode, t_data *data)
{
	t_double_Complex	*player;
	t_double_Complex	*dir;
	double				rotspeed;

	rotspeed = 0.04;
	dir = &data->map_data.direction;
	player = &data->map_data.player;
	if (keycode == W_KEY || keycode == ARR_UP)
		move_player_forward_back(&data->map_data, '+', dir, player);
	if (keycode == S_KEY || keycode == ARR_DOWN)
		move_player_forward_back(&data->map_data, '-', dir, player);
	if (keycode == D_KEY)
		move_player_left_right(&data->map_data, keycode, dir, player);
	if (keycode == A_KEY)
		move_player_left_right(&data->map_data, keycode, dir, player);
	if (keycode == ARR_RIGHT)
		rotate_camera(&data->map_data, rotspeed);
	if (keycode == ARR_LEFT)
		rotate_camera(&data->map_data, -rotspeed);
	if (keycode == CROSS_BTN)
		close_window(data);
	start_simulation(data);
	draw_minimap(data);
	return (0);
}

int	rotate_camera_with_mouse(int x, int y, t_data *data)
{
	while ((x < 100 || x > WINDOW_WIDTH - 100) && x < WINDOW_WIDTH - 1 && x > 1
		&& y < WINDOW_HEIGHT - 1 && y > 1)
	{
		usleep(3000);
		mlx_mouse_get_pos(data->window.mlx, data->window.window, &x, &y);
		if (x < 100)
			rotate_camera(&data->map_data, -0.005);
		if (x > WINDOW_WIDTH - 100)
			rotate_camera(&data->map_data, 0.005);
		start_simulation(data);
		draw_minimap(data);
	}
	return (1);
}

void	events_init(t_data *data)
{
	mlx_hook(data->window.window, ON_KEYDOWN, 1L << 0, close_window_handler,
		data);
	mlx_hook(data->window.window, ON_DESTROY, 0L, close_window, data);
	mlx_hook(data->window.window, ON_KEYDOWN, 1L << 0, move_player_handler,
		data);
	mlx_hook(data->window.window, ON_MOUSEMOVE, 1L << 6,
		rotate_camera_with_mouse, data);
}
