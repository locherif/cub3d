#include "cube.h"

int	rigth_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (count == 2)
				return (printf("ERROR : Too much players on map\n"), 0);
			if (!is_space(map[i][j]) && map[i][j] != '0' && map[i][j] != '1'
				&& !is_player(map[i][j]))
				return (printf("ERROR : This type of char [%c]is not allowed for a map\n",
						map[i][j]), 0);
			if (is_player(map[i][j]))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	player_found(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (is_player(map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (printf("ERROR : No player has been found\n"), 0);
}

int	find_line(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (is_player(str[i][j]))
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	find_colonne(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (is_player(str[i][j]))
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}