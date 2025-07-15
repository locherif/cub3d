#include "cube.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}