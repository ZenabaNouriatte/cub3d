/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:49:53 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/29 21:47:23 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define ARR_UP 65362
# define ARR_DOWN 65364
# define ARR_LEFT 65361
# define ARR_RIGHT 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img_data;

typedef struct s_window_data
{
	void			*mlx;
	void			*window;
	t_img_data		img;
	int				width;
	int				height;
}					t_window_data;

// parsing
typedef struct s_iposition
{
	int				x;
	int				y;
}					t_iposition;

typedef struct s_dbposition
{
	double			x;
	double			y;
}					t_dbposition;

/* meilleur nom a touver pour cette struct donne des idees genre t_aesthetic,
t_graphics, t_colors je trouve pas un bon nom sinon on garde t_textures enft */
typedef struct s_textures
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int				floor;
	int				ceiling;
}					t_textures;

// parsing
typedef struct s_map
{
	char			**map;
	t_dbposition	player;
	char			initial_vue;
	int				map_fd;
	t_textures		textures;
	t_dbposition	position;
	t_dbposition	direction;
	t_dbposition	plan;
	t_dbposition	ray;
	double			camerax;
	t_iposition		map_grid;
	t_dbposition	side_dist;
	t_dbposition	delta_dist;
	t_iposition		step;
	bool			hit;
	int				side;
	double			wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				x;

}					t_map;

typedef struct s_data
{
	t_map			map;
	t_window_data	window;
}					t_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	CROSS_BTN = 65307
};

int					initialize_mlx_connexion(t_window_data *data);
int					close_window(t_data *data);
void				events_init(t_data *data);
int					close_window_handler(int keycode, t_data *data);
void				set_player_position(t_map *map_data);
void				ft_put_pixel(t_data *data, int x, int y, int color);
// free.c
void				free_tab(char **tab);
void				free_data(t_data *data);

/* PARSING*/

// valid_path
int					check_path(char *map_path, t_data *data);
// valid_info
int					read_map(char *map_path, t_data *data);
// valid_textures
void				texture_info(char *line, t_data *data);
// valid_color
int					color_info(char *line,char **f_line, char **c_line, t_data *data);
// utils
void				err(char *str, t_data *data, int flag_exit);
char				*skip_spaces(char *str);
int					count_commas(char *str);
void				print_map(char **map);
int					trgb(int t, int r, int g, int b);
int					check_line_char(char *line);
void				finish_reading_file(int fd);
// init
int					init_data(t_data *data);
void				init_t_map(t_data *data);

// validate_map

int					is_player(char c);
int					is_walkable(char c);
int					is_wall(char c);
int					trgb(int t, int r, int g, int b);

// THOSE ARE TEST FUNCTIONS
char				**create_map(void);
void				draw_map(t_data *data);
#endif
