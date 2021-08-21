#include "so_long.h"

static void	xpm_files(t_all *all)
{
	all->pl_img.player = "./shrek.xpm";
	all->floor_img.floor = "./floor.xpm";
	all->exit_img.exit = "./exit.xpm";
	all->coll_img.collec = "./collectible.xpm";
	all->wall_img.wall = "./wall.xpm";
}

static void	xpm_to_img(t_all *all)
{
	all->pl_img.img = mlx_xpm_file_to_image(all->mlx, all->pl_img.player, &all->pl_img.img_width, &all->pl_img.img_height);
	all->floor_img.img = mlx_xpm_file_to_image(all->mlx, all->floor_img.floor, &all->floor_img.img_width, &all->floor_img.img_height);
	all->coll_img.img = mlx_xpm_file_to_image(all->mlx, all->coll_img.collec, &all->coll_img.img_width, &all->coll_img.img_height);
	all->wall_img.img = mlx_xpm_file_to_image(all->mlx, all->wall_img.wall, &all->wall_img.img_width, &all->wall_img.img_height);
	all->exit_img.img = mlx_xpm_file_to_image(all->mlx, all->exit_img.exit, &all->exit_img.img_width, &all->exit_img.img_height);
}

void	relate_path(t_all *all)
{
	xpm_files(all);
	xpm_to_img(all);
}