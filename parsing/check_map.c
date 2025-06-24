#include "cube.h"

char	**get_map_in_file(char *file_name)
{
	int		i;
	int		fd;
	char	*str;

	// char	**map;
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1 && str)
	{
		// printf("c la\n");
		str = get_next_line(fd);
		if (str != NULL)
			printf("%s", str);
		free(str);
		// printf("\n\n\n%d\n\n\n\n", i);
		i++;
	}
	// printf("rrrrrrrrrrr");
	return (NULL);
}

int	parsing(char *file_name)
{
	char	**map;

	map = get_map_in_file(file_name);
	map = map;
	return (1);
}
