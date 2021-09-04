/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:21:03 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/04 18:36:15 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_height_width(t_all *all)
{
	int	height;
	int	width;
	int	len;

	height = 0;
	width = 0;
	len = 0;
	while (all->arr[height])
	{
		while (all->arr[height][width])
		{
			width++;
			len = width;
		}
		width = 0;
		height++;
	}
	if (height == 0 || len == 0)
		invalid_map();
	all->map.height = height;
	all->map.width = len;
	return (1);
}

static void	check_array(char *array)
{
	if (array == NULL)
		invalid_map();
	else
		return ;
}

static void	check_one_line(char *array, int i)
{
	if (array[i++] == '\0')
		invalid_map();
	else
		return ;
}

int	check_lines(char *array)
{
	int		i;
	int		len;
	char	*comp;

	i = 0;
	check_array(array);
	while (array[i] != '\n' && array[i] != '\0')
		i++;
	len = i;
	check_one_line(array, i);
	while (array[i])
	{
		if (array[i] == '\n' || array[i] == '\0')
		{
			comp = comp_str(array + i + 1);
			if ((int)ft_strlen(comp) != len)
			{
				free (comp);
				return (0);
			}
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
	return (array);
}
