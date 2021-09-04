/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_drawing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:16 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/04 18:37:53 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rendering_map(t_all *all, int w, int h)
{
	if (all->arr[h][w] == '1')
		draw_wall(all, h, w);
	else if (all->arr[h][w] == '0')
		draw_floor(all, h, w);
	else if (all->arr[h][w] == 'C')
		draw_collect(all, h, w);
	else if (all->arr[h][w] == 'E')
		draw_exit(all, h, w);
}

int	drawing_map(t_all *all)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (all->arr[height])
	{
		while (all->arr[height][width])
		{
			rendering_map(all, width, height);
			width++;
		}
		width = 0;
		height++;
	}
	return (0);
}
