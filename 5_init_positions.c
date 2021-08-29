/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_init_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:31 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/29 19:20:32 by jmaryett         ###   ########.fr       */
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

void	player_position(char *array, t_plps *plps)
{
	int	i;
	int	width;
	int	height;

	i = -1;
	width = 0;
	height = 0;
	while (array[++i])
	{
		if (array[i] == '\n' || array[i] == '\0')
		{
			width = 0;
			height++;
			continue ;
		}
		if (array[i] == 'P')
		{
			plps->x = width;
			plps->y = height;
			array[i] = '0';
		}
		width++;
	}
}
