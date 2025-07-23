#include "cube.h"

int	check_coma(int start, char *str)
{
	while (str[start])
	{
		start++;
		if (str[start] == ',')
			return (1);
	}
	return (printf("Error: colorymetry is suposed to be splited by ','\n"), 0);
}

int	rigth_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (printf("ERROR : This type type of chars [%C] is not alowed for colorymetry trt sometning between 0 and 9\n",
					str[i]), 0);
		i++;
	}
	return (1);
}

int	check_nubers_for_colors(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!rigth_char(tab[i]))
			return (0);
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (printf("ERROR : Only numbers between 0 and 255 are accepted for colorymetry[%s] is not ok\n",
					tab[i]), 0);
		i++;
	}
	return (1);
}

int	check_colors(char **map, int i)
{
	int		start;
	char	*str;
	char	**colors;

	start = if_second_word(map[i]);
	if (start == 0)
		return (0);
	if (!check_coma(start, map[i]))
		return (0);
	str = copy_second_word(start, map[i]);
	colors = ft_split(str, ',');
	free(str);
	if (tab_len(colors) != 3)
		return (printf("ERROR :We need exactly 3 numers splited by ',' for colorymetry\n"),
			free_tab(colors), 0);
	if (!check_nubers_for_colors(colors))
		return (free_tab(colors), 0);
	free_tab(colors);
	return (1);
}

int	check_floor_and_ceeleing(char **map)
{
	int	i;
	int	count;
	int	res;

	i = 4;
	count = 0;
	while (map[i])
	{
		if (count == 2)
			return (i);
		while (empty_line(map[i]))
			i++;
		res = look_first_word(map, i);
		if (res == 3)
			return (printf("ERROR :line should start with 'F' || 'C' -> %s\n",
					map[i]), 0);
		if (res == 0)
			return (0);
		if (check_colors(map, i) == 0)
			return (0);
		count++;
		i++;
	}
	return (1);
}
