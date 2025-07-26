#include "cube.h"

char	**get_true_map(char **old_map, int start, int end)
{
	char	**true_map;
	int		i;

	if (end < start + 2)
		return (printf("ERROR : Map should be at least 3 lines\n"), NULL);
	true_map = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (!true_map)
		return (NULL);
	i = 0;
	while (old_map[start] && start < end)
	{
		if (old_map[start])
			true_map[i] = ft_strdup(old_map[start]);
		else
			true_map[i] = NULL;
		start++;
		i++;
	}
	true_map[i] = NULL;
	return (true_map);
}

char	**copy_and_sizeof_map(char **map, int start)
{
	int	end;
	int	i;

	while (empty_line(map[start]))
		start++;
	end = start;
	while (map[end] && !empty_line(map[end]))
		end++;
	if (!map[end])
		return (get_true_map(map, start, end));
	i = end + 1;
	while (map[i])
	{
		if (map[i] && !empty_line(map[i++]))
			return (printf("ERROR : Nothing should be after or before map\n"),
				NULL);
	}
	return (get_true_map(map, start, end));
	return (NULL);
}

int	is_closed(char **str, int ligne, int colonne, int *i)
{
	if ((*i) == 1)
		return (0);
	if (str[ligne][colonne] == '1' || str[ligne][colonne] == 'V')
		return (1);
	if (is_space(str[ligne][colonne]) || str[ligne][colonne] == '\0')
	{
		(*i) = 1;
		printf("ERROR : The Map is suposed to be closed and without spaces in\n");
		return (0);
	}
	str[ligne][colonne] = 'V';
	is_closed(str, ligne - 1, colonne, i);
	is_closed(str, ligne + 1, colonne, i);
	is_closed(str, ligne, colonne - 1, i);
	is_closed(str, ligne, colonne + 1, i);
	return (1);
}

int	longuest_first_word(char **map)
{
	int	i;
	int	j;
	int	last;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (map[i])
	{
		while (map[i][j] && is_space(map[i][j]))
			j++;
		while (map[i][j] && !is_space(map[i][j]))
			j++;
		last = j - 1;
		if (last > res)
			res = last;
		j = 0;
		i++;
	}
	return (res);
}

int	pos_of_second_word(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]) && str[i] != '\0')
		i++;
	while (!is_space(str[i]) && str[i] != '\0')
		i++;
	while (is_space(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}
int	start_of_first_word(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

int	end_of_first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i] && !is_space(str[i]))
		i++;
	i--;
	return (i);
}

int	rigt_holes(char **map)
{
	int	i;
	int	end;
	int	start;

	i = 0;
	start = start_of_first_word(map[0]);
	end = end_of_first_word(map[1]);
	if (start > end)
		return (printf("ERROR : This is not supposed to be here ->%s", map[i]),
			0);
	end = end_of_first_word(map[i]);
	i++;
	while (map[i])
	{
		if (map[i])
			start = start_of_first_word(map[i]);
		if (start > end)
			return (printf("ERROR : This is not supposed to be here ->%s",
					map[i]), 0);
		if (map[i])
			end = end_of_first_word(map[i]);
		i++;
	}
	return (1);
}

int	something_found(char **map)
{
	int	i;
	int	pos;
	int	longuest;

	i = 0;
	if (!rigt_holes(map))
		return (0);
	longuest = longuest_first_word(map);
	while (map[i])
	{
		pos = pos_of_second_word(map[i]);
		if (pos > longuest)
			return (printf("ERROR: We allow only one map -> %s\n", map[i]), 0);
		i++;
	}
	return (1);
}

void	map_filling(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (is_space(map[i][j]))
				map[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
	}
	print_tab(map);
}

int	check_game_map(char **map, int start)
{
	char	**true_map;
	int		ligne;
	int		colonne;
	int		i;

	true_map = copy_and_sizeof_map(map, start);
	if (true_map == NULL)
		return (0);
	if (!rigth_player(true_map))
		return (free_tab(true_map), 0);
	if (!player_found(true_map))
		return (free_tab(true_map), 0);
	ligne = find_line(true_map);
	colonne = find_colonne(true_map);
	i = 0;
	if (is_closed(true_map, ligne, colonne, &i) == 0)
		return (free_tab(true_map), 0);
	if (!something_found(true_map))
		return (free_tab(true_map), 0);
	map_filling(true_map);
	free_tab(true_map);
	return (1);
}
