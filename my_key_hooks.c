#include "so_long.h"

int	esc(t_all *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	exit (0);
	return (0);
}

static void	check_positions(t_all *all, char key)
{
	int	i;
	
	i = all->map.width + 1;
	printf ("player x = %d\nplayer y = %d\n", all->plps.x, all->plps.y);
	if (key == 'w')
	{
		check_w(all, i);
		/* if (all->array[i * (all->plps.y - 1) + all->plps.x] != '1')
			all->plps.y -= 1;
		else
			all->plps.y = all->plps.y; */
	}
	else if (key == 'a')
	{
		check_a(all, i);
		/* if (all->array[i *all->plps.y + all->plps.x - 1] != '1')
			all->plps.x -= 1;
		else
			all->plps.x = all->plps.x; */
	}
	else if (key == 's')
	{
		check_s(all, i);
		/* if (all->array[i * (all->plps.y + 1) + all->plps.x] != '1')
			all->plps.y += 1;
		else
			all->plps.y = all->plps.y; */
	}
	else if (key == 'd')
	{
		check_d(all, i);
		/* if (all->array[i * all->plps.y + all->plps.x + 1] != '1')
			all->plps.x += 1;
		else
			all->plps.x = all->plps.x; */
	}
}

int	key_pressed(int keycode, t_all *all)
{
	if (keycode == 53)
		esc(all);
	else if (keycode == 13)
	{
		all->key.w = 1;
		check_positions(all, 'w');
	}
	else if (keycode == 0)
	{
		all->key.a = 1;
		check_positions(all, 'a');
	}
	else if (keycode == 1)
	{	
		all->key.s = 1;
		check_positions(all, 's');
	}
	else if (keycode == 2)
	{	
		all->key.d = 1;
		check_positions(all, 'd');
	}
	return (0);
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
