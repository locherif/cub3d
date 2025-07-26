#include "cube.h"

int	main(int ac, char **av)
{
	if (!parsing(av[1]))
		return (ac);
}

// oublie pas sur la map tt les 4 espaces sont convertis en 1 seul tab
// ca peut faire bugger la fonction qui recherche les 2emme map
