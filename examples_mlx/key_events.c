//#include "../so_long.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_events
{
	void	*mlx;
	void	*win;
}				t_events;

int	esc(int keycode, t_events *events)
{
	if (keycode == 53)
	{
		mlx_destroy_window(events->mlx, events->win);
		exit (0);
	}
	else
		printf ("Dunno\n");
	//else
	//	printf("%d\n", keycode);
	return (0);
}

int main()
{
	t_events	events;

	events.mlx = mlx_init();
	events.win = mlx_new_window(events.mlx, 640, 480, "bitch");
	mlx_hook(events.win, 12, 1L<<15, esc, &events);
	//mlx_hook(events.win)
	mlx_loop(events.mlx);
	return (0);
}