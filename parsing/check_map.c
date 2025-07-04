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

char	*copy_line(char *str)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (stringlen(str) + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, str);
	return (res);
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

int	find_map_len(char *map)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		// printf("%d%s", i, str);
		if (str == NULL)
			break ;
		i++;
		free(str);
	}
	close(fd);
	return (i);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	free_tab(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
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
	map[len] = '\0';
	get_map_in_file(len, map, file_name);
	print_tab(map);
	free_tab(map);
	return (1);
}
