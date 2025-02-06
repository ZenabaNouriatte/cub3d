# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:18:49 by lasablon          #+#    #+#              #
#    Updated: 2025/02/04 15:11:49 by lasablon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = cub3D

# SRCS FILES 
SRCS =	src/main.c \
		src/events.c \
		src/utils.c \
		src/utils_2.c \
		src/free.c \
		src/minimap.c \
		src/Parsing/read_parse_file.c \
		src/Parsing/valid_path.c \
		src/Parsing/valid_textures.c \
		src/Parsing/valid_color.c \
		src/Parsing/valid_color_utils.c \
		src/Parsing/line_count.c \
		src/Parsing/stock_map.c \
		src/Parsing/stock_map_utils.c \
		src/Parsing/parse_map.c \
		src/Parsing/parsing_utils.c \
		src/Parsing/parsing_utils2.c \
		src/Parsing/validate_walls.c \
		src/Parsing/check_walls.c \
		src/Parsing/check_wall_utils.c \
		src/graphics/raycasting.c \
		src/graphics/raycasting2.c \
		src/graphics/render.c \
		src/graphics/textures.c \
		src/graphics/init.c \
		src/graphics/player_move.c
		

# OBJ FILES 
OBJS := $(SRCS:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror
LIBFT = libft/libft.a

all: MLX $(LIBFT) $(NAME) 

MLX:
	make -C mlx_linux

$(LIBFT):	
	make -C libft

$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C mlx_linux
	make fclean -C libft
	rm mlx_linux/Makefile.gen 
	rm mlx_linux/test/Makefile.gen 
	rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re MLX $(LIBFT)

