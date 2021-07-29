#ifndef SO_LONG_H

# define SO_LONG_H

#include "./libft_42_school/libft.h"
#include "./mlx/mlx.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 32
# endif

typedef	struct s_map
{
	int		height;
	int		lenght;
	char	**map;
}				t_map;

char	*filling_array(int fd);
int	check_lines(char *array);
char	*comp_str(char *array);
int	check_height_width(char *array);
int	check_valid(char *array);
void	init_height_width(char *array);


#endif