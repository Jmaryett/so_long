#include "so_long.h"

static int	fir_las_lin(char **t)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (t[i])
		i++;
	while (t[0][++j])
	{
		if (t[0][j] != '1')
			return (0);
	}
	i--;
	j = 0;
	while (t[i][j])
	{
		if (t[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}


static char	**define_t(char *array)
{
	char **t;

	t = NULL;
	t = ft_split(array, '\n');
	return (t);
}

static int array_len(char *array)
{
	int len;

	len = 0;
	while (array[len] != '\n')
		len++;
	return (len);
}

int check_valid(char *array)
{
	char **t;
	int len; //line len
	int i;
	int j;

	t = NULL;
	i = -1;
	len = array_len(array);
	t = define_t(array);
	if (!fir_las_lin(t))
		return (0);
	while (t[++i])
	{
		j = -1;
		while (t[i][++j])
		{
			if (t[i][0] != '1' && t[i][len] != '1')
				return (0);
			else if (t[i][j] != '1' && t[i][j] != '0' && t[i][j] != 'C' && t[i][j] != 'P' && t[i][j] != 'E')
				return (0);
		}
	}
	return (1);
}