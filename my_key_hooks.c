#include "so_long.h"

int	esc(t_all *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	exit (0);
	return (0);
}

int	key_pressed(int keycode, t_all *all)
{
	if (keycode == 53)
		esc(all);
	if (keycode == 13)
	{
		all->key.w = 1;
		all->map.height -= 10;
	}
	else if (keycode == 0)
	{
		all->key.a = 1;
		all->map.width -= 10;
	}
	else if (keycode == 1)
	{
		all->key.s = 1;
		all->map.height += 10;
	}
	else if (keycode == 2)
	{
		all->key.d = 1;
		all->map.width += 10;
	}
	return (0);
	//printf ("%d\n", keycode);
}

int	key_released(int keycode, t_all *all)
{
	if (keycode == 13)
		all->key.w = 0;
	else if (keycode == 0)
		all->key.a = 0;
	else if (keycode == 1)
		all->key.s = 0;
	else if (keycode == 2)
		all->key.d = 0;
	return (0);
}
