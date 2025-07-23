#include "cube.h"

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
		if (str == NULL)
			break ;
		i++;
		free(str);
	}
	close(fd);
	return (i);
}

int	tab_len(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

void	print_tab(char **tab)
{
	int i;
	int j;

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