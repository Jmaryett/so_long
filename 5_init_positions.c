#include "so_long.h"

void	player_position(char *array, t_plps *plps)
{
	int	i;
	int	width;
	int	height;

	i = -1;
	width = 0;
	height = 0;
	while (array[++i])
	{
		if (array[i] == '\n' || array[i] == '\0')
		{
			width = 0;
			height++;
		}
		if (array[i] == 'P')
		{
			plps->x = width;
			plps->y = height;
			array[i] = '0';
		}
		width++;
	}
	printf ("%d\n%d\n", plps->x, plps->y);
}