#include "so_long.h"

void	player_position(char *array, t_plps *plps)
{
	int	i;
	int	len;
	int heig;

	i = 0;
	len = 0;
	heig = 0;
	while (array[i])
	{
		if (array[i] == '\n' || array[i] == '\0')
		{
			len = 0;
			heig++;
		}
		if (array[i] == 'P')
		{
			plps->x = len;
			plps->y = heig + 1;
		}
		len++;
		i++;	
	}
	printf ("%d\n%d\n", plps->x, plps->y);
}
