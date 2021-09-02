/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:17:02 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 16:19:16 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include	"./libft/libft.h"
# include	"./mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
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

typedef struct s_keys
{
	int	count_moves;
	int	w;
	int	a;
	int	s;
	int	d;
}				t_keys;

typedef struct s_map
{
	int	height;
	int	width;
}				t_map;

typedef struct s_all
{
	int				coin_count;
	char			*array;
	char			**arr;
	void			*mlx;
	void			*mlx_win;
	t_map			map;
	t_keys			key;
	t_plps			plps;
	t_player_img	pl_img;
	t_wall_img		wall_img;
	t_floor_img		floor_img;
	t_coll_img		coll_img;
	t_exit_img		exit_img;
}				t_all;

void	check_file_name(char *filename);
int		check_fd(char *file);

char	*filling_array(int fd);
int		check_lines(char *array);
char	*comp_str(char *array);
int		init_height_width(t_all *all);
char	**check_valid(char *array);
void	init_arr(t_all *all, char **t);
void	free_t(char **t);
int		count_items(char *array);

void	invalid_map(void);
void	invalid_file(void);
void	invalid_input(void);

void	my_mlx_pixel_put(t_all *all, int width, int height, unsigned int color);
void	player_position(t_all *all);
void	count_coins(t_all *all, char *array);
void	relate_path(t_all *all);

void	check_w(t_all *all);
void	check_a(t_all *all);
void	check_s(t_all *all);
void	check_d(t_all *all);

int		drawing_map(t_all *all);
void	draw_wall(t_all *all, int height, int width);
void	draw_floor(t_all *all, int height, int width);
void	draw_collect(t_all *all, int height, int width);
void	draw_exit(t_all *all, int height, int width);
int		draw_player(t_all *all);

int		key_pressed(int keycode, t_all *all);
int		key_released(int keycode, t_all *all);
int		esc(t_all *all);
void	check_exit_for_w(t_all *all);
void	check_exit_for_a(t_all *all);
void	check_exit_for_s(t_all *all);
void	check_exit_for_d(t_all *all);

#endif