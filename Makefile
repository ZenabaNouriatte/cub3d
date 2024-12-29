# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:18:49 by lasablon          #+#    #+#              #
#    Updated: 2024/12/29 22:05:48 by zmogne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = cub3D

# SRCS FILES 
SRCS =	src/main.c \
		src/events.c \
		src/utils.c \
		src/init.c \
		src/free.c \
		src/Parsing/valid_info.c \
		src/Parsing/utils.c \
		src/Parsing/valid_path.c \
		src/Parsing/valid_textures.c \
		src/Parsing/valid_color.c
		

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
	make clean -C libft
	rm mlx_linux/Makefile.gen 
	rm mlx_linux/test/Makefile.gen 
	rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re MLX $(LIBFT)