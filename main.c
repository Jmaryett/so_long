#include "so_long.h"

static void	work_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();

}

static void	invalid_map(char *array)
{
	printf ("%s\n", "Invalid map.");
	free (array);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*array;
	t_map	map;

	array = NULL;
	if (argc != 2)
		printf ("%s\n", "Invalid input.");
	else
	{
		fd = open(argv[1], O_RDONLY);
		array = filling_array(fd);
		if (!check_lines(array) || !check_height_width(array)
		|| !check_valid(array))
			invalid_map(array);
		else
			init_map(array);
			// work_mlx();
	}
	return (0);
}