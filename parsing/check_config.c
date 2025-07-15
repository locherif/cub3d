#include "cube.h"

int	check_if_good_dir(char *line, int i)
{
	static int	N;
	static int	S;
	static int	W;
	static int	E;
	static int	C;

	// printf("%s\n", line);
	if (line[i] == '\0')
		return (1);
	C++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		N++;
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		E++;
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		W++;
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		S++;
	else if (N == 0 && S == 0 && W == 0 && E == 0)
		return (printf("ERROR : No good direction found there %s\n", line), 0);
	if (N >= 2 || S >= 2 || W >= 2 || E >= 2)
		return (printf("ERROR : Same direction found twice : %s\n", line), 0);
	if ((C > N + S + E + W) && (N == 0 || S == 0 || W == 0 || E == 0))
		return (printf("ERROR : something between dir or missing dir\n"), 0);
	return (1);
}

int	check_directions(char **map)
{
	int	i;
	int	j;
	int	res;

	j = 0;
	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && is_space(map[i][j]))
			j++;
		res = check_if_good_dir(map[i], j);
		if (res == 0)
			return (0);
		i++;
	}
	return (res);
}

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
int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
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
			return (1);
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

int	check_config(char **map)
{
	if (!check_directions(map))
		return (0);
	if (!check_textures(map))
		return (0);
	return (1);
}