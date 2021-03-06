/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:21:56 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 16:54:55 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	work_mlx(t_all *all, char *array)
{
	player_position(all);
	printf ("pl x = %d\npl y = %d\n", all->plps.x, all->plps.y);
	count_coins(all, array);
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, all->map.width * ELEM_SIZE,
			all->map.height * ELEM_SIZE, "./so_long");
	relate_path(all);
	printf ("after relate path all good\n");
	drawing_map(all);
	draw_player(all);
	mlx_hook(all->mlx_win, 2, 1L << 0, key_pressed, all);
	mlx_hook(all->mlx_win, 3, 1L << 1, key_released, all);
	mlx_hook(all->mlx_win, 17, 1L << 2, esc, all);
	mlx_loop(all->mlx);
}

static void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
}

static void	init_keys(t_keys *keys)
{
	keys->count_moves = 0;
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
}

static void	directory_check(char **argv)
{
	int	fd;

	fd = open(*argv, O_DIRECTORY);
	if (fd != -1)
		invalid_input();
	else
		return ;
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*array;
	t_all	all;

	if (argc == 2)
	{
		init_map(&all.map);
		init_keys(&all.key);
		directory_check(&argv[1]);
		check_file_name(argv[1]);
		fd = check_fd(argv[1]);
		array = filling_array(fd);
		close (fd);
		all.array = array;
		all.arr = check_valid(array);
		if (!check_lines(array) || all.arr == NULL
			|| !init_height_width(&all))
			invalid_map();
		else
			work_mlx(&all, array);
	}
	else
		invalid_input();
	return (0);
}
