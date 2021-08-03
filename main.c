#include "so_long.h"
//#include <math.h>

static void	work_mlx(t_map *map)
{
	t_all	all;

	all.mlx = mlx_init();
	all.img.img = mlx_new_image(all.mlx, map->width * 100, map->height * 100);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel, &all.img.line_len, &all.img.endian);
	all.mlx_win = mlx_new_window(all.mlx, map->width * 100, map->height * 100, "so_long");
	pixel_put_loop(&all, map->width * 100, map->height * 100);
	//my_mlx_pixel_put(&all.img, map->width * 100, map->height * 100, 0x00FFFF00); //в цикле пушить цвет
	//mlx_put_image_to_window(all.mlx, all.mlx_win, all.img.img, 0, 0); // в цикле пушить спрайты или цвет потом
	mlx_hook(all.mlx_win, 2, 1L<<0, key_pressed, &all);
	mlx_hook(all.mlx_win, 3, 1L<<1, key_released, &all);
	mlx_hook(all.mlx_win, 17, 1L << 2, esc, &all);
	mlx_loop(all.mlx);
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
	t_map	map;
	t_keys	keys;

	array = NULL;
	if (argc == 2)
	{
		init_map(&map);
		init_keys(&keys);
		fd = open(argv[1], O_RDONLY);
		array = filling_array(fd);
		if (!check_lines(array) || !check_height_width(array, &map)
		|| !check_valid(array))
			invalid_map(array);
		else
			work_mlx(&map);
		/*else
			printf ("%s", "Good map."); */
	}
	else
		printf ("%s\n", "Invalid input.");
	return (0);
}