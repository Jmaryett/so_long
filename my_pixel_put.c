#include "so_long.h"

void	my_mlx_pixel_put(t_all *all, int width, int height, unsigned int color)
{
	char	*dst;

	dst = all->img.addr + (height * all->img.line_len + width * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* void	pixel_put_loop(t_all *all, int width, int height)
{
	int	x;
	int	y;
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			my_mlx_pixel_put(&all->img, x, y, 0x00FFFF00);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
} */