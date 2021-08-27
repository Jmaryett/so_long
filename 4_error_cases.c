#include "so_long.h"

void	invalid_map(char *array)
{
	printf ("%s\n", "Invalid map.");
	free (array);
	exit (0);
}

void	invalid_file(void)
{
	printf ("%s\n", "Can't open file.");
	exit (0);
}

void	invalid_input(void)
{
	printf ("%s\n", "Invalid input.");
	exit (0);
}
