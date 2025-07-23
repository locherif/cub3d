#include "cube.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}

int	if_second_word(char *str)
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
		return (printf("ERROR : Missing colorymetry\n"), 0);
	return (i);
}

int	look_first_word(char **str, int pos)
{
	static int	i;
	static int	f;
	static int	c;

	i = 0;
	while (is_space(str[pos][i]))
		i++;
	if (str[pos][i] == 'F' && str[pos][i + 1] == ' ')
	{
		f++;
		if (f >= 2)
			return (printf("ERROR : floor found twice\n"), 0);
		return (1);
	}
	if (str[pos][i] == 'C' && str[pos][i + 1] == ' ')
	{
		c++;
		if (c >= 2)
			return (printf("ERROR : ceeling found twice\n"), 0);
		return (1);
	}
	return (3);
}
