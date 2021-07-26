#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*array;
	int 	i;
	int 	j;
	int 	k;

	array = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		array = filling_array(fd);
	}
	if (!check_lines(array) || !check_height_width(array)
	|| !check_valid(array))
	{
		printf ("%s\n", "Invalid map.");
		free (array);
		return (0);
	}
	else
	{
		printf ("%s\n", "Good map.");
		free (array);
		return (0);
	}
	/* i = check_lines(array);
	j = check_height_width(array);
	k = check_valid(array);
	printf ("%s\n%d\n", array, k);
	free (array); */
	return (0);
}