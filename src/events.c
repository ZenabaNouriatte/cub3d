/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:23:21 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/29 17:45:30 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_data *data)
{
	if (data->window.mlx)
	{
		free_tab(data->map.map);
		if (data->window.window)
			mlx_destroy_window(data->window.mlx, data->window.window);
		if (data->window.img.img)
			mlx_destroy_image(data->window.mlx, data->window.img.img);
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
	}
	exit(0);
	return (0);
}

int	close_window_handler(int keycode, t_data *data)
{
	if (keycode == CROSS_BTN)
		close_window(data);
	return (0);
}

void	update_number(t_data *data, int new_position, t_iposition *player,
		char axis)
{
	data->map.map[player->y][player->x] = '0';
	if (axis == 'x')
		data->map.player.x = new_position;
	if (axis == 'y')
		data->map.player.y = new_position;
	data->map.map[player->y][player->x] = 'N';
}

int	move_player_handler(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	// t_position	*player;

	// player = &data->map.player;
	// if (keycode == ARR_LEFT || keycode == A_KEY)
	// 	// fleche gauche doit faire tourner la camera a gauche
	// {
	// 	if (is_walkable(data->map.map[player->y][player->x - 1]))
	// 		update_number(data, player->x - 1, player, 'x');
	// }
	// if (keycode == ARR_RIGHT || keycode == D_KEY)
	// 	// fleche droite doit faire tourner la camera a droite
	// {
	// 	if (is_walkable(data->map.map[player->y][player->x + 1]))
	// 		update_number(data, player->x + 1, player, 'x');
	// }
	// if (keycode == ARR_UP || keycode == W_KEY)
	// {
	// 	if (is_walkable(data->map.map[player->y - 1][player->x]))
	// 		update_number(data, player->y - 1, player, 'y');
	// }
	// if (keycode == ARR_DOWN || keycode == S_KEY)
	// {
	// 	if (is_walkable(data->map.map[player->y + 1][player->x]))
	// 		update_number(data, player->y + 1, player, 'y');
	// }
	// if (keycode == CROSS_BTN)
	// 	close_window(data);
	// mlx_clear_window(data->window.mlx, data->window.window);
	// // printf("x = %d, y = %d\n", player->x, player->y);
	// draw_map(data);
	return (0);
}
void	events_init(t_data *data)
{
	mlx_hook(data->window.window, ON_KEYDOWN, 1L << 0, close_window_handler,
		data);
	mlx_hook(data->window.window, ON_DESTROY, 0L, close_window, data);
	// mlx_hook(data->window.window, ON_KEYDOWN, (1L << 0), move_player_handler,
	// 	data);
}
