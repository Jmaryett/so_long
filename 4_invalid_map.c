#include "so_long.h"

void	invalid_map(t_all *all, char *array)
{
	printf ("%s\n", "Invalid map.");
	free (all->array);
	free (array);
	return ;
}