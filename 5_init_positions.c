/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_init_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:31 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 16:55:07 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_coins(t_all *all, char *array)
{
	int	i;

	i = -1;
	all->coin_count = 0;
	while (array[++i])
	{
		if (array[i] == 'C')
			all->coin_count++;
	}
}

void	player_position(t_all *all)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (all->arr[height])
	{
		while(all->arr[height][width])
		{
			if (all->arr[height][width] == 'P')
			{
				all->plps.x = width;
				all->plps.y = height;
				all->arr[height][width] = '0';
			}
			width++;
		}
		width = 0;
		height++;
	}
}
