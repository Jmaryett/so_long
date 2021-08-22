#include "so_long.h"

void	draw_wall(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->wall_img.img, width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_floor(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->floor_img.img, width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_collect(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->coll_img.img, width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_exit(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->exit_img.img, width * ELEM_SIZE, height * ELEM_SIZE);
}

int	drawing_map(t_all *all)
{
	int	i;
	int	width;
	int	height;

	i = -1;
	width = 0;
	height = 0;
	while(all->array[++i])
	{
		if (all->array[i] == '\n' || all->array[i] == '\0')
		{
			height++;
			width = 0;
			continue ;
		}
		if (all->array[i] == '1')
			draw_wall(all, height, width);
		else if (all->array[i] == '0')
			draw_floor(all, height, width);
		else if (all->array[i] == 'C')
			draw_collect(all, height, width);
		else if (all->array[i] == 'E')
			draw_exit(all, height, width);
		width++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->pl_img.img, all->plps.x * ELEM_SIZE, all->plps.y * ELEM_SIZE);
	mlx_do_sync(all->mlx);
	return (0);
}