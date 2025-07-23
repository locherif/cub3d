NAME       = cub3D
CC         = gcc

CFLAGS     = -Wall -Wextra -Werror -I./includes

MLX_FLAGS  = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS       = \
cub3d.c \
utils/get_next_line.c \
utils/get_next_line_utils.c \
utils/ft_split.c \
utils/ft_atoi.c \
utils/utils_functions.c \
utils/parsing_utils.c \
utils/paarsing_utils_2nd.c \
parsing/check_map.c \
parsing/check_config.c \
parsing/check_directions.c \
parsing/check_textures.c \
parsing/check_floor_and_ceeleing.c \
parsing/check_game_map.c 

OBJS       = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
