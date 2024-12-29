NAME = libft.a

GNL_DIR = get_next_line/
PRINTF_DIR = ft_printf/

GNL_SRC =	get_next_line.c \
			get_next_line_utils.c
PRINTF_SRC =	ft_printf.c \
				ft_handle_conversions.c \
				ft_modded_putchar.c \
				ft_modded_putnbr.c \
				ft_modded_putstr.c \
				ft_print_hex_memory.c \
				ft_print_int_to_hexa.c \
				ft_unsigned_putnbr.c

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

SRCS = $(SRC) $(addprefix get_next_line/, $(GNL_SRC))  $(addprefix ft_printf/, $(PRINTF_SRC))

GNL_OBJ = $(GNL_SRC:%.c=%.o)
PRINTF_OBJ = $(PRINTF_SRC:%.c=%.o)

OBJ = $(SRC:%.c=%.o)

OBJS = $(GNL_OBJ) $(OBJ) $(PRINTF_OBJ)
FLAGS = -Wall -Wextra -Werror
HEADERS = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) $(HEADERS)

$(OBJS): $(SRCS) 
	cc -c $(FLAGS) $^

clean: 
	rm -rf $(OBJS) 

fclean:	clean
	rm -rf $(NAME)

re: fclean all
