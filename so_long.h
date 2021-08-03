#ifndef SO_LONG_H

# define SO_LONG_H

#include "./libft_42_school/libft.h"
#include "./mlx/mlx.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 32
# endif

typedef struct s_pl_pos
{
	int	x;
	int	y;
}				t_plps;

typedef struct	s_keys 
{
	int	w;
	int	a;
	int	s;
	int	d;
}				t_keys;

typedef	struct s_map
{
	int		height;
	int		width;
}				t_map;

typedef	struct s_image
{
	int		img_width;
	int		img_height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_image;

typedef	struct s_all
{
	void	*mlx;
	void	*mlx_win;
	t_map	map;
	t_image	img;
	t_keys	key;
	t_plps plps;
}				t_all;


char	*filling_array(int fd);
int	check_lines(char *array);
char	*comp_str(char *array);
int	check_height_width(char *array, t_map *map);
int	check_valid(char *array);
void	invalid_map(char *array);

//void	pixel_put_loop(t_all *all, int width, int height);
//void	my_mlx_pixel_put(t_image *img, int width, int height, unsigned int color);
void	player_position(char *array, t_plps *plps);


int	key_pressed(int keycode, t_all *all);
int	key_released(int keycode, t_all *all);
int	esc(t_all *all);

#endif