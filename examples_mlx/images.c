#include "../mlx/mlx.h"

typedef struct s_var
{
	int	w;
	int a;
	int s;
	int d;

	int fps;
	int width;
	int height;
	void *win;
	void *mlx;
	void *img;
	int img_width;
	int img_height;
}				t_var;

void init_key(t_var *var)
{
	var->w = 0;
	var->a = 0;
	var->s = 0;
	var->d = 0;
}

int key_press(int keycode, t_var *var)
{
	if (keycode == 13)
		var->w = 1;
	else if (keycode == 0)
		var->a = 1;
	else if (keycode == 1)
		var->s = 1;
	else if (keycode == 2)
		var->d = 1;
	return (0);
}

int key_release(int keycode, t_var *var)
{
	if (keycode == 13)
		var->w = 0;
	else if (keycode == 0)
		var->a = 0;
	else if (keycode == 1)
		var->s = 0;
	else if (keycode == 2)
		var->d = 0;
	return (0);
}

int move_img(t_var *var)
{
	//char *relative_path = "./test.xpm";
	//var->img = mlx_xpm_file_to_image(var->mlx, relative_path, &var->img_width, &var->img_height);
	//var->width = 600;
	//var->height = 300;
	//mlx_put_image_to_window(var->mlx, var->win, var->img, var->width, var->height);
	if (var->fps % 50 == 0)
	{
		if (var->w == 1)
		{
			while (var->height > 0)
			{
				mlx_clear_window(var->mlx, var->win);
				mlx_put_image_to_window(var->mlx, var->win, var->img, var->width, var->height);
				var->height--;
			}
		}
		//var->fps = 0;
	}
	var->fps++;
	return (0);
}


int main()
{
	t_var	var;
	char *relative_path = "./test.xpm";
	var.width = 600;
	var.height = 300;
	var.fps = 0;

	init_key(&var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1000, 600, "img");
	var.img = mlx_xpm_file_to_image(var.mlx, relative_path, &var.img_width, &var.img_height);
	mlx_put_image_to_window(var.mlx, var.win, var.img, var.width, var.height);
	mlx_hook(var.win, 2, 1L<<0, key_press, &var);
	mlx_hook(var.win, 3, 1L<<1, key_release, &var);
	mlx_loop_hook(var.mlx, move_img, &var);
	mlx_loop(var.mlx);
}