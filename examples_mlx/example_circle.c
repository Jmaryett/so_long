#include <math.h>

static void	work_mlx(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_image img;
	int pix;
	int pix2;
	int vect = 0;
	int r = 100;
	int x = (map->width * 100) / 2;
	int y = (map->height * 100) / 2;
	int x2 = map->width * 100 + r;
	int y2 = map->height * 100 + r; 

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, map->width * 100, map->height * 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	mlx_win = mlx_new_window(mlx, map->width * 100, map->height * 100, "so_long");
	pix = x - r;
	//pix2 = y - r;
	while (pix < x2)
	{
		pix2 = y - r;
		while (pix2 < y2)
		{
			vect = sqrt((pix - x) * (pix - x) + (pix2 - y) * (pix2 - y));
			if (vect < r)
				my_mlx_pixel_put(&img, pix, pix2, 0x00FFFF00);
			pix2++;
		}
		pix++;
	}
	
	/* for (int i = 0; i < map->height * 30; i++)
	{
		for (int j = 0; j < map->width * 30; j++)
			my_mlx_pixel_put(&img, j, i, 0x00FFFF00);
	} */
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}