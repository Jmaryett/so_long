/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:50 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/01 14:55:40 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fir_las_lin(char **t)
{
	int	i;
	int	j;

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
	char	**t;

	t = ft_split(array, '\n');
	return (t);
}

static int	array_len(char *array)
{
	int	len;

	len = 0;
	while (array[len] != '\n')
		len++;
	return (len);
}

static int	fir_las_char(char **t, int len)
{
	int	i;
	int	j;

	i = 0;
	while (t[i])
	{
		j = 0;
		if (t[i][0] == '1' && t[i][len - 1] == '1')
		{	
			while (t[i][j])
			{
				if (t[i][j] != '1' && t[i][j] != '0'
					&& t[i][j] != 'C' && t[i][j] != 'P'
					&& t[i][j] != 'E')
					return (0);
				j++;
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

char	**check_valid(char *array)
{
	char	**t;
	int		len;

	t = NULL;
	len = array_len(array);
	t = define_t(array);
	//init_arr(all, t);
	if (!fir_las_lin(t))
		return (0);
	else if (!fir_las_char(t, len))
		return (0);
	else if (!count_items(array))
		return (0);
	//free_t(t);
	return (t);
}
