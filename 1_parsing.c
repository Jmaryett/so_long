#include "so_long.h"

int	check_height_width(char *array, t_map *map)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	i = 0;
	while (array[i] != '\n')
		i++;
	width = i;
	i = 0;
	while (array[i])
	{
		if (array[i] == '\n')
			height++;
		i++;	
	}
	height++;
	if (height == 0 || width == 0)
		return (0);
	map->height = height;
	map->width = width;
	//printf("width - %d, height - %d\n", map->width, map->height);
	//printf ("%d\n%d\n", height, width);
	return (1);
}

int	check_lines(char *array)
{
	int		i;
	int		len;
	char	*comp;
	
	i = 0;
	comp = NULL;
	while (array[i] != '\n')
		i++;
	len = i;
	while (array[i])
	{
		if (array[i] == '\n')
		{
			comp = comp_str(array + i + 1);
			if ((int)ft_strlen(comp) != len)
				return (0);
			free (comp);
		}
		i++;	
	}
	return (1);
}

char	*filling_array(int fd)
{
	char	*buf;
	int		n_read;
	char	*array;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	array = NULL;
	if (!buf || read(fd, buf, 0) < 0)
		return (0);
	while (1)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read <= 0)
			break ;
		buf[n_read] = '\0';
		array = ft_strjoin(array, buf);
	}
	free (buf);
	return(array);
}