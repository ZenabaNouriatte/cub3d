SRC = ft_printf.c ft_handle_conversions.c ft_modded_putchar.c ft_modded_putnbr.c ft_modded_putstr.c ft_print_hex_memory.c ft_print_int_to_hexa.c ft_strlen.c ft_unsigned_putnbr.c
OBJ =  $(SRC:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
HEADERS = ft_printf.h
NAME = libftprintf.a

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(HEADERS)

$(OBJ): $(SRC) 
	cc -c $(FLAGS) $(SRC)

clean: 
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
