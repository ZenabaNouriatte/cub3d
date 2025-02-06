/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:49:53 by lasablon          #+#    #+#             */
/*   Updated: 2025/02/04 15:15:09 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <complex.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600
# define MINIMAP_WIDTH 250
# define MINIMAP_HEIGHT 120
# define MIN_PIXEL_SIZE 2
# define MAX_MINIMAP_SIZE 500

typedef struct s_map_context
{
	int					inside_map;
	int					map_end;
	size_t				line_count;
	int					map_started;
	char				**temp_map;
	int					line_total_count;
	int					idx;
}						t_map_context;

typedef struct s_map_info
{
	int					map_start;
	int					real_height;
	int					total_lines;
}						t_map_info;

typedef struct s_img_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;

}						t_img_data;

typedef struct s_window_data
{
	void				*mlx;
	void				*window;
	t_img_data			img;
	t_img_data			minimap_img;
	int					width;
	int					height;
}						t_window_data;

typedef struct s_int_Complex
{
	int					x;
	int					y;
}						t_int_Complex;

typedef struct s_double_Complex
{
	double				x;
	double				y;
}						t_double_Complex;

typedef struct s_textures
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	int					floor;
	int					ceiling;
	t_img_data			images[4];
}						t_textures;

typedef struct s_map
{
	char				**map;
	char				initial_vue;
	int					map_fd;
	t_textures			textures;
	t_double_Complex	player;
	t_double_Complex	direction;
	t_double_Complex	plane;
	t_double_Complex	ray;
	double				camera_x;
	t_int_Complex		square;
	t_double_Complex	side_dist;
	t_double_Complex	delta_dist;
	t_int_Complex		step;
	bool				hit;
	int					side;
	double				wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					x;
	int					map_height;
	int					map_width;
	int					hit_orientation;
	double				wall_x;
}						t_map;

typedef struct s_data
{
	t_map				map_data;
	t_window_data		window;
}						t_data;

enum					e_coordinates
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

enum
{
	IS_EMPTY = 48,
	IS_WALL = 49,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	CROSS_BTN = 65307,
	ARR_UP = 65362,
	ARR_DOWN = 65364,
	ARR_LEFT = 65361,
	ARR_RIGHT = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

int						initialize_mlx_connexion(t_data *data);
int						close_window(t_data *data);
void					events_init(t_data *data);
int						close_window_handler(int keycode, t_data *data);
int						set_player_position(t_map *map_data);
void					ft_put_pixel(t_data *data, int x, int y, int color);
// free.c
void					free_tab(char **tab);
void					free_data(t_data *data);
void					free_mlx(t_data *data);

/* PARSING*/

// valid_path
int						check_map_path(char *map_path);
int						check_texture_path(char *map_path);
// valid_info
int						read_parse_file(char *map_path, t_data *data);
// valid_textures
int						texture_info(char *line, t_data *data);
int						check_null_texture(t_data *data, char *f_line,
							char *c_line);
// valid_color
int						color_info(char *line, char **f_line, char **c_line);
int						color_nbr(char *line);
int						is_color_line(const char *line, char color);
int						is_only_spaces(const char *str);
int						check_commas_and_spacing(const char *line);
int						count_tab(char **tab);

// utils
char					*skip_spaces(char *str);
int						count_commas(char *str);
int						trgb(int t, int r, int g, int b);
int						check_line_char(char *line);
void					finish_reading_file(int fd);
char					*trim_spaces(char *str);
char					**trim_tab_space(char **temp_tab);
unsigned int			ft_get_pixel(t_img_data *image, int x, int y);
int						max_width(char **map);
int						is_map_start(char *line);
int						is_data_line(char *line);
int						map_height(char **map);
char					**replace_by_one(char **map, t_data *data);
int						trgb(int t, int r, int g, int b);
void					ft_put_pixel(t_data *data, int x, int y, int color);

// stock_map
int						check_and_store_map(char *map_path, t_data *data);
void					write_and_free(char *str, char *to_free);
int						get_map_line(int fd, t_map_info *map_info);
int						handle_line_processing(char *line, int current_line,
							int *in_map, t_map_info *map_info);
void					free_l(char *line, int fd, char **temp_map,
							t_map_context *context);
int						analyze_map_data(int fd, t_map_info *map_info);
void					free_line_map(char *line, t_map_context *context);
void					free_context_map(t_map_context *context);

// parse_map
int						parse_map(t_data *data);
int						check_map_border(t_map *map_data);
int						top_spaces(t_map *map_data, int *i, int *j);
int						bottom_spaces(t_map *map_data, int *i, int *j);
int						borders_spaces(t_map *map_data, int *i, int *j,
							int *line_len);
int						check_walls(char **map, int height, int width);
int						is_player(char c);
int						is_walkable(char c);
int						trgb(int t, int r, int g, int b);
int						validate_cell_closure(int *row, t_map *map, int j,
							int i);
int						check_side_walls(char **map, int height);
int						validate_closure(t_data *data);
int						check_wall_gaps(char **map, int height);

// minimap
int						initialize_minimap(t_window_data *data,
							t_map *map_data);
int						calculate_pixel_size(t_map *map_data);
void					draw_minimap(t_data *data);

// Raycasting
t_double_Complex		set_initial_direction(char initial_vue);
t_double_Complex		set_plane_vector(char initial_vue);
void					init_simulation(t_map *map);
t_int_Complex			init_square_to_player_pos(t_map *map);
void					start_simulation(t_data *data);
t_double_Complex		calculate_ray_direction(t_double_Complex direction,
							t_double_Complex plane, double camera_x);
t_double_Complex		calcul_ray_len_until_next_side(t_double_Complex *ray);
t_double_Complex		calculate_side_dist(t_map *map);
void					increment_ray(t_map *map);
double					calculate_wall_distance(t_map *map);
int						calculate_line_height(double wallDistance);
void					draw_line(t_data *data, t_map *map, t_img_data *image,
							int x);
void					set_line_to_draw(t_map *map);
void					reset_image(t_data *data);
double					get_hit_value(t_map *map);
// Textures
int						get_textures(t_data *data, t_textures *textures);
int						set_texture_address(t_textures *textures);
int						get_wall_orientation(t_map *map);
// PLAYERS MOVEMENT
void					move_player_forward_back(t_map *map_data, char operator,
							t_double_Complex *dir, t_double_Complex *player);
void					move_player_left_right(t_map *map_data, int keycode,
							t_double_Complex *dir, t_double_Complex *player);
void					rotate_camera(t_map *map, double rotspeed);
double					new_position(double pos, double dir, char operator);
#endif
