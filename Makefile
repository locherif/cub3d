NAME       = cub3D
CC         = gcc

CFLAGS     = -Wall -Wextra -Werror -I./includes

MLX_FLAGS  = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS       = cub3d.c utils/get_next_line.c utils/ft_split.c parsing/check_map.c utils/get_next_line_utils.c
OBJS       = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
