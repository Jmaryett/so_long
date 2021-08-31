/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_rendering_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:16 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/31 19:07:59 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rendering_map(t_all *all, int i, int w, int h)
{
	if (all->array[i] == '1')
		draw_wall(all, h, w);
	else if (all->array[i] == '0')
		draw_floor(all, h, w);
	else if (all->array[i] == 'C')
		draw_collect(all, h, w);
	else if (all->array[i] == 'E')
		draw_exit(all, h, w);
	return (i);
}

int	drawing_map(t_all *all)
{
	int	i;
	int	width;
	int	height;

	i = -1;
	width = 0;
	height = 0;
	mlx_clear_window(all->mlx, all->mlx_win);
	while (all->array[++i])
	{
		if (all->array[i] == '\n' || all->array[i] == '\0')
		{
			height++;
			width = 0;
			continue ;
		}
		else
			i = rendering_map(all, i, width, height);
		width++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->pl_img.img,
		all->plps.x * ELEM_SIZE, all->plps.y * ELEM_SIZE);
	mlx_do_sync(all->mlx);
	return (0);
}
