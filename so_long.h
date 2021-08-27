#ifndef SO_LONG_H

# define SO_LONG_H

#include "./libft_42_school/libft.h"
#include "./mlx/mlx.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 32
# endif

# define ELEM_SIZE 35

typedef struct s_exit_img
{
	char	*exit;
	void	*img;
	int		img_width;
	int		img_height;
}				t_exit_img;

typedef struct s_coll_img
{
	char	*collec;
	void	*img;
	int		img_width;
	int		img_height;
}				t_coll_img;

typedef struct s_wall_img
{
	char	*wall;
	void	*img;
	int		img_width;
	int		img_height;
}				t_wall_img;

typedef struct s_floor_img
{
	char	*floor;
	void	*img;
	int		img_width;
	int		img_height;
}				t_floor_img;

typedef struct s_player_img
{
	char	*player;
	void	*img;
	int		img_width;
	int		img_height;
}				t_player_img;

typedef struct s_pl_pos
{
	int	x;
	int	y;
}				t_plps;

typedef struct	s_keys 
{
	int	count_moves;
	int	w;
	int	a;
	int	s;
	int	d;
}				t_keys;

typedef	struct s_map
{
	int	height;
	int	width;
}				t_map;

typedef	struct s_all
{
	int			coin_count;
	char		*array;
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_keys		key;
	t_plps		plps;
	t_player_img	pl_img;
	t_wall_img		wall_img;
	t_floor_img		floor_img;
	t_coll_img		coll_img;
	t_exit_img		exit_img;
}				t_all;


char	*filling_array(int fd);
int	check_lines(char *array);
char	*comp_str(char *array);
int	check_height_width(char *array, t_map *map);
int	check_valid(char *array);
int	count_items(char *array);
void	invalid_map(char *array);
void	invalid_file(void);
void	invalid_input(void);

//void	pixel_put_loop(t_all *all, int width, int height);
void	my_mlx_pixel_put(t_all *all, int width, int height, unsigned int color);
void	player_position(char *array, t_plps *plps);
void	count_coins(t_all *all, char *array);
//void		count_moves(int keycode, t_all *all);
void	relate_path(t_all *all);

void	check_w(t_all *all, int i);
void	check_a(t_all *all, int i);
void	check_s(t_all *all, int i);
void	check_d(t_all *all, int i);

int		drawing_map(t_all *all);
void	draw_wall(t_all *all, int height, int width);
void	draw_floor(t_all *all, int height, int width);
void	draw_collect(t_all *all, int height, int width);
void	draw_exit(t_all *all, int height, int width);
//void	check_positions(t_all *all, char key);

int	key_pressed(int keycode, t_all *all);
int	key_released(int keycode, t_all *all);
int	esc(t_all *all);

#endif