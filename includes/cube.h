#ifndef CUBE_H
# define CUBE_H
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
}			t_map;

char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
int			parsing(char *file_name);
char		*ft_strdup(char *str);
size_t		ft_strlen(const char *s);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(char *s, int c);
int			is_space(char c);
int			check_config(char **map);
void		free_tab(char **s1);
int			ft_atoi(const char *str);
void		print_tab(char **tab);
char		**copy_and_sizeof_map(char **map, int start);
int			check_game_map(char **map, int start);
int			rigth_player(char **map);
int			is_player(char c);
int			player_found(char **map);
int			find_line(char **str);
int			find_colonne(char **str);
int			empty_line(char *str);
int			find_map_len(char *map);
void		print_tab(char **tab);
int			tab_len(char **tab);
int			check_textures(char **map);
int			check_floor_and_ceeleing(char **map);
char		*copy_second_word(int start, char *line);
int			if_second_word(char *str);
int			look_first_word(char **str, int pos);

#endif