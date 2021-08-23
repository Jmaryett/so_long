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