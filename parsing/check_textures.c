#include "cube.h"

int	go_to_second_word(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) && str[i] != '\0')
		i++;
	while (!is_space(str[i]) && str[i] != '\0')
		i++;
	while (is_space(str[i]) && str[i] != '\0')
		i++;
	return (i);
}
char	*copy_second_word(int start, char *line)
{
	int		end;
	int		i;
	char	*res;
	int		s;

	end = start;
	i = 0;
	s = start;
	while (!is_space(line[end]) && line[end] != '\0')
		end++;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (i < end - start)
	{
		res[i] = line[s];
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}
int	try_to_open(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] != 'm' || file[i - 1] != 'p' || file[i - 2] != 'x' || file[i
		- 3] != '.')
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (close(fd), 0);
	return (1);
}
int	check_textures(char **map)
{
	int		i;
	int		j;
	char	*str;
	int		count;

	i = 0;
	count = 0;
	while (map[i])
	{
		while (empty_line(map[i]))
			i++;
		if (count == 4)
			return (i);
		j = go_to_second_word(map[i]);
		str = copy_second_word(j, map[i]);
		if (!try_to_open(str))
		{
			free(str);
			return (printf("missing or unopenable textures\n"), 0);
		}
		free(str);
		count++;
		i++;
	}
	return (1);
}
