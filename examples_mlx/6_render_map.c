#include "so_long.h"

static void	size_of_sprite(t_all *all)
{
	mlx_get_screen_size(all->mlx, &all->screen.sizex, &all->screen.sizey);
	printf("screen width = %d screen height = %d\n", all->screen.sizex, all->screen.sizey);
	all->screen.sizeofsprite_x = all->screen.sizex / all->map.width;
	all->screen.sizeofsprite_y = all->screen.sizey / all->map.height;
	printf ("sprite width = %d, sprite height = %d", all->screen.sizex / all->map.width, all->screen.sizey / all->map.height);
}

/* static void	draw_piece_of_bg(t_all *all int start_height, int start_width)
{
	int	i;
	int	j;

	i = start_width;
	while (i < start_width + all->screen.sizeofsprite_x)
	{
		j = start_height;
		while (j < start_height + all->screen.sizeofsprite_y)
		{
			//mlx_pixel_put(all->mlx, all->mlx_win, i, j, WALL_COLLOR);
			//printf("height - %d width - %d\n", j, i);
			my_mlx_pixel_put(all, i, j, WALL_COLLOR);
			j++;
		}
		i++;
	}
	printf ("All Good");
} */

static void	draw_piece_of_bg(t_all *all)
{
	
}

void	render_map(t_all *all, char *array)
{
	int	i;
	//int	width;
	//int height;

	i = -1;
	/* height = 0;
	width = 0; */
	//printf("width - %d, height - %d\n", all->map.width, all->map.height);
	all->img.img = mlx_new_image(all->mlx, all->map.width, all->map.height);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_len, &all->img.endian);
	size_of_sprite(all);
	while (array[++i])
	{
		/* if (array[i] == '\n' || array[i] == '\0')
		{
			width = 0;
			height++;
		} */
		if (array[i] == '0')
			draw_piece_of_bg(all/* height, width*/);
		//width++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
}
