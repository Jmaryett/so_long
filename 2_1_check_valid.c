/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_check_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:57 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/01 14:54:45 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	free_t(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free (t[i]);
		i++;
	}
	free(t);
} */

void	init_arr(t_all *all, char **t)
{
	if (t == NULL)
		invalid_map();
	all->arr = t;
	return ;
}

static int	count_result(int p, int c, int e)
{
	if (p != 1)
		return (0);
	else if (c != 1)
		return (0);
	else if (e != 1)
		return (0);
	return (1);
}

int	count_items(char *array)
{
	int	i;
	int	count_player;
	int	count_coll;
	int	count_exit;

	i = -1;
	count_coll = 0;
	count_exit = 0;
	count_player = 0;
	while (array[++i])
	{
		if (array[i] == 'P')
			count_player++;
		else if (array[i] == 'C')
			count_coll = 1;
		else if (array[i] == 'E')
			count_exit = 1;
	}
	return (count_result(count_player, count_coll, count_exit));
}
