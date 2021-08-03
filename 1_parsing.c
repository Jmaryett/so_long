#include "so_long.h"

static void	check_map_size(t_map *map)
{
	if (map->width < 100)
		map->width *= 100;
	if (map->height < 100)
		map->height *= 100;
}

int	check_height_width(char *array, t_map *map)
{
	int	i;
	int	count;
	int	len;

	count = 0;
	i = 0;
	while (array[i] != '\n')
		i++;
	len = i;
	i = 0;
	while (array[i])
	{
		if (array[i] == '\n')
			count++;
		i++;	
	}
	count++;
	if (/* count == len || */ count == 0 || len == 0)
		return (0);
	map->height = count;
	map->width = len;
	check_map_size(map);
	//printf ("%d\n%d\n", count, len);
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
	//printf ("%d\n", len);
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