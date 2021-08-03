#include "../mlx/mlx.h"

typedef struct loop_hooks
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		increaser;

	unsigned int		color;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		frame_counter;
}				t_hooks;

void init_struct(t_hooks *lh)
{
	lh->color = 0x00000000;
	lh->width = 640;
	lh->height = 480;
}

void	my_mlx_pixel_put(t_hooks *img, int width, int height, unsigned int color)
{
	char	*dst;

	dst = img->addr + (height * img->line_len + width * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int render_next_frame(t_hooks *lh)
{
	int x = 0;
	int y;

	if(lh->frame_counter % 2 == 0)
	{
		lh->color += 2;
		lh->frame_counter = 0;
	}
	if (lh->color > 0x000000FF && lh->increaser < 256)
		lh->increaser *= 100000;
	if (lh->color > 0x00FFFFFF)
		lh->color = 0x00000000;
	while (x < lh->width)
	{
		y = 0;
		while (y < lh->height)
		{
			my_mlx_pixel_put(lh, x, y, lh->color);
			y++;
		}
		x++;
	}
	lh->frame_counter++;
	mlx_put_image_to_window(lh->mlx, lh->win, lh->img, 0, 0);
	return (0);
}

int	main()
{
	t_hooks	lh;

	lh.frame_counter = 0;
	lh.increaser = 2;
	lh.mlx = mlx_init();
	lh.img = mlx_new_image(lh.mlx, 640, 480);
	lh.addr = mlx_get_data_addr(lh.img, &lh.bits_per_pixel, &lh.line_len, &lh.endian);
	init_struct(&lh);
	lh.win = mlx_new_window(lh.mlx, 640, 480, "well");
	mlx_loop_hook(lh.mlx, render_next_frame, &lh);
	mlx_loop(lh.mlx);
	return (0);
}