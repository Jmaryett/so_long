#include "so_long.h"
//#include <math.h>

static void	work_mlx(t_all *all, char *array)
{
	player_position(array, &all->plps);
	count_coins(all, array);
	printf("coins = %d\n", all->coin_count);
	printf ("player x = %d\nplayer y = %d\n", all->plps.x, all->plps.y);
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, all->map.width * ELEM_SIZE, all->map.height * ELEM_SIZE, "so_long");
	relate_path(all);
	//printf ("ALL GOOD");
	mlx_hook(all->mlx_win, 2, 1L<<0, key_pressed, all);
	mlx_hook(all->mlx_win, 3, 1L<<1, key_released, all);
	mlx_hook(all->mlx_win, 17, 1L<<2, esc, all);
	mlx_loop_hook(all->mlx, drawing_map, all);
	mlx_loop(all->mlx);
}

static void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
}

static void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*array;
	t_all	all;

	array = NULL;
	if (argc == 2)
	{
		init_map(&all.map);
		init_keys(&all.key);
		fd = open(argv[1], O_RDONLY);
		array = filling_array(fd);
		all.array = array;
		if (!check_lines(array) || !check_height_width(array, &all.map)
		|| !check_valid(array))
			invalid_map(array);
		else
			work_mlx(&all, array);
		/*else
			printf ("%s", "Good map."); */
	}
	else
		printf ("%s\n", "Invalid input.");
	return (0);
}