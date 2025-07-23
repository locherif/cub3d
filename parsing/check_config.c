#include "cube.h"

int	check_if_good_dir(char *line, int i)
{
	static int	N;
	static int	S;
	static int	W;
	static int	E;
	static int	C;

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

int	check_config(char **map)
{
	int start;
	if (!check_directions(map))
		return (0);
	if (!check_textures(map))
		return (0);
	start = check_floor_and_ceeleing(map);
	if (!start)
		return (0);
	if (check_game_map(map, start))
		return (0);
	// ne pas oublier de remplir les espaces par des 1 pour smplifier le ray cating !!!
	return (1);
}