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
char		*ft_strdup(char *s);
size_t		ft_strlen(const char *s);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(char *s, int c);
int			is_space(char c);
int			check_config(char **map);

#endif
