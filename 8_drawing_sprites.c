/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_drawing_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:07 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 16:54:50 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->wall_img.img,
		width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_floor(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->floor_img.img,
		width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_collect(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->coll_img.img,
		width * ELEM_SIZE, height * ELEM_SIZE);
}

void	draw_exit(t_all *all, int height, int width)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->exit_img.img,
		width * ELEM_SIZE, height * ELEM_SIZE);
}

int	draw_player(t_all *all)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->pl_img.img,
		all->plps.x * ELEM_SIZE, all->plps.y * ELEM_SIZE);
	return (0);
}