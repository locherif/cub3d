#include "cube.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int	stringlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	get_map_in_file(int len, char **file, char *map)
{
	int		fd;
	char	*str;
	int		i;
	char	*new_line;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		str = get_next_line(fd);
		new_line = ft_strchr(str, '\n');
		if (new_line)
			*new_line = '\0';
		file[i] = str;
		i++;
	}
}

int	parsing(char *file_name)
{
	int		len;
	char	**map;

	len = find_map_len(file_name);
	// printf("stop%d\n", len);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (0);
	map[len] = 0;
	get_map_in_file(len, map, file_name);
	check_config(map);
	// print_tab(map);
	free_tab(map);
	return (1);
}
