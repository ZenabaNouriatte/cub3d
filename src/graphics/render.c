/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:34:10 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/23 22:39:02 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_floor_and_ceiling(t_data *data, int draw_start, int draw_end,
		int x)
{
	int	y;

	y = 0;
	while (y < draw_start && y < WINDOW_HEIGHT)
	{
		ft_put_pixel(data, x, y, data->map_data.textures.ceiling);
		y++;
	}
	y = draw_end;
	while (y < WINDOW_HEIGHT)
	{
		ft_put_pixel(data, x, y, data->map_data.textures.floor);
		y++;
	}
}

/*Retrives pixels from the texture to put them in the window*/
void	draw_line(t_data *data, t_map *map, t_img_data *texture, int x)
{
	int				y;
	t_int_Complex	tex;
	double			step;
	double			pos;
	unsigned int	color;

	y = map->draw_start;
	tex.x = (int)(map->wall_x * texture->width);
	if ((map->side == 0 && map->ray.x < 0) || (map->side == 1
			&& map->ray.y > 0))
		tex.x = texture->width - tex.x - 1;
	step = 1.0 * texture->height / map->line_height;
	pos = (map->draw_start - WINDOW_HEIGHT / 2 + map->line_height / 2) * step;
	while (y < map->draw_end && y < WINDOW_HEIGHT)
	{
		tex.y = (int)pos;
		pos += step;
		color = ft_get_pixel(texture, tex.x, tex.y);
		ft_put_pixel(data, x, y, color);
		y++;
	}
	draw_floor_and_ceiling(data, map->draw_start, map->draw_end, x);
}

/*Function that puts black pixels in the window to reset the image
because mlx_clear_window fails*/
void	reset_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_put_pixel(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->window.mlx, data->window.window,
		data->window.img.img, 0, 0);
}
